#pragma once
#include "Estrategia.h"

class EstrategiaCentral : public Estrategia {
public:
	EstrategiaCentral();
	virtual ~EstrategiaCentral();
	int getFila() {
		int f = rand() % 11 + 5;
		return f;
	}
	int getColumna() {
		int c = rand() % 11 + 5;
		return c;
	}
	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int fila, int columna, TableroJuego* tab) {}
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	//void dumb();
};