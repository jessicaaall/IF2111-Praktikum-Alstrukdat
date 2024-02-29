// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Implementasi copyqueue.h


#include "copyqueue.h"


// Menyalin queue.
void copyQueue(Queue *queueInput, Queue *queueOutput) {
    Queue Q;
    ElType el;
    int i;

    CreateQueue(&Q);

    if (!(isEmpty(*queueInput))) {
        if (IDX_HEAD(*queueInput) <= IDX_TAIL(*queueInput)) {
            for (i=IDX_HEAD(*queueInput); i<=IDX_TAIL(*queueInput); i++) {
                dequeue(queueInput, &el);
                enqueue(&Q, el);
            }
        } else {
            for (i=IDX_HEAD(*queueInput); i<CAPACITY; i++) {
                dequeue(queueInput, &el);
                enqueue(&Q, el);
            }
            for (i=0; i<=IDX_TAIL(*queueInput); i++) {
                dequeue(queueInput, &el);
                enqueue(&Q, el);
            }
        }

        if (IDX_HEAD(Q) <= IDX_TAIL(Q)) {
            for (i=IDX_HEAD(Q); i<=IDX_TAIL(Q); i++) {
                dequeue(&Q, &el);
                enqueue(queueInput, el);
                enqueue(queueOutput, el);
            }
        } else {
            for (i=IDX_HEAD(Q); i<CAPACITY; i++) {
                dequeue(&Q, &el);
                enqueue(queueInput, el);
                enqueue(queueOutput, el);
            }
            for (i=0; i<=IDX_TAIL(Q); i++) {
                dequeue(&Q, &el);
                enqueue(queueInput, el);
                enqueue(queueOutput, el);
            }
        }
    }
}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/