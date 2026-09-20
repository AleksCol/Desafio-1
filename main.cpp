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
        std::cout<<"No se puede ingresar menos de 3 filas, tiene que ser al menos 3 ó mas"<<std::endl;
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
    marcarcombinaciones(tablero,filas,columnas);
    mostrartableroficha(tablero, filas, columnas);
    bool flag=true;
    while (flag){
        std::cout<<"Por favor escribe 1 para hacer la combinación de fichas\nEscriba 2 para ver el tablero formato binario\nEscriba 3 Si quiere eliminar o agregar una fila o columna\n";
        std::cout<<"Escriba 4 si quiere salir del programa\n";
        int control=0;
        std::cin>>control;
        switch (control) {
    case 1:

        break;

    case 2:
        mostrartablerobinario(tablero, filas, columnas);
        break;

    case 3:

        break;

    case 4:
        std::cout<<"Gracias por jugar";
        return 0;

        break;
    default:
        break;
    }
    }
}