
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 main.c
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Forrest Yu, 2005
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"
#include "2048Game.h"

/*======================================================================*
 kernel_main
 *======================================================================*/
PUBLIC int kernel_main()
{
    disp_str("-----\"kernel_main\" begins-----\n");
    
    struct task* p_task;
    struct proc* p_proc= proc_table;
    char* p_task_stack = task_stack + STACK_SIZE_TOTAL;
    // u16   selector_ldt = SELECTOR_LDT_FIRST;
    u8    privilege;
    u8    rpl;
    int   eflags;
    int   i, j;
    int   prio;
    for (i = 0; i < NR_TASKS+NR_PROCS; i++)
    {
        if (i >= NR_TASKS + NR_NATIVE_PROCS) {
            p_proc->p_flags = FREE_SLOT;
            p_proc++;
            p_task++;
            continue;
        }
        if (i < NR_TASKS)
        {     /* 任务 */
            p_task    = task_table + i;
            privilege = PRIVILEGE_TASK;
            rpl       = RPL_TASK;
            eflags    = 0x1202; /* IF=1, IOPL=1, bit 2 is always 1   1 0010 0000 0010(2)*/
            prio      = 15;     //设定优先级为15
        }
        else
        {                  /* 用户进程 */
            p_task    = user_proc_table + (i - NR_TASKS);
            privilege = PRIVILEGE_USER;
            rpl       = RPL_USER;
            eflags    = 0x202; /* IF=1, bit 2 is always 1              0010 0000 0010(2)*/
            prio      = 5;     //设定优先级为5
        }
        
        strcpy(p_proc->name, p_task->name); /* 设定进程名称 */
        p_proc->p_parent = NO_TASK;
        
        if (strcmp(p_task->name, "Init") != 0) {
            p_proc->ldts[INDEX_LDT_C]  = gdt[SELECTOR_KERNEL_CS >> 3];
            p_proc->ldts[INDEX_LDT_RW] = gdt[SELECTOR_KERNEL_DS >> 3];
            
            /* change the DPLs */
            p_proc->ldts[INDEX_LDT_C].attr1  = DA_C   | privilege << 5;
            p_proc->ldts[INDEX_LDT_RW].attr1 = DA_DRW | privilege << 5;
        }
        else {      /* INIT process */
            unsigned int k_base;
            unsigned int k_limit;
            int ret = get_kernel_map(&k_base, &k_limit);
            assert(ret == 0);
            init_descriptor(&p_proc->ldts[INDEX_LDT_C],
                            0, /* bytes before the entry point
                                * are useless (wasted) for the
                                * INIT process, doesn't matter
                                */
                            (k_base + k_limit) >> LIMIT_4K_SHIFT,
                            DA_32 | DA_LIMIT_4K | DA_C | privilege << 5);
            
            init_descriptor(&p_proc->ldts[INDEX_LDT_RW],
                            0, /* bytes before the entry point
                                * are useless (wasted) for the
                                * INIT process, doesn't matter
                                */
                            (k_base + k_limit) >> LIMIT_4K_SHIFT,
                            DA_32 | DA_LIMIT_4K | DA_DRW | privilege << 5);
        }
        
        p_proc->regs.cs = INDEX_LDT_C << 3 | SA_TIL | rpl;
        p_proc->regs.ds =
        p_proc->regs.es =
        p_proc->regs.fs =
        p_proc->regs.ss = INDEX_LDT_RW << 3 | SA_TIL | rpl;
        p_proc->regs.gs = (SELECTOR_KERNEL_GS & SA_RPL_MASK) | rpl;
        
        p_proc->regs.eip = (u32)p_task->initial_eip;
        p_proc->regs.esp = (u32)p_task_stack;
        p_proc->regs.eflags = eflags;
        
        /* p_proc->nr_tty       = 0; */
        
        p_proc->p_flags = 0;
        p_proc->p_msg = 0;
        p_proc->p_recvfrom = NO_TASK;
        p_proc->p_sendto = NO_TASK;
        p_proc->has_int_msg = 0;
        p_proc->q_sending = 0;
        p_proc->next_sending = 0;
        p_proc->pid = i;
        
        for (j = 0; j < NR_FILES; j++)
            p_proc->filp[j] = 0;
        
        p_proc->ticks = p_proc->priority = prio;
        
        p_task_stack -= p_task->stacksize;
        p_proc++;
        p_task++;
        // selector_ldt += 1 << 3;
    }
    
    /* proc_table[NR_TASKS + 0].nr_tty = 0; */
    /* proc_table[NR_TASKS + 1].nr_tty = 1; */
    /* proc_table[NR_TASKS + 2].nr_tty = 1; */
    
    k_reenter = 0;
    ticks = 0;
    
    p_proc_ready = proc_table;
    
    init_clock();
    init_keyboard();
    
    restart();
    
    while(1){}
}


