#include <stdio.h>
#include "nbtrees.h"

int main()
{
    Isi_Tree P;
    int Jml_Node = 10;
    int pilihan;
    char cari, node1, node2;

    // Membuat pohon
    Create_tree(P, Jml_Node);

    do
    {
        TampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("\n=== Traversal PreOrder ===\n");
            PreOrder(P);
            break;
        case 2:
            printf("\n=== Traversal InOrder ===\n");
            InOrder(P);
            break;
        case 3:
            printf("\n=== Traversal PostOrder ===\n");
            PostOrder(P);
            break;
        case 4:
            printf("\n=== Traversal Level Order ===\n");
            Level_order(P, Jml_Node);
            break;
        case 5:
            printf("\n=== Print Tree ===\n");
            PrintTree(P);
            break;
        case 6:
            printf("\nMasukkan node yang ingin dicari: ");
            scanf(" %c", &cari);
            printf("Apakah '%c' ada di dalam pohon? %s\n", cari, Search(P, cari) ? "YA" : "TIDAK");
            break;
        case 7:
            printf("\nJumlah daun dalam pohon: %d\n", nbDaun(P));
            break;
        case 8:
            printf("\nMasukkan node untuk mencari level: ");
            scanf(" %c", &cari);
            printf("Level dari node '%c': %d\n", cari, Level(P, cari));
            break;
        case 9:
            printf("\nKedalaman pohon: %d\n", Depth(P));
            break;
        case 10:
            printf("\nMasukkan dua node untuk dibandingkan: ");
            scanf(" %c %c", &node1, &node2);
            printf("Nilai terbesar antara '%c' dan '%c': %c\n", node1, node2, Max(node1, node2));
            break;
        case 11:
            printf("\nKeluar dari program...\n");
            break;
        default:
            printf("\nPilihan tidak valid, coba lagi!\n");
        }
    } while (pilihan != 11);

    return 0;
}
