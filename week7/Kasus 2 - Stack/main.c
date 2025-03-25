#include <stdio.h>
#include "conversion.h"

int main() {
    int choice, decimal;

    do {
        // Display the menu
        ShowMenu();

        // Get the user's choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Decimal to Binary Conversion
                printf("Masukkan bilangan desimal: ");
                scanf("%d", &decimal);
                DecimalToBinary(decimal); // Call the function from conversion.c
                break;

            case 2:
                // Exit the program
                printf("Keluar dari program. Sampai jumpa!\n");
                break;

            default:
                // Invalid option
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 2); // Loop until the user chooses to exit

    return 0;
}
