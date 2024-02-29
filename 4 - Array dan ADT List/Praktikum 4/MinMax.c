// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 26 September 2022
// Topik praktikum  : Praktikum 4 - Array dan ADT List
// Deskripsi        : Implementasi MinMax.h


#include "MinMax.h"


List MinMax(List L) {
    int i, min, max, countmin, countmax;

    min = L.A[FirstIdx(L)];
    max = L.A[FirstIdx(L)];

    for (i=FirstIdx(L)+1; i<=LastIdx(L); i++) {
        if (min > L.A[i]) {
            min = L.A[i];
        }
        if (max < L.A[i]) {
            max = L.A[i];
        }
    }

    countmin = 0;
    countmax = 0;

    for (i=FirstIdx(L); i<=LastIdx(L); i++) {
        if (L.A[i] == min) {
            countmin += 1;
            DeleteAt(&L, i);
        }
        if (L.A[i] == max) {
            countmax += 1;
            DeleteAt(&L, i);
        }
    }

    for (i=0; i<countmin; i++) {
        InsertLast(&L, min);
    }

    for (i=0; i<countmax; i++) {
        InsertLast(&L, max);
    }

    return L;
}