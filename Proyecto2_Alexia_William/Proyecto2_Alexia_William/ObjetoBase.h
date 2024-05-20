#pragma once
#pragma once
#include "ClasesUtiles.h"

class ObjetoBase {
public:
	ObjetoBase();
	virtual~ObjetoBase();
	virtual string toString() const = 0;
};
ostream& operator << (ostream& out, const ObjetoBase& obj);

