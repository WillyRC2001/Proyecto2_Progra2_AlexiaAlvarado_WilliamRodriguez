#pragma once
#include "Iterador.h"

class IterArreglo :public Iterador
{
private:
	int i;
	int cant;
	Memento** vect;
public:
	IterArreglo(int, Memento* []);
	virtual~IterArreglo();
	virtual bool masElemento() const;
	virtual Memento* proximoElemento();
	virtual string toString() const;
};