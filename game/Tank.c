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
 
void Tank(int fd_stdin, int fd_stdout)
{
	int pox, poy;
	int x = 10;
	int y = 25;
	//可以定义一个input输入框，用于控制移动方向
	char input[1] = { 0 };
	// 是否发射子弹
	int isFired = 0;
	//////////////////////////////////////////////////////////////////////////
	//用加号代替靶子
	int king_y = 5;//这是靶子的y坐标。靶子用“+”表示
	//是否被击中
	int isKilled = 0;
	//计分器
	int score = 0;
	//计数器
	long int count = 0;
	//敌机移动flag
	int flag = 0;
	//加入while循环
	while (1)
	{
		clear();
		printf("steps you have used:%d",count);
		printf("\n");
		printf("press enter to exit");
		printf("\n");
		printf("your score:%d",score);
		printf("\n");
		for (poy = 0; poy < king_y; poy++)
		{
			printf(" ");
		}
		printf("+\n");

		//如果不开火，则不发射子弹
		if (isFired == 0)
		{
			for (pox = 0; pox < x; pox++)
			{
				printf("\n");
			}
		}
		else
		{
			for (pox = 0; pox < x; pox++)
			{
				for (poy = 0; poy < y; poy++)
				{
					printf(" ");
				}
				printf("  | \n");
			}
			if (king_y == (y + 2))
			{
				score++;
				flag=0;
				srand(count);
				king_y = rand()%50+2;
			}

			isFired = 0; //按一次空格发射一次子弹，重置为0；
		}
		if (flag == 2)
		{
			flag=0;
			srand(count);
			if(king_y>2)
				king_y += rand()%3-1;
		}
		//雪花作为飞机
		for (poy = 0; poy < y; poy++)
			printf(" ");
		printf("  *  \n");
		for (poy = 0; poy < y; poy++)
			printf(" ");
		printf(" *** \n");
		for (poy = 0; poy < y; poy++)
			printf(" ");
		printf("  *  \n");
		for (poy = 0; poy < y; poy++)
			printf(" ");
		printf(" * * \n");

		// x++;  //此x的功能是让雪花点向下移动。
		if(!read(fd_stdin, input, 1))
			break;
		flag++;
		//scanf通过获取你输入的字符串进行移动雪花点。
		//scanf("%c",&input); //输入字符需要按回车键才能生效、
		if (input[0] == 'w')
			x--;//雪花点向上移动

		if (input[0] == 's')
			x++;//雪花点向下移动

		if (input[0] == 'a')
			y--;//向左

		if (input[0] == 'd')
			y++;//向右

		if (input[0] == ' ')//空格作为开火键
			isFired = 1;
		count++;
	}
	clear();
}