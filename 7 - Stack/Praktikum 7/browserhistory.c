// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 26 Oktober 2022
// Topik praktikum  : Praktikum 7 - Stack
// Deskripsi        : Implementasi browserhistory.h


#include "browserhistory.h"


void browserHistoryVisit(Stack *openedTab, Stack *history, char *url) {
    Push(openedTab, url);
    browserHistoryFree(history);
}
/**
 * Menambahkan url ke openedTab
 * I.S. openedTab mungkin kosong, tabel penampung elemen stack TIDAK penuh
 * F.S. url menjadi TOP yang baru, TOP bertambah 1, history kosong
 */


char *currentUrl(Stack *openedTab) {
    return (InfoTop(*openedTab));
}
/**
 * Mengembalikan url yang sedang dibuka
 * I.S. openedTab tidak mungkin kosong
 * F.S. url adalah nilai elemen TOP yang lama
 */


char *browserHistoryBack(Stack *openedTab, Stack *history, int steps) {
    int i;
    infotype el;

    if (IsEmpty(*openedTab)) {
        return NULL;
    } else {
        for (i = 0; i < steps; i++) {
            Push(history, InfoTop(*openedTab));
            Pop(openedTab, &el);
        }
        return InfoTop(*openedTab);
    }
}
/**
 * Mengembalikan url yang sedang dibuka setelah kembali ke sebelumnya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP berkurang 1
 */


char *browserHistoryForward(Stack *openedTab, Stack *history, int steps) {
    int i;
    infotype el;

    if (IsEmpty(*history)) {
        return NULL;
    } else {
        for (i = 0; i < steps; i++) {
            Push(openedTab, InfoTop(*history));
            Pop(history, &el);
        }
        return InfoTop(*openedTab);
    }
}
/**
 * Mengembalikan url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak langkah yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */


void browserHistoryFree(Stack *history) {
    while (!IsEmpty(*history)) {
        Pop(history, &InfoTop(*history));
    }
}
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */