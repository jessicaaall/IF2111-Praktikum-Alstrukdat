// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 4 September 2022
// Topik praktikum  : Pra-Praktikum 1 - Pengenalan C
// Deskripsi        : Konversi detik

#include <stdio.h>

int main() {
    int lamawaktu, jam, menit, detik;

    scanf("%d", &lamawaktu);

    jam = lamawaktu / 3600;
    menit = (lamawaktu%3600) / 60;
    detik = (lamawaktu%3600) % 60;

    printf("%d detik = %d jam %d menit %d detik\n", lamawaktu, jam, menit, detik);

    return 0;
}