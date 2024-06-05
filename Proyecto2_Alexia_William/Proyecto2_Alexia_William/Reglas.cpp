#include "Reglas.h"

Reglas::Reglas() {}

Reglas::~Reglas() {}

void Reglas::Generales()
{
	cout << "\033[34m" << "========================================================================" "\033[0m" << endl;
	cout << "                               REGLAS                                 " << endl;
	cout << "\033[34m" << "========================================================================""\033[0m" << endl << endl;
	cout << "1- Un turno por cada jugador." << endl;
	cout << "2- Solo se permite agregar lineas en los espacios disponibles" << endl;
	cout << "3- No se permite trazar lineas fuera del tablero (en los espacios 'O')" << endl;
	cout << "4- Si se comete error en trazar un linea en una zona no permitida, pierdes el turno." << endl;
	cout << "5- Cada vez que un jugador completa un cuadrado, \n   se escribe su inicial en el centro del cuadrado." << endl;
	cout << "6- El jugador que gana es el que posea mas cuadros/puntos." << endl << endl;
	cout << "\033[34m" << "========================================================================" "\033[0m" << endl;
}