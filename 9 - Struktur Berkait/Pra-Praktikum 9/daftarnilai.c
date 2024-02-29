// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 November 2022
// Topik praktikum  : Pra-Praktikum 9 - Struktur Berkait
// Deskripsi        : Daftar Nilai


#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    List L;
    infotype nilai;

    CreateEmpty(&L);

    do {
        scanf("%d", &nilai);
        
        if ((nilai >= 0) && (nilai <= 100)) {
            InsVFirst(&L, nilai);
        }
        
    } while ((nilai >= 0) && (nilai <= 100));

    if (!IsEmpty(L)) {
        printf("%d\n%d\n%d\n%.2f\n", NbElmt(L), Max(L), Min(L), Average(L));
        InversList(&L);
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    } else {
        printf("Daftar nilai kosong\n");
    }

    return 0;
}