void nothing(){
}


void Init_test()
{
    char tty_name[] = "/dev_tty2";
    
    char rdbuf[128];
    
    
    int fd_stdin  = open(tty_name, O_RDWR);
    assert(fd_stdin  == 0);
    int fd_stdout = open(tty_name, O_RDWR);
    assert(fd_stdout == 1);
    
    printf("Init() is running ...\n");
    
    while(1) {
        int r = read(fd_stdin, rdbuf, 70);
        rdbuf[r] = 0;
        printf("Before fork()");
        int pid = fork();
        if (pid != 0) { /* parent process */
            printf("parent is running, child pid:%d\n", pid);
            spin("parent");
        }
        else {  /* child process */
            printf("child is running, pid:%d\n", getpid());
            spin("child");
        }
    }
}


/*****************************************************************************
 *                                get_ticks
 *****************************************************************************/
PUBLIC int get_ticks()
{
    MESSAGE msg;
    reset_msg(&msg);
    msg.type = GET_TICKS;
    send_recv(BOTH, TASK_SYS, &msg);
    return msg.RETVAL;
}


/*****************************************************************************
 *                                convert_to_absolute
 *                      将传入的路径和文件名组合成一个完整的绝对路径
 *****************************************************************************/
PUBLIC void convert_to_absolute(char* dest, char* path, char* file)
{
    int i=0, j=0;
    while (path[i] != 0)  // 写入路径
    {
        dest[j] = path[i];
        j++;
        i++;
    }
    i = 0;
    while (file[i] != 0)  // 写入文件名
    {
        dest[j] = file[i];
        j++;
        i++;
    }
    dest[j] = 0;  // 结束符
}


/*======================================================================*
 TestA
 *======================================================================*/

