#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "combinaciones.h"
int main() {
    int filas = 0, columnas = 0;
    std::cout << "Ingresa filas: ";
    std::cin >> filas;
    while(filas<=0){
        std::cout<<"No se puede ingresar menos de 0 filas, tiene que ser al menos 1"<<std::endl;
        std:: cin>>filas;
    }
    std::cout << "Ingresa columnas: ";
    std::cin >> columnas;
    while(columnas<=0){
        std::cout<<"No se puede ingresar menos de 0 columnas, tiene que ser al menos 1"<<std::endl;
            std:: cin>>columnas;
    }
    int totalBits      = filas * columnas * 3;
    int bytesCapacidad = (totalBits + 7) / 8;
    unsigned char* tablero = new unsigned char[bytesCapacidad];
    for (int i = 0; i < bytesCapacidad; i++) tablero[i] = 0;
    // 3. Semilla aleatoria (una sola vez)
    srand(time(0));
    bool hubo = marcarcombinaciones(tablero, filas, columnas);
    // 5. Liberar memoria
    delete[] tablero;
    tablero = nullptr;
    return 0;
}