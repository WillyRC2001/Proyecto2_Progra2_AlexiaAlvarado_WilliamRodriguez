#include "Jugada.h"

Jugada::Jugada(Jugador* jug)
{
	jugadorJugada = jug;
	reglas = new Reglas();
	punto = new Punto();
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
void Jugada::AgregarLineaCompu(JugadorComputadora* jugadorPC, TableroJuego* tableroJugada, int f, int c, int tipo)
{
	bool verificar;
	int fila;
	int columna;
	switch (tipo) {
	case 1:
		jugadorPC->estrategiaAleatoria();
		do {
			fila = jugadorPC->obtenerEstrategias()->getFila();
			columna = jugadorPC->obtenerEstrategias()->getColumna();
			verificar = tableroJugada->SetLineaCelda(fila, columna);
		}while(verificar != true);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 2:
		jugadorPC->estrategiaCercano();
		jugadorPC->obtenerEstrategias()->buscarCerca(f,c,tableroJugada);
		fila = jugadorPC->obtenerEstrategias()->getFila();
		columna = jugadorPC->obtenerEstrategias()->getColumna();
		tableroJugada->SetLineaCelda(fila, columna);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 3:
		jugadorPC->estrategiaCentral();
		do {
			fila = jugadorPC->obtenerEstrategias()->getFila();
			columna = jugadorPC->obtenerEstrategias()->getColumna();
			verificar = tableroJugada->SetLineaCelda(fila, columna);
		} while (verificar != true);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 4:
		jugadorPC->estrategiaPeriferico();
		jugadorPC->obtenerEstrategias()->buscarPeriferico(tableroJugada);
		fila = jugadorPC->obtenerEstrategias()->getFila();
		columna = jugadorPC->obtenerEstrategias()->getColumna();
		tableroJugada->SetLineaCelda(fila, columna);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	case 5:
		jugadorPC->estrategiaIslas();
		jugadorPC->obtenerEstrategias()->posicionRandom(tableroJugada,fila,columna);
		tableroJugada->SetLineaCelda(fila, columna);
		if (tableroJugada->CasillaLlena(jugadorPC->getInicial()) == true) {
			int sumarPuntos = jugadorPC->getPuntos() + 1;
			jugadorPC->setPuntos(sumarPuntos);
		}
		break;
	}//Fin del switch
}

void Jugada::setPunto(Punto* punt)
{
	if (punto != nullptr) delete punto;
	punto = punt;
}

int Jugada::anatorPunto(int f, int c)
{
	int aux = punto->anotarPunto(f, c, jugadorJugada->getInicial());
	if (aux == 1)
	{
		return 1;
	}
	else if (aux == 2)
	{
		jugadorJugada->aumentarPuntos();
		return 2;
	}
	else {
		return 0;
	}
}

int Jugada::comanatorPunto(int f, int c)
{
	int verificar = 0;
	int fila;
	int columna;
	do {
		verificar = 0;
		jugadorJugada->obtenerEstrategias()->buscarCerca(f,c,punto->getTablero());
		fila = jugadorJugada->obtenerEstrategias()->getFila();
		columna = jugadorJugada->obtenerEstrategias()->getColumna();
		verificar = punto->anotarPunto(fila, columna, jugadorJugada->getInicial());
	} while (verificar == 0);
	if (verificar == 2)
		jugadorJugada->aumentarPuntos();
	else
		verificar = 1;
	return verificar;
}
bool Jugada::quedaEspacio()
{
	if (punto->quedaEspacio() == true) {
		return true;
	}
	else {
		return false;
	}
}

string Jugada::toString()
{
	stringstream s;
	s << "Movimento realizado por : " << jugadorJugada->getNombreJugador() << endl;
	s << punto->toString() << endl;
	return s.str();
}
