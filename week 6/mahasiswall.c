#include "mahasiswall.h"

void CreateList(List *L) {
    First(*L) = Nil;
}

bool ListEmpty(List L) {
    return (First(L) == Nil);
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DeAlokasi(address P) {
    free(P);
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address last = First(*L);
            while (Next(last) != Nil) {
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

void PrintInfo(List L) {
    if (ListEmpty(L)) {
        printf("List Kosong\n");
    } else {
        address P = First(L);
        while (P != Nil) {
            printf("Nama: %s, Nilai UTS SDA: %d\n", Info(P).nama, Info(P).nilaiUTSSDA);
            P = Next(P);
        }
    }
}

int CountElements(List L) {
    int count = 0;
    address P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}

void SortList(List *L, int sortBy, bool ascending) {
    if (ListEmpty(*L)) return;

    bool swapped;
    do {
        swapped = false;
        address P = First(*L);
        while (Next(P) != Nil) {
            address Q = Next(P);
            bool condition;

            if (sortBy == 1) { 
                condition = (ascending) ? 
                    (strcmp(Info(P).nama, Info(Q).nama) > 0) : 
                    (strcmp(Info(P).nama, Info(Q).nama) < 0);
            } else { 
                condition = (ascending) ? 
                    (Info(P).nilaiUTSSDA > Info(Q).nilaiUTSSDA) : 
                    (Info(P).nilaiUTSSDA < Info(Q).nilaiUTSSDA);
            }

            if (condition) {
                infotype temp = Info(P);
                Info(P) = Info(Q);
                Info(Q) = temp;
                swapped = true;
            }
            P = Q;
        }
    } while (swapped);
}

void CopyToL2(List L1, List *L2, int threshold) {
    CreateList(L2);
    address P = First(L1);
    while (P != Nil) {
        if (Info(P).nilaiUTSSDA > threshold) {
            InsVLast(L2, Info(P));
        }
        P = Next(P);
    }
}

void RemoveDuplicates(List *L) {
    address outer = First(*L);
    while (outer != Nil && Next(outer) != Nil) {
        address inner = outer;
        while (Next(inner) != Nil) {
            if (strcmp(Info(outer).nama, Info(Next(inner)).nama) == 0) {
                address duplicate = Next(inner);
                Next(inner) = Next(duplicate);
                DeAlokasi(duplicate);
            } else {
                inner = Next(inner);
            }
        }
        outer = Next(outer);
    }
}

void DeleteList(List *L) {
    address P;
    while (First(*L) != Nil) {
        P = First(*L);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}

void displayMenu() {
    printf("\nMenu Utama:\n");
    printf("1. Tambah Mahasiswa ke List L1\n");
    printf("2. Tampilkan dan Urutkan List L1\n");
    printf("3. Hitung Jumlah Elemen di List L1\n");
    printf("4. Copy Elemen Nilai > 70 ke L2\n");
    printf("5. Tampilkan List L2\n");
    printf("6. Hapus Duplikat Nama di List L2\n");
    printf("7. Hapus Semua Data di List L1 dan L2\n");
    printf("0. Exit\n");
    printf("Pilih menu: ");
}

void sortAndDisplayList(List *L) {
    int sortBy, order;

    printf("\nPilih jenis pengurutan:\n");
    printf("1. Berdasarkan Nama\n");
    printf("2. Berdasarkan Nilai UTS\n");
    printf("Pilih: ");
    scanf("%d", &sortBy);

    printf("\nPilih urutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilih: ");
    scanf("%d", &order);

    bool ascending = (order == 1);

    SortList(L, sortBy, ascending);

    printf("\nList L1 setelah diurutkan:\n");
    PrintInfo(*L);
}
