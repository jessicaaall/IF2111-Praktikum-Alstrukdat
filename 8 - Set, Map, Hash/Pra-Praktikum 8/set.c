// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 28 Oktober 2022
// Topik praktikum  : Pra-Praktikum 8 - Set, Map, dan Hash
// Deskripsi        : Implementasi set.h


#include "set.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S) {
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S) {
    return (S.Count == Nil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */


boolean IsFull(Set S) {
    return (S.Count == MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */


/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt) {
    if (!IsMember(*S, Elmt)) {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */


void Delete(Set *S, infotype Elmt) {
    int i = 0, found = 0, idx;

    while ((i < (*S).Count) && (found == 0)) {
        if ((*S).Elements[i] == Elmt) {
            idx = i;
            found = 1;
        }
        i++;
    }

    if (found == 1) {
        if (((*S).Count != 1) && (idx != (*S).Count-1)) {
            for (i = idx+1; i < (*S).Count; i++) {
                (*S).Elements[i-1] = (*S).Elements[i];
            }
        }
        (*S).Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */


boolean IsMember(Set S, infotype Elmt) {
    int i = 0, found = 0;
    
    if (!IsEmpty(S)) {
        while ((i < S.Count) && (found == 0)) {
            if (S.Elements[i] == Elmt) {
                found = 1;
            }
            i++;
        }
    }

    return (found == 1);
}
/* Mengembalikan true jika Elmt adalah member dari S */