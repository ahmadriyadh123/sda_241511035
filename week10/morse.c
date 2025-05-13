#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morse.h"

const char CHAR_SET[MAX_CHAR] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};

/***************************/
/*     Pembuatan tree      */
/***************************/
void CreateTree(Isi_Tree T)
{
    for (int i = 0; i < jml_maks; i++)
    {
        T[i].info = ' ';
        T[i].leftChild = -1;
        T[i].rightChild = -1;
        strcpy(T[i].morseCode, "");
    }
}

/***************************/
/*    Pemeriksaan kosong   */
/***************************/
boolean IsEmpty(Isi_Tree P)
{
    return (P[1].info == nil);
}

/***************************/
/*        Traversal        */
/***************************/
void PreOrder(Isi_Tree P, int idx)
{
    if (idx != -1)
    {
        if (P[idx].info != ' ' && P[idx].info != '\0')
        {
            printf("%c => %s\n", P[idx].info, P[idx].morseCode);
        }
        PreOrder(P, P[idx].leftChild);
        PreOrder(P, P[idx].rightChild);
    }
}

void InOrder(Isi_Tree P, int idx)
{
    if (idx != -1)
    {
        InOrder(P, P[idx].leftChild);
        if (P[idx].info != ' ' && P[idx].info != '\0')
        {
            printf("%c => %s\n", P[idx].info, P[idx].morseCode);
        }
        InOrder(P, P[idx].rightChild);
    }
}

void PostOrder(Isi_Tree P, int idx)
{
    if (idx != -1)
    {
        PostOrder(P, P[idx].leftChild);
        PostOrder(P, P[idx].rightChild);
        if (P[idx].info != ' ' && P[idx].info != '\0')
        {
            printf("%c => %s\n", P[idx].info, P[idx].morseCode);
        }
    }
}

void LevelOrder(Isi_Tree P, int Maks_node)
{
    for (int i = 0; i <= Maks_node; i++)
    {
        if (P[i].info != ' ')
        {
            printf("%c ", P[i].info);
        }
    }
    printf("\n");
}

void BuildMorseTree(Isi_Tree T)
{
    CreateTree(T);

    infotype urutanLevelOrder[jml_maks + 1] = {
        '*', 'A', 'B', 'C', 'E', 'D', 'F', 'G', 'I', 'K', 'M', 'H', 'J', 'L', 'N', 'O', 'Q',
        ' ', 'S', 'U', 'W', 'Y', '1', 'P', 'R', 'T', ' ', 'V', ' ', 'X', 'Z', ' ',
        '3', ' ', '5', ' ', ' ', '7', ' ', ' ', '9', ' ', ' ', ' ', ' ', '_', '2', ' ', ' ',
        ' ', '4', ' ', ' ', '6', ' ', ' ', ' ', '8', ' ', '0'};

    T[0].info = urutanLevelOrder[0];
    strcpy(T[0].morseCode, "");

    for (int i = 1; i <= jml_maks; i++)
    {
        if (urutanLevelOrder[i] == ' ')
            continue;

        T[i].info = urutanLevelOrder[i];

        address parentIdx = (i - 1) / 2;

        if (i % 2 == 1)
        {
            T[parentIdx].leftChild = i;
            strcpy(T[i].morseCode, T[parentIdx].morseCode);
            strcat(T[i].morseCode, ".");
        }
        else
        {
            T[parentIdx].rightChild = i;
            strcpy(T[i].morseCode, T[parentIdx].morseCode);
            strcat(T[i].morseCode, "-");
        }
    }
}

void ConvertToMorse(Isi_Tree T, char *input, char *output)
{
    output[0] = '\0';

    for (int i = 0; input[i] != '\0'; i++)
    {
        char currentChar = input[i];

        for (int j = 0; j <= jml_maks; j++)
        {
            if (T[j].info == currentChar)
            {
                strcat(output, T[j].morseCode);
                strcat(output, "/");
                break;
            }
        }
    }
}

void ConvertMorseToText(Isi_Tree T, char *input, char *output) {
    output[0] = '\0';  
    
    char buffer[10];  
    int bufIdx = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != '/') {
            buffer[bufIdx++] = input[i]; 
        } else {
            buffer[bufIdx] = '\0';  
            
            for (int j = 0; j <= jml_maks; j++) {
                if (strcmp(T[j].morseCode, buffer) == 0) {
                    strncat(output, &T[j].info, 1);  
                    break;
                }
            }
            
            bufIdx = 0; 
        }
    }

    if (bufIdx > 0) {
        buffer[bufIdx] = '\0';
        for (int j = 0; j <= jml_maks; j++) {
            if (strcmp(T[j].morseCode, buffer) == 0) {
                strncat(output, &T[j].info, 1);
                break;
            }
        }
    }
}

/***************************/
/* Cetak Pohon */
/***************************/
void PrintTree(Isi_Tree T)
{

    nbtree sortedNodes[jml_maks + 1];
    int count = 0;

    for (int i = 0; i <= jml_maks; i++)
    {
        if (T[i].info != ' ' && T[i].info != '*' && T[i].info != '\0')
        {
            sortedNodes[count++] = T[i];
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (sortedNodes[i].info > sortedNodes[j].info)
            {
                nbtree temp = sortedNodes[i];
                sortedNodes[i] = sortedNodes[j];
                sortedNodes[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%c => %s\n", sortedNodes[i].info, sortedNodes[i].morseCode);
    }
}

void TampilkanMenu()
{
    printf("\n=== MENU TREE MORSE ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Mengubah teks ke morse\n");
    printf("7. Mengubah morse ke teks\n");
    printf("8. Keluar\n");
}