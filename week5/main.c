/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi;
		address P;
		int pilihan;

	/* Program */
	CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	
	//aksi mahasiswa untuk implementasi studi kasus
	do {
        // Tampilkan menu
        printf("\n=== MENU PILIHAN ===\n");
        printf("1. Tambah Elemen di Awal\n");
        printf("2. Tambah Elemen di Akhir\n");
        printf("3. Hapus Elemen Pertama\n");
        printf("4. Hapus Elemen Terakhir\n");
        printf("5. Cari Elemen Berdasarkan Nilai\n");
        printf("6. Hapus Elemen Berdasarkan Nilai\n");
        printf("7. Tampilkan Isi List\n");
        printf("8. Hapus Semua Elemen yang Bernilai Ganjil\n");
        printf("9. Keluar\n");
        printf("Pilih menu (1-9): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Tambah elemen di awal
                printf("Masukkan nilai elemen: ");
                scanf("%d", &isi);
                InsVFirst(&MyList, isi);
                printf("Elemen %d ditambahkan di awal.\n", isi);
                break;

            case 2:
                // Tambah elemen di akhir
                printf("Masukkan nilai elemen: ");
                scanf("%d", &isi);
                InsVLast(&MyList, isi);
                printf("Elemen %d ditambahkan di akhir.\n", isi);
                break;

            case 3:
                // Hapus elemen pertama
                if (!ListEmpty(MyList)) {
                    DelVFirst(&MyList, &isi);
                    printf("Elemen pertama (%d) dihapus.\n", isi);
                } else {
                    printf("List kosong, tidak ada elemen untuk dihapus.\n");
                }
                break;

            case 4:
                // Hapus elemen terakhir
                if (!ListEmpty(MyList)) {
                    DelVLast(&MyList, &isi);
                    printf("Elemen terakhir (%d) dihapus.\n", isi);
                } else {
                    printf("List kosong, tidak ada elemen untuk dihapus.\n");
                }
                break;

            case 5:
                // Cari elemen berdasarkan nilai
                printf("Masukkan nilai elemen yang ingin dicari: ");
                scanf("%d", &isi);
                P = Search(MyList, isi);
                if (P != Nil) {
                    printf("Elemen dengan nilai %d ditemukan.\n", isi);
                } else {
                    printf("Elemen dengan nilai %d tidak ditemukan.\n", isi);
                }
                break;

            case 6:
                // Hapus elemen berdasarkan nilai
                printf("Masukkan nilai elemen yang ingin dihapus: ");
                scanf("%d", &isi);
                DelP(&MyList, isi);
                printf("Elemen dengan nilai %d dihapus jika ada.\n", isi);
                break;

            case 7:
                // Tampilkan isi list
                printf("Isi list: ");
                PrintInfo(MyList);
                break;

            case 8:
                // Hapus semua elemen yang bernilai ganjil
                DelAllGanjil(&MyList);
                printf("Semua elemen bernilai ganjil dihapus.\n");
                break;

            case 9:
                // Keluar
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang benar.\n");
        }
    } while (pilihan != 9);

	/* Finishing */
	
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

