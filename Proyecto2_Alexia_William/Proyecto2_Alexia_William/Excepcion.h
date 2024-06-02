#pragma once
#include "ClasesUtiles.h"

class Excepcion {
public:
	virtual ~Excepcion() {}
	virtual string toString() const = 0;
};
