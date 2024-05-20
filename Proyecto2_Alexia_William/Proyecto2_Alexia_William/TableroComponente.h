#pragma once
#include "ClasesUtiles.h"
#include "ObjetoBase.h"

class TableroComponente : public ObjetoBase{
protected:
	string** tablero;
	int filas;
	int columnas;
public:
	TableroComponente(int, int);
	virtual~TableroComponente();
	virtual string GetValorCelda(int, int) = 0;
	virtual void SetLineaCelda(int, int) = 0;
	virtual bool Vacio(int, int) = 0;
	virtual void Add(TableroComponente&) = 0;
	virtual string toString() const = 0;
	
};