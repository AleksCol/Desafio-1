#ifndef TABLERO_H
#define TABLERO_H

#endif // TABLERO_H

int calcularBytesNecesarios(int filas, int columnas);
unsigned char* crearTablero(int filas, int columnas);
unsigned char leerFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna);
void escribirFicha(unsigned char* tablero, int filas, int columnas, int fila, int columna, unsigned char valor);