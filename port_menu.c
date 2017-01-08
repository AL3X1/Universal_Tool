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
            system("cd ~/Universal_Tool-master/ && mkdir base");

            printf("Creating port folder\n");
            system("cd ~/Universal_Tool-master/ && mkdir port");

            printf("Done\n");
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
            system("cd ~/*/base/ && unzip *.zip");
            printf("Unpacking stock ROM: Done\n");

            //Unpacking port ROM
            printf("Unpacking port ROM...\n");
            system("cd ~/*/port/ && unzip *.zip");
            printf("Unpacking port ROM: Done\n");

            // Decompiling base framework-res
            printf("Decompiling base framework-res.apk\n");
            system("cd ~/*/base/system/framework/ && cp framework-res.apk ~/*/Decompiled_Files/ && cd ~/*/Decompiled_Files/ && mv framework-res.apk framework-base.apk && apktool d framework-base.apk");

            // Copying power_profile.xml and storage_list.xml to workspace folder
            printf("Copying power_profile.xml and storage_list.xml to workspace folder\n");
            system("cd ~/*/Decompiled_Files/framework-base/res/xml && cp power_profile.xml storage_list.xml ~/*/workspace");

            // Decompiling port framework-res
            printf("Decompiling port framework-res.apk\n");
            system("cd ~/*/port/system/framework/ && cp framework-res.apk ~/*/Decompiled_Files/ && cd ~/*/Decompiled_Files/ && mv framework-res.apk framework-port.apk && apktool d framework-port.apk");

            // Copying power_profile.xml and storage_list.xml to framework-port.apk
            printf("Copying power_profile.xml and storage_list.xml in framework-port.apk\n");
            system("cd ~/*/workspace/ && cp storage_list.xml power_profile.xml ~/*/Decompiled_Files/framework-port/res/xml/");

            // Building port framework-apk
            printf("Building port framework-res.apk\n");
            system("cd ~/*/Decompiled_Files/ && apktool b framework-port");

            // Copying port framework-res.apk to "port" folder
            printf("Copying port framework-res.apk to 'port' folder\n");
            system("cd ~/*/Decompiled_Files/ && mv framework-port.apk framework-res.apk && cp framework-res.apk ~/*/port/system/framework");

            // Deleting system folders from 'base'
            printf("Deleting app, fonts, framework, media, priv-app folders from 'base'\n");
            system("cd ~/*/base/system && rm -rf app font framework media priv-app");

            // Copying system folders from 'port'
            printf("Copying app, fonts, framework, media, priv-app folders from 'port' to 'base'\n");
            system("cd ~/*/port/system && cp -a app fonts framework media priv-app ~/*/base/system");

            // Unpacking boot.img
            printf("Unpacking boot.img\n");
            system("cd ~/*/base/ && mkdir boot");
            system("cp ~/*/insides/boot/* ~/*/base/boot");
            system("cp ~/*/base/boot.img ~/*/base/boot");
            system("cd ~/*/base/boot/ && ./unpackbootimg -i boot.img");
            system("cd ~/*/base/boot/ && mkdir ramdisk");
            system("cd ~/*/base/boot/ && mv boot.img-ramdisk.gz ramdisk");
            system("cd ~/*/base/boot/ramdisk && gzip -dc boot.img-ramdisk.gz | cpio -i");
            printf("\nboot.img and ramdisk ready(in folder ~/Universal_Tool/base/. When you finish work with ramdisk, press enter.\n");
            getchar();

            // Opening build.prop (if user have a wish)
            printf("Do you want open build.prop and edit some str-r-rings?[Y/N]: ");
            scanf("%c", &answer);
                if (answer == yes)
                    system("gedit ~/*/base/system/build.prop");
                else
                {
                    printf("Okay, let's continue?[Enter]");
                        getchar();
                }

            // Repacking boot.img
            printf("Repack boot.img\n");
            system("cd ~/*/base/boot/ && ./mkbootfs ./ramdisk | gzip > boot.img-ramdisk.gz");

            system("cd ~/*/base/boot/ && ./mkbootimg --cmdline 'no_console_suspend=1 console=null' --kernel boot.img-kernel --ramdisk boot.img-ramdisk.gz -o boot-new.img");
            printf("boot-new.img ready!\n");

            // Renaming boot-new.img to boot.img
            printf("Renaming boot-new.img to boot.img\n");
            system("cd ~/*/base/boot/ && mv boot-new.img ~/*/base/boot.img");

            // Deleting boot folder and base ROM.zip
            printf("Deleting some trash :P\n");
            system("cd ~/*/base/ && rm -rf boot *.zip");

            // Repacking portrom.zip
            printf("Finally, repacking portrom.zip\n");
            system("cd ~/*/base/ && zip -r portrom.zip *");

            printf("Done!\n");
            getchar();
            break;
        }
        default:
            printf("Make your choice\n");
            return portMenu();
    }
    return 0;
}

#endif // UNIVERSAL_TOOL_PORT_MENU_H