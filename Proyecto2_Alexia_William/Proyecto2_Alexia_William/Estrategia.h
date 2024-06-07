#pragma once
#include "ClasesUtiles.h"
#include "Tableros.h"

class Estrategia {
protected:
	int fila;
	int columna;
public:
	Estrategia(){
		fila = 0;
		columna = 0;
	}
	virtual ~Estrategia(){}
	//virtual void dumb() = 0;
	//Metodos para aleatorio y Central
	virtual int getFila() = 0;
	virtual int getColumna() = 0;
	//Metodos para cercano
	virtual void buscarCerca(int fila, int columna, TableroJuego* tab) = 0;
	//Metodo para periferico
	virtual bool buscarPeriferico(TableroJuego* tab) = 0;
	//Metodo para islas
	virtual void aplicarEstrategia(TableroJuego* tab) = 0;
};