#pragma once
#include "TableroComponente.h"

class TableroCompuesto :public TableroComponente{
private: 
	TableroComponente** vec; //tableros
	int can; 
	int tam;
public:
	TableroCompuesto();
	virtual~TableroCompuesto();

	int GetCantidad() const;
	TableroComponente* GetMatriz(int index) const;

	//METODOS M.V.P
	
	TableroComponente* obtenerMatriz(int pos) {
		return vec[pos];
	}
	virtual char* GetValorCelda(int, int) const override; //get valor celda
	virtual void SetLineaCelda(int, int) override; //set valor celda
	virtual int AnchuraColumnas() const; //get columnas
	virtual int AlturaFilas() const; //get filas
	virtual bool Vacio(int, int) const override;
	virtual string toString() const override;
	bool AddMatriz(TableroComponente*);

};