/*************************************************************************/
/**
 *****************************************************************************
 * @file   sl.c
 * @brief  sl
 * @author Sweet
 * @date   2015
 *****************************************************************************
 *****************************************************************************/

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

/*****************************************************************************
 *                                sl
 *****************************************************************************/
/**
 * An animation for sl
 
 
 
 
 # ######  # #    ###   #####   #########  # #    ####   ####  ##### #####
 ##    ##  ##    ##   #     #   ##      #  ###    ##   # ## #   ##   ##
 ##    ##  ##    ##  ##     ##  ##         ## #   ##     ##       ###
 #######   ########  ##     ##  #######    ##  #  ##     ##       ###
 ##        ##    ##  ##     ##  ##         ##   # ##     ##      ## ##
 ##        ##    ##   #    ##   ##      #  ##    ###   # ## #   ##   ##
 ####      # #    # #   #####   ######### # ##    ####   ####  ##### #####
 
 
 
 
 *
 *****************************************************************************/
PUBLIC void sl()
{
    int delay_time = 1500;
    
    
    
    
    printf("                                                                        ___\n");
    printf("                                                                   _,-' ______\n");
    printf("                                                                  .'  .-'  ____7\n");
    printf("                                                                /   /   ___7\n");
    printf("                                                             __ |   /  ___7\n");
    printf("                                                           >(' )\ | ___7\n");
    printf("                                                             \\/     \_______\n");
    printf("                                                             '        _======>\n");
    printf("                                                             `'----\\` \n");
    printf("                                                                    \\'. \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    
    milli_delay(delay_time+10000);
    clear();
    
    printf("                                              ___\n");
    printf("                                         _,-' ______\n");
    printf("                                        .'  .-'  ____7\n");
    printf("                                      /   /   ___7\n");
    printf("                                   __ |   /  ___7                          ___\n");
    printf("                                > (' )\ | ___7                       _,-' ______\n");
    printf("                                    \\/     \_______                  .'  .-'  ____7\n");
    printf("                                   '        _======>              /   /   ___7\n");
    printf("                                   `'----\\`                   __ |   /  ___7\n");
    printf("                                          \\                 >(' )\ | ___7\n");
    printf("                                                                \\/     \_______\n");
    printf("                                                                '        _======>    \n");
    printf("                                                               `'----\\`\n");
    printf("                                                                      \\             \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    printf("                                                                                     \n");
    
    milli_delay(delay_time+10000);
    clear();
    
    
    printf("             ___\n");
    printf("        _,-' ______\n");
    printf("       .'  .-'  ____7\n");
    printf("     /   /   ___7\n");
    printf("  __ |   /  ___7                          ___\n");
    printf(">(' )\ | ___7                       _,-' ______\n");
    printf("  \\/     \_______                  .'  .-'  ____7\n");
    printf("  '        _======>              /   /   ___7\n");
    printf("  `'----\\`                   __ |   /  ___7                         ___\n");
    printf("         \\                 >(' )\ | ___7                       _,-' ______\n");
    printf("                              \\/     \_______                  .'  .-'  ____7\n");
    printf("                              '        _======>              /   /   ___7\n");
    printf("                              `'----\\`                   __ |   /  ___7\n");
    printf("                                     \\                 >(' )\ | ___7\n");
    printf("                                                           \\/     \_______\n");
    printf("                                                           '        _======>\n");
    printf("                                                           `'----\\`\n");
    printf("                                                                  \\.\n");
    
    milli_delay(delay_time+10000);
    clear();
    
    
    printf("             ___\n");
    printf("        _,-' ______\n");
    printf("       .'  .-'  ____7\n");
    printf("   /   ___7\n");
    printf("   /  ___7                          ___\n");
    printf(" ___7                       _,-' ______\n");
    printf("    \_______                  .'  .-'  ____7\n");
    printf("     _======>              /   /   ___7\n");
    printf("--\\`                   __ |   /  ___7                         ___\n");
    printf("   \\                 >(' )\ | ___7                       _,-' ______\n");
    printf("                              \\/     \_______                  .'  .-'  ____7\n");
    printf("                              '        _======>              /   /   ___7\n");
    printf("                              `'----\\`                   __ |   /  ___7\n");
    printf("                                     \\                 >(' )\ | ___7\n");
    printf("                                                           \\/     \_______\n");
    printf("                                                           '        _======>\n");
    printf("                                                           `'----\\`\n");
    printf("                                                                  \\.\n");
    
    milli_delay(delay_time+10000);
    clear();
    
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("              ___\n");
    printf("        _,-' ______\n");
    printf("        .'  .-'  ____7\n");
    printf("     /   /   ___7\n");
    printf("  __ |   /  ___7                         ___\n");
    printf(">(' )\ | ___7                       _,-' ______\n");
    printf("   \\/     \_______                  .'  .-'  ____7\n");
    printf("   '        _======>              /   /   ___7\n");
    printf("   `'----\\`                   __ |   /  ___7\n");
    printf("          \\                 >(' )\ | ___7\n");
    printf("                                \\/     \_______\n");
    printf("                                '        _======>\n");
    printf("                                `'----\\`\n");
    printf("                                       \\.\n");
    
    milli_delay(delay_time+10000);
    clear();
    
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("                                                                               \n");
    printf("             ___\n");
    printf("        _,-' ______\n");
    printf("        .'  .-'  ____7\n");
    printf("     /   /   ___7\n");
    printf("  __ |   /  ___7\n");
    printf(">(' )\ | ___7\n");
    printf("   \\/     \_______\n");
    printf("   '        _======>\n");
    printf("   `'----\\`\n");
    printf("          \\.\n");
    
    milli_delay(delay_time+10000);
    clear();
    
    
    
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                  @@@@@@@@@@\n");
    printf("                                                                  @@      \n");
    printf("                                                                  @@  # ### \n");
    printf("                                                                  @@   ##   \n");
    printf("                                                                  @@   ##   \n");
    printf("                                                                  @@   #####\n");
    printf("                                                                  @@   ##   \n");
    printf("                                                                  @@   ##   \n");
    printf("                                                                  @@  ####  \n");
    printf("                                                                  @@        \n");
    printf("                                                                  @@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    
    
    
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                @@@@@@@@@@@ \n");
    printf("                                                                @@          \n");
    printf("                                                                @@  # ######\n");
    printf("                                                                @@   ##    #\n");
    printf("                                                                @@   ##    #\n");
    printf("                                                                @@   #######\n");
    printf("                                                                @@   ##     \n");
    printf("                                                                @@   ##     \n");
    printf("                                                                @@  ####    \n");
    printf("                                                                @@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                            @@@@@@@@@@@@@@@@\n");
    printf("                                                            @@              \n");
    printf("                                                            @@  # ######  # \n");
    printf("                                                            @@   ##    ##  #\n");
    printf("                                                            @@   ##    ##  #\n");
    printf("                                                            @@   #######   #\n");
    printf("                                                            @@   ##        #\n");
    printf("                                                            @@   ##        #\n");
    printf("                                                            @@  ####      # \n");
    printf("                                                            @@             \n");
    printf("                                                            @@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                      @@@@@@@@@@@@@@@@@@@@@ \n");
    printf("                                                      @@                    \n");
    printf("                                                      @@  ` #####:  # #     \n");
    printf("                                                      @@   ##:  :##  ##     \n");
    printf("                                                      @@   ##:  :##  ##     \n");
    printf("                                                      @@   ######`   ###### \n");
    printf("                                                      @@   ##        ##     \n");
    printf("                                                      @@   ##        ##     \n");
    printf("                                                      @@  :###      # #     \n");
    printf("                                                      @@                    \n");
    printf("                                                      @@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                                                 @@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("                                                 @@                         \n");
    printf("                                                 @@  ` #####:  # #    ###   \n");
    printf("                                                 @@   ##:  :##  ##    ##   #\n");
    printf("                                                 @@   ##:  :##  ##    ##  ##\n");
    printf("                                                 @@   ######`   ########  ##\n");
    printf("                                                 @@   ##        ##    ##  ##\n");
    printf("                                                 @@   ##        ##    ##   #\n");
    printf("                                                 @@  :###      # #    # #  #\n");
    printf("                                                 @@                         \n");
    printf("                                                 @@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("                                            @@                               \n");
    printf("                                            @@  ` #####:  # #    ###   ##### \n");
    printf("                                            @@   ##:  :##  ##    ##   #     #\n");
    printf("                                            @@   ##:  :##  ##    ##  ##     #\n");
    printf("                                            @@   ######`   ########  ##     #\n");
    printf("                                            @@   ##        ##    ##  ##     #\n");
    printf("                                            @@   ##        ##    ##   #    ##\n");
    printf("                                            @@  :###      # #    # #   ##### \n");
    printf("                                            @@                               \n");
    printf("                                            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("                                     @@                                      \n");
    printf("                                     @@  ` #####:  # #    ###   #####   #####\n");
    printf("                                     @@   ##:  :##  ##    ##   #     #   ##\n");
    printf("                                     @@   ##:  :##  ##    ##  ##     ##  ##\n");
    printf("                                     @@   ######`   ########  ##     ##  ####\n");
    printf("                                     @@   ##        ##    ##  ##     ##  ##\n");
    printf("                                     @@   ##        ##    ##   #    ##   ##\n");
    printf("                                     @@  :###      # #    # #   #####   #####\n");
    printf("                                     @@                               \n");
    printf("                                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                               @@                                           \n");
    printf("                               @@  # ######  # #    ###   #####   ######### \n");
    printf("                               @@   ##    ##  ##    ##   #     #   ##      #\n");
    printf("                               @@   ##    ##  ##    ##  ##     ##  ##       \n");
    printf("                               @@   #######   ########  ##     ##  #######  \n");
    printf("                               @@   ##        ##    ##  ##     ##  ##       \n");
    printf("                               @@   ##        ##    ##   #    ##   ##      #\n");
    printf("                               @@  ####      # #    # #   #####   ######### \n");
    printf("                               @@                                           \n");
    printf("                               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    printf("                        @@                                                  \n");
    printf("                        @@  # ######  # #    ###   #####   #########  # #    \n");
    printf("                        @@   ##    ##  ##    ##   #     #   ##      #  ###  \n");
    printf("                        @@   ##    ##  ##    ##  ##     ##  ##         ## #  \n");
    printf("                        @@   #######   ########  ##     ##  #######    ##  #\n");
    printf("                        @@   ##        ##    ##  ##     ##  ##         ##    \n");
    printf("                        @@   ##        ##    ##   #    ##   ##      #  ##    \n");
    printf("                        @@  ####      # #    # #   #####   ######### # ##    \n");
    printf("                        @@                                                  \n");
    printf("                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                  @@                                                         \n");
    printf("                  @@  # ######  # #    ###   #####   #########  # #    ####  \n");
    printf("                  @@   ##    ##  ##    ##   #     #   ##      #  ###    ##   \n");
    printf("                  @@   ##    ##  ##    ##  ##     ##  ##         ## #   ##   \n");
    printf("                  @@   #######   ########  ##     ##  #######    ##  #  ##   \n");
    printf("                  @@   ##        ##    ##  ##     ##  ##         ##   # ##   \n");
    printf("                  @@   ##        ##    ##   #    ##   ##      #  ##    ###   \n");
    printf("                  @@  ####      # #    # #   #####   ######### # ##    ####  \n");
    printf("                  @@                                                         \n");
    printf("                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("              @@                                                             \n");
    printf("              @@  # ######  # #    ###   #####   #########  # #    ####   ###\n");
    printf("              @@   ##    ##  ##    ##   #     #   ##      #  ###    ##   # ##\n");
    printf("              @@   ##    ##  ##    ##  ##     ##  ##         ## #   ##     ##\n");
    printf("              @@   #######   ########  ##     ##  #######    ##  #  ##     ##\n");
    printf("              @@   ##        ##    ##  ##     ##  ##         ##   # ##     ##\n");
    printf("              @@   ##        ##    ##   #    ##   ##      #  ##    ###   # ##\n");
    printf("              @@  ####      # #    # #   #####   ######### # ##    ####   ###\n");
    printf("              @@                                                             \n");
    printf("              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("          @@                                                                 \n");
    printf("          @@  # ######  # #    ###   #####   #########  # #    ####   ####  #\n");
    printf("          @@   ##    ##  ##    ##   #     #   ##      #  ###    ##   # ## #  \n");
    printf("          @@   ##    ##  ##    ##  ##     ##  ##         ## #   ##     ##    \n");
    printf("          @@   #######   ########  ##     ##  #######    ##  #  ##     ##    \n");
    printf("          @@   ##        ##    ##  ##     ##  ##         ##   # ##     ##    \n");
    printf("          @@   ##        ##    ##   #    ##   ##      #  ##    ###   # ## #  \n");
    printf("          @@  ####      # #    # #   #####   ######### # ##    ####   ####  #\n");
    printf("          @@                                                                 \n");
    printf("          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("      @@                                                                     \n");
    printf("      @@  # ######  # #    ###   #####   #########  # #    ####   ####  #####\n");
    printf("      @@   ##    ##  ##    ##   #     #   ##      #  ###    ##   # ## #   ## \n");
    printf("      @@   ##    ##  ##    ##  ##     ##  ##         ## #   ##     ##       #\n");
    printf("      @@   #######   ########  ##     ##  #######    ##  #  ##     ##       #\n");
    printf("      @@   ##        ##    ##  ##     ##  ##         ##   # ##     ##      ##\n");
    printf("      @@   ##        ##    ##   #    ##   ##      #  ##    ###   # ## #   ## \n");
    printf("      @@  ####      # #    # #   #####   ######### # ##    ####   ####  #####\n");
    printf("      @@                                                                     \n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time);
    clear();
    
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("                                                                             \n");
    printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("  @@                                                                       @@\n");
    printf("  @@ # ######  # #    ###   #####   ####### # #    ####  #### #  #### #### @@\n");
    printf("  @@ ##    ##  ##    ##   #     #    ##       ###    ##  # ## #   ##   ##  @@\n");
    printf("  @@ ##    ##  ##    ##  ##     ##   ##       ## #   ##    ##       ###    @@\n");
    printf("  @@ #######   ########  ##     ##   #####    ##  #  ##    ##       ###    @@\n");
    printf("  @@ ##        ##    ##  ##     ##   ##       ##   # ##    ##      ## ##   @@\n");
    printf("  @@ ##        ##    ##   #    ##    ##       ##    ###  # ## #   ##   ##  @@\n");
    printf("  @@ ####      # #    # #   #####   ####### # ##    ####  ####  #### ##### @@\n");
    printf("  @@                                                                       @@\n");
    printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    milli_delay(delay_time + 30000);
    clear();
    
    
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("      Created by :                              .---.        .-----------\n");
    printf("      Xie Kang                     /     \  __  /    ------\n");
    printf("      Xie Shangru                 / /     \(  )/    -----\n");
    printf("      Liu Lanxin                 //////   ' \/ `   ---\n");
    printf("      Zhou Xian                 //// / // :    : ---\n");
    printf("                               // /   /  /`    '--\n");
    printf("                              //          //..\\\n");
    printf("                            =============UU====UU====\n");
    printf("                                         '//||\\`\n");
    printf("                                           ''``\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    milli_delay(delay_time+60000);
    clear();
}

