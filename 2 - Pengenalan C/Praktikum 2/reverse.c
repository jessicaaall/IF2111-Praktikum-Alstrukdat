// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Reverse bilangan integer positif


#include <stdio.h>

int main() {

    int bilangan;

    scanf ("%d", &bilangan);

    do {
        printf("%d", (bilangan%10));
        bilangan /= 10;
    } while (bilangan != 0);

    printf ("\n");

    return 0;
}