// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 21 September 2022
// Topik praktikum  : Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Implementasi arraydin.h


#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>


ArrayDin MakeArrayDin() {
    ArrayDin arr;

    arr.A = (ElType *) malloc (InitialSize * (sizeof(ElType)));
    arr.Capacity = InitialSize;
    arr.Neff = 0;

    return arr;
}


void DeallocateArrayDin(ArrayDin *array) {
    free(array->A);
	array->Neff = 0;
	array->Capacity = 0;
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

	if (array->Capacity == array->Neff)	{ 	
		array->A = (ElType*) realloc (array->A , (array->Capacity)*sizeof(ElType)*2);
		array->Capacity = array->Capacity*2;
	}	
		
	int j;
	for (j = Length(*array)-1 ; j >= i ; j--) {
		array->A[j+1] = array->A[j];
	}
	
	array->A[i] = el;
	array->Neff += 1;
}


void InsertLast(ArrayDin *array, ElType el) {
    int indeks = Length(*array);
    InsertAt(array, el, indeks);
}


void InsertFirst(ArrayDin *array, ElType el) {
    InsertAt(array, el, 0);
}


void DeleteAt(ArrayDin *array, IdxType i) {
    int j;

    for (j=i; j<((*array).Neff)-1; j++) {
        (*array).A[j] = (*array).A[j+1];
    }
    (*array).Neff -= 1;
}


void DeleteLast(ArrayDin *array) {
    int indeks = ((*array).Neff)-1;
    DeleteAt(array, indeks);
}


void DeleteFirst(ArrayDin *array) {
    DeleteAt(array, 0);
}


void PrintArrayDin(ArrayDin array) {
    int i;

    printf("[");

    if ((array.Neff) != 0) {
        for (i=0; i<array.Neff; i++) {
            if (i == 0) {
                printf("%d", array.A[i]);
            } else {
                printf(", %d", array.A[i]);
            }
        }
    }

    printf("]\n");
}


void ReverseArrayDin(ArrayDin *array){
    ElType *temp = (ElType*) malloc ((*array).Capacity * (sizeof(ElType)));
    int i;

    for (i=0; i<(*array).Neff; i++) {
        temp[i] = (*array).A[(*array).Neff - i - 1];
    }

    (*array).A = temp;
}


ArrayDin CopyArrayDin(ArrayDin array) {
    return array;
}


IdxType SearchArrayDin(ArrayDin array, ElType el) {
    int found = 0;
    int i = 0;
    int indeks;

    while ((found == 0) && (i < array.Neff)) {
        if (array.A[i] == el) {
            found = 1;
            indeks = i;
        }
        i++;
    }

    if (found == 0) {
        return -1;
    } else {
        return indeks;
    }
}