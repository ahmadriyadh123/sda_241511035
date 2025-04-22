/*File header untuk ADT Queue*/

#ifndef QUEUE_H
#define QUEUE_H
#include "boolean.h"
#include "spnrsll.h" //nama header disesuaikan dengan program linked list pribadi


typedef address Queue;

/* Define Queue as the head pointer to a linked list */
typedef address Queue;

/**** Additional Queue Properties ****/
typedef struct {
    Queue Front;  
    Queue Rear; 
    int MaxSize;     
    int CurrentSize;  
} DynamicQueue;

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue(DynamicQueue *Q, int MaxSize);

/*Memeriksa apakah queue kosong */
boolean IsEmpty(DynamicQueue Q);

/*Memeriksa apakah queue penuh */
boolean IsFull(DynamicQueue Q);

/*Melekukan insertion pada queue*/
void EnQueue(DynamicQueue *Q, infotype X);

/*Melakukan deletion pada queue*/
void DeQueue(DynamicQueue *Q, infotype *X);

void PrintQueue(DynamicQueue Q);;

#endif

