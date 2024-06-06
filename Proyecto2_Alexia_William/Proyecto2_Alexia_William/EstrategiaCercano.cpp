#include "EstrategiaCercano.h"

EstrategiaCercano::EstrategiaCercano()
{
}

EstrategiaCercano::~EstrategiaCercano()
{
}


//bool EstrategiaCercano::buscarCerca(TableroJuego* tablero, int& fila, int& columna) {
//    if (!tablero) return false;
//    int filas = tablero->AlturaFilas();
//    int columnas = tablero->AnchuraColumnas();
//    for (int i = 0; i < filas; ++i) {
//        for (int j = 0; j < columnas; ++j) {
//            if (tablero->Vacio(i, j)) {
//                fila = i;
//                columna = j;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int EstrategiaCercano::getFila(TableroJuego* tablero) {
//    int fila, columna;
//    if (buscarCerca(tablero, fila, columna)) {
//        return fila;
//    }
//    return -1; // Return an invalid row if not found
//}
//
//int EstrategiaCercano::getColumna(TableroJuego* tablero) {
//    int fila, columna;
//    if (buscarCerca(tablero, fila, columna)) {
//        return columna;
//    }
//    return -1; // Return an invalid column if not found
//}