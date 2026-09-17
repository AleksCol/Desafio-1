#include "Tablero.h"

int calcularbytesnecesarios(int filas, int columnas, int ){
    int totalbits = filas * columnas * bits_por_ficha;
    int totalbytes = totalbits / 8;
    if (totalbits % 8 != 0) {
        totalbytes++;

    }

    return totalbytes;




}