#pragma once
#include "Estrategia.h"

class EstrategiaCercano : public Estrategia {
private:
	//TableroJuego* tablero = NULL;
	//bool buscarCerca(TableroJuego* tablero, int& fila, int& columna);

public:
	EstrategiaCercano();
	virtual ~EstrategiaCercano();
	void buscarCerca(int f, int c, TableroJuego* tab) {
		if (tab->GetValorCelda(f-1, c-1) == ' ') {
			fila = f - 1;
			columna = c - 1;
		}
		else {
			if (tab->GetValorCelda(f - 1, c + 1) == ' ') {
				fila = f - 1;
				columna = c + 1;
			}
			else {
				if (tab->GetValorCelda(f + 1, c + 1) == ' ') {
					fila = f + 1;
					columna = c + 1;
				}
				else {
					if (tab->GetValorCelda(f + 1, c - 1) == ' ') {
						fila = f + 1;
						columna = c - 1;
					}
				}
			}
		}
	}

	int getFila() {
		return fila;
	}
	int getColumna() {
		return columna;
	}
	//Metodos Basura (Pero NO BORRAR)
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	void aplicarEstrategia(TableroJuego* tab){}
	//void dumb();
};