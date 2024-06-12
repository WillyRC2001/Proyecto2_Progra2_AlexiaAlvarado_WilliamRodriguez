#pragma once
#include"Juego.h"

class MenuPrincipal {
public:
	//Principal
	static int menuPrincipal();
	static int menuJuego();
	static int menuPartida();
	static void OpcionEnQueConsi();
	/*Tablero*/
	static TableroCompuesto* creartablero();
	/*Opciones*/
	/*Jugador*/
	static Jugador* crearJugador();
	static Jugador* crearComputadora();
	static Estrategia* selecionarEstrategia();
	static void cambiarEstrategia(Jugador*);
	/*Opciones*/
	static int Oponente();
	static int Cambiar();
	static int GuardarPartida();
	/*Jugada*/
	static int fila();
	static int columna();
	static void FinalDePartida(Jugador*, Jugador*);
	/*Opciones*/
	//Excepciones
	static void excepcionRango(Excepcion*);
	static void error();
	static void errorFoC();
	/*Comprobacion*/
	static void comprobarInt(int);
	static void comprobarDouble(double);
	static void Bienvenida();
	static void salir(); 
	//Arcivos
	static int Archivos(int);
	//Mensajes
	static void noArchivos();
	static void noMemento();


	//MenuPrincipal();
	//
	////Principal
	//static int menuPrincipal();
	////Menus Secundarios
	//static void OpcionIniciar(MenuPrincipal* instancia);

	//static void OpcionRecuperarJugada();
	//static void	OpcionSalir();
	///*Tablero*/
	//static TableroCompuesto* creartablero();
	///*Jugador*/
	//static Jugador* crearJugador();
	///*Jugada*/
	// static void MostrarReglas();
	// static void JugadaJugador(Juego* juego, int fila, int columna, Jugador* jug);
	// static int estrategiasComputadora();
	////Excepciones
	// static void excepcionRango(Excepcion*);
	// static void error();
	///*Comprobacion*/
	//static void comprobarInt(int);
	// static void compronarDouble(double);
	// static void Bienvenida();
	// //Arcivos
	// static int Archivos(int);	
	// static int GuardarPartida();
};
