#pragma once
#include "Estrategia.h"

class EstrategiaIslas : public Estrategia {
private:
	int con;
	int afila;
	int acol;
	int a;
public:
    EstrategiaIslas();
    virtual ~EstrategiaIslas();
    int getFila();
    int getColumna();
    int getTipo();
	void buscarCerca(int, int, TableroJuego*);
	virtual int cuadrado(TableroJuego*);
	int izquierda(TableroJuego*);
	int derecha(TableroJuego*);
	int abajo(TableroJuego*);
	int arriba(TableroJuego*);
	int cero(TableroJuego*);
	int posicionRandom(TableroJuego* tab, int& fila, int& columna);

    //	Metodos Basura (Pero NO BORRAR)
	bool buscarPeriferico(TableroJuego* tab) {return false;}
	//void dumb();


};