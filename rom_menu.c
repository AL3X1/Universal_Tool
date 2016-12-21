/*
 *
 * ROM Menu
 * Written by 4L3X
 *
 */
#ifndef UNIVERSALTOOL_ROM_MENU_H
#define UNIVERSALTOOL_ROM_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "advanced_menu.c"

// Clearing screen function
void clrscr()
{
    system("@cls||clear");
}

int romMenu()
{
    int     value;
    clrscr();

    // Printing ROM Menu [srsly?o.O]
    printf("=======================================\n");
    printf("\tROM Menu\n");
    printf("=======================================\n");
    printf("\t[1] Create workspace\n");
    printf("\t[2] Extract ROM.zip\n");
    printf("\t[3] Extract boot.img\n");
    printf("\t[4] Repack boot.img\n");
    printf("\t[5] Extract system.img\n");
    printf("\t[6] Extract system.new.dat\n");
    printf("\t[7] Delete workspace\n");
    printf("\t[8] Install SuperSU(root)\n");
    printf("\t[10] Enter to advanced ROM menu\n");
    printf("\t[0] Exit\n");
    printf("\tWhat you want?: ");

    scanf("%d", &value);

    switch(value)
    {
        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;
        // Create working directory
        case 1:
        {
            printf("\tDone\n");
                getchar();

                system("mkdir workspace && cd workspace ");

            printf("\n\t[!]Throw your ROMZIP in on workspace folder\n");

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

                system("cp ~/Universal_Tool/insides/boot/* ~/Universal_Tool/workspace/");

            printf("Press enter to continue\n");

                getchar();

            printf("\tUnpacking boot.img\n");

                system("cd ~/Universal_Tool/workspace/ && ./unpackbootimg -i boot.img");

            printf("\tMaking 'ramdisk' directory\n");

                system("cd ~/Universal_Tool/workspace/ && mkdir ramdisk");

            printf("\tReplacing boot.img-ramdisk.gz to 'ramdisk'\n");

                system("cd ~/Universal_Tool/workspace/ && mv boot.img-ramdisk.gz ramdisk");

            printf("Unpacking ramdisk\n");

                system("cd ~/Universal_Tool/workspace/ramdisk && gzip -dc boot.img-ramdisk.gz | cpio -i");

            printf("\n\tboot.img and ramdisk ready\n");

                getchar();
            break;
        }
        // Repacking boot.img
        case 4:
        {
            printf("\tRepacking ramdisk\n");

                system("./mkbootfs ./ramdisk | gzip > boot.img-ramdisk.gz");

            printf("\tRepacking boot.img\n");

                system("./mkbootimg --cmdline 'no_console_suspend=1 console=null' --kernel boot.img-kernel --ramdisk boot.img-ramdisk.gz -o boot-new.img");

            printf("\tboot-new.img ready!\n");

                getchar();

                system("cd ~/Universal_Tool/workspace/");
            break;
        }
        // Mounting system.img to editing
        case 5:
        {
            printf("\t\nPut your system.img in ROM folder.\n");

                getchar();

            printf("\t\nI'm working! Please wait!\n");

                system("cd ~/Universal_Tool/workspace");

                system("cp ~/Universal_Tool/workspace/system.img ~/Universal_Tool/");

                system("mkdir extractedsystem && sudo mount -t ext4 -o loop system.img extractedsystem");

            printf("\tDone. .img file extracted to Universal_Tool/extractedsystem/\n");

                getchar();
            break;
        }
        // Unpacking system.new.dat
        case 6:
        {
                system("cd ~/Universal_Tool/insides/rom/ && cp sdat2img/* ~/Universal_Tool/workspace/ ");

            printf("Press any key to continue");

                getchar();

                system("cd ~/Universal_Tool/workspace/ && ./sdat2img.py system.transfer.list system.new.dat system.img");

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

                system("cp ~/Universal_Tool/insides/rom/supersu ~/Universal_Tool/workspace/system/priv-app");

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
#endif //UNIVERSALTOOL_ROM_MENU_H
