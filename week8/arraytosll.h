#ifndef ARRAYTOSLL_H 
#define ARRAYTOSLL_H

typedef char kata[50];
typedef kata kota;
typedef kata nama;

typedef struct tElmtList *address;
typedef struct arrtosll {
    kota kt;
    address p;
} arrtosll;

typedef struct tElmtList {
    nama nm;
    address q;
} ElmtList;

void tambahKota(arrtosll daftarKota[], int *jumlahKota);
void tambahOrang(arrtosll *kt);
void tampilkanDaftarKota(arrtosll daftarKota[], int jumlahKota);
void hapusKota(arrtosll daftarKota[], int *jumlahKota, int index);
void hapusOrang(address *head, nama targetNama);
void tampilkanMenu();

#endif