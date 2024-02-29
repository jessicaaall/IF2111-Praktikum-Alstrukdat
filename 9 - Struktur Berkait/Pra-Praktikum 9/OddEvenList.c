// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 November 2022
// Topik praktikum  : Pra-Praktikum 9 - Struktur Berkait
// Deskripsi        : Implementasi OddEvenList.h


#include "OddEvenList.h"
#include <stdio.h>
#include <stdlib.h>


void OddEvenList(List L, List *Odd, List *Even) {
    List ganjil, genap;
    address p;
    infotype X;

    CreateEmpty(&ganjil);
    CreateEmpty(&genap);
    CreateEmpty(Odd);
    CreateEmpty(Even);

    p = First(L);
    while (p != Nil) {
        if ((Info(p) == 0) || (Info(p) % 2 == 0)) {
            InsVFirst(&genap, Info(p));
        } else {
            InsVFirst(&ganjil, Info(p));
        }
        p = Next(p);
    }

    while (!IsEmpty(ganjil)) {
        X = Max(ganjil);
        InsVFirst(Odd, X);
        DelP(&ganjil, X);
    }

    while (!IsEmpty(genap)) {
        X = Max(genap);
        InsVFirst(Even, X);
        DelP(&genap, X);
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/