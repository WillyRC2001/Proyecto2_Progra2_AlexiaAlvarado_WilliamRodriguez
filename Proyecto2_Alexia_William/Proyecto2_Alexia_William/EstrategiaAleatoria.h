#pragma once
#include "Estrategia.h"

class EstrategiaAleatoria : public Estrategia{
public:
	EstrategiaAleatoria() : Estrategia(){
	}
	virtual ~EstrategiaAleatoria(){}
	int getFila() {
		int fila = rand() % 20;
		return fila;
	}
	int getColumna() {
		int columna = rand() % 20;
		return columna;
	}
	//void dumb(){}
};