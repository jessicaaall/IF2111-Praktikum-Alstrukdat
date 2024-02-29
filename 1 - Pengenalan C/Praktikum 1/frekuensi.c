// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 September 2022
// Topik praktikum  : Praktikum 1 - Pengenalan C
// Deskripsi        : Bilangan subset genap

#include <stdio.h>
#include <string.h>

int main() {
    char kata[10], karakter;
    int number[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, angka;

    scanf("%s", kata);

    for (i=0;i<strlen(kata);i++) {
        karakter = kata[i];

        if (48 <= ((int) karakter) <= 56) {
            angka = karakter - '0';
            number[angka]+=1;
        }
    }

    for (i=0;i<10;i++) {
        printf("%d", number[i]);
    }

    printf("\n");
    
    return 0;
}