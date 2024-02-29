// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 2 Oktober 2022
// Topik praktikum  : Praktikum 5 - Mesin Karakter
// Deskripsi        : Menghitung jumlah kemunculan karakter

#include "mesinkarakter.h"
#include <stdio.h>


int hitungkarakter(char karakter) {
    int count = 0;

    START();
    while (!IsEOP()) {
        if (GetCC() == karakter) {
            count += 1;
        }
        ADV();
    }

    return count;
}