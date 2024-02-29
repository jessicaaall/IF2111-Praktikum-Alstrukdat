// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 26 Oktober 2022
// Topik praktikum  : Praktikum 7 - Stack
// Deskripsi        : Pengurangan dua buah string yang merupakan integer besar (big integer) positif atau 0


#include "stack.h"
#include <stdio.h>


int panjang(char *s) {
    int i = 0, count = 0;

    while (s[i] != '\0') {
        count++;
        i++;
    }
    
    return count;
}


void toStack (Stack *st, char *s) {
    int angka, i = 0;

    while (s[i] != '\0') {
        angka = s[i] - '0';
        Push(st, angka);
        i++;
    }
}


void printStack (Stack st) {
    infotype el;

    while (!IsEmpty(st)) {
        printf("%d", InfoTop(st));
        Pop(&st, &el);
    }
    printf("\n");
}


void substract(Stack st1, Stack st2, Stack *st) {
    infotype top1, top2, currentTop;

    while ((!IsEmpty(st1)) || (!IsEmpty(st2))) {
        if (!IsEmpty(st2)) {
            Pop(&st1, &top1);
            Pop(&st2, &top2);

            if (top1 < top2) {
                Pop(&st1, &currentTop);
                currentTop -= 1;
                Push(&st1, currentTop);
                top1 += 10;
            }
            Push(st, top1-top2);
        }
        else {
            Push(st, InfoTop(st1));
            Pop(&st1, &top1);
        }
    }

    while ((!IsEmpty(*st)) && (InfoTop(*st) == 0)) {
        Pop(st, &currentTop);
    }

    if (IsEmpty(*st)) {
        Push(st, 0);
    }
}


int main() {
    char s1[100], s2[100];
    Stack st1, st2, st;
    int lens1, lens2;
    int bigger = 1, i = 0, found = 0;

    CreateEmpty(&st1);
    CreateEmpty(&st2);
    CreateEmpty(&st);

    scanf("%s", s1);
    scanf("%s", s2);

    lens1 = panjang(s1);
    lens2 = panjang(s2);

    if (lens1 < lens2) {
        bigger = 2;
    } else if (lens1 == lens2) {
        while ((i < lens1) && (found == 0)) {
            if (s1[i] > s2[i]) {
                bigger = 1;
                found = 1;
            } else if (s1[i] < s2[i]) {
                bigger = 2;
                found = 1;
            }
            i++;
        }
    }

    toStack(&st1, s1);
    toStack(&st2, s2);

    if (bigger == 1) {
        substract(st1, st2, &st);
    } else {
        printf("-");
        substract(st2, st1, &st);
    }

    printStack(st);

    return 0;
}