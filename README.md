[README.md](https://github.com/user-attachments/files/32357456/README.md)
# Desafío 1 — Sweet Crush (C++)

>  **Proyecto en desarrollo.** Este README describe el estado actual del
> repositorio y se irá actualizando a medida que avance la implementación.
> Entrega final: **18 de septiembre de 2026**.

Implementación en consola del juego Sweet Crush para el curso de Informática II.
El tablero se almacena de forma comprimida usando **bitwise** (3 bits por ficha),
en lugar de un arreglo convencional de enteros.

## Desarrolladores

- Alejandro Arce Palacios
- Santiago Ramírez Almeida

## Estado actual

- [x] Definición de la estructura bitwise del tablero (`tablero.h/.cpp`)
- [x] Creación dinámica del tablero (mínimo 3x3)
- [x] Lectura y escritura de fichas individuales
- [x] Agregar/quitar filas y columnas
- [x] Menú principal en consola (`main.cpp`)
- [x] Visualización del tablero en fichas y en binario (`mostrar.h/.cpp`)
- [ ] Detección de combinaciones — declarada en `combinaciones.h`, **en proceso de implementación/pruebas**
- [ ] Colapso y relleno tras combinación (efecto cascada) — en proceso
- [ ] Conteo y lógica completa de fichas especiales (tipo 5)
- [ ] Pruebas de bordes (tableros mínimos, combinaciones múltiples, cascadas encadenadas)
- [ ] Reporte escrito final
- [ ] Video de sustentación

## Características (una vez completado)

- Tablero dinámico con fichas comprimidas en 3 bits cada una.
- Intercambio de fichas adyacentes con detección de combinaciones de 3 o más.
- Colapso y relleno automático del tablero (cascada).
- Fichas especiales con contador de eliminación.

## Estructura del proyecto

```
Desafio-1/
├── CMakeLists.txt       # Configuración de build (CMake, C++17)
├── main.cpp             # Punto de entrada, menú y flujo del juego
├── tablero.h / .cpp      # Representación bitwise del tablero (crear, leer, escribir fichas)
├── estructura.h / .cpp   # Acceso auxiliar a fichas dentro del tablero
├── combinaciones.h / .cpp # Detección de combinaciones, colapso y cascada (en desarrollo)
└── mostrar.h / .cpp      # Presentación del tablero en pantalla (fichas y binario)
```

## Descripción de los módulos

### `tablero`
Define la codificación de cada ficha en 3 bits (`bits_por_ficha`), con valores del
0 al 5 como fichas jugables, 6 como estado especial y 7 como estado libre.
Contiene las funciones para calcular el tamaño en bytes necesario, crear el
tablero, y leer/escribir una ficha en una posición específica.

### `estructura`
Acceso auxiliar a una ficha del tablero dada su fila y columna.

### `combinaciones` *(en desarrollo)*
Módulo encargado de detectar combinaciones de 3 o más fichas iguales,
colapsar las fichas eliminadas y rellenar los espacios vacíos (cascada).
Las funciones ya están declaradas pero la lógica interna sigue en pruebas.

### `mostrar`
Módulo de solo lectura encargado de imprimir el tablero en pantalla, tanto en
su representación de fichas (números) como en su representación binaria.

### `main`
Contiene el menú principal: intercambiar fichas, agregar/quitar filas y
columnas, mostrar el tablero en binario, y el conteo de fichas especiales
eliminadas.

## Compilación

El proyecto usa **CMake** (versión mínima 3.16) y **C++17**.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Esto genera el ejecutable `Desafio`.

## Ejecución

```bash
./Desafio
```

Al iniciar, el programa solicita las dimensiones iniciales del tablero
(mínimo 3x3) y luego despliega el menú principal:

```
1. Intercambiar dos fichas adyacentes (jugar)
2. Agregar fila
3. Quitar fila
4. Agregar columna
5. Quitar columna
6. Mostrar tablero en binario
0. Salir
```

## Requisitos

- Compilador compatible con C++17
- CMake 3.16 o superior

## Curso

Informática II — Semestre 2026-2
