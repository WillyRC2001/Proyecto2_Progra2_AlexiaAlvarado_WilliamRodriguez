#include "Juego.h"

Juego::Juego(Jugador* jug1, Jugador* jug2, TableroJuego* tab)
{
	jugador1 = jug1;
	jugador2 = jug2;
	juego = tab;
}

Juego::~Juego()
{
}

Jugador* Juego::getJugador1()
{
	return jugador1;
}

Jugador* Juego::getJugador2()
{
	return jugador2;
}

TableroJuego* Juego::getCampo()
{
	return juego;
}

string Juego::InfoJugador_1()
{
	return jugador1->toString();
}

string Juego::InfoJugador_2()
{
	return jugador2->toString();
}

string Juego::MostrarTablero()
{
	return juego->toString();
}

void Juego::HacerJugada(Jugador* jug, int f,int c)
{
	string opreglas;
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLinea(f, c, juego);
	delete jugada;
}
void Juego::HacerJugadaCompu(JugadorComputadora* jug, int f, int c)
{
	string opreglas;
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLineaCompu(jug, juego, f, c);
	delete jugada;
}

bool Juego::HayJugada() {
	return juego->HayEspacios();
}

void Juego::guarda(string& guarda) {
	guarda = guarda + getJugador1()->getNombreJugador() + "!";
	guarda = guarda + getJugador1()->getInicial() + "!";
	guarda = guarda + getJugador2()->getNombreJugador() + "!";
	guarda = guarda + getJugador2()->getInicial() + "!";
	guarda = guarda + getCampo()->toString() + "!";
}