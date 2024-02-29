// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 21 Oktober 2022
// Topik praktikum  : Pra-Praktikum 7 - Stack
// Deskripsi        : Memeriksa apakah sebuah stack merupakan stack yang palindrom atau tidak
//                    Palindrom merupakan sebuah kata, bilangan, frasa, atau susunan karakter
//                    lain yang serupa jika dibaca dengaan urutan terbalik ataupun tidak


#include "stack.h"
#include <stdio.h>


int main() {
    
    int n, sama;
    Stack s, s1, s2;
    infotype x, x1, x2;

    CreateEmpty(&s);
    CreateEmpty(&s1);
    CreateEmpty(&s2);

    do {
        scanf("%d", &n);

        if (n != 0) {
            Push(&s, n);
            Push(&s1, n);
        }

    } while (n != 0);

    while (Top(s) != Nil) {
        Pop(&s, &x);
        Push(&s2, x);
    }

    if (IsEmpty(s1)) {
        printf("Stack kosong\n");
    } else {
        sama = 1;

        while ((Top(s1) != Nil) && (sama == 1)) {
            Pop(&s1, &x1);
            Pop(&s2, &x2);

            if (x1 != x2) {
                sama = 0;
            }
        }

        if (sama == 1) {
            printf("Palindrom\n");
        } else {
            printf("Bukan Palindrom\n");
        }
    }

    return 0;
}