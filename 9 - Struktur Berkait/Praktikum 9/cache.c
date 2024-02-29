// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Cache


#include "listlinier.h"
#include <stdio.h>


int main() {
    int N, Q, i, X;
    address p;
    List cache;

    CreateEmpty(&cache);

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        InsVLast(&cache, i);
    }

    scanf("%d", &Q);

    for (i = 0; i < Q; i++) {
        scanf("%d", &X);

        p = Search(cache, X);

        if (p != Nil) {
            DelP(&cache, X);
            InsVFirst(&cache, X);
            printf("hit ");
            PrintInfo(cache);
            printf("\n");
        } else {
            DelLast(&cache, &p);
            InsVFirst(&cache, X);
            printf("miss ");
            PrintInfo(cache);
            printf("\n");
        }
    }

    return 0;
}