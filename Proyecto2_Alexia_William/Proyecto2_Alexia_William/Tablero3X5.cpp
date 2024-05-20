#include "Tablero3X5.h"


Tablero3x5::Tablero3x5() : TableroComponente(7, 11) {}

Tablero3x5::~Tablero3x5() {}

string Tablero3x5::GetValorCelda(int f, int c) {
	if (f >= 0 && f < 7 && c >= 0 && c < 9) {
		return tablero[f][c];
	}
	return "";
}

void Tablero3x5::SetLineaCelda(int f, int c)
{
	if (this->Vacio(f, c) == false) {
		cout << "Ya hay una linea trazada en esa posicion" << endl;
	}
	else {
		if (f % 2 == 1 && c % 2 == 1 || f % 2 == 0 && c % 2 == 0) {
			cout << "No se puede agregar la linea en los vertices o centro" << endl;
		}
		else {
			if (f % 2 == 1 && c % 2 == 0) {
				tablero[f][c] = "|";
			}
			else
				tablero[f][c] = "-";
		}
	}
}

bool Tablero3x5::Vacio(int f, int c) {
	if (tablero[f][c] == "|" || tablero[f][c] == "-") {
		return false;
	}
	else
		return true;
}
void Tablero3x5::Add(TableroComponente&) {
	//Supongo que será un metodo para agregar otro Tablero
}

string Tablero3x5::toString() const {
	stringstream s;
	//Ciclo para agregar los numeros de las columnas
	s << "    ";
	for (int col = 0; col < columnas; ++col) {
		s << "  " << col;
	}
	s << endl;
	for (int i = 0; i < filas; ++i) {
		s << "  " << i << " "; // Número de la fila
		for (int j = 0; j < columnas; ++j) {
			s << "  ";
			//s << (tablero[i][j].empty() ? " " : tablero[i][j]) << " ";
			if (tablero[i][j] == " ") {
				s << " ";
			}
			else {
				s << tablero[i][j];
			}
		}
		s << endl;
	}
	return s.str();
}
