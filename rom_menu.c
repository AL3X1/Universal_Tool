/*
 *
 * ROM Menu
 * Written by 4L3X
 *
 */
#ifndef UNIVERSAL_TOOL_ROM_MENU_H
#define UNIVERSAL_TOOL_ROM_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "advanced_menu.c"

int romMenu(void)
{

  //  char    i;
    int     user_key;
    system("@cls||clear");

    // Printing ROM Menu [srsly?o.O]
    printf("=======================================\n");
    printf("   ROM Menu                       |\n");
    printf("=======================================\n");
    printf("| [1] Create workspace            |\n");
    printf("| [2] Extract ROM.zip             |\n");
    printf("| [3] Extract boot.img            |\n");
    printf("| [4] Repack boot.img             |\n");
    printf("| [5] Extract system.img          |\n");
    printf("| [6] Extract system.new.dat      |\n");
    printf("| [7] Delete workspace            |\n");
    printf("| [8] Install SuperSU(root)       |\n");
    printf("| [9] Install apktool             |\n");
    printf("| [10] Enter to advanced ROM menu |\n");
    printf("| [11] Information about menu     |\n");
    printf("=======================================\n");
    printf("[0] Exit\n");
    printf("\nWhat you want?: ");

    scanf("%d", &user_key);

    switch(user_key)
    {
        // Info
        case 11:
            getchar();
            printf("This is information about ROM Menu.\n");
            printf("1. For working with ROM's you must create personal workspace. Press [1] to do it.\n");
            printf("2. If you need extract .zip with you ROM, place him to 'workspace' folder, then press [2].\n");
            printf("3. If you need extract boot.img, press [3].\n");
            printf("4. For repacking boot.img press [4]\n");
            printf("5. When you want unpack some images (for example system.img), use this feature - [5]\n");
            printf("6. For unpacking system.new.dat, press [6]. // Repack feature in progress...\n");
            printf("7. If you tired of your workspace, you can delete it. Just press [7]\n");
            printf("8. Also you can install SuperSU in your ROM. Press [8] to do it.\n");
            printf("10. I think it doesn't need to explain... And next items too.\n");
            getchar();
            return romMenu();
            break;

        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;

        // Create working directory
        case 1:
        {
            system("cd C:\\Universal_Tool\\ && mkdir workspace");
            getchar();
            printf("Done. Replace your ROMZIP in on 'workspace' folder\n");
            getchar();
            break;
        }

        // Unzipping ROM.zip
        case 2:
        {
            system("cd workspace && 7z x *.zip && cd ..");
            printf("\n\tROM is unzipped\n");
            getchar();
            break;
        }

        // Unpacking boot.img
        case 3:
        {
            system("copy C:\\Universal_Tool\\insides\\boot\\AndImgTool.exe C:\\Universal_Tool\\workspace");
            system("cd C:\\Universal_Tool\\workspace\\ && AndImgTool.exe boot.img extracted_boot -i");
            getchar();
            printf("boot.img ready. Press 'Enter'to continue.\n");
            getchar();
            break;
        }

        // Repacking boot.img
        case 4:
        {
            system("cd C:\\Universal_Tool\\workspace\\ && AndImgTool extracted_boot new_boot.img -i");
            getchar();
            printf("Done! Press 'Enter' to continue.\n");
            getchar();
            break;
        }

        // Extracting system.img
        case 5:
        {
            system("copy C:\\Universal_Tool\\insides\\rom\\ImgExtractor.exe C:\\Universal_Tool\\workspace");
            system("cd C:\\Universal_Tool\\workspace && ImgExtractor.exe system.img extracted_system_img -i");
            getchar();
            printf("Done! Press 'Enter' to continue.\n");
            getchar();
            break;
        }

        // Extracting system.new.dat
        case 6:
        {
            system("copy C:\\Universal_Tool\\insides\\rom\\ImgExtractor.exe C:\\Universal_Tool\\workspace");
            system("copy C:\\Universal_Tool\\insides\\rom\\sdat2img\\sdat2img.py C:\\Universal_Tool\\workspace");
            system("cd C:\\Universal_Tool\\workspace && sdat2img.py system.transfer.list system.new.dat system.img");
            getchar();
            printf("Press 'Enter' to continue.\n");
            getchar();
            break;
        }

        // Removing workspace folder
        case 7:
            system("cd C:\\Universal_Tool\\ && rmdir /s workspace");
            break;

        // Installing SuperSU
        case 8:
        {
            getchar();
            system("copy C:\\Universal_Tool\\insides\\rom\\supersu\\SuperSU.apk C:\\Universal_Tool\\workspace\\system\\priv-app\\SuperSU");
            printf("Done\n");
            getchar();
            break;
        }

        // Installing apktool
        case 9:
            getchar();
            printf("Open Universal_Tool/insides/apktool and copy this files in C:/Windows folder. [Press Enter]\n");
            getchar();
            break;

        // Enter to advanced menu
        case 10:
           advancedMenu();
            break;

        default:
            printf("Make a choice!\n");
    }
    return romMenu();
}
#endif //UNIVERSAL_TOOL_ROM_MENU_H
