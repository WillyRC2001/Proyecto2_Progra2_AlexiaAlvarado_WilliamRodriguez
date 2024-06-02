#pragma once
#include "Jugador.h"
#include "Estrategia.h"

class JugadorComputadora : public Jugador {
private: 
	Estrategia* estrategia;
public:

	JugadorComputadora(Estrategia*);
	virtual~JugadorComputadora();

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