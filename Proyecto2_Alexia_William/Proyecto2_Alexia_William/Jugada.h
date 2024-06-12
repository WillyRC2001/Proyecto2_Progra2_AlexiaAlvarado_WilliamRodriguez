#pragma once
#include "ClasesUtiles.h"
#include "Reglas.h"
#include "Jugadores.h"
#include "Punto.h"
#include "TableroJuego.h"

class Jugada {
private:
	Jugador* jugadorJugada;
	Punto* punto;
	Reglas* reglas;
public:
	Jugada(Jugador* = nullptr);
	~Jugada();
	string MostrarInfoJugador(); //getnombre
	void setPunto(Punto*);
	int anatorPunto(int, int);
	int comanatorPunto(int, int);
	void MostrarReglas();
	bool quedaEspacio();
	string toString();
	void AgregarLinea(int f, int c, TableroJuego* tableroJugada);
	void AgregarLineaCompu(JugadorComputadora* jugadorPC, TableroJuego* tableroJugada, int f, int c, int tip_estrategia);

};