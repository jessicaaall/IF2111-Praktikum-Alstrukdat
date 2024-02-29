// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 September 2022
// Topik praktikum  : Praktikum 1 - Pengenalan C
// Deskripsi        : Bilangan subset genap

#include <stdio.h>


int main() {
    int bil;

    scanf("%d", &bil);

    if ((bil !=2) && ((bil % 2) == 0)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    
    return 0;
}