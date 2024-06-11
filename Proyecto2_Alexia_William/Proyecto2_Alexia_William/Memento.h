#pragma once
#include "TableroJuego.h"

class Memento {
private:
	TableroJuego* estado;
public:
	Memento() { estado = nullptr; }
	Memento(TableroJuego* est) { estado = new TableroJuego(*est); }
	virtual~Memento() { delete estado; }
	TableroJuego* getEstado() { return new TableroJuego(*estado); }
	friend ostream& operator << (ostream& os, const  Memento& m) {
		os << *m.estado;
		return os;
	}
	
};