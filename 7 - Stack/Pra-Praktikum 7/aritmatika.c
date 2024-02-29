// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 21 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - Stack
// Deskripsi        : Implementasi aritmatika.h


#include "aritmatika.h"


boolean isOperator(char input) {
    return ((input == '+') || (input == '-') || (input == '*') || (input == '/'));
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/


int hitung(int angka1, int angka2, char op) {
    if (op == '+') {
        return (angka1 + angka2);
    } else if (op == '-') {
        return (angka1 - angka2);
    } else if (op == '*') {
        return (angka1 * angka2);
    } else if (op == '/') {
        return (angka1 / angka2);
    }
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/


int eval(char *input, int length) {

    Stack s;
    int i, angka, op1, op2, hasil;

    CreateEmpty(&s);

    for (i=0; i<length; i++) {
        if (!(isOperator(input[i]))) {
            angka = input[i] - '0';
            Push(&s, angka);
        } else {
            Pop(&s, &op2);
            Pop(&s, &op1);
            hasil = hitung(op1, op2, input[i]);
            Push(&s, hasil);
        }
    }

    return (InfoTop(s));
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/