// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Implementasi arraydin.h


#include "arraydin.h"
#include <stdlib.h>


ArrayDin MakeArrayDin() {
    ArrayDin arr;

    arr.A = (ElType *) malloc (InitialSize * (sizeof(ElType)));
    arr.Capacity = InitialSize;
    arr.Neff = 0;

    return arr;
}

void DeallocateArrayDin(ArrayDin *array) {
    free((*array).A);
    (*array).Capacity = 0;
    (*array).Neff = 0;
}

boolean IsEmpty(ArrayDin array) {
    return (array.Neff == 0);
}

int Length(ArrayDin array) {
    return (array.Neff);
}

ElType Get(ArrayDin array, IdxType i) {
    return (array.A[i]);
}

int GetCapacity(ArrayDin array) {
    return (array.Capacity);
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) {
    int j;
    
    if (((*array).Capacity) == ((*array).Neff)) {
        (*array).A = realloc ((*array).A, ((*array).Capacity)*(sizeof(ElType)*2));
    }
    
    for (j=((*array).Neff)-1; j>=i; j--) {
        (*array).A[j+1] = (*array).A[j];
    }
    (*array).A[i] = el;
    (*array).Neff += 1;
}

void DeleteAt(ArrayDin *array, IdxType i) {
    int j;

    for (j=i; j<(*array).Neff; j++) {
        (*array).A[j] = (*array).A[j+1];
    }
    (*array).Neff -= 1;
}