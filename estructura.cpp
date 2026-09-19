#include "estructura.h"
int obtenerFicha(unsigned char* tablero, int fila, int columna, int columnas) {
    int indice    = (fila * columnas) + columna;
    int bitInicio = indice * 3;
    int valor     = 0;
    for (int b = 0; b < 3; b++) {
        int posGlobal  = bitInicio + b;
        int indicebyte = posGlobal / 8;
        int bitIdx     = posGlobal % 8;
        int estadoBit = (tablero[indicebyte] >> bitIdx) & 1;
        valor |= (estadoBit << b);
    }
    return valor;
}

void asignarficha(unsigned char* tablero, int fila, int columna, int valor, int columnas) {
    int indice    = (fila * columnas) + columna;
    int bitInicio = indice * 3;
    for (int b = 0; b < 3; b++) {
        int posGlobal  = bitInicio + b;
        int indicebyte = posGlobal / 8;
        int bitIdx     = posGlobal % 8;
        int estadoBit = (valor >> b) & 1;
        if (estadoBit == 1) {
            tablero[indicebyte] |= (1 << bitIdx);
        } else {
            tablero[indicebyte] &= ~(1 << bitIdx);
        }
    }
}