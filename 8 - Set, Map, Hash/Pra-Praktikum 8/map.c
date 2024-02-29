// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 28 Oktober 2022
// Topik praktikum  : Pra-Praktikum 8 - Set, Map, dan Hash
// Deskripsi        : Implementasi map.h


#include "map.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M) {
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M) {
    return (M.Count == Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */


boolean IsFull(Map M) {
    return (M.Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */


/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k) {
    int i = 0, found = 0;
    valuetype nilai;

    while ((i < M.Count) && (found == 0)) {
        if (M.Elements[i].Key == k) {
            nilai = M.Elements[i].Value;
            found = 1;
        }
        i++;
    }

    if (found == 1) {
        return nilai;
    } else {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */


void Insert(Map *M, keytype k, valuetype v) {
    if (!IsMember(*M, k)) {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */


void Delete(Map *M, keytype k) {
    int i = 0, found = 0, idx;

    while ((i < (*M).Count) && (found == 0)) {
        if ((*M).Elements[i].Key == k) {
            idx = i;
            found = 1;
        }
        i++;
    }

    if (found == 1) {
        if (((*M).Count != 1) && (idx != (*M).Count-1)) {
            for (i = idx+1; i < (*M).Count; i++) {
                (*M).Elements[i-1].Key = (*M).Elements[i].Key;
                (*M).Elements[i-1].Value = (*M).Elements[i].Value;
            }
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */


boolean IsMember(Map M, keytype k) {
    int i = 0, found = 0;

    while ((i < M.Count) && (found == 0)) {
        if (M.Elements[i].Key == k) {
            found = 1;
        }
        i++;
    }

    return (found == 1);
}
/* Mengembalikan true jika k adalah member dari M */