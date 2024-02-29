// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 November 2022
// Topik praktikum  : Praktikum 9 - Struktur Berkait
// Deskripsi        : Fibonacci


#include <stdio.h>
#include "listlinier.h"


int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    infotype nilai1, nilai2, i, temp;

    if (el == 0) {
        PrintInfo(fibonacci);
    } else if (el == 1) {
        scanf("%d", &nilai1);
        InsVLast(&fibonacci, nilai1);
        PrintInfo(fibonacci);
    } else {
        scanf("%d", &nilai1);
        scanf("%d", &nilai2);
        InsVLast(&fibonacci, nilai1);
        InsVLast(&fibonacci, nilai2);
        for (i = 1; i <= el-2; i++) {
            InsVLast(&fibonacci, nilai1+nilai2);
            temp = nilai1;
            nilai1 = nilai2;
            nilai2 = temp + nilai2;
        }
        PrintInfo(fibonacci);
    }

    return 0;
}