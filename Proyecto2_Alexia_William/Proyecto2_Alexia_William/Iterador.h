#pragma once
#include "ObjetoBase.h"
#include "Memento.h"

class Iterador : public ObjetoBase
{
private:

public:
	Iterador() {}
	virtual ~Iterador() {}
	virtual bool masElemento() const = 0;
	virtual Memento* proximoElemento() = 0;
	virtual string toString() const = 0;
};