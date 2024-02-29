// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 5 November 2022
// Topik praktikum  : Pra-Praktikum 9 - Struktur Berkait
// Deskripsi        : Implementasi listlinier.h


#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong */


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */


/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    ElmtList *p = (ElmtList *) malloc (sizeof(ElmtList));
    if (p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */


void Dealokasi (address *P) {
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    address p = First(L);
    int found = 0;

    while ((p != Nil) && (found == 0)) {
        if (Info(p) == X) {
            found = 1;
        } else {
            p = Next(p);
        }
    }

    return p;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    address p;

    p = Alokasi(X);
    if (p != Nil) {
        Next(p) = First(*L);
        First(*L) = p;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */


void InsVLast (List *L, infotype X) {
    address p;

    p = Alokasi(X);

    if (p != Nil) {
        InsertLast(L, p);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X) {
    address p;

    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */


void DelVLast (List *L, infotype *X) {
    address p;

    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */


void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */


void InsertLast (List *L, address P) {
    address last;

    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */


void DelP (List *L, infotype X) {
    address P, Prec;

    P = Search(*L, X);
    Prec = First(*L);

    if (P != Nil) {
        if (P == Prec) {
            DelFirst(L, &P);
        } else {
            while (Next(Prec) != P) {
                Prec = Next(Prec);
            }
            DelAfter(L, &P, Prec);
        }
    }
    Dealokasi(&P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */


void DelLast (List *L, address *P) {
    address prec, last;

    last = First(*L);
    prec = Nil;

    while (Next(last) != Nil) {
        prec = last;
        last = Next(last);
    }
    *P = last;

    if (prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(prec) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */


void DelAfter (List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
    }
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    address p;

    printf("[");
    if (!IsEmpty(L)) {
        p = First(L);
        while (p != Nil) {
            printf("%d", Info(p));
            p = Next(p);
            if (p != Nil) {
                printf(",");
            }
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */


int NbElmt (List L) {
    address p;
    int count = 0;

    p = First(L);
    while (p != Nil) {
        count++;
        p = Next(p);
    }

    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L) {
    address p;
    infotype max;

    p = Next(First(L));
    max = Info(First(L));

    while (p != Nil) {
        if (Info(p) > max) {
            max = Info(p);
        }
        p = Next(p);
    }

    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */


address AdrMax (List L) {
    address p;

    p = Search(L, Max(L));

    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */


infotype Min (List L) {
    address p;
    infotype min;

    p = Next(First(L));
    min = Info(First(L));

    while (p != Nil) {
        if (Info(p) < min) {
            min = Info(p);
        }
        p = Next(p);
    }

    return min;
}
/* Mengirimkan nilai info(P) yang minimum */


address AdrMin (List L) {
    address p;

    p = Search(L, Min(L));

    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */


float Average (List L) {
    address p;
    float sum = 0;
    int count = 0;

    p = First(L);

    while (p != Nil) {
        sum += Info(p);
        count++;
        p = Next(p);
    }

    return (sum/count);
}
/* Mengirimkan nilai rata-rata info(P) */


/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L) {
    address p, prec, last;

    p = First(*L);
    prec = Nil;
    last = Nil;

    while (p != Nil) {
        last = p;
        p = Next(p);
        Next(last) = prec;
        prec = last;
    }
    First(*L) = last;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */


void Konkat1 (List *L1, List *L2, List *L3) {
    address p;

    CreateEmpty(L3);

    while (!IsEmpty(*L1)) {
        DelFirst(L1, &p);
        InsertLast(L3, p);
    }

    while (!IsEmpty(*L2)) {
        DelFirst(L2, &p);
        InsertLast(L3, p);
    }
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */