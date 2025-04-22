/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013

#include "spnrsll.h"
#include "queue.h"

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (DynamicQueue *Q, int MaxSize)
{
    Q->Front = Nil;  
    Q->Rear = Nil;
    Q->MaxSize = MaxSize;
    Q->CurrentSize = 0;
}

/*Memeriksa apakah queue kosong */
boolean IsEmpty(DynamicQueue Q) 
{
        return (Q.CurrentSize == 0);
}

/*Memeriksa apakah queue penuh */
boolean IsFull(DynamicQueue Q) 
{
    return (Q.CurrentSize >= Q.MaxSize);
}

/*Melekukan insertion pada queue*/
void EnQueue(DynamicQueue *Q, infotype X) 
{
    if (!IsFull(*Q)) {
        address P = Alokasi(X); 
        if (P != Nil) {
            if (Q->Rear == Nil) {
                Q->Front = P;
                Q->Rear = P;
            } else {
                Next(Q->Rear) = P;
                Q->Rear = P;
            }
            Q->CurrentSize++; 
        } else {
            printf("Alokasi memori gagal. Tidak bisa enqueue.\n");
        }
    } else {
        printf("Queue penuh! Tidak dapat menambahkan elemen baru.\n");
    }
}

/*Melakukan deletion pada queue*/
void DeQueue(DynamicQueue *Q, infotype *X) 
{
    if (!IsEmpty(*Q)) {
        address PDel = Q->Front;
        *X = Info(PDel);      
        Q->Front = Next(PDel); 
        if (Q->Front == Nil) {
            Q->Rear = Nil; 
        }
        DeAlokasi(PDel);      
        Q->CurrentSize--;     
    } else {
        printf("Queue kosong! Tidak ada elemen untuk dihapus.\n");
    }
}

/*Mencetak Queue*/
void PrintQueue(DynamicQueue Q)
{
    if (!IsEmpty(Q)) {
        address P = Q.Front;
        while (P != Nil) {
            printf("%d ", Info(P));
            P = Next(P);
        }
        printf("\n");
    } else {
        printf("Queue kosong.\n");
    }
}