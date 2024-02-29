// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 28 September 2022
// Topik praktikum  : Praktikum 4 - Array dan ADT List
// Deskripsi        : Isi array berukuran N diulang tak hingga kali.
//                    Diberikan rentang I dan r sebanyak q kali.
//                    Menghitung penjumlahan bilangan dari posisi I sampai ke posisi ke r.


#include <stdio.h>


int main() {
    int N, i, j, q;

    scanf("%d", &N);

    int arrN[N];

    for (i=0; i<N; i++) {
        scanf("%d", &(arrN[i]));
    }

    scanf("%d", &q);

    int hasil[q];
    int awal, akhir, sum;

    for (i=0; i<q; i++) {
        scanf("%d %d", &awal, &akhir);

        sum = 0;
        for (j=awal-1; j<=akhir-1; j++) {
            sum += arrN[j%N];
        }

        hasil[i] = sum;
    }

    for (i=0; i<q; i++) {
        printf("%d\n", hasil[i]);
    }

    return 0;
}