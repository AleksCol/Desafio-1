#include "Tablero.h"
#include <cstdlib>
#include <ctime>
#include "combinaciones.h"
#include "iostream"
int calcularbytesnecesarios(int filas, int columnas, int ){
    int totalbits = filas * columnas * bits_por_ficha;
    int totalbytes = totalbits / 8;
    if (totalbits % 8 != 0) {
        totalbytes++;

    }

    return totalbytes;}

    void agregarFila(unsigned char*& tablero, int& filas, int columnas) {
        int bytesViejos = (filas * columnas * 3 + 7) / 8;
        int bytesNuevos = ((filas + 1) * columnas * 3 + 7) / 8;
        unsigned char* nuevo = new unsigned char[bytesNuevos];
        for (int i = 0; i < bytesNuevos; i++) nuevo[i] = 0;
        for (int i = 0; i < bytesViejos; i++) nuevo[i] = tablero[i];
        delete[] tablero;
        tablero = nuevo;
        filas++;
        for (int c = 0; c < columnas; c++) {
            asignarficha(tablero, filas - 1, c, rand() % 7, columnas);
        }
    }
    void eliminarFila(unsigned char*& tablero, int& filas, int columnas) {
        if (filas <= 1) {
            std::cout << "No se puede eliminar, el tablero debe tener al menos 1 fila." << std::endl;
            return;
        }
        int filasNuevas = filas - 1;
        int bytesNuevos = (filasNuevas * columnas * 3 + 7) / 8;
        unsigned char* nuevo = new unsigned char[bytesNuevos];
        for (int i = 0; i < bytesNuevos; i++) nuevo[i] = 0;
        for (int f = 0; f < filasNuevas; f++) {
            for (int c = 0; c < columnas; c++) {
                int val = obtenerFicha(tablero, f, c, columnas);
                int indice    = f * columnas + c;
                int bitInicio = indice * 3;
                for (int b = 0; b < 3; b++) {
                    int posGlobal  = bitInicio + b;
                    int indicebyte = posGlobal / 8;
                    int bitIdx     = posGlobal % 8;
                    int estadoBit  = (val >> b) & 1;
                    if (estadoBit == 1)
                        nuevo[indicebyte] |= (1 << bitIdx);
                    else
                        nuevo[indicebyte] &= ~(1 << bitIdx);
                }
            }
        }
        delete[] tablero;
        tablero = nuevo;
        filas--;
    }

