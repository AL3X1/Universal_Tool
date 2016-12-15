/*
 * Debloat menu
 * Written by 4L3X
 *
 */

#ifndef UNIVERSALTOOL_DEBLOAT_MENU
#define UNIVERSALTOOL_DEBLOAT_MENU

#include <stdlib.h>
#include <stdio.h>
#include "advanced_menu.c"

int debloatMenu()
{
    int     value;

    system("@cls||clear");

    printf("=======================================\n");
    printf("\t Debloat menu\n");
    printf("=======================================\n");
    printf("\t [1] App debloat\n");
    printf("\t [2] Priv-app debloat\n");
    printf("\t [9] Information about Debloat\n");
    printf("\t [0] Exit\n");

    scanf("%d", &value);

    switch (value)
    {
        // Exit
        case 0:
            return 0;
        // Deleting apps from system/app
        case 1:
        {
                getchar();
            system("cd ~/UniversalTool/workspace/system/app && rm -rf BasicDreams Email Exchange2 FMRadio Galaxy4 HoloSpiralWallpaper LiveWallpapers LiveWallpapersPicker NoiseField PhaseBeam PhotoPhase PhotoTable PicoTts PrintSpooler");

            printf("Done!\n");
                getchar();
            break;
        }
        // Deleting apps from system/priv-app
        case 2:
        {
                getchar();
                system("cd ~/UniversalTool/workspace/system/priv-app && rm -rf BackupRestoreConfirmation CellBroadcastReceiver FusedLocation");

            printf("Done!\n");
                getchar();
            break;
        }
        // Information about Debloat
        case 9:
        {
            printf("\n[!]Debloat script delete this applications: BasicDreams, Email, Exchange2, FMRadio, Galaxy4, HoloSpiralWallpaper, LiveWallpapers, LiveWallpapersPicker, NoiseField, PhaseBeam, PhotoPhase, PhotoTable, PicoTts, PrintSpooler in 'app' folder\n");
            printf("\n[!]And this applications: BackupRestoreConfirmation, CellBroadcastReceiver, FusedLocation in 'priv-app' folder\n");
                getchar();
            printf("\n[!]Debloat script working only with 5.0 - 6.0 API versions. Work for lower version in progress\n");
            printf("\nPress 'ENTER' to continue...\n");
                getchar();
            printf("\n[!]Debloat function in this tool must be use for low end devices (or medium). This feature delete apps for increasing performance and free RAM\n");
                getchar();
            break;
        }
        default:
            printf("Make your choice!\n");
    }

    return 0;
}

#endif //UNIVERSALTOOL_DEBLOAT_MENU

