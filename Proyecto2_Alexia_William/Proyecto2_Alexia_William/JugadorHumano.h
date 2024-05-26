#pragma once
#include "Jugador.h"
#include "ClasesUtiles.h"

class JugadorHumano : public Jugador {

public:
	
	JugadorHumano(string);
	virtual~JugadorHumano();
	
	virtual void setNombreJugador(string);
	virtual string getNombreJugador();
	
	virtual  string toString() const;

};