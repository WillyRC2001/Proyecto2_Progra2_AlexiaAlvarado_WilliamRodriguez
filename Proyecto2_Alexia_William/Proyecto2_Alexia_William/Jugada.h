#pragma once
#include "ClasesUtiles.h"
#include "Reglas.h"
#include "Jugadores.h"
#include "TableroJuego.h"

class Jugada {
private:
	Jugador* jugadorJugada;
	Reglas* reglas;
public:
	Jugada(Jugador* jug);
	~Jugada();
	void MostrarReglas();
	string MostrarInfoJugador();
	void AgregarLinea(int f, int c, TableroJuego* tableroJugada);
	void AgregarLineaCompu(JugadorComputadora* jugadorPC, TableroJuego* tableroJugada, int f, int c);
};