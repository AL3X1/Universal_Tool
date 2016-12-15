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
 *  Thank's:
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

void logo()
{

    printf("\t _   _       _                          _ _____           _\n");
    printf("\t| | | |_ __ (___   _____ _ __ ___  __ _| |_   ____   ___ | |\n");
    printf("\t| | | | '_ || | | / / _ | '__/ __|/ _` | | | |/ _ | / _ || |\n");
    printf("\t| |_| | | | | || V |  __| |  |__ | (_| | | | | (_) | (_) | |\n");
    printf("\t |___/|_| |_|_| |_/ |___|_|  |___/|__,_|_| |_||___/ |___/|_|\n");

}

int main()
{

    int     input;
    clrscr();
    logo();

    printf("\n==============================\n");
    printf("\t\nUNIVERSAL TOOL is STARTED\n");
    printf("\n==============================\n");
    printf("\n\t[1] Enter to ROM Menu\n");
    printf("\t[2] Enter to APK Menu\n");
    printf("\t[3] ADB Devices\n");
    printf("\t[4] Fastboot Menu\n");
    printf("\t[5] Install ADB\n");
    printf("\t[6] Exit\n");
    printf("\tWhat you want?: ");

    // Waiting for user input
    scanf("%d", &input);

    // Menu accelerate
    switch(input)
    {
        case 1:
            // Calling romMenu function (from rom_menu.c)
            romMenu();
            break;
        case 2:
            // Calling apkMenu function (from apk_menu.c)
            apkMenu();
            break;
        case 3:
            // Execution adb service (for showing devices, connected to PC)
                system("adb devices");
            break;
        case 4:
            // Execution fastboot service (for connect device in fastboot mode to PC)
                system("fastboot");
            break;
        case 5:
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
        case 6:
            printf("Goodbye ;P\n");// [6] - it's Exit, return 0 to return accelerate to user
            return 0;
        break;
        default:
            printf("Make ur choice!\n");
    }

    getchar();
}