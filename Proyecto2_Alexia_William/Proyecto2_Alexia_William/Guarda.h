#pragma once
#include <fstream>
#include <string>
using namespace std;

class Guarda {
private:
	int cont;
	ofstream writte;
	ifstream read;
public:
	Guarda(int = 1);
	int getCont();
	void guardando(string);
	void guardaImportante();
	void recuperaImportante();
	void guardaJugada(const string& jugador, int fila, int columna, int puntos);
	void recuperaJugadas();
	virtual ~Guarda();
};