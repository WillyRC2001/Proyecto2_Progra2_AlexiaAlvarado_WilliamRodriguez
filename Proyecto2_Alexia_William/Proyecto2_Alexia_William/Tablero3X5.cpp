#include "Tablero3X5.h"


Tablero3x5::Tablero3x5() {
	tablero = new char* [11];
	for (int i = 0; i < 11; i++) {
		tablero[i] = new char[7];
		for (int j = 0; j < 7; j++) {
			tablero[i][j] = '+';
		}
	}
}

Tablero3x5::~Tablero3x5() {
	for (int i = 0; i < 11; ++i) {
		delete[] tablero[i];
	}
	delete[] tablero;
}

string Tablero3x5::GetValorCelda(int f, int c) {
	if (f >= 0 && f < 7 && c >= 0 && c < 11) {
		return string(1, tablero[f][c]);
	}
	return "";
}

void Tablero3x5::SetLineaCelda(int f, int c)
{

	if (!this->Vacio(f, c)) {
		cout << "Ya hay una línea trazada en esa posición" << endl;
	}
	else {
		if ((f % 2 == 1 && c % 2 == 1) || (f % 2 == 0 && c % 2 == 0)) {
			cout << "No se puede agregar la línea en los vértices o centro" << endl;
		}
		else {
			if (f % 2 == 1 && c % 2 == 0) {
				tablero[f][c] = '|';
			}
			else {
				tablero[f][c] = '-';
			}
		}
	}
}

bool Tablero3x5::Vacio(int f, int c) {
	return (tablero[f][c] != '|' && tablero[f][c] != '-');
}
//void Tablero3x5::Add(TableroComponente*) {}
	//Supongo que será un metodo para agregar otro Tablero

string Tablero3x5::toString() const {
	// Agregar los números de las columnas
	stringstream s;
	s << "    ";
	for (int col = 0; col < 11; ++col) {
		s << "  " << col;
	}
	s << std::endl;

	// Mostrar el contenido del tablero con números de filas
	for (int i = 0; i < 7; ++i) {
		s << "  " << i << " "; // Número de la fila
		for (int j = 0; j < 11; ++j) {
			s << "  ";
			s << tablero[i][j];
		}
		s << std::endl;
	}

	return s.str();
}
