#pragma once
#include "ObjetoBase.h"
#include "Memento.h"
#include "IterArreglo.h"

class RepositorioMementos :public ObjetoBase {
private:
	Memento** vec;
	int can;
	int tam;
public:
	RepositorioMementos();
	virtual ~RepositorioMementos();
	int getCantElem();
	void agregaMemento(Memento* m);
	Memento* getMemento(int pos);
	string toString() const;
	Iterador* obtenerIterador() const;
};