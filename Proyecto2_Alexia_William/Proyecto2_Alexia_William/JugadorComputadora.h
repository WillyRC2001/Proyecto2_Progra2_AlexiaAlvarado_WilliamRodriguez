#pragma once
#include "Jugador.h"

class JugadorComputadora : public Jugador {

public:

	JugadorComputadora(string);
	virtual~JugadorComputadora();

	virtual void setNombreJugador(string);
	virtual string getNombreJugador();

	virtual  string toString() const;
};