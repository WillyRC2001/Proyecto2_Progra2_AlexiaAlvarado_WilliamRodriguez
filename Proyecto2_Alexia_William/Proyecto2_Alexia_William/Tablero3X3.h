#pragma once
#include "TableroComponente.h"

class Tablero3x3 :public TableroComponente{
public:
	Tablero3x3();
	virtual~Tablero3x3();
	virtual string GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) override;
	virtual void Add(TableroComponente&) override;
	virtual string toString() const;

};