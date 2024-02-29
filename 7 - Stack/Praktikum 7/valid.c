// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 26 Oktober 2022
// Topik praktikum  : Praktikum 7 - Stack
// Deskripsi        : Implementasi browserhistory.h


#include "valid.h"


Stack validParantheses(char* input, int length) {
    Stack simpan, valid;
    int i;

    CreateEmpty(&simpan);
    CreateEmpty(&valid);

    for (i=0; i<length; i++) {
        if (!IsEmpty(simpan)) {
            if ((input[i] == '}' && InfoTop(simpan) == '{') || (input[i] == ')' && InfoTop(simpan) == '(') || (input[i] == ']' && InfoTop(simpan) == '[')) {
                Push(&valid, InfoTop(simpan));
                Push(&valid, input[i]);
            }
            else {
                Push(&simpan, input[i]);
            }
        } else {
            Push(&simpan, input[i]);
        }
    }

    return valid;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/