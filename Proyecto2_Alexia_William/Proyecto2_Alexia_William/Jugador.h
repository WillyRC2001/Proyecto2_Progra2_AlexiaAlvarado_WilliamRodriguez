#pragma once
#include "ClasesUtiles.h"
#include "Estrategias.h"
#include "ObjetoBase.h"

class Jugador : public ObjetoBase{ 
protected: 
	string nombre;
	int puntos;
public:
	Jugador(string nom);
	virtual ~Jugador();
	//Metodos para sus clases derivadas
	virtual char getInicial() = 0;
	virtual void setNombreJugador(string) =0;
	virtual string getNombreJugador()=0;
	virtual int getPuntos() = 0;
	virtual void setPuntos(int) = 0;
	virtual void aumentarPuntos() = 0;
	virtual string toString() const = 0;
	virtual Estrategia* obtenerEstrategias() = 0;
	virtual void setearEstrategias(Estrategia*) = 0;
	friend ostream& operator << (ostream& os, const Jugador& jugador) {
		os << jugador.toString();
		return os;
	}
};

