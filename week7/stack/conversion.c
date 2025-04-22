#include <stdio.h>
#include "conversion.h"
#include "stack.h"

void DecimalToBinary(int decimal) {
    Stack S;
    int remainder;

    CreateStack(&S); 

    // Merubah desimal ke biner
    while (decimal > 0) {
        remainder = decimal % 2; 
        Push(&S, remainder);   
        decimal /= 2;
    }

    printf("Bilangan biner: ");
    while (!IsEmpty(S)) {
        Pop(&S, &remainder);
        printf("%d", remainder);
    }
    printf("\n");
}

void ShowMenu() {
    printf("\n===== MENU UTAMA =====\n");
    printf("1. Konversi Desimal ke Biner\n");
    printf("2. Keluar\n");
    printf("=======================\n");
    printf("Pilih opsi: ");
}