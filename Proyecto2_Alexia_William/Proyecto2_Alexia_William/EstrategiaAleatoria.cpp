#include "EstrategiaAleatoria.h"

EstrategiaAleatoria::EstrategiaAleatoria() : Estrategia() {
}
EstrategiaAleatoria::~EstrategiaAleatoria() {}
int EstrategiaAleatoria::getFila() {
	int fila = rand() % 20;
	return fila;
}
int EstrategiaAleatoria::getColumna() {
	int columna = rand() % 20;
	return columna;
}
//void EstrategiaAleatoria::dumb(){}