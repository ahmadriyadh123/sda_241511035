#include <stdio.h>
#include "nbtrees.h"

int main() {
    Isi_Tree T;
    int pilihan;
    infotype cari;

    Create_tree(T, jml_maks);

    do {
        TampilkanMenu();
        printf("\nPilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("PreOrder: ");
                PreOrder(T);
                break;
            case 2:
                printf("InOrder: ");
                InOrder(T);
                break;
            case 3:
                printf("PostOrder: ");
                PostOrder(T);
                break;
            case 4:
                printf("Level Order: ");
                Level_order(T, jml_maks);
                break;
            case 5:
                PrintTree(T);
                break;
            case 6:
                printf("Masukkan info yang dicari: ");
                scanf(" %c", &cari);
                if (Search(T, cari))
                    printf("Info ditemukan.\n");
                else
                    printf("Info tidak ditemukan.\n");
                break;
            case 7:
                printf("Jumlah Node: %d\n", nbElmt(T));
                break;
            case 8:
                printf("Jumlah Daun: %d\n", nbDaun(T));
                break;
            case 9:
                printf("Masukkan info node: ");
                scanf(" %c", &cari);
                printf("Level node %c: %d\n", cari, Level(T, cari));
                break;
            case 10:
                printf("Kedalaman Tree: %d\n", Depth(T));
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan >= 1 && pilihan <= 10);

    return 0;
}