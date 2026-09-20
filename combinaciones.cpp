#include "combinaciones.h"
#include <cstdlib>
#include "estructura.h"
#include "estructura.h"
static unsigned char* crearmascara(int filas, int columnas) {

    int totalbits = filas * columnas;
    int totalbytes = totalbits / 8;
     if (totalbits %8 != 0) {
        totalbytes++;

    }

     unsigned char* mascara  = new unsigned char [totalbytes];
        for (int i = 0; i < totalbytes; i++) {
         mascara[i] = 0;

     }
     return mascara;

     //"BORRAR" Este bloque lo que hace es crear un array continuo de bits
     // el objetivo es reservar la memoria dinamica exacta para que cada bit
     // represente la casilla del tablero ocupando el menor espacio posible.

}

static void marcarenmascara(unsigned char* mascara, int columnas, int fila, int columna) {
    int indice = fila * columnas + columna;

    mascara[indice / 8] |= (1 << (7 - (indice % 8)));
}

static bool estamarcada(unsigned char* mascara, int columnas, int fila, int columna) {
    int indice = fila * columnas + columna;

    return (mascara[indice / 8] & (1 << (7 - (indice % 8)))) != 0;
}

bool marcarcombinaciones(unsigned char* tablero, int filas, int columnas){
    unsigned char* mascara = crearmascara(filas, columnas);
    bool hubocomb = false;
    for (int f = 0; f < filas; f++) {
        int c = 0;
        while (c < columnas) {
            int valorActual = obtenerFicha(tablero, f, c, columnas);

            int j = c;
            while (j < columnas && obtenerFicha(tablero, f, j, columnas) == valorActual) {
                j++;
            }
            if (j - c >= 3) {
                hubocomb = true;
                for (int k=c;k<j;k++) {
                    marcarenmascara(mascara,columnas,f,k);
                }
            }
            c=j;
        }
    }
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            if (estamarcada(mascara, columnas, f, c)) {

                asignarficha(tablero,f,c,6,columnas);
            }
        }
    }
    delete[] mascara;

    return hubocomb;
}

