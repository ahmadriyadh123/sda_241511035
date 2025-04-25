#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "slltosll.h"

//Menambah kota ke linked list
void tambahKota(addressKota *head, infotype namaKota) {
    addressKota newKota = (addressKota) malloc(sizeof(KotaNode));
    strcpy(newKota->kt, namaKota);
    newKota->next = NULL;
    newKota->p = NULL;

    if (*head == NULL) {
        *head = newKota;
    } else {
        addressKota current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newKota;
    }
    printf("Kota '%s' berhasil ditambahkan.\n", namaKota);
}

// Tampilkan daftar kota dan orang
void tampilkanDaftarKota(addressKota head) {
    if (head == NULL) {
        printf("Belum ada kota yang terdaftar.\n");
        return;
    }
    addressKota current = head;
    printf("\nDaftar Kota:\n");
    while (current != NULL) {
        printf("- %s\n", current->kt);
        tampilkanOrang(current->p);
        current = current->next;
    }
}

//Menghapus kota dan semua orangnya
void hapusKota(addressKota *head, infotype namaKota) {
    if (*head == NULL) {
        printf("Belum ada kota yang terdaftar.\n");
        return;
    }

    addressKota current = *head;
    addressKota prev = NULL;

    while (current != NULL && strcmp(current->kt, namaKota) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    //Menghapus seluruh orang di suatu kota
    address tempOrang = current->p;
    while (tempOrang != NULL) {
        address temp = tempOrang;
        tempOrang = tempOrang->q;
        free(temp);
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Kota '%s' berhasil dihapus.\n", namaKota);
}

//Menambah orang ke linked list
void tambahOrang(address *head, infotype namaOrang) {
    address newPerson = (address) malloc(sizeof(ElmtList));
    strcpy(newPerson->nm, namaOrang);
    newPerson->q = NULL;

    if (*head == NULL) {
        *head = newPerson;
    } else {
        address current = *head;
        while (current->q != NULL) {
            current = current->q;
        }
        current->q = newPerson;
    }
    printf("Orang '%s' berhasil ditambahkan.\n", namaOrang);
}

//Menghapus orang dari linked list
void hapusOrang(address *head, infotype namaOrang) {
    if (*head == NULL) {
        printf("Tidak ada orang yang terdaftar.\n");
        return;
    }

    address current = *head;
    address prev = NULL;

    while (current != NULL && strcmp(current->nm, namaOrang) != 0) {
        prev = current;
        current = current->q;
    }

    if (current == NULL) {
        printf("Orang '%s' tidak ditemukan.\n", namaOrang);
        return;
    }

    if (prev == NULL) {
        *head = current->q;
    } else {
        prev->q = current->q;
    }

    free(current);
    printf("Orang '%s' berhasil dihapus.\n", namaOrang);
}

//Menampilkan daftar orang
void tampilkanOrang(address head) {
    if (head == NULL) {
        printf("  Tidak ada orang.\n");
        return;
    }

    address current = head;
    printf("  Orang:\n");
    while (current != NULL) {
        printf("  - %s\n", current->nm);
        current = current->q;
    }
}
