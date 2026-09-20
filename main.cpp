#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "combinaciones.h"
#include "mostrar.h"
#include "estructura.h"
int main() {
    int filas = 0, columnas = 0;
    std::cout << "Ingresa filas: ";
    std::cin >> filas;
    while(filas<=0){
        std::cout<<"No se puede ingresar menos de 3 filas, tiene que ser al menos 3 ó mas"<<std::endl; // se tiene que ingresar 3 ó mas filas porque se crashea XD, Ahora reviso el por qué
        std:: cin>>filas;
    }
    std::cout << "Ingresa columnas: ";
    std::cin >> columnas;
    while(columnas<=0){
        std::cout<<"No se puede ingresar menos de 0 columnas, tiene que ser al menos 1"<<std::endl;
            std:: cin>>columnas;
    }
    int totalBits      = filas * columnas * 3;      //Borramos total bytes ya que, aunque queriamos tener memoria demás por si de pronto llegase a haber bits sobrantes y quisieramos hacer algo con ellos, ocasionaba que no se pudiese crear matrices con menos de 3 filas
    unsigned char* tablero = new unsigned char[totalBits];
    for (int i = 0; i < totalBits; i++) tablero[i] = 0;
    srand(time(0));
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            asignarficha(tablero, f, c, rand() % 6, columnas);
        }
    }
    std::cout << "\n=== TABLERO ===" << std::endl;
    mostrartablerobinario(tablero, filas, columnas);
    mostrartableroficha(tablero, filas, columnas);
    delete[] tablero;
    tablero = nullptr;
    return 0;
}