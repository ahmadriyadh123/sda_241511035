/* File : linked.cpp */
/* Deskripsi : Implementasi ADT linked list dengan representasi
fisik pointer */
/* InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#include "linked.h"

boolean isEmpty(address p)
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
{
    return (p == NULL);
}

void Create_Node(address *p)
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
{
    (*p) = (address)malloc(sizeof(ElmtList));
}

void Isi_Node(infotype nilai, address *p)
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : Nilai (parameter Input); P (parameter Input-Output)
{
    if (!isEmpty(*p))
    {
        (*(*p)).info = nilai;
        (*(*p)).next = NULL;
    }
}
void Tampil_List(address p)
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
{
    while (!isEmpty(p))
    {
        printf("%d ", (*p).info);
        p = (*p).next;
    }
}
void Ins_Awal(address *p, infotype nilai)
// Tujuan : Insert 1 node di awal Linked List
// Parameter : P (input-output)
// nilai (input)
{
    address PNew;
    Create_Node(&PNew);
    Isi_Node(nilai, &PNew);
    if (!isEmpty(*p))
    {
        (*PNew).next = (*p);
        (*p) = PNew;
    }
    else
    {
        *p = PNew;
    }
}
void Ins_Akhir(address *p, infotype nilai)
/* Tujuan : menambahkan elemen list di akhir (elemen terakhir adalah
yang baru) */
/* IS : p mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang
baru)*/
/* bernilai nilai jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
    /* Kamus Lokal */
    address PNew, Temp;
    /* Algoritma */
    Create_Node(&PNew);
    Isi_Node(nilai, &PNew);
    if (!isEmpty(*p))
    {
        Temp = *p;
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = PNew;
    }
    else
    {
        *p = PNew;
    }
}
address Search(address p, infotype nilai)
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
    /* Kamus Lokal */
    address Temp;
    boolean found = false;
    /* algoritma */
    Temp = p;
    while ((Temp != NULL) && (!found))
    {

        if (Temp->info == nilai)
        {
            found = true;
        }
        else
        {
            Temp = Temp->next;
        }
    } /* P = Null atau Yang dicari Ketemu */
    return (Temp);
}
void InsertAfter(address *p, infotype nilai, infotype newNilai)
/* Tujuan : Menyisipkan 1 Node setelah node dengan info = nilai */
/* IS : P sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah elemen dengan info = nilai
yang pertama */
/* Asumsi : jika p = null atau p->info <> nilai, maka gagal insert */
{
    /* Kamus Lokal */
    address PNew, Temp;
    /* Algoritma */
    if (!isEmpty(*p))
    {
        Temp = Search(*p, nilai);
        if (Temp != NULL)
        {
            Create_Node(&PNew);
            Isi_Node(newNilai, &PNew);
            PNew->next = Temp->next;
            Temp->next = PNew;
        }
    }
}
void Del_Awal(address *p, infotype *X)
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
{
    /* Kamus Lokal */
    address PDel;
    /* Algoritma */
    if (!isEmpty(*p))
    {
        PDel = *p;
        *X = PDel->info;
        *p = (*p)->next;
        DeAlokasi(&PDel);
    }
}
void Del_Akhir(address *p, infotype *X)
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
{
    /* Kamus Lokal */
    address PDel, Temp;
    /* Algoritma */
    if (!isEmpty(*p))
    {
        PDel = *p;
        Temp = NULL;
        while (PDel->next != NULL)
        {
            Temp = PDel;
            PDel = PDel->next;
        }
        if (Temp == NULL) /* Hanya 1 elemen */
        {
            *p = NULL;
        }
        else /* List Lebih dari 1 elemen */
        {
            Temp->next = NULL;
        }
        (*X) = PDel->info;
        DeAlokasi(&PDel);
    }
}
void Del_After(address *p, infotype nilai, infotype *X)
/* IS : p TIDAK Kosong */
/* FS : menghapus Node setelah node->info = nilai */
/* Pdel adalah alamat elemen list yang dihapus */
/* Jika info node yang akan dihapus tidak ada, maka *X diisi 0 */
{
    /* Kamus Lokal */
    address PDel, Temp;
    /* Algoritma */
    if (!isEmpty(*p))
    {
        Temp = Search(*p, nilai);
        if (Temp != NULL)
        {
            PDel = Temp->next;
            if (PDel != NULL)
            {
                (*X) = PDel->info;
                Temp->next = PDel->next;
                DeAlokasi(&PDel);
            }
            else
                (*X) = 0;
        }
        else
            (*X) = 0;
    }
}
void DeAlokasi(address *p)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
    if (!isEmpty(*p))
    {
        (*p)->next = NULL;
        free(*p);
    }
}

int NbElmt(address p)
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong
 */
// Recursif Mode
{
    if (isEmpty(p))
        return (0);
    else
    {
        p = p->next;
        return (1 + NbElmt(p));
    }
}
infotype Min(address p)
/* Mengirimkan nilai Info(P) yang minimum */
{
    // Kamus Lokal
    infotype VMin;
    // Algoritma
    if (!isEmpty(p))
    {
        VMin = p->info;
        while (p->next != NULL)
        {
            p = p->next;
            if (VMin > (p->info))
                VMin = p->info;
        }
    }
    return (VMin);
}
infotype Rerata(address p)
/* Mengirimkan nilai rata-rata Info(P) */
{
    /* Kamus lokal */
    int Jml = 0;
    int Acc = 0;
    /* Algoritma */
    while (!isEmpty(p))
    {
        Acc = Acc + p->info;
        Jml++;
        p = p->next;
    }
    if (Jml > 0)
    {
        Jml = (int)Acc / Jml;
    }
    return (Jml);
}

address BalikList(address p)
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama,
dst */
{
    // Kamus Lokal
    address PNew = NULL, Temp;
    infotype X;
    // Algoritma
    if (!isEmpty(p))
    {
        Temp = p;
        while (Temp != NULL)
        {
            X = Temp->info;
            Ins_Awal(&PNew, X);
            Temp = Temp->next;
        }
    }
    return (PNew);
}