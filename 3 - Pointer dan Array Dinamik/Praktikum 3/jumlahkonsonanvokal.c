// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 21 September 2022
// Topik praktikum  : Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Menghitung jumlah huruf konsonan dan huruf vokal yang terdapat di suatu kalimat


#include "jumlahkonsonanvokal.h"


int isAlphabet(huruf) {
    int ascii;
    int alphabet = 0;

    ascii = (int) huruf;

    if (((ascii>=65) && (ascii<=90)) || ((ascii>=97) && (ascii<=122))) {
        if ((ascii!=65) && (ascii!=97) && (ascii!=69) && (ascii!=101) && (ascii!=73) && (ascii!=105) && (ascii!=79) && (ascii!=111) && (ascii!=85) && (ascii!=117)) {
            alphabet = 1;
        }
    }

    return alphabet;
}

int isVowel(huruf) {
    int ascii;
    int vowel = 0;

    ascii = (int) huruf;

    if ((ascii==65) || (ascii==97) || (ascii==69) || (ascii==101) || (ascii==73) || (ascii==105) || (ascii==79) || (ascii==111) || (ascii==85) || (ascii==117)) {
        vowel = 1;
    }

    return vowel;
}

void jumlahKonsonanVokal(char* kalimat, int* sumAlphabet, int* sumVowel) {
    int i = 0;

    *sumAlphabet = 0;
    *sumVowel = 0;

    while (kalimat[i] != '\0') {
        if (isAlphabet(kalimat[i]) == 1) {
            *sumAlphabet += 1;
        } else if (isVowel(kalimat[i]) == 1) {
            *sumVowel += 1;
        }
        i++;
    }
}