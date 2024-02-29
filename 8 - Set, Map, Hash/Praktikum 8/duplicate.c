// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 31 Oktober 2022
// Topik praktikum  : Praktikum 8 - Set, Map, dan Hash
// Deskripsi        : Implementasi duplicate.h


#include "duplicate.h"


/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize) {
    Set s;
    int i;

    CreateEmpty(&s);

    for (i = 0; i < arrSize; i++) {
        if (!IsMember(s, arr[i])) {
            Insert(&s, arr[i]);
        }
    }

    return s;
}


/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize) {
    Set s;
    int i, j, temp;

    CreateEmpty(&s);

    s = arrToSet(arr, arrSize);

    for (i = 0; i < s.Count; i++) {
        for (j = 0; j < s.Count-1; j++) {
            if (s.Elements[j+1] > s.Elements[j]) {
                temp = s.Elements[j+1];
                s.Elements[j+1] = s.Elements[j];
                s.Elements[j] = temp;
            }
        }
    }

    for (i = 0; i < s.Count; i++) {
        arrRes[i] = s.Elements[i];
    }

    *arrResSize = s.Count;
}