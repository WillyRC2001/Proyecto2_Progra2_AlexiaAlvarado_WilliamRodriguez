#pragma once
#include "Tableros.h"

class Punto
{
private:
	TableroJuego* tablero;
public:
	Punto(TableroJuego*);
	virtual~Punto();
	void anotarLinea(int, int);
	void anotarPuntoGanador(char);
};