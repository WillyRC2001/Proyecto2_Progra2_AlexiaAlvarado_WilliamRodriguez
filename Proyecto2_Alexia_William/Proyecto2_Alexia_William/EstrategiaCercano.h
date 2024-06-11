#pragma once
#include "Estrategia.h"

class EstrategiaCercano : public Estrategia {
private:
	//TableroJuego* tablero = NULL;
	//bool buscarCerca(TableroJuego* tablero, int& fila, int& columna);

public:
	EstrategiaCercano();
	virtual ~EstrategiaCercano();
	void buscarCerca(int f, int c, TableroJuego* tab);
	int getFila();
	int getColumna();
	//Metodos Basura (Pero NO BORRAR)
	bool buscarPeriferico(TableroJuego* tab) { return false; }
	void aplicarEstrategia(TableroJuego* tab){}
	//void dumb();
};