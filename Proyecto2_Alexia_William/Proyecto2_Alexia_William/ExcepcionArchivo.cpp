#include "ExcepcionArchivo.h"

ExcepcionArchivo::~ExcepcionArchivo() {}

string ExcepcionArchivo::toString() const
{
	return "ERROR: archivo no encontrado o no es posible guardar.\n";
}
