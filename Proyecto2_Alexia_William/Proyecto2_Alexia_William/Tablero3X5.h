#pragma once
#include "TableroComponente.h"

class Tablero3x5 :public TableroComponente {
private: 
	char** tablero;
public:
	Tablero3x5();
	virtual~Tablero3x5();
	virtual char* GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) override;
	virtual string toString() const;
	virtual int getAncho() const;
	virtual int getAlto() const;

};