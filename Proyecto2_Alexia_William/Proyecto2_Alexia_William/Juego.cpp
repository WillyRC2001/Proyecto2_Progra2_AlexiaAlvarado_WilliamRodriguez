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
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLinea(f, c, juego);
	delete jugada;
}

bool Juego::HayJugada() {
	return juego->HayEspacios();
}
