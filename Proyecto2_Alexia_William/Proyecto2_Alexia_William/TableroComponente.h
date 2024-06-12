#pragma once
#include "ClasesUtiles.h"
#include "ObjetoBase.h"

class TableroComponente : public ObjetoBase{
protected: 

public:
	TableroComponente()=default;
	virtual~TableroComponente()=default;

	virtual char* GetValorCelda(int, int) const = 0;
	virtual void SetLineaCelda(int, int) = 0; //set valor celda
	virtual bool Vacio(int, int) const = 0;
	virtual string toString() const = 0;
	virtual int AnchuraColumnas() const = 0; //get columnas
	virtual int AlturaFilas() const = 0; //get filas
	
}; 