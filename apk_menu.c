/*
 *
 * APK Menu
 * Written by 4L3X
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "rom_menu.c"

#ifndef UNIVERSALTOOL_APK_MENU_H
#define UNIVERSALTOOL_APK_MENU_H

int apkMenu()
{
    int     value;
    clrscr();

    // Printing APK Menu
    printf("=======================================\n");
    printf("\tAPK Menu\n");
    printf("=======================================\n");
    printf("\t [1] Install apktool\n");
    printf("\t [2] Decompile apk(using apktool)\n");
    printf("\t [3] Build apk(using apktool)\n");
    printf("\t [4] Deodex apk(using baksmali)\n");
    printf("\t [0] Exit\n");
    printf("\t What you want?: ");

    scanf("%d", &value);

    switch (value)
    {
        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;
            break;

        // Installing apktool
        case 1:
        {
            printf("\t\nInstalling apktool\n");

            system("sudo apt-get install lib32ncurses5 -y");
            system("cd ~/Universal_Tool/insides/apktool/");
            system("sudo cp apktool.jar /usr/local/bin && sudo cp apktool /usr/local/bin");
            system("cd /usr/local/bin/ && chmod a+x apktool");

            printf("\t\nApktool has been installed.\n"); //MUST BE TESTED
            getchar();

            apkMenu();
            break;
        }
        // Decompile apk
        case 2:
                getchar();
                system("cd ~/Universal_Tool/ && mkdir Decompiled_Files");
                printf("Throw your .apk in Decompiled_Files folder\n");
                getchar();
                system("cd ~/Universal_Tool/Decompiled_Files && apktool d *");
                getchar();
            printf("Done! Press 'Enter' to continue");
            break;
        // Building apk
        case 3:
                getchar();
                system("cd ~/Universal_Tool/Decompiled_Files && apktool b *");
            printf("Done! Your .apk is in Decompile_Files/yourapkfolder/dist.\n");
            break;
        // Look at comment higher#2 again...
        case 4:
        {   
                system("cd ~/Universal_Tool/ && mkdir Deodexed_Files");
                system("cd ~/Universal_Tool/insides/smali/ && java -jar baksmali.jar deodex ~/Universal_Tool/Deodexed_Files/* ");
                getchar();
            printf("Done! Your files in Deodexed_Files folder\n");
            return 0;
            break;
        }

        default:
            printf("Make your choice!\n");
}

    return 0;
}
#endif //UNIVERSALTOOL_APK_MENU_H
