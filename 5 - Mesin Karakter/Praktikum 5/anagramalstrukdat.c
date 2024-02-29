// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 3 Oktober 2022
// Topik praktikum  : Praktikum 5 - Mesin Karakter
// Deskripsi        : Menghitung jumlah kata yang bersifat anagram alstrukdat


#include "anagramalstrukdat.h"


/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string) {
    int i = 0;

    while (string[i] != '\0') {
        i++;
    }

    return i;
}


/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command) {
    Word kata;
    int i = 0;

    while ((command[i] != '\0') && (i < NMax)) {
        kata.TabWord[i] = command[i];
        i++;
    }

    kata.Length = i;

    return kata;
}


/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2) {
    int i, j, k;
    int count1, count2, sama;
    char huruf;

    sama = 0;

    if (string1.Length == string2.Length) {
        sama = 1;

        while ((sama == 1) && (i < string1.Length)) {
            huruf = string1.TabWord[i];

            count1 = 0;
            for (j = 0; j < string1.Length; j++) {
                if (string1.TabWord[j] == huruf) {
                    count1 += 1;
                }
            }

            count2 = 0;
            for (k = 0; k < string2.Length; k++) {
                if (string2.TabWord[k] == huruf) {
                    count2 += 1;
                }
            }

            if (count1 != count2) {
                sama = 0;
            }

            i++;
        }
    }

    return (sama == 1);
}


/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek) {
    Word kata;

    kata.TabWord[0] = 'a';
    kata.TabWord[1] = 'l';
    kata.TabWord[2] = 's';
    kata.TabWord[3] = 't';
    kata.TabWord[4] = 'r';
    kata.TabWord[5] = 'u';
    kata.TabWord[6] = 'k';
    kata.TabWord[7] = 'd';
    kata.TabWord[8] = 'a';
    kata.TabWord[9] = 't';

    kata.Length = 10;

    *frek = 0;

    STARTWORD();
    while (!(isEndWord())) {
        if (isAnagram(kata, currentWord)) {
            *frek += 1;
        }
        ADVWORD();
    }
}
