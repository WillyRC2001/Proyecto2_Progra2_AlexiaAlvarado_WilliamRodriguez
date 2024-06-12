#pragma once
#include "Tableros.h"

class Punto
{
private:
	TableroJuego* tablero;
public:
	Punto(TableroJuego* = nullptr);
	virtual~Punto();
	TableroJuego* getTablero();
	int anotarPunto(int, int, char);
	string toString() const;
	bool quedaEspacio();
};