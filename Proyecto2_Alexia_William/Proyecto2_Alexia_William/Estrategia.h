#pragma once
#include "ClasesUtiles.h"

class Estrategia {
public:
	Estrategia(){
	}
	virtual ~Estrategia(){}
	//virtual void dumb() = 0;
	virtual int getFila() = 0;
	virtual int getColumna() = 0;
};