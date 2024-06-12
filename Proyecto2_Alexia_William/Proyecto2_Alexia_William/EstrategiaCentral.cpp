#include "EstrategiaCentral.h"

EstrategiaCentral::EstrategiaCentral(): Estrategia()
{
	this->tipo = 3;
}

EstrategiaCentral::~EstrategiaCentral()
{
}
int EstrategiaCentral::getFila() {
	int f = rand() % 11 + 5;
	return f;
}
int EstrategiaCentral::getColumna() {
	int c = rand() % 11 + 5;
	return c;
}

int EstrategiaCentral::getTipo()
{
	return tipo;
}
