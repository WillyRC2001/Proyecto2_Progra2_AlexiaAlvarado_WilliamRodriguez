#include "EstrategiaAleatoria.h"

EstrategiaAleatoria::EstrategiaAleatoria() : Estrategia() 
{
	this->tipo = 1;
}
EstrategiaAleatoria::~EstrategiaAleatoria() {}
int EstrategiaAleatoria::getFila() {
	int f = rand() % 20;
	return f;
}
int EstrategiaAleatoria::getColumna() {
	int c = rand() % 20;
	return c;
}

int EstrategiaAleatoria::getTipo()
{
	return tipo;
}
