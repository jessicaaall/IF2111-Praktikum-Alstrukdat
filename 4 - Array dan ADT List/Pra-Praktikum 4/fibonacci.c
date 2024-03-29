// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 25 September 2022
// Topik praktikum  : Pra-raktikum 4 - Array dan ADT List
// Deskripsi        : Implementasi fibonnaci.h


#include "fibonacci.h"


// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8


// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result) {
    if ((n == 0) || (n == 1)) {
        *result = 1;
    } else {
        *result = fibonacci2(n-1) + fibonacci2(n-2);
    }
}


// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n) {
    int temp1, temp2, i;

    temp1 = 1;
    temp2 = 1;

    if ((n == 0) || (n == 1)) {
        temp1 = 1;
    } else {
        for (i=2; i<=n; i++) {
            if (i%2 == 0) {
                temp1 += temp2;
            } else {
                temp2 += temp1;
            }
        }
    }

    if (temp1 > temp2) {
        return temp1;
    } else {
        return temp2;
    }
}


// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result) {
    int i;

    if (n > 0) {
        for (i=0; i<n; i++) {
            result[i] = fibonacci2(i);
        }
    }
    result[n] = fibonacci2(n);
}