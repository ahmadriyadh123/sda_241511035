#include <stdio.h>
#include "arraytosll.h"

int main() {
    arrtosll daftarKota[10];
    int jumlahKota = 0;
    int pilihan, indexKota;
    nama targetNama;

    for (int i = 0; i < 10; i++) {
        strcpy(daftarKota[i].kt, "");
        daftarKota[i].p = NULL;
    }

    do {
        tampilkanMenu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                tambahKota(daftarKota, &jumlahKota);
                break;
            case 2:
                printf("\nMasukkan nomor kota untuk menambahkan orang (1-%d): ", jumlahKota);
                scanf("%d", &indexKota);
                if (indexKota >= 1 && indexKota <= jumlahKota) {
                    tambahOrang(&daftarKota[indexKota - 1]);
                } else {
                    printf("Nomor kota tidak valid!\n");
                }
                break;
            case 3:
                tampilkanDaftarKota(daftarKota, jumlahKota);
                break;
            case 4:
                printf("\nMasukkan nomor kota yang ingin dihapus (1-%d): ", jumlahKota);
                scanf("%d", &indexKota);
                hapusKota(daftarKota, &jumlahKota, indexKota);
                break;
            case 5:
                printf("\nMasukkan nomor kota tempat orang yang akan dihapus (1-%d): ", jumlahKota);
                scanf("%d", &indexKota);
                if (indexKota >= 1 && indexKota <= jumlahKota) {
                    printf("Masukkan nama orang yang ingin dihapus: ");
                    scanf(" %[^\n]", targetNama);
                    hapusOrang(&(daftarKota[indexKota - 1].p), targetNama);
                } else {
                    printf("\nNomor kota tidak valid!\n");
                }
                break;
            case 6:
                printf("\nKeluar dari program.\n");
                break;
            default:
                printf("\nPilihan tidak valid, coba lagi!\n");
        }
    } while (pilihan != 6);

    return 0;
}
