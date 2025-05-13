#ifndef MORSE_H
#define MORSE_H

#include "boolean.h"

#define jml_maks 63
#define kebawah 1
#define keatas 2
#define kekanan 3
#define nil 0
#define MAX_CHAR 63

typedef char infotype;
typedef int address;
typedef struct
{
    infotype info;
    int leftChild, rightChild;
    char morseCode[10];
} nbtree;
typedef nbtree Isi_Tree[jml_maks + 1];

void BuildMorseTree(Isi_Tree T);
void ConvertToMorse(Isi_Tree T, char *input, char *output);
void ConvertMorseToText(Isi_Tree T, char *input, char *output);
void Create_tree(Isi_Tree T, int jumlahNode);
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
boolean IsEmpty(Isi_Tree P);
/* Mengirimkan true jika Isi_Tree KOSONG */

/***** Traversal *****/
void PreOrder(Isi_Tree P, int idx);
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */
void InOrder(Isi_Tree P, int idx);
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */
void PostOrder(Isi_Tree P, int idx);
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb, Parent */
void LevelOrder(Isi_Tree X, int Maks_node);
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
void PrintTree(Isi_Tree P);
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */

void TampilkanMenu();

#endif