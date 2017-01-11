/*
 *
 * Debloat menu
 * Written by 4L3X
 *
 */

#ifndef UNIVERSAL_TOOL_DEBLOAT_MENU_H
#define UNIVERSAL_TOOL_DEBLOAT_MENU_H

#include <stdlib.h>
#include <stdio.h>
#include "advanced_menu.c"

int debloatMenu(void)
{
    int     user_key;
    system("@cls||clear");

    printf("=======================================\n");
    printf("   Debloat menu                   |\n");
    printf("=======================================\n");
    printf("| [1] App debloat                 |\n");
    printf("| [2] Priv-app debloat            |\n");
    printf("| [11] Information about Debloat  |\n");
    printf("=======================================\n");
    printf("[0] Exit\n");

    scanf("%d", &user_key);

    switch (user_key)
    {
        // Exit
        case 0:
        return 0;

        // Deleting apps from system/app
        case 1:
        {
            getchar();
            system("cd C:\\Universal_Tool\\workspace\\system\\app && del BasicDreams Email Exchange2 FMRadio Galaxy4 HoloSpiralWallpaper LiveWallpapers LiveWallpapersPicker NoiseField PhaseBeam PhotoPhase PhotoTable PicoTts PrintSpooler");
            printf("Done!\n");
            getchar();
            break;
        }

        // Deleting apps from system/priv-app
        case 2:
        {
            getchar();
            system("cd C:\\Universal_Tool\\workspace\\system\\priv-app && del BackupRestoreConfirmation CellBroadcastReceiver FusedLocation");
            printf("Done!\n");
            getchar();
            break;
        }

        // Information about Debloat
        case 11:
        {
            getchar();
            printf("\n[!]Debloat script delete this applications: BasicDreams, Email, Exchange2, FMRadio, Galaxy4, HoloSpiralWallpaper, LiveWallpapers, LiveWallpapersPicker, NoiseField, PhaseBeam, PhotoPhase, PhotoTable, PicoTts, PrintSpooler in 'app' folder\n");
            printf("\n[!]And this applications: BackupRestoreConfirmation, CellBroadcastReceiver, FusedLocation in 'priv-app' folder\n");
            getchar();
            printf("\n[!]Debloat script working only with 5.0 - 6.0 API versions. Work for lower version in progress\n");
            printf("\nPress 'ENTER' to continue...\n");
            getchar();
            printf("\n[!]Debloat function in this tool must be use for low end devices (or medium). This feature delete apps for increasing performance and free RAM\n");
            getchar();
            return debloatMenu();
            break;
        }

        default:
            printf("Make your choice!\n");
    }

    return 0;
}
#endif //UNIVERSAL_TOOL_DEBLOAT_MENU_H
