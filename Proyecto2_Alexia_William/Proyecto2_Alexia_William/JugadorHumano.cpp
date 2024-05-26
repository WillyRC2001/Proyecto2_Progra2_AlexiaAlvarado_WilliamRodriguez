#include "JugadorHumano.h"
#include "Jugador.h"

JugadorHumano::JugadorHumano(string nom):Jugador(nom)
{
}

JugadorHumano::~JugadorHumano()
{
}

void JugadorHumano::setNombreJugador(string name)
{
    nombre = name;
}

string JugadorHumano::getNombreJugador()
{
    return nombre;
}

string JugadorHumano::toString() const
{
	stringstream s;
	s << "\t Nombre del Jugador: " << nombre << endl <<endl;
	return s.str();
}
