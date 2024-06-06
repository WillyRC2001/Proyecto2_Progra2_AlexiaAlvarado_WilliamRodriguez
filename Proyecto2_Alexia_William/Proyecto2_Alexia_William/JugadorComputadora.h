#pragma once
#include "Jugador.h"
#include "Estrategias.h"

class JugadorComputadora : public Jugador {
private: 
	Estrategia* estrategia;
	char Letra;
public:

	JugadorComputadora();
	virtual~JugadorComputadora();

	virtual string getNombreJugador();
	virtual char getInicial();
	virtual int getPuntos();
	virtual void setPuntos(int);
	virtual void estrategiaAleatoria();
	/*virtual void estrategiaCercano();
	virtual void estrategiaPeriferico();
	virtual void estrategiaCentral();
	virtual void estrategiaIslas();*/
	virtual void setNombreJugador(string);
	virtual void aumentarPuntos();

	// Metodos
	virtual  string toString() const;
	virtual Estrategia* getestrategia();

	
};