//1号终端
void TestA()
{
    char tty_name[] = "/dev_tty0";
    
    char rdbuf[256] = { 0 };
    char cmd[20];
    char filename1[128];
    char filename2[128];
    
    int fd_stdin  = open(tty_name, O_RDWR);
    assert(fd_stdin  == 0);
    int fd_stdout = open(tty_name, O_RDWR);
    assert(fd_stdout == 1);
    
    //  char filename[MAX_FILENAME_LEN+1] = "zsp01";
    const char bufw[80] = {0};
    //  const int rd_bytes = 3;
    //  char bufr[rd_bytes];
    sl();
    clear();
    printf(">=============================================================================< \n");
    printf("                                    Phoenix v1.0.0\n");
    printf("                                           \n");
    printf("                                      Hello !\n");
    printf(">=============================================================================< \n");
    
    char current_dirr[512] = "/";  // 记录当前路径（其实路径字符长度上限为MAX_PATH）
    
    while (1) {
        printf("[root@localhost: %s]", current_dirr);  // 打印当前路径
        int r = read(fd_stdin, rdbuf, 512);
        rdbuf[r] = 0;
        
        // 解析命令
        int pos = 0;
        while (rdbuf[pos] != ' ' && rdbuf[pos] != 0)  // 读取指令
        {
            cmd[pos] = rdbuf[pos];
            pos++;
        }
        cmd[pos] = 0;
        if (rdbuf[pos] != 0)  // 指令还未结束
        {
            pos++;
            int len = pos;
            while (rdbuf[pos] != ' ' && rdbuf[pos] != 0)  // 读取第一个文件名
            {
                filename1[pos - len] = rdbuf[pos];
                pos++;
            }
            filename1[pos - len] = 0;
        }
        if (rdbuf[pos] != 0)  // 指令还未结束
        {
            pos++;
            int len = pos;
            while (rdbuf[pos] != ' ' && rdbuf[pos] != 0)  // 读取第二个文件名
            {
                filename2[pos - len] = rdbuf[pos];
                pos++;
            }
            filename2[pos - len] = 0;
        }
        // printf("%s O %s O %s O", cmd, filename1, filename2);
        //show();
        if (strcmp(cmd, "process") == 0)
        {
            ProcessManage();
        }
        else if (strcmp(cmd, "filemng") == 0)
        {
            printf("File Manager is already running on CONSOLE-1 ! \n");
            continue;
        }
        else if (strcmp(cmd, "ls") == 0)
        {
            ls(current_dirr);
        }
        else if (strcmp(cmd, "mk") == 0)  // 创建文件
        {
            CreateFile(current_dirr, filename1);
        }
        else if (strcmp(cmd, "rm") == 0)  // 删除文件
        {
            DeleteFile(current_dirr, filename1);
        }
        else if (strcmp(cmd, "pr") == 0)  // 打印文件内容
        {
            ReadFile(current_dirr, filename1);
        }
        else if (strcmp(cmd, "vi") == 0)  // 写文件
        {
            WriteFile(current_dirr, filename1);
        }
        else if(strcmp(cmd, "mkdir") == 0)  // 创建目录
        {
            CreateDir(current_dirr, filename1);
        }
        else if(strcmp(cmd, "cd") == 0)
        {
            GoDir(current_dirr, filename1);
        }
        else if (strcmp(cmd, "help") == 0)
        {
            help();
        }
        else if (strcmp(cmd, "runchess") == 0)
        {
            TTT(fd_stdin, fd_stdout);
        }
        else if (strcmp(cmd, "runtank") == 0)
        {
            Tank(fd_stdin, fd_stdout);
        }
        else if (strcmp(cmd, "runMS") == 0)
        {
            MS(fd_stdin, fd_stdout);
        }
        else if (strcmp(cmd, "run2048") == 0)
        {
            start2048Game(fd_stdin, fd_stdout);
        }
        else if (strcmp(cmd, "clear") == 0)
        {
            clear();
            printf(">=============================================================================< \n");
            printf("                                    Phoenix v1.0.0\n");
            printf("                                           \n");
            printf("                                      Hello !\n");
            printf(">=============================================================================< \n");
            printf(" \n");
            
        }
        
        else if (strcmp(cmd, "getpid") == 0) {
            printf(asm_strcat(getpid(), "\n"));
            printi(getpid());
            printf("\n");
            printi(new_getpid());
            printf("\n");
        }
        
        else if (strcmp(cmd, "test_fork") == 0) {
            int pid = fork();
            if (pid == 0) {
            } else {
                printl("childpid: %d, childname: %s\n", pid, proc_table[pid].name);
            }
        }
        
        else if (strcmp(cmd, "test_ldt") == 0) {
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[0].ldts[INDEX_LDT_C].base_high, proc_table[0].ldts[INDEX_LDT_C].base_mid, proc_table[0].ldts[INDEX_LDT_C].base_low);
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[1].ldts[INDEX_LDT_C].base_high, proc_table[1].ldts[INDEX_LDT_C].base_mid, proc_table[1].ldts[INDEX_LDT_C].base_low);
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[2].ldts[INDEX_LDT_C].base_high, proc_table[2].ldts[INDEX_LDT_C].base_mid, proc_table[2].ldts[INDEX_LDT_C].base_low);
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[3].ldts[INDEX_LDT_C].base_high, proc_table[3].ldts[INDEX_LDT_C].base_mid, proc_table[3].ldts[INDEX_LDT_C].base_low);
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[4].ldts[INDEX_LDT_C].base_high, proc_table[4].ldts[INDEX_LDT_C].base_mid, proc_table[4].ldts[INDEX_LDT_C].base_low);
            printl("{MM} base_high: %d, bsae_mid: %d, low: %d)\n", proc_table[5].ldts[INDEX_LDT_C].base_high, proc_table[5].ldts[INDEX_LDT_C].base_mid, proc_table[5].ldts[INDEX_LDT_C].base_low);
            int k_base, k_limit;
            get_kernel_map(&k_base, &k_limit);
            printl("0x%x, 0x%x\n", k_base, k_limit);
            // struct proc* p_proc= proc_table+5;
            // printl("{MM} %d, %d, %d, %d)\n", p_proc->ldts[INDEX_LDT_C], p_proc->ldts[INDEX_LDT_RW], p_proc->ldts[INDEX_LDT_C].attr1, p_proc->ldts[INDEX_LDT_RW].attr1);
            // struct descriptor* ppd = &(proc_table[5].ldts[INDEX_LDT_RW]);
            // printl("{MM} %d,%d,%d,%d,%d,%d)\n", ppd->limit_low, ppd->base_low,  ppd->base_high, ppd->base_mid, ppd->attr1, ppd->limit_high_attr2, ppd->base_high);
            int i;
            for (i = 0; i < NR_TASKS + NR_NATIVE_PROCS ; ++i) {
                struct descriptor* ppd = &(proc_table[i].ldts[INDEX_LDT_RW]);
                printl("{MM} %s, %x,%x,%x,%x,%x,%x)\n", proc_table[i].name, ppd->limit_low, ppd->base_low,  ppd->base_mid, ppd->base_high, ppd->attr1, ppd->limit_high_attr2);
                
            }
        }
        
        else
            printf("Command not found, please check!\n");
        // printf("rdbuf:      %s\n", rdbuf);
        // printf("cmd:        %s\n", cmd);
        // printf("filename1:  %s\n", filename1);
        // printf("filename2:  %s\n", filename2);
    }
    
}

