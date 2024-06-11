#pragma once
#include "Estrategia.h"

class EstrategiaIslas : public Estrategia {
protected:
    int estado;

    // Metodo para realizar el siguiente movimiento en la secuencia de formación de una isla
    bool siguienteMovimiento(TableroJuego* tab) {
        switch (estado) {
        case 0: // Línea superior
            if (tab->SetLineaCelda(fila, columna + 1)) {
                estado = 1;
                return true;
            }
            break;
        case 1: // Línea izquierda
            if (tab->SetLineaCelda(fila + 1, columna)) {
                estado = 2;
                return true;
            }
            break;
        case 2: // Línea derecha
            if (tab->SetLineaCelda(fila + 1, columna + 2)) {
                estado = 3;
                return true;
            }
            break;
        case 3: // Línea inferior
            if (tab->SetLineaCelda(fila + 2, columna + 1)) {
                estado = 0; // Reiniciar para la siguiente isla
                buscarNuevaPosicion(tab); // Buscar una nueva posición para la siguiente isla
                return true;
            }
            break;
        }
        return false;
    }

    // Metodo para buscar una nueva posición para iniciar la formación de una isla
    void buscarNuevaPosicion(TableroJuego* tab) {
        for (int i = 0; i < tab->AlturaFilas() - 2; i += 1) {
            for (int j = 0; j < tab->AnchuraColumnas() - 2; j += 1) {
                if (tab->Vacio(i, j) && tab->Vacio(i + 1, j) && tab->Vacio(i, j + 1) && tab->Vacio(i + 1, j + 1)) {
                    fila = i;
                    columna = j;
                    return;
                }
            }
        }
    }

public:
    EstrategiaIslas();
    virtual ~EstrategiaIslas();
    int getFila();
    int getColumna();
    void aplicarEstrategia(TableroJuego* tab);

    //	Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	bool buscarPeriferico(TableroJuego* tab) {return false;}
	//void dumb();


};