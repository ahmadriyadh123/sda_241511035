#include <stdio.h>
#include <string.h>
#include "slltosll.h"

int main() {
    addressKota daftarKota = NULL;
    int pilihan;
    infotype namaKota, namaOrang;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah nama orang ke Kota\n");
        printf("3. Tampilkan Daftar Kota dan Nama Orang\n");
        printf("4. Hapus Kota\n");
        printf("5. Hapus nama orang dari Kota\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                scanf(" %[^\n]", namaKota);
                tambahKota(&daftarKota, namaKota);
                break;
            case 2:
                printf("Masukkan nama kota: ");
                scanf(" %[^\n]", namaKota);

                addressKota current = daftarKota;
                while (current != NULL && strcmp(current->kt, namaKota) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
                    printf("Kota '%s' tidak ditemukan.\n", namaKota);
                } else {
                    printf("Masukkan nama orang: ");
                    scanf(" %[^\n]", namaOrang);
                    tambahOrang(&(current->p), namaOrang);
                }
                break;
            case 3:
                tampilkanDaftarKota(daftarKota);
                break;
            case 4:
                printf("Masukkan nama kota yang ingin dihapus: ");
                scanf(" %[^\n]", namaKota);
                hapusKota(&daftarKota, namaKota);
                break;
            case 5:
                printf("Masukkan nama kota: ");
                scanf(" %[^\n]", namaKota);

                current = daftarKota;
                while (current != NULL && strcmp(current->kt, namaKota) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
                    printf("Kota '%s' tidak ditemukan.\n", namaKota);
                } else {
                    printf("Masukkan nama orang yang ingin dihapus: ");
                    scanf(" %[^\n]", namaOrang);
                    hapusOrang(&(current->p), namaOrang);
                }
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}
