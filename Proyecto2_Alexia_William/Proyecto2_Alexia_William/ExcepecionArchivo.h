#pragma once
#include "Excepcion.h"

class ExcepcionArchivo : public Excepcion {
public:
	virtual ~ExcepcionArchivo();
	string toString() const;
};