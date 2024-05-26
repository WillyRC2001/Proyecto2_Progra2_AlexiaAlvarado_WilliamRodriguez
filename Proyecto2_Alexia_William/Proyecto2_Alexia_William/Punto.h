#pragma once
#include "Tableros.h"

class Punto
{
private:
	TableroJuego* tablero;
public:
	Punto(TableroJuego*);
	virtual~Punto();
	void anotarPunto(int, int);
	void anotarPuntoGanador(char);
};