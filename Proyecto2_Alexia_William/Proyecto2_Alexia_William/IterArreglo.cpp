#include "IterArreglo.h"

IterArreglo::IterArreglo(int can, Memento* v[]) :i(0), cant(can), vect(v), Iterador() {}
IterArreglo::~IterArreglo() {}
bool IterArreglo::masElemento() const { return i < cant; }
Memento* IterArreglo::proximoElemento()
{
	Memento* o = NULL;
	if (this->masElemento()) {
		o = vect[i++];
	}
	return o;
}

string IterArreglo::toString() const { return ""; }
