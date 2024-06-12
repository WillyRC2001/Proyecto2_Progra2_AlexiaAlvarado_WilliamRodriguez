#include "Tablero3X4.h"

Tablero3x4::Tablero3x4() {
	tablero = new char* [9];
	for (int i = 0; i < 7; i++) {
		tablero[i] = new char[9];
		for (int j = 0; j < 9; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				tablero[i][j] = '+';
			else
				tablero[i][j] = ' ';
		}
	}
}

Tablero3x4::~Tablero3x4() {
	for (int i = 0; i < 9; ++i) {
		delete[] tablero[i];
	}
	delete[] tablero;
}
int Tablero3x4::AnchuraColumnas() const { return 9; };
int Tablero3x4::AlturaFilas() const { return 7; };

char* Tablero3x4::GetValorCelda(int f, int c) const {
	if (f < 0 || f >= 7 || c < 0 || c >= 9) {
		throw out_of_range("posicion fuera del tablero");
	}
	else {
		return &tablero[f][c];
	}

}

void Tablero3x4::SetLineaCelda(int f, int c)
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

bool Tablero3x4::Vacio(int f, int c) const {
	return (tablero[f][c] != '|' && tablero[f][c] != '-');
}

string Tablero3x4::toString() const {
	// Agregar los números de las columnas
	stringstream s;
	s << "    ";
	for (int col = 0; col < 9; ++col) {
		s << "  " << col;
	}
	s << std::endl;

	// Mostrar el contenido del tablero con números de filas
	for (int i = 0; i < 7; ++i) {
		s << "  " << i << " "; // Número de la fila
		for (int j = 0; j < 9; ++j) {
			s << "  ";
			s << tablero[i][j];
		}
		s << std::endl;
	}

	return s.str();
}