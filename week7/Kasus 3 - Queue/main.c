#include <stdio.h>
#include "queue.h"

void ShowMenu() {
    printf("\n===== MENU ANTRIAN BANK =====\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Cetak Antrian\n");
    printf("4. Keluar\n");
    printf("==============================\n");
    printf("Pilih opsi: ");
}

int main() {
    DynamicQueue Q;
    int MaxSize;
    int choice, customerNumber = 0, processedNumber;

    // Set the maximum size of the queue
    printf("Masukkan jumlah maksimal antrian: ");
    scanf("%d", &MaxSize);

    // Initialize the queue with the specified maximum size
    CreateQueue(&Q, MaxSize);

    do {
        ShowMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Ambil antrian
                customerNumber++;
                EnQueue(&Q, customerNumber);
                printf("Daftar antrian: ");
                PrintQueue(Q);
                break;

            case 2: // Proses antrian
                if (!IsEmpty(Q)) {
                    DeQueue(&Q, &processedNumber);
                    printf("Nomor antrian %d sedang diproses.\n", processedNumber);
                    printf("Daftar antrian: ");
                    PrintQueue(Q);
                } else {
                    printf("Antrian kosong. Tidak ada yang diproses.\n");
                }
                break;

            case 3: // Cetak antrian
                printf("Daftar antrian: ");
                PrintQueue(Q);
                break;

            case 4: // Keluar
                printf("Program selesai. Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 4);

    return 0;
}
