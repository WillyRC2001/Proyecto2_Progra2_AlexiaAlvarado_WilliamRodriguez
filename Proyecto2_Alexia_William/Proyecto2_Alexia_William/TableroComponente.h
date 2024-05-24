#pragma once
#include "ClasesUtiles.h"
#include "ObjetoBase.h"

class TableroComponente : public ObjetoBase{

public:
	TableroComponente()=default;
	virtual~TableroComponente()=default;

	virtual char* GetValorCelda(int, int) = 0;
	virtual void SetLineaCelda(int, int) = 0;

	virtual bool Vacio(int, int) = 0;
	//virtual bool Add(TableroComponente*) = 0; //yo lo elimino de aqui y lo dejo como solo del compuesto
	virtual string toString() const = 0;
	virtual int getAncho() const = 0;
	virtual int getAlto() const = 0;
	
};