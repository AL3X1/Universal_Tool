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
    printf("    ██╗   ██╗████████╗\n");
    printf("    ██║   ██║╚══██╔══╝\n");
    printf("    ██║   ██║   ██║   \n");
    printf("    ██║   ██║   ██║   \n");
    printf("    ╚██████╔╝   ██║   \n");
    printf("     ╚═════╝    ╚═╝   \n");

}

int main(void)
{
    int     user_key;
    system("@cls||clear");
    logo();

    printf("============================================\n");
    printf("  UNIVERSAL TOOL is STARTED                |\n");
    printf("============================================\n");
    printf("| [1] Enter to ROM Menu                    |\n");
    printf("| [2] Enter to APK Menu                    |\n");
    printf("| [3] Enter to Porting menu(Experemental!) |\n");
    printf("| [4] ADB Devices                          |\n");
    printf("| [5] Fastboot Menu                        |\n");
    printf("| [6] Install ADB and Fastboot tools       |\n");
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

        // Execution adb service (for showing devices, connected to PC)
        case 4:
            system("adb devices");
            return main();
            break;

        // Calling fastboot menu
        case 5:
            fastbootMenu();
            break;

        // Installing adb and fastboot-tools
        case 6:
        {
            // Getting android rules for adb
            system("sudo wget -O /etc/udev/rules.d/51-android.rules https://raw.githubusercontent.com/NicolasBernaerts/ubuntu-scripts/master/android/51-android.rules");

            // Appropriation read/write mode to 51-android.rules
            system("sudo chmod a+r /etc/udev/rules.d/51-android.rules");

            // Restarting udev service (for accepting android rules)
            system("sudo service udev restart");

            // Recieving adb and fastboot services
            system("sudo apt-get install android-tools-adb android-tools-fastboot");
            printf("\nInstalling was succesful, now connect your device and press on 'adb menu'\n");

            // Waiting to user input
            getchar();
            break;
        }

        default:
            printf("Make ur choice!\n");
    }
    getchar();
}
