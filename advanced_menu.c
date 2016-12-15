/*
 *
 * Advanced menu
 * Written by 4L3X
 *
 */
#ifndef UNIVERSALTOOL_ADVANCED_MENU_H
#define UNIVERSALTOOL_ADVANCED_MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "rom_menu.c"
#include "debloat_menu.c"
#include <stdlib.h>

int advancedMenu()
{
    int     key;

    system("@cls||clear");
    // Printing Advanced Menu
    printf("=======================================\n");
    printf("\t Advanced Menu\n");
    printf("=======================================\n");
    printf("\t [1] Edit build.prop\n");
    printf("\t [2] Debloat Menu\n");
    printf("\t [3] Edit updater-script\n");
    printf("\t [0] Exit\n");

    scanf("%d", &key);

    switch (key)
    {
        // Exit
        case 0:
            printf("Goodbye ;P\n");
            return 0;
            break;
        // Edit build.prop
        case 1:
            system("gedit ~/UniversalTool/workspace/system/build.prop");
                getchar();
            break;
        // Enter in Debloat Menu (calling function from debloat_menu.c
        case 2:
            debloatMenu();
            break;
        // Edit updater-script
        case 3:
                system("gedit ~/UniversalTool/workspace/META-INF/com/google/android/updater-script");
        default:
            printf("Make a choice\n");
    }

    return 0;
}
#endif //UNIVERSALTOOL_ADVANCED_MENU_H