#pragma once
#include "Estrategia.h"

class EstrategiaCentral : public Estrategia {
public:
	EstrategiaCentral();
	virtual ~EstrategiaCentral();
	int getFila();
	int getColumna();
	int getTipo();
	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int fila, int columna, TableroJuego* tab) {}
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	int posicionRandom(TableroJuego* tab, int& fila, int& columna) { return 0; }
};