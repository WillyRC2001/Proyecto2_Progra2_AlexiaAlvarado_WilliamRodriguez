#include "TableroComponente.h"

TableroComponente::TableroComponente(int f, int c) : filas(f), columnas(c){
    tablero = new string * [filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new string[columnas];
        for (int j = 0; j < columnas; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                tablero[i][j] = "+";
            }
            else {
                tablero[i][j] = " ";
            }
        }
    }
}

TableroComponente::~TableroComponente(){
    for (int i = 0; i < filas; ++i) {
        delete[] tablero[i];
    }
    delete[] tablero;
}
