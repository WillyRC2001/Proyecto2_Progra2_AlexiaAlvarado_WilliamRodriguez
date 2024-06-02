#pragma once
#include "ClasesUtiles.h"
#include "Jugadores.h"
#include "TableroJuego.h"
#include "Jugada.h"

class Juego {
private:
	TableroJuego* juego;
	Jugador* jugador1;	//Jugador 1 siempre va a ser humano
	Jugador* jugador2;	//Jugador 2 puede ser tanto humano como computadora
public:
	Juego(Jugador* jug1, Jugador* jug2, TableroJuego* tab);
	virtual ~Juego();
	string InfoJugador_1();
	string InfoJugador_2();
	string MostrarTablero();	//Usar el toString de TableroJuego
	void HacerJugada(Jugador* jug, int f, int c);
	//void ContarPuntos();
	bool HayJugada();
};