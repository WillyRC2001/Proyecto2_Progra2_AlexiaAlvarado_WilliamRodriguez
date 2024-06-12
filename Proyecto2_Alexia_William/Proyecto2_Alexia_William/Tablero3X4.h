#pragma once
#include "TableroComponente.h"

class Tablero3x4 :public TableroComponente{
private:
	char** tablero;
public:
	Tablero3x4();
	virtual~Tablero3x4();
	virtual int AnchuraColumnas() const;
	virtual int AlturaFilas() const;
	virtual char* GetValorCelda(int, int) const override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) const override;
	virtual string toString() const;

};
