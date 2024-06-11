#include "RepositorioMementos.h"

RepositorioMementos::RepositorioMementos()
{
	can = 0;
	tam = 400;
	vec = new Memento * [400];
	for (int i = 0; i < tam; i++)
		vec[i] = nullptr;
}

RepositorioMementos::~RepositorioMementos()
{
	for (int i = 0; i < can; i++) {
		delete vec[i];
	}
	delete[] vec;
}

int RepositorioMementos::getCantElem() { return can; }

void RepositorioMementos::agregaMemento(Memento* m)
{
	if (can < tam) {
		vec[can++] = new Memento(*m);
	}
}

Memento* RepositorioMementos::getMemento(int pos)
{
	if (pos >= 0 && pos < can) {
		return vec[pos];
	}
	else {
		return nullptr;
	}
}


string RepositorioMementos::toString() const
{
	stringstream s;
	int nu = 1;
	Iterador* i = this->obtenerIterador();
	s << "=========================  LISTADO DE PARTIDAS  =======================" << endl << endl;
	while (i->masElemento()) {
		s << "Jugada del jugador numero: " << nu << endl << endl;
		s << *(i->proximoElemento()) << endl << endl;
		nu = (nu == 1) ? 2 : 1;
	}
	s << "\n=======================================================================" << endl << endl;
	return s.str();
	delete i;
}

Iterador* RepositorioMementos::obtenerIterador() const
{
	IterArreglo* nuevoIterador = new IterArreglo(can, vec);
	return nuevoIterador;
}
