// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Bilangan cantik 7


#include <stdio.h>

int main() {
    
    int N, M, bilcantik, i, j, temp, check;
    check = 0;

    scanf("%d", &N);

    for (i=1; i<=N; i++) {
        scanf ("%d", &M);

        bilcantik = 0;

        if (M >= 7) {
            for (j=7; j<=M; j++) {
                if (j%7 == 0) {
                    bilcantik += j;
                } else {
                    temp = j;

                    while (temp != 0) {
                        if (temp%10 == 7) {
                            check = 1;
                        }
                        temp = temp/10;

                    }

                    if (check == 1) {
                        bilcantik += j;
                        check = 0;
                    }
                }
            }
        }

        printf("%d\n", bilcantik);
    }

    return 0;
}