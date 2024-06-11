#include "EstrategiaIslas.h"

EstrategiaIslas::EstrategiaIslas() :Estrategia() {
    estado = 0;
}

EstrategiaIslas::~EstrategiaIslas() {}

int EstrategiaIslas::getFila() { return fila; }
int EstrategiaIslas::getColumna() { return columna; }

void EstrategiaIslas::aplicarEstrategia(TableroJuego* tab) {
    if (!siguienteMovimiento(tab)) {
        // Si no se pudo realizar el siguiente movimiento, buscar una nueva posición
        buscarNuevaPosicion(tab);
        siguienteMovimiento(tab);
    }
}