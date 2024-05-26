#include "Reglas.h"

Reglas::Reglas() {}

Reglas::~Reglas() {}

void Reglas::Generales()
{
	cout << "\033[34m" << "========================================================================" "\033[0m" << endl;
	cout << "                               REGLAS                                 " << endl;
	cout << "\033[34m" << "========================================================================""\033[0m" << endl << endl;
	cout << "1- Un turno por cada jugador." << endl;
	cout << "2- Los jugadores se turnan para dibujar lineas entre los puntos." << endl;
	cout << "3- Cada vez que un jugador completa un cuadrado, \n   se escribe su inicial en el centro del cuadrado." << endl;
	cout << "4- Despues de completar un cuadrado, el jugador dibuja otra linea." << endl;
	cout << "5- El juego termina cuando toda el area del juego ha sido completada." << endl;
	cout << "6- El jugador que gana es el que posea mas cuadros." << endl << endl;
	cout << "\033[34m" << "========================================================================" "\033[0m" << endl;
}