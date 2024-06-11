#pragma once
#include "Memento.h"


class Originador {
private:
	TableroJuego* estado;
public:
	Originador() : estado(nullptr) {}
	virtual~Originador() { delete estado; }

	void setEstado(TableroJuego* est) {
		if (estado != nullptr) {
			delete estado;
		}
		estado = new TableroJuego(*est);
	}
	TableroJuego* getEstado() { return estado; }

	Memento* retornarMemento() { return new Memento(estado); }
	void restaurarEstado(Memento* m) {
		if (estado != nullptr) {
			delete estado;
		}
		estado = m->getEstado();
	}
};