#include "ObjetoBase.h"

ObjetoBase::ObjetoBase()
{
}

ObjetoBase::~ObjetoBase()
{
}

ostream& operator << (ostream& out, const ObjetoBase& obj)
{
	out << obj.toString();
	return out;
}

