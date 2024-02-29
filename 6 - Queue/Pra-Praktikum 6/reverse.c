// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 14 Oktober 2022
// Topik praktikum  : Pra-Praktikum 6 - Queue
// Deskripsi        : Implementasi reverse.h


#include "reverse.h"


void transferReverse(Queue* q1, Queue* q2) {
    IdxType i;
    ElType el;
    int panjang;

    panjang = Length(*q1);

    for (i=0; i<panjang; i++) {
        el = (*q1).Tab[(*q1).TAIL];

        if (Length(*q1) == 1) {
            (*q1).HEAD = NIL;
            (*q1).TAIL = NIL;
        } else {
            if ((*q1).TAIL == 0) {
                (*q1).TAIL = (*q1).MaxEl - 1;
            } else {
                (*q1).TAIL -= 1;
            }
        }

        Push(q2, el);
    }

}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik