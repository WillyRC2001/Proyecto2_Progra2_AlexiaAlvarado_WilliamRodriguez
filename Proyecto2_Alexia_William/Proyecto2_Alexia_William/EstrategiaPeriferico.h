#pragma once
#include "Estrategia.h"

class EstrategiaPeriferico : public Estrategia {
public:
	EstrategiaPeriferico();
	virtual ~EstrategiaPeriferico();
	bool buscarPeriferico(TableroJuego* tab);
	int getFila();
	int getColumna();

	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	void aplicarEstrategia(TableroJuego* tab){}
	//void dumb();
};