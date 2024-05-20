#pragma once
#include "TableroComponente.h"

class TableroCompuesto :public TableroComponente{
public:
	TableroCompuesto();
	virtual~TableroCompuesto();
	virtual string GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;
	virtual bool Vacio(int, int) override;
	virtual void Add(TableroComponente&) override;
	virtual string toString() const override;
	

};