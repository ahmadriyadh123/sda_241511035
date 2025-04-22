/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	 return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
{
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	
	 return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Info(P) == X)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

	 /* Kamus Lokal */
	 void InsVFirst(List *L, infotype X) {
		address P = Alokasi(X);
		if (P != Nil) {
			InsertFirst(&(*L), P);
		}
	}
	
	
	//Buatkan algoritma sesuai spesifikasi modul ini


/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
	 /* Kamus Lokal */
	 void InsVLast(List *L, infotype X) {
		address P = Alokasi(X);
		if (P != Nil) {
			InsertLast(L, P);
		}
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	 if (First(*L) != Nil) {
        PDel = First(*L);       
        *X = Info(PDel);        
        First(*L) = Next(PDel);  
        DeAlokasi(PDel);        
    }
	//Buatkan algoritma sesuai spesifikasi modul ini
}

/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
void DelVLast(List *L, infotype *X) {
    address PDel, Prec;
    if (First(*L) != Nil) {
        if (Next(First(*L)) == Nil) {
            PDel = First(*L);
            First(*L) = Nil;
        } else {
            PDel = First(*L);
            while (Next(PDel) != Nil) {
                Prec = PDel;
                PDel = Next(PDel);
            }
            Next(Prec) = Nil;
        }
        *X = Info(PDel);
        DeAlokasi(PDel);
    }
}


/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
    First(*L) = P;
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertAfter(List *L, address P, address Prec) {
    (void)L; // Suppress unused parameter warning
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	 if (First(*L) == Nil) {
        // Jika list kosong
        First(*L) = P;
    } else {
        // Cari elemen terakhir
        Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        Next(Last) = P; 
    }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	*P = First(*L);
    First(*L) = Next(First(*L));
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelP(List *L, infotype X) {
	/* IS : L sembarang */
	/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
	/* 	Maka P dihapus dari list dan di dealokasi */
	/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
	/* List mungkin menjadi kosong karena penghapusan */
    address P, Prec;
    boolean found = false;

    P = First(*L);
    Prec = Nil;
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = true;
        } else {
            Prec = P;
            P = Next(P);
        }
    }

    if (found) {
        if (Prec == Nil) {
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        DeAlokasi(P);
    }
}


void DelLast(List *L, address *Pdel) {
	/* IS : L TIDAK kosong */
	/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
	/*	Elemen list berkurang satu (mungkin menjadi kosong) */
	/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
		address Prec = Nil;
	
		if (First(*L) == Nil) {
			*Pdel = Nil;
		} else if (Next(First(*L)) == Nil) {
			*Pdel = First(*L);
			First(*L) = Nil;
		} else {
			*Pdel = First(*L);
			while (Next(*Pdel) != Nil) {
				Prec = *Pdel;
				*Pdel = Next(*Pdel);
			}
			Next(Prec) = Nil;
		}
		DeAlokasi(*Pdel);
}
	

void DelAfter(List *L, address *Pdel, address Prec) {
    (void)L; // Suppress unused parameter warning
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        DeAlokasi(*Pdel);
    }
}


/**** PROSES SEMUA ELEMEN LIST  ****/
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
void PrintInfo(List L) {
    address P = First(L);
    if (P == Nil) {
        printf("List Kosong\n");
    } else {
        while (P != Nil) {
            printf("%d ", Info(P));
            P = Next(P);
        }
        printf("\n");
    }
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	 while (First(*L) != Nil) {
        PDel = First(*L);
        First(*L) = Next(First(*L)); 
        DeAlokasi(PDel);          
    }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAllGanjil(List * L) {
    /* Kamus Lokal */
    address P, PDel, Prec;

    /* Algoritma */
    P = First(*L);
    Prec = Nil;

    while (P != Nil) {
        if (Info(P) % 2 != 0) {
            PDel = P;
            if (Prec == Nil) {
                First(*L) = Next(P);
            } else {
                Next(Prec) = Next(P);
            }
            P = Next(P); 
            DeAlokasi(PDel);  
        } else {
            Prec = P;
            P = Next(P);
        }
    }
}




