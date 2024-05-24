#include "Tablero3X3.h"

Tablero3x3::Tablero3x3(){
	tablero = new char* [7];
	for (int i = 0; i < 7; i++) {
		tablero[i] = new char[7];
		for (int j = 0; j < 7; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				tablero[i][j] = '+';
			else
				tablero[i][j] = ' ';
		}
	}
}

Tablero3x3::~Tablero3x3(){
	for (int i = 0; i < 7; ++i) {
		delete[] tablero[i];
	}
	delete[] tablero;
}
int Tablero3x3::getAncho() const { return 7; };
int Tablero3x3::getAlto() const { return 7; };

char* Tablero3x3::GetValorCelda(int f, int c){
	if (f < 0 || f >= 7 || c < 0 || c >= 7) {
		throw out_of_range("posicion fuera del tablero");
	}
	else {
		return &tablero[f][c];
	}
	
	/*if (f >= 0 && f < 7 && c >= 0 && c < 7) {
		return string(1, tablero[f][c]);
	}
	return "";*/
}

void Tablero3x3::SetLineaCelda(int f, int c)
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
	/*if (f >= 0 && f < 3 && c >= 0 && c < 3) {
		tablero[f][c] = v;
	}*/
}

bool Tablero3x3::Vacio(int f, int c){
	return (tablero[f][c] != '|' && tablero[f][c] != '-');

	//if (tablero[f][c] != ".") /*Esta no vacio*/
	//{
	//	return false;
	//}
	//else { /*Esta  vacio*/
	//	return true;
	//}

}
//bool Tablero3x3::Add(TableroComponente*){}
	//Supongo que será un metodo para agregar otro Tablero

string Tablero3x3::toString() const{
	// Agregar los números de las columnas
	stringstream s; 
	s << "    ";
	for (int col = 0; col < 7; ++col) {
		s << "  " << col;
	}
	s << std::endl;

	// Mostrar el contenido del tablero con números de filas
	for (int i = 0; i < 7; ++i) {
		s << "  " << i << " "; // Número de la fila
		for (int j = 0; j < 7; ++j) {
			s << "  ";
			s << tablero[i][j];
		}
		s << std::endl;
	}

	return s.str();
	//stringstream s;
	//for (int i = 0; i < 7; ++i) {
	//	for (int j = 0; j < 7; ++j) {
	//		s << tablero[i][j] << "  ";
	//	}
	//	s << endl;
	//}
	//return s.str();

	////Ciclo para agregar los numeros de las columnas
	//s << "    ";
	//for (int col = 0; col < columnas; ++col) {
	//	s << "  " << col;
	//}
	//s << endl;
	//for (int i = 0; i < filas; ++i) {
	//	s << "  " << i << " "; // Número de la fila
	//	for (int j = 0; j < columnas; ++j) {
	//		s << "  ";
	//		//s << (tablero[i][j].empty() ? " " : tablero[i][j]) << " ";
	//		if (tablero[i][j] == " ") {
	//			s << " ";
	//		}
	//		else {
	//			s << tablero[i][j];
	//		}
	//	}
	//	s << endl;
	//}
	//return s.str();
	//stringstream s;
	//for (int i = 0; i < 7; ++i) {
	//	for (int j = 0; j < 7; ++j) {
	//		//s << (tablero[i][j].empty() ? " " : tablero[i][j]) << " ";
	//		if (tablero[i][j] == " ") {
	//			s << " ";
	//		}
	//		else {
	//			s << tablero[i][j];
	//		}
	//	}
	//	s << endl;
	//}
	//return s.str();
}
