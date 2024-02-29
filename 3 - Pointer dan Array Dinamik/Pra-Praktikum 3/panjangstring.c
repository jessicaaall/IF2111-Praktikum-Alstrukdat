// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Implementasi fungsi panjangString


#include "panjangstring.h"

int panjangString(char* kata) {
    int i = 0;

    while (kata[i] != '\0') {
        i += 1;
    }

    return i;
}