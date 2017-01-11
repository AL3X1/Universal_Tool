/*
 *
 * Porting menu
 * Written by 4L3X
 *
 */

#ifndef UNIVERSAL_TOOL_PORT_MENU_H
#define UNIVERSAL_TOOL_PORT_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "advanced_menu.c"

int portMenu(void)
{
    char    yes = 'y',
            answer;
    int     user_key;
    system("@cls||clear");

    printf("=======================================\n");
    printf("   Porting Menu                   |\n");
    printf("EXPEREMENTAL FEATURE! ONLY FOR DEVELOPERS!\n");
    printf("=======================================\n");
    printf("| [1] Make workspace for porting  |\n");
    printf("| [2] Port CM-based ROM           |\n");
    printf("=======================================\n");
    // In progress printf("\t\t[3] Port MiUI ROM\n");
    printf("\n[0] Exit\n");
    printf("\nWhat you want?: ");

    scanf("%d", &user_key);

    switch (user_key)
    {
        // Exit
        case 0:
            printf("Goodbye! :P");
            return 0;

        // Making workspace
        case 1:
        {
            printf("Creating workspace\n");

            printf("Creating base folder\n");
            system("cd C:\\Universal_Tool\\ && mkdir base");

            printf("Creating port folder\n");
            system("cd C:\\Universal_Tool\\ && mkdir port");

            printf("Done\n");
            return portMenu();
            break;
        }

        // Porting CyanogenMod-based ROM
        case 2:
        {
            getchar();
            printf("Throw your .zip archive with stock ROM in 'base' folder and ROM, which you want porting to 'port' folder, then press 'Enter'.\n");
            getchar();

            // Unpacking stock ROM
            printf("Unpacking stock ROM...\n");
            system("cd C:\\Universal_Tool\\base\\ && 7z x *.zip");
            printf("Unpacking stock ROM: Done\n");

            //Unpacking port ROM
            printf("Unpacking port ROM...\n");
            system("cd C:\\Universal_Tool\\port\\ && 7z x *.zip");
            printf("Unpacking port ROM: Done\n");

            // Decompiling base framework-res
            printf("Decompiling base framework-res.apk\n");
            system("cd C:\\Universal_Tool\\base\\system\\framework\\ && copy framework-res.apk C:\\Universal_Tool\\Decompiled_Files\\ && cd C:\\Universal_Tool\\Decompiled_Files\\ && rename framework-res.apk framework-base.apk && apktool d framework-base.apk");

            // Copying power_profile.xml and storage_list.xml to workspace folder
            printf("Copying storage_list.xml to workspace folder\n");
            system("cd C:\\Universal_Tool\\Decompiled_Files\\framework-base\\res\\xml && copy storage_list.xml C:\\Universal_Tool\\workspace");

            // Decompiling port framework-res
            printf("Decompiling port framework-res.apk\n");
            system("cd C:\\Universal_Tool\\port\\system\\framework\\ && copy framework-res.apk C:\\Universal_Tool\\Decompiled_Files\\");
            system("cd C:\\Universal_Tool\\Decompiled_Files\\ && rename framework-res.apk framework-port.apk && apktool d framework-port.apk");

            // Copying power_profile.xml and storage_list.xml to framework-port.apk
            printf("Copying storage_list.xml in framework-port.apk\n");
            system("cd C:\\Universal_Tool\\workspace\\ && copy storage_list.xml C:\\Universal_Tool\\Decompiled_Files\\framework-port\\res\\xml\\");

            // Building port framework-apk
            printf("Building port framework-res.apk\n");
            system("cd C:\\Universal_Tool\\Decompiled_Files\\ && apktool b framework-port");

            // Copying port framework-res.apk to "port" folder
            printf("Copying port framework-res.apk to 'port' folder\n");
            system("cd C:\\Universal_Tool\\Decompiled_Files\\framework-port\\dist\\ && rename framework-port.apk framework-res.apk && copy framework-res.apk C:\\Universal_Tool\\port\\system\\framework\\");

            // Deleting system folders from 'base'
            printf("Deleting app, fonts, framework, media, priv-app folders from 'base'\n");
            system("cd C:\\Universal_Tool\\base\\system && rmdir /s app fonts framework media priv-app");

            // Copying system folders from 'port'
            printf("Copying app, fonts, framework, media, priv-app folders from 'port' to 'base'\n");
            system("cd C:\\Universal_Tool\\port\\system && xcopy app\\* C:\\Universal_Tool\\base\\system\\app\\ /e /i && xcopy fonts\\* C:\\Universal_Tool\\base\\system\\fonts\\ /e /i "
                           "&& xcopy framework\\* C:\\Universal_Tool\\base\\system\\framework\\ /e /i"
                           " && xcopy media\\* C:\\Universal_Tool\\base\\system\\media\\ /e /i"
                           "&& xcopy priv-app\\* C:\\Universal_Tool\\base\\system\\priv-app\\ /e /i");

            // Unpacking boot.img
            printf("Unpacking boot.img\n");
            system("copy C:\\Universal_Tool\\insides\\boot\\AndImgTool.exe C:\\Universal_Tool\\base");
            system("cd C:\\Universal_Tool\\base\\ && AndImgTool.exe boot.img extracted_boot -i");
            printf("\nboot.img ready(in folder Universal_Tool/base/. When you finish work with ramdisk, press enter.\n");
            getchar();

            // Opening build.prop (if user have a wish)
            printf("Do you want open build.prop and edit some str-r-rings?[Y/N]: ");
            scanf("%c", &answer);
                if (answer == yes)
                    system("start notepad++ C:\\Universal_Tool\\base\\system\\build.prop");
                else
                {
                    printf("Okay, let's continue?[Enter]");
                        getchar();
                }

            // Repacking boot.img
            system("cd C:\\Universal_Tool\\workspace\\ && AndImgTool extracted_boot new_boot.img -i");
            getchar();
            printf("Done! Press 'Enter' to continue.\n");

            // Deleting boot folder and base ROM.zip
            printf("Deleting some trash :P\n");
            system("cd C:\\Universal_Tool\\base\\ && del AndImgTool.exe extracted_boot *.zip");

            // Repacking portrom.zip
            printf("Finally, repacking portrom.zip\n");
            system("cd C:\\Universal_Tool\\base\\ && 7z a portrom.zip *");

            printf("Done!\n");
            getchar();
            return portMenu();
            break;
        }
        default:
            printf("Make your choice\n");
            return portMenu();
    }
    return 0;
}

#endif // UNIVERSAL_TOOL_PORT_MENU_H