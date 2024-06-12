#pragma once
#include "ClasesUtiles.h"
#include "Jugadores.h"
#include "Jugada.h"
#include "Tableros.h"
#include "Mementos.h"
#include "Excepciones_H.h"

class Juego {
private:
	Juego();
	static Juego* juego;
	TableroJuego* tablero;
	RepositorioMementos* rm;
	Originador* org;
	int con;
	
	Jugador* jugador1;	//Jugador 1 siempre va a ser humano
	Jugador* jugador2;	//Jugador 2 puede ser tanto humano como computadora
	
public:
	virtual ~Juego();
	static Juego* getJuego();
	TableroJuego* getCampo();

	void activarTablero(TableroCompuesto*);
	

	Jugador* getJugador1();
	Jugador* getJugador2();
	string InfoJugador_1();
	string InfoJugador_2();

	string MostrarTablero();	//Usar el toString de TableroJuego
	int HacerJugada(Jugada* jug, int f, int c); //anotar posicion
	int HacerJugadaCompu(JugadorComputadora* jug,int f,int c, int tip_estrategia);
	int comanotarPosicion(Jugada*, int, int);
	bool HayJugada(); //queda espacio

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