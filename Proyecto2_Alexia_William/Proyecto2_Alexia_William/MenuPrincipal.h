#pragma once
#include"Juego.h"
#include "Excepciones_H.h"
class MenuPrincipal
{
public:
	//Principal
	static int menuPrincipal();
	//Menus Secundarios
	static void OpcionIniciar();
	static void OpcionEnQueConsi();
	static void	OpcionSalir();
	/*Tablero*/
	static TableroCompuesto* creartablero();
	/*Jugador*/
	static Jugador* crearJugador();
	/*Jugada*/
	static void MostrarReglas();
	static void JugadaJugador(Juego* juego, int fila, int columna, Jugador* jug);
	//Excepciones
	static void excepcionRango(Excepcion*);
	static void error();
	/*Comprobacion*/
	static void comprobarInt(int);
	static void compronarDouble(double);
	static void Bienvenida();
	//static void salir(); /*Falta*/
};
