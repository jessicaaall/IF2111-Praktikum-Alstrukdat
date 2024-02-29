// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 12 September 2022
// Topik praktikum  : Praktikum 2 - Pengenalan C
// Deskripsi        : Menghitung jumlah mahasiswa lulus, indeks rata-rata, dan indeks akhir kelas

#include <stdio.h>

int main() {

    int angka, lulus;
    float valid, sum, average;
    char indeks;

    lulus = 0;
    valid = 0;
    sum =0;

    do {
        scanf("%d", &angka);

        if ((angka>=0) && (angka<=4)) {
            valid += 1;
            sum += angka;

            if (angka>=3) {
                lulus += 1;
            }
        }
    } while (angka != -999);

    if (valid == 0) {
        printf("Tidak ada data\n");
    } else {
        average = sum / valid;

        if (average == 4) (indeks='A');
        else if ((average>=3)&&(average<4)) (indeks='B');
        else if ((average>=2)&&(average<3)) (indeks='C');
        else if ((average>=1)&&(average<2)) (indeks='D');
        else (indeks='E');

        printf ("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf ("Nilai rata-rata = %.2f\n", average);
        printf ("Indeks akhir kelas = %c\n", indeks);
    }

    return 0;
}