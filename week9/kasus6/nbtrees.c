#include <stdio.h>
#include "nbtrees.h"

/***************************/
/*     Pembuatan tree      */
/***************************/
void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 1; i <= jml_maks; i++) {
        X[i].info = '-';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    X[1].info = 'A'; X[1].ps_fs = 2; X[1].ps_nb = 0; X[1].ps_pr = 0;
    X[2].info = 'B'; X[2].ps_fs = 4; X[2].ps_nb = 3; X[2].ps_pr = 1;
    X[3].info = 'C'; X[3].ps_fs = 6; X[3].ps_nb = 0; X[3].ps_pr = 1;
    X[4].info = 'D'; X[4].ps_fs = 0; X[4].ps_nb = 5; X[4].ps_pr = 2;
    X[5].info = 'E'; X[5].ps_fs = 9; X[5].ps_nb = 6; X[5].ps_pr = 2;
    X[6].info = 'F'; X[6].ps_fs = 0; X[6].ps_nb = 7; X[6].ps_pr = 3;
    X[7].info = 'G'; X[7].ps_fs = 0; X[7].ps_nb = 8; X[7].ps_pr = 3;
    X[8].info = 'H'; X[8].ps_fs = 0; X[8].ps_nb = 0; X[8].ps_pr = 3;
    X[9].info = 'I'; X[9].ps_fs = 0; X[9].ps_nb = 10; X[9].ps_pr = 5;
    X[10].info = 'J'; X[10].ps_fs = 0; X[10].ps_nb = 0; X[10].ps_pr = 5;

}


/***************************/
/*    Pemeriksaan kosong   */
/***************************/
boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '-');
}

/***************************/
/*        Traversal        */
/***************************/
void PreOrder(Isi_Tree P) {
    void Recurse(address i) {
        if (i != nil) {
            printf("%c ", P[i].info);
            Recurse(P[i].ps_fs);
            Recurse(P[i].ps_nb);
        }
    }
    Recurse(1);
    printf("\n");
}

void InOrder(Isi_Tree P) {
    void Recurse(address i) {
        if (i != nil) {
            if (P[i].ps_fs != nil) Recurse(P[i].ps_fs);
            printf("%c ", P[i].info);
            if (P[i].ps_fs != nil) {
                address anak = P[i].ps_fs;
                anak = P[anak].ps_nb;
                while (anak != nil) {
                    Recurse(anak);
                    anak = P[anak].ps_nb;
                }
            }
        }
    }
    Recurse(1);
    printf("\n");
}

void PostOrder(Isi_Tree P) {
    void Recurse(address i) {
        if (i != nil) {
            Recurse(P[i].ps_fs);
            Recurse(P[i].ps_nb);
            printf("%c ", P[i].info);
        }
    }
    Recurse(1);
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != '-') {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

/***************************/
/*       Fungsi Lain       */
/***************************/
boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-' && P[i].ps_fs == nil) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    address idx = nil;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            idx = i;
            break;
        }
    }
    int lvl = 0;
    while (P[idx].ps_pr != nil) {
        idx = P[idx].ps_pr;
        lvl++;
    }
    return lvl;
}

int Depth(Isi_Tree P) {
    int max = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-') {
            int lvl = Level(P, P[i].info);
            if (lvl > max) max = lvl;
        }
    }
    return max;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

void TampilkanMenu() {
    printf("\nMenu:");
    printf("\n1. Tampilkan PreOrder");
    printf("\n2. Tampilkan InOrder");
    printf("\n3. Tampilkan PostOrder");
    printf("\n4. Tampilkan LevelOrder");
    printf("\n5. Tampilkan Tree");
    printf("\n6. Cari Info");
    printf("\n7. Jumlah Node");
    printf("\n8. Jumlah Daun");
    printf("\n9. Cek Level Node");
    printf("\n10. Kedalaman Tree\n");
}

/***************************/
/* Cetak Pohon */
/***************************/
void PrintTree(Isi_Tree P) {
    printf("Index | Info | Parent | FS | NB\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '-') {
            printf("%5d | %4c | %6d | %2d | %2d\n", i, P[i].info, P[i].ps_pr, P[i].ps_fs, P[i].ps_nb);
        }
    }
}