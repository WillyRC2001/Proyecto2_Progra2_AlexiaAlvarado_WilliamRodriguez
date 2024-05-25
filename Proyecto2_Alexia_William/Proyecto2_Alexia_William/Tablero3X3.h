#pragma once
#include "TableroComponente.h"

class Tablero3x3 :public TableroComponente{
private: 
	char** tablero;
public:
	Tablero3x3();
	virtual~Tablero3x3();
	virtual char* GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) override;
	virtual string toString() const;
	virtual int AnchuraColumnas() const;
	virtual int AlturaFilas() const;
};