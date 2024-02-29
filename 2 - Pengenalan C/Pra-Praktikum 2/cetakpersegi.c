// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 10 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Mencetak sebuah persegi berdasarkan masukkan n

#include <stdio.h>


int main() {

    int n, i, j;

    scanf("%d", &n);

    for (i=1; i<=2*n-1; i++) {
        for (j=1; j<=2*n-1; j++) {
            
            if (i%2 != 0) {
                if (j%2 != 0) {
                    printf("O");
                } else {
                    printf("X");
                }
            } else {
                if (j%2 != 0) {
                    printf("X");
                } else {
                    printf("O");
                }
            }

            if (j == 2*n-1) {
                printf("\n");
            }
        
        }
    }

    return 0;
}