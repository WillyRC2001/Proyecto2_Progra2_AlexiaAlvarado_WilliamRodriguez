#include "Linea.h"

Linea::Linea()
{
	lineaHorizontal = " - ";
	lineaVertical = " | ";
}

Linea::~Linea()
{
}

string Linea::getHorizontal()
{
	return lineaHorizontal;
}

string Linea::getVertical()
{
	return lineaVertical;
}

string Linea::toString() const
{
	return " ";
}