/*======================================================================*
 TestB
 *======================================================================*/
//二号终端
void TestB()
{
    char tty_name[] = "/dev_tty1";
    
    int fd_stdin  = open(tty_name, O_RDWR);
    assert(fd_stdin  == 0);
    int fd_stdout = open(tty_name, O_RDWR);
    assert(fd_stdout == 1);
    
    char rdbuf[128];
    char cmd[8];
    char filename[120];
    char buf[1024];
    int m,n;
    printf(">=============================================================================< \n");
    printf("                                    File Manager\n");
    printf("                                           \n");
    printf("                                 Kernel on Orange's\n");
    printf(">=============================================================================< \n");
    
    while (1) {
        printf("$ ");
        int r = read(fd_stdin, rdbuf, 70);
        rdbuf[r] = 0;
        
        
        
        if (strcmp(rdbuf, "help") == 0)
        {
            printf("=============================================================================\n");
            printf("Command List \n");
            printf("-----------------------------------------------------------------------------\n");
            printf("||   help  ||          Show this help message             ||\n");
            printf("==============================================================================\n");
        }
        else
        {
            printf("Command not found, Please check!\n");
            continue;
        }
    }
    assert(0); /* never arrive here */
}


void TestC()
{
    spin("TestC");
}


/*****************************************************************************
 *                                panic
 *****************************************************************************/
PUBLIC void panic(const char *fmt, ...)
{
    int i;
    char buf[256];
    
    /* 4 is the size of fmt in the stack */
    va_list arg = (va_list)((char*)&fmt + 4);
    
    i = vsprintf(buf, fmt, arg);
    
    printl("%c !!panic!! %s", MAG_CH_PANIC, buf);
    
    /* should never arrive here */
    __asm__ __volatile__("ud2");
}

void clear()
{
    clear_screen(0,console_table[current_console].cursor);
    console_table[current_console].crtc_start = 0;
    console_table[current_console].cursor = 0;
    
}

//void show()
//{
//  printf("%d  %d  %d  %d",console_table[current_console].con_size, console_table[current_console].crtc_start, console_table[current_console].cursor, console_table[current_console].orig);
//}

