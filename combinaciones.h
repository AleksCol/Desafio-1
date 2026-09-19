#ifndef COMBINACIONES_H
#define COMBINACIONES_H

#include "tablero.h"

#define ficha_especial_jugable ficha_max

bool marcarcombinaciones(unsigned char* tablero, int filas, int columnas);
bool colapsaryrellenar(unsigned char* tablero, int filas, int columnas);
int resolvercascada(unsigned char* tablero, int filas, int columnas, int* contadorfichaespecial);


#endif