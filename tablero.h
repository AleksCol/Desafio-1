#ifndef TABLERO_H
#define TABLERO_H

//este es el dominio de los valores de 3 bit (0....7):6 fichas jugables + 2 estados internos.
#define bits_por_ficha 3
#define ficha_min 0
#define ficha_max 5
#define estado_especial 6
#define estado_libre 7

int calcularBytesNecesarios(int filas, int columnas);
unsigned char* crearTablero(int filas, int columnas);
unsigned char leerFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna);
void escribirFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna, unsigned char valor);





#endif // TABLERO_H