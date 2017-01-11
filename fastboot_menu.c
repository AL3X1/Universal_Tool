/*
 *
 * Written by 4L3X
 * 06.01.17
 *
 */

#include <stdio.h>
#include <stdlib.h>

int fastbootMenu(void)
{
    int     user_key;
    system("@cls||clear");

    // Printing Fastboot Menu
    printf("=======================================\n");
    printf("  Fastboot menu                      |\n");
    printf("=======================================\n");
    printf("| [1] Fastboot devices               |\n");
    printf("| [2] Fastboot reboot                |\n");
    printf("| [3] Fastboot reboot-bootloader     |\n");
    printf("| [4] Fastboot help                  |\n");
    printf("========================================\n");
    printf("\n[0] Exit\n");
    printf("What you want?: ");

    scanf("%d", &user_key);

    switch (user_key)
    {
        // Show device, connected via fastboot
        case 1:
            system("fastboot devices");
            return fastbootMenu();
            break;

        // Reboot device from bootloader
        case 2:
            system("fastboot reboot");
            return fastbootMenu();
            break;

        // Reboot device from normal mode to bootloader
        case 3:
            system("fastboot reboot-bootloader");
            return fastbootMenu();
            break;

        // Show help for fastboot-tool usage
        case 4:
            system("fastboot help");
            return fastbootMenu();
            break;

        default:
            printf("Make your choice!\n");
    }

    return 0;
}
