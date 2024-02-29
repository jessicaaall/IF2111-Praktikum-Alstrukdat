// NIM              : 18221073
// Nama             : Jessica
// Tanggal          : 18 September 2022
// Topik praktikum  : Pra-Praktikum 3 - Pointer dan Array Dinamik
// Deskripsi        : Implementasi point.h


#include "point.h"
#include <stdio.h>
#include <math.h>


POINT MakePOINT(float X, float Y) {
    POINT p;

    Absis(p) = X;
    Ordinat(p) = Y;

    return p;
}

void BacaPOINT (POINT * p) {
    float x, y;

    scanf ("%f %f", &x, &y);
    *p = MakePOINT(x,y);
}

void TulisPOINT (POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2) {
    return ((Absis(P1) != Absis(P2)) && (Ordinat(P1) != Ordinat(P2)));
}

boolean IsOrigin (POINT P) {
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P) {
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    if ((Absis(P) > 0) && (Ordinat(P) > 0))
        return 1;
    else if ((Absis(P) < 0) && (Ordinat(P) > 0))
        return 2;
    else if ((Absis(P) < 0) && (Ordinat(P) < 0))
        return 3;
    else if ((Absis(P) > 0) && (Ordinat(P) < 0))
        return 4;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;

    return P;
}

void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

float Jarak0 (POINT P) {
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2) {
    float xP1toP2, yP1toP2;

    xP1toP2 = Absis(P1) - Absis(P2);
    yP1toP2 = Ordinat(P1) - Ordinat(P2);

    return sqrt((xP1toP2*xP1toP2) + (yP1toP2*yP1toP2));
}