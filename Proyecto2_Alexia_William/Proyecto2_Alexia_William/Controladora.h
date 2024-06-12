#pragma once
#include "MenuPrincipal.h"
class Controladora{
private:
	Juego* juego;
	int opcion;
	int comm; 
public:
	Controladora();
	virtual~Controladora();
	//Principal
	void controlPrincipal();
	void controlJugar();
	// Jugar
	void Jugar1();
	void Jugar1vs1();
	void Jugar1vsC();
	void Jugar2();
	//Reglas
	void verReglas();
	//Salida
	void Finalizar();
	//Archivos
	void Archivos1();
};