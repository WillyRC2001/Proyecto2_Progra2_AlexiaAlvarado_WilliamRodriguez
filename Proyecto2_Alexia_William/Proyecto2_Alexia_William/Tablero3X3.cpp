#include "Tablero3X3.h"

Tablero3x3::Tablero3x3() : TableroComponente(7, 7) {}

Tablero3x3::~Tablero3x3(){}

string Tablero3x3::GetValorCelda(int f, int c){
	if (f >= 0 && f < 7 && c >= 0 && c < 7) {
		return tablero[f][c];
	}
	return "";
}

void Tablero3x3::SetLineaCelda(int f, int c)
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
	/*if (f >= 0 && f < 3 && c >= 0 && c < 3) {
		tablero[f][c] = v;
	}*/
}

bool Tablero3x3::Vacio(int f, int c){
	if (tablero[f][c] == "|" || tablero[f][c] == "-") {
		return false;
	}
	else
		return true;
	//if (tablero[f][c] != ".") /*Esta no vacio*/
	//{
	//	return false;
	//}
	//else { /*Esta  vacio*/
	//	return true;
	//}

}
void Tablero3x3::Add(TableroComponente&){
	//Supongo que será un metodo para agregar otro Tablero
}

string Tablero3x3::toString() const{
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
