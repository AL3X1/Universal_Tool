/*
 *
 * Advanced menu
 * Written by 4L3X
 *
 */
#ifndef UNIVERSAL_TOOL_ADVANCED_MENU_H
#define UNIVERSAL_TOOL_ADVANCED_MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "rom_menu.c"
#include "debloat_menu.c"
#include <stdlib.h>

int advancedMenu(void)
{
    int     user_key;
    system("@cls||clear");

    // Printing Advanced Menu
    printf("=======================================\n");
    printf("   Advanced Menu             |\n");
    printf("=======================================\n");
    printf("| [1] Edit build.prop        |\n");
    printf("| [2] Debloat Menu           |\n");
    printf("| [3] Edit updater-script    |\n");
    printf("| [4] Add Kernel Adiutor     |\n");
    printf("| [9] Information about menu |\n");
    printf("=======================================\n");
    printf("\n[0] Exit\n");
    printf("\nWhat you want?: ");

    scanf("%d", &user_key);

    switch (user_key)
    {
        // Info
        case 9:
            printf("1. Press [1] to edit build.prop file.\n");
            printf("2. Press [2] to enter to Debloat Menu.\n");
            printf("3. Press [3] to edit updater-script.\n");
            printf("4. Press [4] to add Kernel Adiutor in your ROM.\n");

        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;
            break;

        // Edit build.prop
        case 1:
            system("gedit ~/*/workspace/system/build.prop");
            getchar();
            break;

        // Enter in Debloat Menu (calling function from debloat_menu.c
        case 2:
            debloatMenu();
            break;

        // Edit updater-script
        case 3:
            system("gedit ~/*/workspace/META-INF/com/google/android/updater-script");
            break;

        //  Replacing Kernel Adiutor to system/priv-app
        case 4:
            system("cp ~/*/insides/rom/KernelAdiutor/* ~/*/workspace/system/priv-app");
            break;

        default:
            printf("Make a choice\n");
    }
    return 0;
}
#endif // UNIVERSAL_TOOL_ADVANCED_MENU_H
