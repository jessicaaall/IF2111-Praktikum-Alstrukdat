// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 3 Oktober 2022
// Topik praktikum  : Praktikum 5 - Mesin Karakter
// Deskripsi        : Menghitung jumlah kemunculan kata 'tiga' pada sebuah kata yang dapat 
//                    tersusun atas semua huruf lowercase, semua huruf uppercase, ataupun campuran


#include "hitungfrekuensi.h"


int hitungfrekuensi() {
    int count = 0;

    START();

    while (GetCC() != MARK) {
        if ((GetCC() == 'T') || (GetCC() == 't')) {
            ADV();
            
            if (((GetCC() == 'I') || (GetCC() == 'i')) && (GetCC() != MARK)) {
                ADV();

                if (((GetCC() == 'G') || (GetCC() == 'g')) && (GetCC() != MARK)) {
                    ADV();

                    if (((GetCC() == 'A') || (GetCC() == 'a')) && (GetCC() != MARK)) {
                        count += 1;
                        ADV();
                    }
                }
            }
        } else {
            ADV();
        }
    }

    return count;
}