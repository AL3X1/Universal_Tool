/*
 *
 * APK Menu
 * Written by 4L3X
 *
 */
#ifndef UNIVERSAL_TOOL_APK_MENU_H
#define UNIVERSAL_TOOL_APK_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "rom_menu.c"


int apkMenu()
{
    int     user_key;
    system("@cls||clear");

    // Printing APK Menu
    printf("=======================================\n");
    printf("   APK Menu                        |\n");
    printf("=======================================\n");
    printf("| [1] Create workspace for APK     |\n");
    printf("| [2] Decompile .apk               |\n");
    printf("| [3] Build .apk                   |\n");
    printf("| [4] Deodex .apk                  |\n");
    printf("| [11] Information                 |\n");
    printf("=======================================\n");
    printf("[0] Exit\n");
    printf("\nWhat you want?: ");

    scanf("%d", &user_key);

    switch (user_key)
    {
        // Info
        case 11:
        {
            getchar();
            printf("[1] Create workspace folders [Decompiled_Files, Deodexed_Files] to work with apktool.\n");
            printf("[2] Install apktool, IMPORTANT!\n");
            printf("[3] Decompiling .apk from executable to source code.\n");
            printf("[4] Build .apk from source code to executable (.apk)\n");
            printf("[5] Deodex .apk - if you have .odex file with your .apk, you must replace it to 'Deodexed_Files' folder to deodexing\n");
            getchar();
            return apkMenu();
            break;
        }

        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;
            break;

        // Creating Decompiled_Files folder
        case 1:
            printf("Creating workspace.\n");
            system("cd C:\\Universal_Tool\\ && mkdir Decompiled_Files Deodexed_Files");
            getchar();

            printf("Done! [Press Enter]\n");
            getchar();
            apkMenu();
            break;

        // Decompiling .apk
        case 2:
        {
            char param[128];
            char apkd_name[32]; // in apkd - 'd' mean 'decompile';

            printf("Enter name of your .apk, to decompile it: ");
            scanf("%s", apkd_name);

            sprintf(param, "cd C:\\Universal_Tool\\Decompiled_Files\\ && apktool d %s", apkd_name);
            system(param);

            apkMenu();
            break;
        }

        // Building .apk
        case 4:
        {
            char param[128];
            char apkb_name[32]; // and in apkb - 'b' mean 'build';

            printf("Enter name of your decompiled apk folder, to build it: ");
            scanf("%s", apkb_name);

            sprintf(param, "cd C:\\Universal_Tool\\Decompiled_Files\\ && apktool b %s", apkb_name); // .apk-build in dist/ folder
            system(param);

            printf("Done. Take your .apk in decompiled_app/dist/ folder.\n");
            apkMenu();
            break;
        }

        // Deodexing .apk
        case 5:
        {
            char param[128];
            char apkdex_name[32]; // apkdex - mean apk deodex;

            printf("Enter name of your .apk, to deodex it: ");
            scanf("%s", apkdex_name);

            sprintf(param, "cd C:\\Universal_Tool\\Deodexed_Files\\ && java -jar baksmali.jar deodex %s", apkdex_name);
            system(param);

            apkMenu();
            break;
        }

        default:
            printf("Make your choice!\n");
}

    return 0;
}
#endif //UNIVERSAL_TOOL_APK_MENU_H
