// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 28 Oktober 2022
// Topik praktikum  : Pra-Praktikum 8 - Set, Map, dan Hash
// Deskripsi        : Implementasi hashmap.h


#include "hashmap.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
    int i;

    for (i = 0; i < MaxEl; i++) {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }

    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi map Undefined */


/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
    return (K % MaxEl);
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */


/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
    int i = 0, found = 0;
    valuetype nilai;

    while ((i < MaxEl) && (found == 0)) {
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


void Insert(HashMap *M, keytype k, valuetype v) {
    int i = 0, found = 0;
    address idx;

    while ((i < MaxEl) && (found == 0)) {
        if ((*M).Elements[i].Key == k) {
            found = 1;
        }
        i++;
    }

    idx = Hash(k);
    
    if (found == 0) {        
        while ((*M).Elements[idx].Key != Undefined) {
            idx = Hash(idx+1);
        }
        (*M).Elements[idx].Key = k;
        (*M).Elements[idx].Value = v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing jika index sudah terisi    */