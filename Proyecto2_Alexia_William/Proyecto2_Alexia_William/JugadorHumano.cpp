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

char JugadorHumano::getInical()
{
	if (nombre[0] == 'C') {
		return 'c';
	}
	return nombre[0];
}

int JugadorHumano::getPuntos() { return puntos; }
void JugadorHumano::setPuntos(int pun) { puntos = pun; }

void JugadorHumano::aumentarPuntos() { puntos++; }


string JugadorHumano::toString() const
{
	stringstream s;
	s << "\t Nombre del Jugador: " << nombre << endl <<endl;
	return s.str();
}

void JugadorHumano::getestrategia()
{

}