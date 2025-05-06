#include <stdio.h>
#include "nbtrees.h"

/***************************/
/*     Pembuatan tree      */
/***************************/
void Create_tree(Isi_Tree X, int Jml_Node)
{
    for (int i = 1; i <= Jml_Node; i++)
    {
        X[i].info = 'A' + (i - 1);
        X[i].ps_pr = (i == 1) ? nil : i / 2;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
    }
}

/***************************/
/*    Pemeriksaan kosong   */
/***************************/
boolean IsEmpty(Isi_Tree P)
{
    return (P[1].info == nil);
}

/***************************/
/*        Traversal        */
/***************************/
void PreOrder(Isi_Tree P)
{
    if (idx != nil) {
        printf("%c ", P[idx].info);
        PreOrder(P, P[idx].ps_fs);  
        PreOrder(P, P[idx].ps_nb);
}
}
void InOrder(Isi_Tree P)
{
    if (idx != nil) {
        InOrder(P, P[idx].ps_fs); 
        printf("%c ", P[idx].info);
        if (P[idx].ps_fs != nil) {
            InOrder(P, P[P[idx].ps_fs].ps_nb);
    }
}
}
void PostOrder(Isi_Tree P)
{
    if (idx != nil) {
        PostOrder(P, P[idx].ps_fs);  
        PostOrder(P, P[idx].ps_nb);
        printf("%c ", P[idx].info);
    }
}

void LevelOrder(Isi_Tree X, int Maks_node)
{
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != nil) {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

/***************************/
/*       Fungsi Lain       */
/***************************/
boolean Search(Isi_Tree P, infotype X)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            return true;
        }
    }
    return false;
}

int nbElmt(Isi_Tree P)
{
    int count = 0;
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != nil)
        {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P)
{
    int count = 0;
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != nil && P[i].ps_fs == nil)
        {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            int level = 0, parent = P[i].ps_pr;
            while (parent != nil)
            {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P)
{
    int maxDepth = 0;
    for (int i = 1; i <= jml_maks; i++)
    {
        int level = Level(P, P[i].info);
        if (level > maxDepth)
        {
            maxDepth = level;
        }
    }
    return maxDepth;
}

int Max(infotype Data1, infotype Data2)
{
    return (Data1 > Data2) ? Data1 : Data2;
}

/***************************/
/* Cetak Pohon */
/***************************/
void PrintTree(Isi_Tree P)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != nil)
        {
            printf("--> Indeks ke-%d\n", i);
            printf("----------------------------------------\n");
            printf("info array ke %d        : %c\n", i, P[i].info);
            printf("first son array ke %d   : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d: %d\n", i, P[i].ps_nb);
            printf("parent array ke %d      : %d\n", i, P[i].ps_pr);
            printf("----------------------------------------\n");
        }
    }
}

void TampilkanMenu()
{
    printf("\n=== MENU POHON NON-BINER ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("Pilih Menu: ");
}