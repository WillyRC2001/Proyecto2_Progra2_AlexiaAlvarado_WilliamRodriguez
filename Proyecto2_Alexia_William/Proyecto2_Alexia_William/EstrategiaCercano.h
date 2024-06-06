#pragma once
#include "Estrategia.h"
#include "Tableros.h"

class EstrategiaCercano : public Estrategia {
private:

	//TableroJuego* tablero;
	//bool buscarCerca(TableroJuego* tablero, int& fila, int& columna);

public:
	EstrategiaCercano();
	virtual ~EstrategiaCercano();
	//int getFila(/*TableroJuego* tablero*/);
	//int getColumna(/*TableroJuego* tablero*/);
	//void dumb();
};