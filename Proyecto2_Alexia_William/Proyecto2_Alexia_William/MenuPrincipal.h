#pragma once
#include"Juego.h"
#include "Excepciones_H.h"
class MenuPrincipal
{
public:
	//Principal
	static int menuPrincipal();
	/*Tablero*/
	TableroCompuesto* creartablero();
	/*Jugador*/
	Jugador* crearJugador();
	/*Jugada*/
	//Excepciones
	static void excepcionRango(Excepcion*);
	static void error();
	/*Comprobacion*/
	void comprobarInt(int);
	void compronarDouble(double);
	static void Bienvenida();
	static void salir(); /*Falta*/
};
