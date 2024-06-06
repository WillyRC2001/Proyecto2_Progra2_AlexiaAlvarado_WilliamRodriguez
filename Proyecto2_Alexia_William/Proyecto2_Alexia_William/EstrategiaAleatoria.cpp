#include "EstrategiaAleatoria.h"

EstrategiaAleatoria::EstrategiaAleatoria() : Estrategia() {
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

//void EstrategiaAleatoria::dumb(){}