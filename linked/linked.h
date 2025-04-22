/* File : linked.h */
/* Deskripsi : ADT linked list dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <alloc.h>
#include "boolean.h"
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
infotype info;
address next;
} ElmtList;
boolean isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
void Create_Node (address *p);
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node (infotype nilai, address *p);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang
dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : Nilai (parameter Input); P (parameter Input-Output)
void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal (address *p, infotype nilai);
// Tujuan : Insert 1 node di awal Linked List
// Parameter : P (input-output)
// nilai (input)
void Ins_Akhir (address *p, infotype nilai);
/* Tujuan : menambahkan elemen list di akhir (elemen terakhir adalah
yang baru) */
/* IS : p mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang
baru)*/
/* bernilai nilai jika alokasi berhasil. Jika alokasi gagal IS = FS */
address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
void InsertAfter (address * p, infotype nilai, infotype newNilai);
/* Tujuan : Menyisipkan 1 Node setelah node dengan info = nilai */
/* IS : P sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah elemen dengan info = nilai
yang pertama */
/* Asumsi : jika p = null atau p->info <> nilai, maka gagal insert */
void Del_Awal (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
void Del_After (address * p, infotype nilai, infotype * X);
/* IS : p TIDAK Kosong */
/* FS : menghapus Node setelah node->info = nilai */
/* Pdel adalah alamat elemen list yang dihapus */
/* Jika info node yang akan dihapus tidak ada, maka *X diisi 0 */
void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong
*/
// Recursif Mode
infotype Min (address p);
/* Mengirimkan nilai Info(P) yang minimum */
infotype Rerata (address p);
/* Mengirimkan nilai rata-rata Info(P) */
address BalikList (address p);
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama,
dst */

#endif