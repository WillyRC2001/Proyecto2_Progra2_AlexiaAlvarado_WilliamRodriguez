#pragma once
#include "ClasesUtiles.h"
#include "Jugadores.h"
#include "TableroJuego.h"
#include "Jugada.h"
#include "Tableros.h"
#include "Mementos.h"
#include "Excepciones_H.h"

class Juego {
private:
	TableroJuego* juego;
	Jugador* jugador1;	//Jugador 1 siempre va a ser humano
	Jugador* jugador2;	//Jugador 2 puede ser tanto humano como computadora
	RepositorioMementos* rm;
	Originador* org;
	int con;
public:
	Juego(Jugador* jug1, Jugador* jug2, TableroJuego* tab);
	virtual ~Juego();
	Jugador* getJugador1();
	Jugador* getJugador2();
	TableroJuego* getCampo();
	string InfoJugador_1();
	string InfoJugador_2();
	string MostrarTablero();	//Usar el toString de TableroJuego
	void HacerJugada(Jugador* jug, int f, int c);
	void HacerJugadaCompu(JugadorComputadora* jug,int f,int c, int tip_estrategia);
	//void ContarPuntos();
	bool HayJugada();

	/*Elementos de memento*/
	void crearMemento();
	void getMemento();
	void verMemento();
	//Archivos
	int getCont();
	void guarda();
	void carga(int);
	void guardaCont();
	void cargaCont();
};