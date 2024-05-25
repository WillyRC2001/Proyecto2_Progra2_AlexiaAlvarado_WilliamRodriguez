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
	bool AddMatriz(TableroComponente*);
	int GetCantidad() const;
	TableroComponente* GetMatriz(int index) const;

	//METODOS M.V.P
	//estos metodos seradesarrollados con valores por defecto
	//ya que solo interezan desarrollarlo en las matrices de 3x3, 3x4, 3x5
	virtual char* GetValorCelda(int, int) override;
	virtual void SetLineaCelda(int, int) override;

	virtual bool Vacio(int, int) override;
	virtual string toString() const override;

	TableroComponente* obtenerMatriz(int pos) {
		return vec[pos];
	}
	virtual int AnchuraColumnas() const;
	virtual int AlturaFilas() const;

};