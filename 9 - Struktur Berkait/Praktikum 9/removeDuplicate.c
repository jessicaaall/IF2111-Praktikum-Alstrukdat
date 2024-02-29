// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Implementasi removeDuplicate.h


#include "removeDuplicate.h"


List removeDuplicate(List l) {
    List newL;
    CreateEmpty(&newL);

    address p;
    infotype X;

    while (!IsEmpty(l)) {
        DelVFirst(&l, &X);

        p = Search(newL, X);

        if (p == Nil) {
            InsVLast(&newL, X);
        }
    }

    return newL;
}

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/