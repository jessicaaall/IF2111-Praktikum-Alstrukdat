// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 21 September 2022
// Topik praktikum  : Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Implementasi garis.h


#include "garis.h"
#include <stdio.h>


void MakeGARIS(POINT P1, POINT P2, GARIS *L) {
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}


void BacaGARIS(GARIS *L) {
    POINT P1, P2;
    int valid;

    do {
        valid = 1;

        BacaPOINT(&P1);
        BacaPOINT(&P2);

        if (EQ(P1,P2)) {
            printf ("Garis tidak valid\n");
            valid = 0;
        }

    } while (valid == 0);

    MakeGARIS(P1,P2,L);
}


void TulisGARIS(GARIS L) {
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}


float PanjangGARIS(GARIS L) {
    return (Panjang(PAwal(L),PAkhir(L)));
}


float Gradien(GARIS L) {
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L))));
}


boolean IsTegakLurus(GARIS L1, GARIS L2) {
    return ((Gradien(L1)*Gradien(L2)) == -1);
}


boolean IsSejajar(GARIS L1, GARIS L2) {
    return (Gradien(L1) == Gradien(L2));
}