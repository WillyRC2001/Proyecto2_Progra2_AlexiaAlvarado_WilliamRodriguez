#include "Jugada.h"

Jugada::Jugada(Jugador* jug)
{
	jugadorJugada = jug;
	reglas = new Reglas();
}

Jugada::~Jugada()
{
}

void Jugada::MostrarReglas()
{
	reglas->Generales();
}

string Jugada::MostrarInfoJugador()
{
	return jugadorJugada->toString();
}

void Jugada::AgregarLinea(int f,int c, TableroJuego* tableroJugada)
{
	tableroJugada->SetLineaCelda(f,c); 
	string nom = jugadorJugada->getNombreJugador();
	char primLetra = nom[0];
	if (tableroJugada->CasillaLlena(primLetra) == true) {
		int sumarPuntos = jugadorJugada->getPuntos() + 1;
		jugadorJugada->setPuntos(sumarPuntos);
	}
}