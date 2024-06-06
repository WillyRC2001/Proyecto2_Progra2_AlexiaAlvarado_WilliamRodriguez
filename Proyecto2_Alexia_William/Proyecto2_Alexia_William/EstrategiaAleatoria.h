#pragma once
#include "Estrategia.h"

class EstrategiaAleatoria : public Estrategia{
public:
	EstrategiaAleatoria();
	virtual ~EstrategiaAleatoria();
	int getFila();
	int getColumna();
	//void dumb();
};