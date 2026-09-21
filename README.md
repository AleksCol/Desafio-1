[README.md](https://github.com/user-attachments/files/32357456/README.md)
# Desafío 1 — Sweet Crush (C++)

Juego de combinación de fichas por consola, implementado con almacenamiento
bitwise: cada ficha ocupa solo 3 bits dentro de un arreglo de `unsigned char`,
en lugar de un entero completo por ficha.

## Desarrolladores

- Alejandro Arce Palacios
- Santiago Ramírez Almeida

## VIDEO DE YOUTUBE
[VIDEO](https://youtu.be/JQ1ZkrN1DzE)

## INFORME FINAL
[INFORME](https://docs.google.com/document/d/1TrMEv-O7tzdhXQNqllQoK55IgLpSQM_mN79ltT-dpd4/edit?usp=sharing)

## Mecánica del juego

Al iniciar, el jugador define una **meta** de fichas especiales a recolectar.
El tablero se llena aleatoriamente y el jugador intercambia fichas adyacentes
para formar combinaciones de 3 o más. Cada combinación resuelta en cascada
tiene probabilidad de generar fichas especiales (tipo 5/6), que cuentan para
la meta y también sirven como "moneda" para modificar el tamaño del tablero
(agregar o quitar una fila).

## Estructura del proyecto
Informática II — Semestre 2026-2

Desafio-1/
├── CMakeLists.txt # Configuración de build (CMake, C++17)
├── main.cpp # Menú, flujo del juego y lógica de meta
├── tablero.h / .cpp # Constantes de codificación (3 bits/ficha) + resize de filas
├── estructura.h / .cpp # Lectura y escritura de una ficha (obtenerFicha, asignarficha)
├── combinaciones.h / .cpp # Detección de combinaciones, intercambio, relleno y fichas especiales
└── mostrar.h / .cpp # Impresión del tablero en fichas y en binario


## Descripción de los módulos

### `tablero`
Define la codificación de cada ficha en 3 bits: valores 0–5 como fichas
jugables, 6 como estado especial y 7 como estado libre (vacío tras una
combinación). Contiene `agregarFila` y `eliminarFila`, que redimensionan el
tablero preservando el contenido existente.

### `estructura`
Acceso de bajo nivel a una ficha específica del tablero: `obtenerFicha` lee
los 3 bits correspondientes a una posición, `asignarficha` los escribe.

### `combinaciones`
Detecta combinaciones de 3 o más fichas iguales en fila y en columna,
marca las posiciones eliminadas como estado libre, intercambia fichas
adyacentes (`intercambiarFichas`), rellena los espacios vacíos con fichas
aleatorias (`rellenarVacios`) y convierte fichas especiales en fichas
normales sumándolas al contador de meta (`procesarFichasEspeciales`).

### `mostrar`
Módulo de solo lectura: imprime el tablero en su representación de fichas
(números) y en su representación binaria (3 bits por ficha).

### `main`
Punto de entrada. Solicita la meta y las dimensiones iniciales del tablero,
resuelve las combinaciones iniciales y despliega el menú principal:
intercambiar fichas, ver el tablero en binario, agregar/quitar fila,
salir o reiniciar partida.

## Compilación

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Ejecución

```bash
./Desafio
```

## Requisitos

- Compilador compatible con C++17
- CMake 3.16 o superior

## Curso

Informática II — Semestre 2026-2
