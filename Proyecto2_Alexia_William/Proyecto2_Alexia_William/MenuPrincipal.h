#pragma once
#include"Juego.h"
#include "Guarda.h"
#include "Excepciones_H.h"
class MenuPrincipal //controladora del juego
{
private: 
	TableroJuego* tableroJuego;
	Guarda* guardado;
	//Juego* juego;	//Nota: El juego se esta creando dentro del metodo OpcionIniciar entonces no debería ser necesario esto
public:

	MenuPrincipal();
	
	//Principal
	static int menuPrincipal();
	//Menus Secundarios
	static void OpcionIniciar(MenuPrincipal* instancia);
	static void OpcionEnQueConsi();
	static void OpcionRecuperarJugada();
	static void	OpcionSalir();
	/*Tablero*/
	static TableroCompuesto* creartablero();
	/*Jugador*/
	static Jugador* crearJugador();
	/*Jugada*/
	 static void MostrarReglas();
	 static void JugadaJugador(Juego* juego, int fila, int columna, Jugador* jug);
	 static int estrategiasComputadora();
	//Excepciones
	 static void excepcionRango(Excepcion*);
	 static void error();
	/*Comprobacion*/
	static void comprobarInt(int);
	 static void compronarDouble(double);
	 static void Bienvenida();
	 //Arcivos
	 static int Archivos(int);	
	 static int GuardarPartida();
};
