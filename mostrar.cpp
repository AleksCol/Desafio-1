#include "estructura.h"
#include "mostrar.h"
void mostrartableroficha(unsigned char* tablero, int filas, int columnas) {
    char simbolos[] = {'A', 'B', 'C', 'D', 'E', 'F', '-', '*'};
    unsigned int contador=1;
    for (int f = 0; f < filas; f++) {
        std::cout<<contador;
        for (int c = 0; c < columnas; c++) {
            int valor = obtenerFicha(tablero, f, c, columnas);
            std:: cout << "[" << simbolos[valor] << "]";
        }
        std::cout << std::endl;
        contador++;

    }
}

void mostrartablerobinario(unsigned char* tablero, int filas, int columnas){
    unsigned int contador=1;
    for (int f = 0; f < filas; f++) {
        std::cout<<contador;
        for (int c = 0; c < columnas; c++) {
            int valor = obtenerFicha(tablero, f, c, columnas);
            std::cout << "[";
            for (int b = 2; b >= 0; b--) {
                std::cout << ((valor >> b) & 1);
            }
            std::cout<<"]";
        }
        std::cout << std::endl;
        contador++;
    }

}