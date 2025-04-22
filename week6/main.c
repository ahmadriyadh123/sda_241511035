#include "mahasiswall.h"

int main() {
    List L1, L2;
    CreateList(&L1);
    CreateList(&L2);
    int choice;
    infotype data;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clean up newline

        switch (choice) {
            case 1:
                printf("Masukkan Nama Mahasiswa: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = 0; // Remove newline
                printf("Masukkan Nilai UTS SDA: ");
                scanf("%d", &data.nilaiUTSSDA);
                InsVLast(&L1, data);
                printf("Data mahasiswa berhasil ditambahkan ke L1.\n");
                break;
            case 2:
                sortAndDisplayList(&L1);
                break;
            case 3:
                printf("Jumlah Mahasiswa di List L1: %d\n", CountElements(L1));
                break;
            case 4:
                CopyToL2(L1, &L2, 70);
                printf("Data mahasiswa dengan Nilai > 70 berhasil disalin ke L2.\n");
                break;
            case 5:
                printf("\nIsi List L2:\n");
                PrintInfo(L2);
                break;
            case 6:
                RemoveDuplicates(&L2);
                printf("Duplikat pada List L2 berhasil dihapus.\n");
                break;
            case 7:
                DeleteList(&L1);
                DeleteList(&L2);
                printf("Semua data di List L1 dan L2 berhasil dihapus.\n");
                break;
            case 0:
                printf("Keluar dari program. Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
