#pragma once
#include "Estrategia.h"

class EstrategiaAleatoria : public Estrategia{
public:
	EstrategiaAleatoria();
	virtual ~EstrategiaAleatoria();
	int getFila();
	int getColumna();
	//Metodos Basura (Pero NO BORRAR)
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	//void dumb();
};