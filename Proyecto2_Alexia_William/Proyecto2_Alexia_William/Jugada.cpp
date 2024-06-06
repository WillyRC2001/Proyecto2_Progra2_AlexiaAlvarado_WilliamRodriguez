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
	system("pause");
	if (tableroJugada->CasillaLlena(primLetra) == true) {
		int sumarPuntos = jugadorJugada->getPuntos() + 1;
		jugadorJugada->setPuntos(sumarPuntos);
	}
}
void Jugada::AgregarLineaCompu(JugadorComputadora* jugadorPC, TableroJuego* tableroJugada, int f, int c)
{
	//int tipo = rand() % 5 + 1;	//(de 1 a 5)
	int tipo = 4;
	bool verificar;
	int fila;
	int columna;
	switch (tipo) {
	case 1:
		jugadorPC->estrategiaAleatoria();
		do {
			fila = jugadorPC->getestrategia()->getFila();
			columna = jugadorPC->getestrategia()->getColumna();
			verificar = tableroJugada->SetLineaCelda(fila, columna);
		}while(verificar != true);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 2:
		jugadorPC->estrategiaCercano();
		jugadorPC->getestrategia()->buscarCerca(f,c,tableroJugada);
		fila = jugadorPC->getestrategia()->getFila();
		columna = jugadorPC->getestrategia()->getColumna();
		tableroJugada->SetLineaCelda(fila, columna);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 3:
		jugadorPC->estrategiaCentral();
		do {
			fila = jugadorPC->getestrategia()->getFila();
			columna = jugadorPC->getestrategia()->getColumna();
			verificar = tableroJugada->SetLineaCelda(fila, columna);
		} while (verificar != true);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
	case 4:
		jugadorPC->estrategiaPeriferico();
		jugadorPC->getestrategia()->buscarPeriferico(tableroJugada);
		fila = jugadorPC->getestrategia()->getFila();
		columna = jugadorPC->getestrategia()->getColumna();
		tableroJugada->SetLineaCelda(fila, columna);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	}//Fin del switch
}