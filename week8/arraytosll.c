#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraytosll.h"

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
    kata nama;
    
    printf("\nMasukkan nama orang yang tinggal di %s: ", kt->kt);
    scanf(" %[^\n]", nama);
    
    address newPerson = (address) malloc(sizeof(ElmtList));
    strcpy(newPerson->nm, nama);
    newPerson->q = NULL;
    
    if (kt->p == NULL) {
        kt->p = newPerson;
    } 
    else {
        address current = kt->p;
        while (current->q != NULL) { 
            current = current->q;
        }
        current->q = newPerson; 
    }
    
    printf("Orang berhasil ditambahkan ke kota %s!\n", kt->kt);
}

void tampilkanDaftarKota(arrtosll daftarKota[], int jumlahKota) {
    printf("\nDaftar Kota & Nama Orang:\n");
    if (jumlahKota == 0){
        printf("Tidak ada data\n");
    }
    for (int i = 0; i < jumlahKota; i++) {
        printf("\nKota %d: %s\n", i + 1, daftarKota[i].kt);
        address current = daftarKota[i].p;
        if (current == NULL) {
            printf("  Tidak ada nama orang.\n");
        } else {
            while (current != NULL) {
                printf("  - %s\n", current->nm);
                current = current->q;
            }
        }
    }
}

void hapusKota(arrtosll daftarKota[], int *jumlahKota, int inputIndex) {
    int index = inputIndex - 1;  

    if (index < 0 || index >= *jumlahKota) {
        printf("\nNomor kota tidak valid!\n");
        return;
    }

    address current = daftarKota[index].p;
    while (current != NULL) {
        current = current->q;
        address temp = current;
        free(temp);
    }
    daftarKota[index].p = NULL;

    for (int i = index; i < *jumlahKota - 1; i++) {
        daftarKota[i] = daftarKota[i + 1];
    }
    (*jumlahKota)--;  
    printf("\nKota %d berhasil dihapus beserta semua penduduknya.\n", inputIndex);
}



void hapusOrang(address *head, nama targetNama) {   
        address current = *head;
        address prev = NULL;

    if (*head == NULL) {
        printf("\nTidak ada penduduk dalam kota.\n");
        return;
    }
    while (current != NULL && strcmp(current->nm, targetNama) != 0) {
        prev = current;
        current = current->q;
    }
    if (current == NULL) {
        printf("\nNama '%s' tidak ditemukan dalam daftar penduduk.\n", targetNama);
        return;
    }
    if (prev == NULL) {
        *head = current->q;
    } 
    else {
        prev->q = current->q;
    }
    free(current);
    printf("\nNama '%s' berhasil dihapus dari daftar penduduk kota.\n", targetNama);
}

void tampilkanMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Nama orang\n");
    printf("3. Tampilkan Daftar Kota & Nama orang\n");
    printf("4. Hapus Data Kota\n");
    printf("5. Hapus Nama Orang\n");
    printf("4. Keluar\n");
}
