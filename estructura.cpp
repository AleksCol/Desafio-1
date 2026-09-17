int obtenerFicha(unsigned char* tablero, int fila, int columna, int totalColumnas) {
    int indice    = (fila * totalColumnas) + columna;
    int bitInicio = indice * 3;
    int valor     = 0;
    for (int b = 0; b < 3; b++) {
        int posGlobal  = bitInicio + b;
        int indicebyte = posGlobal / 8;
        int bitIdx     = posGlobal % 8;
        int estadoBit = (tablero[indicebyte] >> bitIdx) & 1;
        valor |= (estadoBit << b);
    }
    return valor;
}