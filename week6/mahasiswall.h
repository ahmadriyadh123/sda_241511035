#ifndef MAHASISWALL_H
#define MAHASISWALL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef struct {
    char nama[50];
    int nilaiUTSSDA;
} infotype;

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address First;
} List;

//deklarasi modul
void CreateList(List *L);
bool ListEmpty(List L);
address Alokasi(infotype X);
void DeAlokasi(address P);
void InsVLast(List *L, infotype X);
void PrintInfo(List L);
int CountElements(List L);
void SortList(List *L, int sortBy, bool ascending);
void CopyToL2(List L1, List *L2, int threshold);
void RemoveDuplicates(List *L);
void DeleteList(List *L);
void displayMenu();
void sortAndDisplayList(List *L);

#endif
