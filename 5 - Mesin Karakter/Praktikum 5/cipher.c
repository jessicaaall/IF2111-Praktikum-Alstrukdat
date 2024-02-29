// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 3 Oktober 2022
// Topik praktikum  : Praktikum 5 - Mesin Karakter
// Deskripsi        : Caesar Cipher, yaitu metode enkripsi dimana setiap karakter dari teks awal/plaintext 
//                    diganti dengan karakter lain dengan selisih tertentu dalam alfabet.
//                    Membaca sebuah pita karakter, lalu melakukan enkripsi dengan Caesar Cipher dimana 
//                    banyaknya penggeseran ditentukan dari panjang kata pertama dan pita karakter tidak
//                    mungkin kosong, kemudian mencetaknya ke layar.


#include "mesinkata.h"
#include <stdio.h>


int main() {
    int length, i;

    STARTWORD();
    length = currentWord.Length;

    while (!(isEndWord())) {
        for (i = 0; i < currentWord.Length; i++) {
            if ((currentWord.TabWord[i] >= 'A') && (currentWord.TabWord[i] <= 'Z')) {
                currentWord.TabWord[i] = ((currentWord.TabWord[i] + length - 65) % 26) + 65;
            }
            printf("%c", currentWord.TabWord[i]);
        }

        if (currentChar == MARK) {
            printf("%c", MARK);
        } else {
            printf(" ");
        }

        ADVWORD();
    }

    printf("\n");
    
    return 0;
}