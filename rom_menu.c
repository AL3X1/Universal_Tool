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
    printf("| [9] Information about menu      |\n");
    printf("| [10] Enter to advanced ROM menu |\n");
    printf("=======================================\n");
    printf("[0] Exit\n");
    printf("\nWhat you want?: ");

    scanf("%d", &user_key);

    switch(user_key)
    {
        // Info
        case 9:
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
            system("mkdir workspace && cd workspace ");
            printf("Done. Replace your ROMZIP in on 'workspace' folder\n");
            getchar();
            break;
        }

        // Unzipping ROM.zip
        case 2:
        {
            system("cd workspace && unzip *.zip && cd ..");
            printf("\n\tROM is unzipped\n");
            getchar();
            break;
        }

        // Unpacking boot.img
        case 3:
        {
            system("cd ~/*/workspace/ && mkdir boot");
            system("cp ~/*/insides/boot/* ~/*/workspace/boot");

            printf("\tUnpacking boot.img\n");
            system("cd ~/*/workspace/ && cp boot.img ~/*/workspace/boot");
            system("cd ~/*/workspace/boot && ./unpackbootimg -i boot.img");

            printf("\tMaking 'ramdisk' directory\n");
            system("cd ~/*/workspace/boot && mkdir ramdisk");

            printf("\tReplacing boot.img-ramdisk.gz to 'ramdisk'\n");
            system("cd ~/*/workspace/boot && mv boot.img-ramdisk.gz ramdisk");

            printf("Unpacking ramdisk\n");
            system("cd ~/*/workspace/boot/ramdisk && gzip -dc boot.img-ramdisk.gz | cpio -i");
            printf("\n\tboot.img and ramdisk ready\n");
            getchar();
            break;
        }

        // Repacking boot.img
        case 4:
        {
            printf("\tRepacking ramdisk\n");
            system("cd ~/*/workspace/boot/ && ./mkbootfs ./ramdisk | gzip > boot.img-ramdisk.gz");

            printf("\tRepacking boot.img\n");
            system("cd ~/*/workspace/boot/ && ./mkbootimg --cmdline 'no_console_suspend=1 console=null' --kernel boot.img-kernel --ramdisk boot.img-ramdisk.gz -o boot-new.img");

            printf("\tboot-new.img ready!\n");
            getchar();
            system("cd ~/*/workspace/");
            break;
        }

        // Mounting system.img for edit
        case 5:
        {
            printf("\t\nPut your system.img in ROM folder.\n");
            getchar();

            printf("\t\nI'm working! Please wait!\n");
            system("cd ~/*/workspace");
            system("cp ~/*/workspace/system.img ~/Universal_Tool/");
            system("mkdir extractedsystem && sudo mount -t ext4 -o loop system.img extractedsystem");

            printf("\tDone. .img file extracted to Universal_Tool/extractedsystem/\n");
            getchar();
            break;
        }

        // Unpacking system.new.dat
        case 6:
        {
            system("cd ~/*/insides/rom/ && cp sdat2img/* ~/Universal_Tool/workspace/ ");
            printf("Press any key to continue");

            getchar();

            system("cd ~/*/workspace/ && ./sdat2img.py system.transfer.list system.new.dat system.img");
            getchar();
            break;
        }

        // Removing workspace folder
        case 7:
            system("cd ~/Universal_Tool/ && rm -rf workspace && rm -rf extractedsystem");
            break;

        // Installing SuperSU
        case 8:
        {
            getchar();
            system("cp ~/*/insides/rom/supersu ~/*/workspace/system/priv-app");
            printf("\tDone\n");

            getchar();
            break;
        }

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
