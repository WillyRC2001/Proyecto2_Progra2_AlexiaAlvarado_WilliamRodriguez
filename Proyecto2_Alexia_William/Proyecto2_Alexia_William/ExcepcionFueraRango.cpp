#include "ExcepcionFueraRango.h"

ExcepcionFueraRango::~ExcepcionFueraRango() {}
string ExcepcionFueraRango::toString() const
{
	return "ERROR: el numero digitado esta fuera de rango.\n";
}
