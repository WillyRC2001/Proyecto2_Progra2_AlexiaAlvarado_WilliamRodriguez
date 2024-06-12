
#pragma once
#include "Estrategia.h"

class EstrategiaCercano : public Estrategia {

public:
	EstrategiaCercano();
	virtual ~EstrategiaCercano();
	void buscarCerca(int f, int c, TableroJuego* tab);
	int getFila();
	int getColumna();
	int getTipo();

	//Metodos Basura (Pero NO BORRAR)
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	int posicionRandom(TableroJuego* tab, int& fila, int& columna) { return 0; }
};