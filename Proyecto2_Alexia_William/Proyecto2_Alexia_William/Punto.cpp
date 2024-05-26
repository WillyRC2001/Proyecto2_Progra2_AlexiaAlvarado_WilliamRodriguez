#include "Punto.h"

Punto::Punto(TableroJuego* ta)
{
	tablero = ta;
}
Punto::~Punto() {}

void Punto::anotarPunto(int f, int c)
{
	tablero->SetLineaCelda(f, c);
}


void Punto::anotarPuntoGanador(char)
{

}