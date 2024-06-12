#pragma once
#include "Estrategia.h"

class EstrategiaPeriferico : public Estrategia {
public:
	EstrategiaPeriferico();
	virtual ~EstrategiaPeriferico();
	bool buscarPeriferico(TableroJuego* tab);
	int getFila();
	int getColumna();
	int getTipo();

	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	int posicionRandom(TableroJuego* tab, int& fila, int& columna) { return 0; }
};