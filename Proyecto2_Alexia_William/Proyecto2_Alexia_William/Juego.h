#pragma once
#include "ClasesUtiles.h"
#include "Jugador.h"
#include "TableroJuego.h"
#include "Jugada.h"

class Juego {
private:
	TableroJuego* juego;
	Jugador* jugador1;	//Jugador 1 siempre va a ser humano
	Jugador* jugador2;	//Jugador 2 puede ser tanto humano como computadora
public:
	Juego(Jugador* jug1, Jugador* jug2);
	virtual ~Juego();
	//string toString();
	Jugador* InfoJugador_1();
	Jugador* InfoJugador_2();
	TableroJuego* MostrarTablero();	//Usar el toString de TableroJuego
	//Metodos que creo que son mas de la clase Jugada
	//void AgregarLinea(int f,int c);
};