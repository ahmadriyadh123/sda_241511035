#include "ass.h"

void inisialisasikota(arrtosll *kota) {
    if (strcmp(kota->kt, "") == 0) { 
        kota->p = NULL; 
    }
}

void tambahKota(arrtosll daftarKota[], int *jumlahKota) {
    if (*jumlahKota >= 10) {
        printf("\nDaftar kota sudah penuh.\n");
        return;
    }
    
    printf("\nMasukkan nama kota: ");
    scanf(" %[^\n]", daftarKota[*jumlahKota].kt);
    (*jumlahKota)++;
    printf("Kota berhasil ditambahkan!\n");
}

void tambahOrang(arrtosll *kt) {

}