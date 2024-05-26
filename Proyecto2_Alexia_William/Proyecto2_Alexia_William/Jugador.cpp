#include "Jugador.h"

Jugador::Jugador(string nom) : nombre(nom)
{
	Totalpuntos = 0;
	victorias = 0;
}

Jugador::~Jugador()
{
}

//string Jugador::toString() const
//{
//	stringstream s;
//	s << "=============INFORMACION DEL JUGADOR==============" << endl;
//	s << "nombre: " << nombre << endl;
//	s << "victorias: " << victorias << endl;
//	s << endl;
//	return s.str();
//}
