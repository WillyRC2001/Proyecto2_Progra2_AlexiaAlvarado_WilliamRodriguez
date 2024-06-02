#pragma once
#include "Jugador.h"
#include "ClasesUtiles.h"

class JugadorHumano : public Jugador {

public:
	
	JugadorHumano(string);
	virtual~JugadorHumano();
	
	virtual void setNombreJugador(string);
	virtual string getNombreJugador();
	virtual char getInical();
	virtual int getPuntos();
	virtual void setPuntos(int);
	virtual void aumentarPuntos();
	
	// Metodos
	virtual  string toString() const;
	virtual void getestrategia();
};