#ifndef SLLTOSLL_H
#define SLLTOSLL_H

typedef char infotype[50];

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype nm; 
    address q;  
} ElmtList;

typedef struct KotaNode *addressKota;
typedef struct KotaNode {
    infotype kt;
    addressKota next;
    address p;        
} KotaNode;

void tambahKota(addressKota *head, infotype namaKota);
void tampilkanDaftarKota(addressKota head);
void hapusKota(addressKota *head, infotype namaKota);
void tambahOrang(address *head, infotype namaOrang);
void hapusOrang(address *head, infotype namaOrang);
void tampilkanOrang(address head);

#endif
