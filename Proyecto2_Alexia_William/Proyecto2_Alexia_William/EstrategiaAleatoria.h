#pragma once
#include "Estrategia.h"

class EstrategiaAleatoria : public Estrategia{
public:
	EstrategiaAleatoria();
	virtual ~EstrategiaAleatoria();
	int getFila();
	int getColumna();
	virtual int getTipo();
	//virtual void estrategia(int, int, TableroJuego*);
	
	//basura xd
	void buscarCerca(int f, int c, TableroJuego* tab) {}
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	int posicionRandom(TableroJuego* tab, int& fila, int& columna) { return 0; }

};