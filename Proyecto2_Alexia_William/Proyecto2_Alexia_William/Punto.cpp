#include "Punto.h"


Punto::Punto(TableroJuego* tab) :tablero(tab) {}

Punto::~Punto() {}

TableroJuego* Punto::getTablero()
{
	return tablero;
}

int Punto::anotarPunto(int f, int c, char nic)
{
	if (tablero->SetLineaCelda(f, c) == true) {
		if (tablero->CasillaLlena(nic) == true) {
			return 2;
		}
		return 1;
	}
	return 0;
}

string Punto::toString() const
{
	stringstream s;
	s << tablero->toString();
	return s.str();
}

bool Punto::quedaEspacio()
{
	if (tablero->HayEspacios() == true) {
		return true;
	}
	else {
		return false;
	}
}


