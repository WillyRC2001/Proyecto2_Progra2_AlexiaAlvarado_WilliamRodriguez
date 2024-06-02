#pragma once
#include "ClasesUtiles.h"

class Jugador { //aqui hay que utilizar el patron strategy (estrategia)
protected: 
	string nombre;
	double puntos;
	double victorias;
public:
	Jugador(string nom);
	virtual ~Jugador();

	virtual char getInical() = 0;
	virtual void setNombreJugador(string) =0;
	virtual string getNombreJugador()=0;
	virtual int getPuntos() = 0;
	virtual void setPuntos(int) = 0;
	virtual void aumentarPuntos() = 0;

	virtual string toString() const = 0;
	virtual void getestrategia() = 0;

	friend ostream& operator << (ostream& os, const Jugador& jugador) {
		os << jugador.toString();
		return os;
	}
};

