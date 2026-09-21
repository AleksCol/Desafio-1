#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "combinaciones.h"
#include "mostrar.h"
#include "estructura.h"
int main() {
    bool flagini=true;
    while (flagini){
    int filas = 0, columnas = 0;
        int meta=0;
    std::cout<<"Hola jugador para comenzar elige la meta que quieres completar, en este juego tienes que recaudar una cantidad mayor de metas para poder ganar\nComo obtenemos esas metas?\nPara obtener las metas solo debes ir haciendo combinaciones de fichas para lograr tener una probabilidad de obtener una ficha especial\n Si esta supera al número de meta ganaste\n";
    std::cout<<"Que se puede hacer con esas fichas especiales?\nPuedes agregar una fila más o una fila menos y reinicar el tablero para no quedarte estancado\npero cada vez que lo hagas perderas una ficha especial";
    std::cout<<"La primera vez que se crea el tablero tienes probabilidades de obtener puntuacion especial para superar tu meta\nAhora elige tu meta jugador:";
    std::cin>>meta;
    while(meta<=0){
        std::cout<<"La meta tiene que ser mayor a 0 Que sentido tiene una vida sin metas?";
        std::cin>>meta;
    }
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
    rellenarVacios(tablero,filas,columnas);
    int especial=0;
    especial=procesarFichasEspeciales(tablero,filas,columnas,especial);
    mostrartableroficha(tablero, filas, columnas);
    std::cout<<"tienes esta cantidad de especiales="<<especial<<"\n";

    bool flag=true;
    while (flag){
        if(especial>meta){
            std::cout<<"Felicidades has ganado esta partida. Has superado la meta de fichas especiales\nQuieres volver a jugar otra partida?\nEscribe 1 para volver a jugar\n Escribe 2 para salir";
            int pregunta;
            std::cin>>pregunta;
            while(pregunta!=1 && pregunta!=2){
                std::cout<<"Escribe 1 para volver a jugar\nEscribe 2 para salir ";
                std::cin>>pregunta;
            }
            if (pregunta==1){
                flag=false;
                delete[] tablero;
                break;
            }
            else if(pregunta==2){
                std::cout<<"gracias por jugar";
                delete[] tablero;
                return 0;

            }

        }
        std::cout<<"Por favor escribe 1 para hacer la combinación de fichas\nEscriba 2 para ver el tablero formato binario\nEscriba 3 Si quiere eliminar o agregar una fila o columna\n";
        std::cout<<"Escriba 4 si quiere salir del programa\n";
        std::cout<<"Escriba 5 si quiere volver a jugar\n";
        int control=0;
        std::cin>>control;
        switch (control) {

    case 1:
             mostrartableroficha(tablero, filas, columnas);
            int f1, c1, f2, c2;
            std::cout << "Elige las fichas que vas a escoger para intercambiar desde 1 hasta n\nFila ficha 1: ";    std::cin >> f1;
            std::cout << "Columna ficha 1: "; std::cin >> c1;
            std::cout << "Fila ficha 2: ";    std::cin >> f2;
            std::cout << "Columna ficha 2: "; std::cin >> c2;
            if (intercambiarFichas(tablero, filas, columnas, f1, c1, f2, c2)) {
                marcarcombinaciones(tablero,filas,columnas);
                rellenarVacios(tablero,filas,columnas);
                procesarFichasEspeciales(tablero,filas,columnas,especial);
                mostrartableroficha(tablero, filas, columnas);
                std::cout<<"tienes esta cantidad de especiales="<<especial<<"\n";
            }
        break;

    case 2:
        mostrartablerobinario(tablero, filas, columnas);
        break;

    case 3:
        unsigned int pregunta;
        std::cout<<"Escoge 1 para agregar fila\nEscoge 2 para eliminar fila\n";
        std::cin>>pregunta;
        switch (pregunta) {
        case 1:
            if(especial>0){
                especial--;
                std::cout<<"Estas son las fichas especiales restantes:"<<especial<<std::endl;
                agregarFila(tablero,filas,columnas);
                mostrartableroficha(tablero,filas,columnas);
                break;
                }
            else{
                std::cout<<"No tienes suficientes fichas especiales para cambiar la dimensión del tablero";
                break;}

        case 2:
            if(especial>0){
                especial--;
                std::cout<<"Estas son las fichas especiales restantes:"<<especial<<std::endl;
                eliminarFila(tablero,filas,columnas);
                mostrartableroficha(tablero,filas,columnas);
                break;
            }
            else {std::cout<<"No tienes suficientes fichas especiales para cambiar la dimensión del tablero";
                break;}

        default:
            break;
        }
        break;

    case 4:
        std::cout<<"Gracias por jugar";
        delete[] tablero;
        return 0;

        break;
    case 5:
        std::cout<<"iniciando una nueva partida\n";
        flag=false;
        break;
    default:
        break;
    }
    }}
}