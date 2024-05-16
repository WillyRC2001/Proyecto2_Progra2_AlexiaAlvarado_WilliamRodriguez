#pragma once
#include "ClasesUtiles.h"
#include "Elemento.h"

class Vertice{
private:
	string elementvertice;
public:
	Vertice();
	virtual ~Vertice();
	string toString() const;
	friend ostream& operator << (ostream& os, const Vertice& ver) {
		os << ver.toString();
	}
};