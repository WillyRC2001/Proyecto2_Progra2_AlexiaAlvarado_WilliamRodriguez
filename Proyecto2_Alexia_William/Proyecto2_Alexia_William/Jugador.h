#pragma once
#include "ClasesUtiles.h"

class Jugador {
private:
	string nombre;
	double Totalpuntos;
	double victorias;
public:
	Jugador(string nom);
	virtual ~Jugador();
	virtual string toString() const;

	friend ostream& operator << (ostream& os, const Jugador& jugador) {
		os << jugador.toString();
		return os;
	}
};

