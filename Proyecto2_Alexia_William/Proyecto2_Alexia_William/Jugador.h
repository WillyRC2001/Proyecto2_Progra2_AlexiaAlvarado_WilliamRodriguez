#pragma once
#include "ClasesUtiles.h"

class Jugador { //aqui hay que utilizar el patron strategy (estrategia)
protected: 
	string nombre;
	double Totalpuntos;
	double victorias;
public:
	Jugador(string nom);
	virtual ~Jugador();
	virtual void setNombreJugador(string) =0;
	virtual string getNombreJugador()=0;
	virtual string toString() const=0;

	friend ostream& operator << (ostream& os, const Jugador& jugador) {
		os << jugador.toString();
		return os;
	}
};

