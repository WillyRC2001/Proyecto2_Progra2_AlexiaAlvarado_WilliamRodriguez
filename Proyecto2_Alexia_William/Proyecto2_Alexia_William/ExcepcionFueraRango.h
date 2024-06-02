#pragma once
#include "Excepcion.h"

class ExcepcionFueraRango : public Excepcion {
public:
	virtual ~ExcepcionFueraRango();
	string toString() const;
};