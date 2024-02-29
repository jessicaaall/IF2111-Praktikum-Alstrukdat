// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 10 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Menentukan apakah dua string sama

#include <stdio.h>
#include <string.h>


int main() {

    char string1[100], string2[100];
    int karakter1, karakter2;
    int i;

    scanf("%s", string1);
    scanf("%s", string2);

    if (strlen(string1) != strlen(string2)) {
        printf("Tidak\n");
    } else {

        for (i=0; i<strlen(string1); i++) {
            karakter1 = string1[i] - '0';
            karakter2 = string2[i] - '0';

            if (((karakter1-karakter2) == 32) || ((karakter1-karakter2) == -32) || (karakter1 == karakter2)) {
                if (i == strlen(string1)-1) {
                    printf("Ya\n");
                }
            } else {
                printf("Tidak\n");
                break;
            }

        }
    }

    return 0;
}