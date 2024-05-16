#pragma once
#include "ClasesUtiles.h"

class Elemento {
public:
	virtual ~Elemento() = 0;
	virtual string toString() const = 0;
};