void help()
{
    printf("=============================Phoeniux help info=================================\n");
    printf("                              Command List\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("|1.process                || Run the process manage                          |\n");
    printf("|2.filemng                || Run the file manager                            |\n");
    printf("|3.clear                  || Clear the screen                                |\n");
    printf("|4.help                   || Show the  all the cmd and detail meaning        |\n");
    printf("|5.ls                     || List all files in current directory             |\n");
    printf("|6.mk        [filename]   || Create a new file in current directory          |\n");
    printf("|7.rm        [filename]   || Delete a file in current directory              |\n");
    printf("|8.pr        [filename]   || Print the content of a file in current directory|\n");
    printf("|9.vi        [filename]   || Write new content at the end of the file        |\n");
    printf("|10.mkdir    [dirname]    || Create a new directory in current directory     |\n");
    printf("|11.cd       [dirname]    || Go to a directory in current directory          |\n");
    printf("|12.runtank               || Run a small game on this OS                     |\n");
    printf("|13.runchess              || Run a small game on this OS                     |\n");
    printf("|14.run2048               || Run 2048 game on this OS                        |\n");
    printf("|15.runMS                 || Run a small game on this OS                     |\n");
    printf("================================================================================\n");
}

void ProcessManage()
{
    int i;
    printf("=============================================================================\n");
    printf("      PID      |    name       | spriority    | running?\n");
    //进程号，进程名，优先级，是否是系统进程，是否在运行
    printf("-----------------------------------------------------------------------------\n");
    for ( i = 0 ; i < NR_TASKS + NR_PROCS ; ++i )//逐个遍历
    {
        /*if ( proc_table[i].priority == 0) continue;//系统资源跳过*/
        if(proc_table[i].p_flags!=FREE_SLOT)
            printf("        %d           %s            %d                %s\n", proc_table[i].pid, proc_table[i].name, proc_table[i].priority, proc_table[i].p_flags==FREE_SLOT? "NO":"YES");
    }
    printf("=============================================================================\n");
}

void CreateFile(char* path, char* file)
{
    char absoPath[512];
    convert_to_absolute(absoPath, path, file);
    
    int fd = open(absoPath, O_CREAT | O_RDWR);
    
    if (fd == -1)
    {
        printf("Failed to create a new file with name %s\n", file);
        return;
    }
    
    char buf[1] = {0};
    write(fd, buf, 1);
    printf("File created: %s (fd %d)\n", file, fd);
    close(fd);
}

void DeleteFile(char* path, char* file)
{
    char absoPath[512];
    convert_to_absolute(absoPath, path, file);
    int m=unlink(absoPath);
    if (m == 0)
        printf("%s deleted!\n", file);
    else
        printf("Failed to delete %s!\n", file);
}

void ReadFile(char* path, char* file)
{
    char absoPath[512];
    convert_to_absolute(absoPath, path, file);
    int fd = open(absoPath, O_RDWR);
    if (fd == -1)
    {
        printf("Failed to open %s!\n", file);
        return;
    }
    
    char buf[4096];
    int n = read(fd, buf, 4096);
    if (n == -1)  // 读取文件内容失败
    {
        printf("An error has occured in reading the file!\n");
        close(fd);
        return;
    }
    
    printf("%s\n", buf);
    close(fd);
}

void WriteFile(char* path, char* file)
{
    char absoPath[512];
    convert_to_absolute(absoPath, path, file);
    int fd = open(absoPath, O_RDWR);
    if (fd == -1)
    {
        printf("Failed to open %s!\n", file);
        return;
    }
    
    char tty_name[] = "/dev_tty0";
    int fd_stdin  = open(tty_name, O_RDWR);
    if (fd_stdin == -1)
    {
        printf("An error has occured in writing the file!\n");
        return;
    }
    char writeBuf[4096];  // 写缓冲区
    int endPos = read(fd_stdin, writeBuf, 4096);
    writeBuf[endPos] = 0;
    write(fd, writeBuf, endPos + 1);  // 结束符也应写入
    close(fd);
}

void CreateDir(char* path, char* file)
{
    char absoPath[512];
    convert_to_absolute(absoPath, path, file);
    int fd = open(absoPath, O_RDWR);
    
    if (fd != -1)
    {
        printf("Failed to create a new directory with name %s\n", file);
        return;
    }
    mkdir(absoPath);
}

void GoDir(char* path, char* file)
{
    int flag = 0;  // 判断是进入下一级目录还是返回上一级目录
    char newPath[512] = {0};
    if (file[0] == '.' && file[1] == '.')  // cd ..返回上一级目录
    {
        flag = 1;
        int pos_path = 0;
        int pos_new = 0;
        int i = 0;
        char temp[128] = {0};  // 用于存放某一级目录的名称
        while (path[pos_path] != 0)
        {
            if (path[pos_path] == '/')
            {
                pos_path++;
                if (path[pos_path] == 0)  // 已到达结尾
                    break;
                else
                {
                    temp[i] = '/';
                    temp[i + 1] = 0;
                    i = 0;
                    while (temp[i] != 0)
                    {
                        newPath[pos_new] = temp[i];
                        temp[i] = 0;  // 抹掉
                        pos_new++;
                        i++;
                    }
                    i = 0;
                }
            }
            else
            {
                temp[i] = path[pos_path];
                i++;
                pos_path++;
            }
        }
    }
    char absoPath[512];
    char temp[512];
    int pos = 0;
    while (file[pos] != 0)
    {
        temp[pos] = file[pos];
        pos++;
    }
    temp[pos] = '/';
    temp[pos + 1] = 0;
    if (flag == 1)  // 返回上一级目录
    {
        temp[0] = 0;
        convert_to_absolute(absoPath, newPath, temp);
    }
    else  // 进入下一级目录
        convert_to_absolute(absoPath, path, temp);
    int fd = open(absoPath, O_RDWR);
    if (fd == -1)
        printf("invalid operation!\n");
    else
        memcpy(path, absoPath, 512);
}

