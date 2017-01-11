/*
 _   _       _                          _ _____           _
| | | |_ __ (___   _____ _ __ ___  __ _| |_   ____   ___ | |
| | | | '_ \| \ \ / / _ | '__/ __|/ _` | | | |/ _ \ / _ \| |
| |_| | | | | |\ V |  __| |  \__ | (_| | | | | (_) | (_) | |
 \___/|_| |_|_| \_/ \___|_|  |___/\__,_|_| |_|\___/ \___/|_|

 *  Tool Written by 4L3X (Bl4ck0verlord on xda, Grand_leMon on 4pda)
 *  I don't use bash, i love C and program written on Pure C Programming language (first, as i look :) )
 *
 *  Libs for install Tool: libncurses5, python (2.7 or newer), JDK (not need but desirable)
 *  Thanks to:
 *  iBotPeaches - for ApkTool
 *  JesusFreke - for smali/baksmali
 *  xpirt - for sdat2img
 *  osm0sis - for mkbootimg
 *  Willi Ye - for Kernel Adiutor
 *  Chainfire - for SuperSU
 *  Neko.cpp and lolmaxlik - for helping with some questions
 *  and...
 *  I am a modest man, but if you want, you can say 'thank you' to me too. :)
 */

#include <stdio.h>
#include <stdlib.h>
#include "rom_menu.c"
#include "apk_menu.c"
#include "port_menu.c"
#include "fastboot_menu.c"

void logo(void)
{
	printf("#     # #######         #     #          \n");
	printf("#     #    #            #  #  # # #    # \n");
	printf("#     #    #            #  #  # # ##   # \n");
	printf("#     #    #            #  #  # # # #  # \n");
	printf("#     #    #            #  #  # # #  # # \n");
	printf("#     #    #            #  #  # # #   ## \n");
	printf(" #####     #    #######  ## ##  # #    # \n");

}

int main(void)
{
    int     user_key;
    system("@cls||clear");
    logo();

    printf("============================================\n");
    printf(" Welcome to UNIVERSAL_TOOL                 |\n");
    printf("============================================\n");
    printf("| [1] Enter to ROM Menu                    |\n");
    printf("| [2] Enter to APK Menu                    |\n");
    printf("| [3] Enter to Porting menu(Experemental!) |\n");
    printf("| [4] Fastboot Menu                        |\n");
    printf("============================================\n");
    printf("\n[0] Exit\n");
    printf("\nWhat you want?: ");

    // Waiting for user input
    scanf("%d", &user_key);

    switch(user_key)
    {
        // Return accelerate to user
        case 0:
            printf("Goodbye ;P\n");
            return 0;
            break;

        // Calling romMenu function (from rom_menu.c)
        case 1:
            romMenu();
            break;

        // Calling apkMenu function (from apk_menu.c)
        case 2:
            apkMenu();
            break;

        // Calling portMenu function (from port_menu.c)
        case 3:
            portMenu();
            break;

        // Calling fastboot menu
        case 4:
            fastbootMenu();
            break;

        default:
            printf("Make your choice!\n");
    }
    getchar();
}
