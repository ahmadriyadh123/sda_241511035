#include <stdio.h>
#include <string.h>
#include "morse.h"

    int main() {
    Isi_Tree MorseTree;

    int Jml_Node = 63;
    int pilihan;
    char cari, node1, node2;
    char kalimat[100], output[500];;

    BuildMorseTree(MorseTree);

do {
    TampilkanMenu();
    printf("Pilih menu: ");
    scanf("%d", &pilihan);
    getchar(); 

    switch (pilihan) {
        case 1:
            printf("\n=== Traversal PreOrder ===\n");
            PreOrder(MorseTree, 0);
            break;
        case 2:
            printf("\n=== Traversal InOrder ===\n");
            InOrder(MorseTree, 0);
            break;
        case 3:
            printf("\n=== Traversal PostOrder ===\n");
            PostOrder(MorseTree, 0);
            break;
        case 4:
            printf("\n=== Traversal Level Order ===\n");
            LevelOrder(MorseTree, MAX_CHAR);
            break;
        case 5:
            printf("\n=== Print Tree ===\n");
            PrintTree(MorseTree);
            break;
        case 6:
            printf("Masukkan kata(dalam huruf kapital): ");
            fgets(kalimat, sizeof(kalimat), stdin);
            kalimat[strcspn(kalimat, "\n")] = '\0';  
            ConvertToMorse(MorseTree, kalimat, output);
            printf("Kode Morse: %s\n", output);
            break;
        case 7:
            printf("Masukkan kode Morse (pisahkan dengan '/'): ");
            fgets(kalimat, sizeof(kalimat), stdin);
            kalimat[strcspn(kalimat, "\n")] = '\0';
            ConvertMorseToText(MorseTree, kalimat, output);
            printf("Teks biasa: %s\n", output);
            break;
        case 8:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }
} while (pilihan != 12);

return 0;
}
