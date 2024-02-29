// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 14 November 2022
// Topik praktikum  : Praktikum 10 - Variasi List Linier
// Deskripsi        : Implementasi queuelist.h


#include "queuelist.h"
#include <stdio.h>


/* Prototype manajemen memori */
void Alokasi(address *P, infotype X) {
    *P = (address) malloc (sizeof(ElmtQueue));
    if (*P != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */

void Dealokasi(address P) {
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmpty(Queue Q) {
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */

int NbElmt(Queue Q) {
    int count = 0;
    address P = Head(Q);
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/

void CreateEmpty(Queue *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/

void Enqueue(Queue *Q, infotype X) {
    address P;
    Alokasi(&P, X);
    if (P != Nil) {
        if (IsEmpty(*Q)) {
            Head(*Q) = P;
        } else {
            Next(Tail(*Q)) = P;
        }
        Tail(*Q) = P;
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */

void Dequeue(Queue *Q, infotype *X) {
    address P = Head(*Q);
    *X = InfoHead(*Q);
    Head(*Q) = Next(Head(*Q));
    if (Head(*Q) == Nil) {
        Tail(*Q) == Nil;
    }
    Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */