#ifndef COMBINACIONES_H
#define COMBINACIONES_H
#include "estructura.h"
#include "tablero.h"

#define ficha_especial_jugable ficha_max

bool marcarcombinaciones(unsigned char* tablero, int filas, int columnas);
bool intercambiarFichas(unsigned char* tablero, int filas, int columnas,int f1, int c1, int f2, int c2);
void rellenarVacios(unsigned char* tablero, int filas, int columnas);
int procesarFichasEspeciales(unsigned char* tablero, int filas, int columnas,int &especial);
#endif