// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 10 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Jumlah setiap digit dari integer

#include <stdio.h>


int main() {

    int angka, sum;

    scanf("%d", &angka);

    sum = 0;

    do {
        sum += angka % 10;
        angka = angka/10;

    } while (angka != 0);

    printf("%d\n", sum);

    return 0;
}