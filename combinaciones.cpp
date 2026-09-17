#include "combinaciones.h"
#include <cstdlib>

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