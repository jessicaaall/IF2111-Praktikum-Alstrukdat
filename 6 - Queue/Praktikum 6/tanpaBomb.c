// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 17 Oktober 2022
// Topik praktikum  : Praktikum 6 - Queue
// Deskripsi        : Implementasi tanpaBomb.h


#include "tanpaBomb.h"


Queue tanpaBomb(Queue queue, ElType bomb) {
    Queue Q;
    ElType el;
    int i;

    CreateQueue(&Q);

    if (!(isEmpty(queue))) {
        if (IDX_HEAD(queue) <= IDX_TAIL(queue)) {
            for (i=IDX_HEAD(queue); i<=IDX_TAIL(queue); i++) {
                dequeue(&queue, &el);
                if (el != bomb) {
                    enqueue(&queue, el);
                }
            }
        } else {
            for (i=IDX_HEAD(queue); i<CAPACITY; i++) {
                dequeue(&queue, &el);
                if (el != bomb) {
                    enqueue(&queue, el);
                }
            }
            for (i=0; i<=IDX_TAIL(queue); i++) {
                dequeue(&queue, &el);
                if (el != bomb) {
                    enqueue(&queue, el);
                }
            }
        }
    }

    return Q;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/