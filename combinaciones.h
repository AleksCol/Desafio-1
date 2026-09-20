#ifndef COMBINACIONES_H
#define COMBINACIONES_H
#include "iostream"
#include "estructura.h"
#include "tablero.h"

#define ficha_especial_jugable ficha_max

bool marcarcombinaciones(unsigned char* tablero, int filas, int columnas);
bool colapsaryrellenar(unsigned char* tablero, int filas, int columnas);
int resolvercascada(unsigned char* tablero, int filas, int columnas, int* contadorfichaespecial);
bool intercambiarFichas(unsigned char* tablero, int filas, int columnas,int f1, int c1, int f2, int c2);

#endif