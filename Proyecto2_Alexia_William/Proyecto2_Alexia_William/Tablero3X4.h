#pragma once
#include "TableroComponente.h"

class Tablero3x4 :public TableroComponente{
public:
	Tablero3x4();
	virtual~Tablero3x4();
	virtual string GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) override;
	virtual void Add(TableroComponente&) override;
	virtual string toString() const;

};
