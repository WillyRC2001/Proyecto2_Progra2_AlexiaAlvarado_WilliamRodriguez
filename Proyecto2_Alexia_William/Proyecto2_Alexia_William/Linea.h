#pragma once
#include "ClasesUtiles.h"
#include "Elemento.h"

class Linea{
private:
	string lineaHorizontal;
	string lineaVertical;
public:
	Linea();
	virtual ~Linea();
	string getHorizontal();
	string getVertical();
	string toString() const;
};