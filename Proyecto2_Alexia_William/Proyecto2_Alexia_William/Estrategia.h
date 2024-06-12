#pragma once
#include "ClasesUtiles.h"
#include "Tableros.h"

class Estrategia {
protected:
	int fila;
	int columna;
	int tipo;
public:
	Estrategia(){
		fila = 0;
		columna = 0;
		tipo = 0;
	}
	virtual ~Estrategia(){}
	//Metodos para aleatorio y Central
	virtual int getFila() = 0;
	virtual int getColumna() = 0;
	virtual int getTipo() = 0;
	//virtual void estrategia(int, int, TableroJuego*) = 0;
	//Metodos para cercano e islas
	virtual void buscarCerca(int fila, int columna, TableroJuego* tab) = 0;
	//Metodo para periferico
	virtual bool buscarPeriferico(TableroJuego* tab) = 0;
	//metodo para islas
	virtual int posicionRandom(TableroJuego* tab, int& fila, int& columna) = 0;
	
};