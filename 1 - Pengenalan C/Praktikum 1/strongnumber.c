// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 September 2022
// Topik praktikum  : Praktikum 1 - Pengenalan C
// Deskripsi        : Cek strong number

#include <stdio.h>

int main () {
    int number, angka, x, i, faktorial, sum;

    scanf("%d", &number);

    sum = 0;
    angka = number;

    do {
        x = angka%10;

        faktorial = 1;

        for (i=x;i>0;i--) {
            faktorial *= i;
        }

        sum += faktorial;
        angka = angka/10;

    } while (angka != 0);


    if (sum == number) {
        printf("Y\n"); 
    } else {
        printf("N\n");
    }


    return 0;
}