#include "TableroCompuesto.h"

TableroCompuesto::TableroCompuesto() :TableroComponente(7, 7) {
	/*for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			tablero[i][j] = " + ";
		}
	}*/
}

TableroCompuesto::~TableroCompuesto() {}

string TableroCompuesto::GetValorCelda(int f, int c){
	if (f >= 0 && f < 6 && c >= 0 && c < 6) {
		return tablero[f][c];
	}
	return "";
}

void TableroCompuesto::SetLineaCelda(int f, int c){
	/*if (f >= 0 && f < 6 && c >= 0 && c < 6) {
		tablero[f][c] = tablero[f][c] + v;
	}*/
	if (this->Vacio(f,c) == false) {
		cout << "Ya hay una linea trazada en esa posicion" << endl;
	}
	else {
		if (f % 2 == 1 && c % 2 == 1 || f % 2 == 0 && c % 2 == 0) {
			cout << "No se puede agregar la linea en los vertices o centro" << endl;
		}
		else {
			if (f % 2 == 1 && c % 2 == 0) {	//Para que sea linea vertical la fila tiene que ser impar y la columna par
				tablero[f][c] = "|";
			}
			else     //Para que sea linea horizontal la fila tiene que ser par y la columna impar
				tablero[f][c] = "-";
		}
	}
}

bool TableroCompuesto::Vacio(int f, int c){
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
void TableroCompuesto::Add(TableroComponente& nuevo) {

}

string TableroCompuesto::toString() const{
	stringstream s;
	//Ciclo para agregar los numeros de las columnas
	s << "    ";
	for (int col = 0; col < columnas; ++col) {
		s <<"  " << col;
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
