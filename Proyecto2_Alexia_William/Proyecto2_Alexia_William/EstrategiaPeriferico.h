#pragma once
#include "Estrategia.h"

class EstrategiaPeriferico : public Estrategia {
public:
	EstrategiaPeriferico();
	virtual ~EstrategiaPeriferico();
	bool buscarPeriferico(TableroJuego* tab) {
		bool verificar;
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 19; j++) {
				if (tab->GetValorCelda(i, j) == ' ') {
					fila = i;
					columna = j;
					return verificar = true;
				}
			}
		}
		for (int i = 15; i <= 19; i++) {
			for (int j = 0; j <= 19; j++) {
				if (tab->GetValorCelda(i, j) == ' ') {
					fila = i;
					columna = j;
					return verificar = true;
				}
			}
		}
		for (int i = 0; i <= 19; i++) {
			for (int j = 0; j <= 4; j++) {
				if (tab->GetValorCelda(i, j) == ' ') {
					fila = i;
					columna = j;
					return verificar = true;
				}
			}
		}
		for (int i = 0; i <= 19; i++) {
			for (int j = 15; j <= 19; j++) {
				if (tab->GetValorCelda(i, j) == ' ') {
					fila = i;
					columna = j;
					return verificar = true;
				}
			}
		}
		fila = 0;
		columna = 0;
		return verificar = false;
	}
	int getFila() {
		return fila;
	}
	int getColumna() {
		return columna;
	}

	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	void aplicarEstrategia(TableroJuego* tab){}
	//void dumb();
};