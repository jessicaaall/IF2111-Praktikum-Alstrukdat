// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Mencetak jumlah masakan yang disajikan Ibu Gra, waktu minimal, dan waktu maksimal
//                    yang dibutuhkan pada 1 hari tertentu


#include "queue.h"
#include <stdio.h>


int main() {
    Queue Q;
    ElType el;
    int i, n;
    int waktu, countterima;
    int min, max;

    CreateQueue(&Q);

    countterima = 0;

    do {
        scanf("%d", &n);

        if (n == 1) {
            scanf("%d", &waktu);

            if ((waktu > 0) && (!(isFull(Q)))) {
                enqueue(&Q, waktu);
            }
            
        } else if ((n == 2) && (!(isEmpty(Q))) && (countterima < length(Q))) {
            countterima++;
        }

    } while (n != 0);

    min = 0;
    max = 0;

    if (countterima > 0) {
        dequeue(&Q, &el);
        min = el;
        max = el;

        if (countterima > 1) {
            for (i=0; i<countterima-1; i++) {
                dequeue(&Q, &el);

                if (min > el) {
                    min = el;
                }
                if (max < el) {
                    max = el;
                }
            }
        }
    }

    printf("%d\n", countterima);
    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}