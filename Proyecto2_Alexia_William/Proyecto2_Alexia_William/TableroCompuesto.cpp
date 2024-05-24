#include "TableroCompuesto.h"

TableroCompuesto::TableroCompuesto():tam(20),can(0){
	vec = new TableroComponente * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = nullptr;
	}
}

TableroCompuesto::~TableroCompuesto() {
	for (int i = 0; i < can; i++) delete vec[i];
	delete[] vec;
}

string TableroCompuesto::GetValorCelda(int f, int c){

	for (int i = 0; i < can; ++i) {
		string valor = vec[i]->GetValorCelda(f, c);
		if (!valor.empty()) {
			return valor;
		}
	}
	return "";
	/*if (f >= 0 && f < 6 && c >= 0 && c < 6) {
		return tablero[f][c];
	}
	return "";*/
}

void TableroCompuesto::SetLineaCelda(int f, int c){
	for (int i = 0; i < can; ++i) {
		if (vec[i]->Vacio(f, c)) {
			vec[i]->SetLineaCelda(f, c);
			return;
		}
	}

	/*if (f >= 0 && f < 6 && c >= 0 && c < 6) {
		tablero[f][c] = tablero[f][c] + v;
	}*/
	//if (this->Vacio(f,c) == false) {
	//	cout << "Ya hay una linea trazada en esa posicion" << endl;
	//}
	//else {
	//	if (f % 2 == 1 && c % 2 == 1 || f % 2 == 0 && c % 2 == 0) {
	//		cout << "No se puede agregar la linea en los vertices o centro" << endl;
	//	}
	//	else {
	//		if (f % 2 == 1 && c % 2 == 0) {	//Para que sea linea vertical la fila tiene que ser impar y la columna par
	//			tablero[f][c] = "|";
	//		}
	//		else     //Para que sea linea horizontal la fila tiene que ser par y la columna impar
	//			tablero[f][c] = "-";
	//	}
	//}
}

bool TableroCompuesto::Vacio(int f, int c){
	for (int i = 0; i < can; ++i) {
		if (!vec[i]->Vacio(f, c)) {
			return false;
		}
	}
	return true;

	/*if (tablero[f][c] == "|" || tablero[f][c] == "-") {
		return false;
	}
	else
		return true;*/
	//if (tablero[f][c] != ".") /*Esta no vacio*/
	//{
	//	return false;
	//}
	//else { /*Esta  vacio*/
	//	return true;
	//}
}
bool TableroCompuesto::AddMatriz(TableroComponente* nuevo) {
	if (can < tam) {
		vec[can++] = nuevo;
		return true;
	}
	else {
		return false; 
	}
}

int TableroCompuesto::GetCantidad() const
{
	return can;
}

TableroComponente* TableroCompuesto::GetMatriz(int index) const
{
	if (index >= 0 && index < can) {
		return vec[index];
	}
	return nullptr;
}

string TableroCompuesto::toString() const{
	stringstream s;
	for (int i = 0; i < can; ++i) {
		s << vec[i]->toString() << "\n";
	}
	return s.str();

	//stringstream s;
	////Ciclo para agregar los numeros de las columnas
	//s << "    ";
	//for (int col = 0; col < columnas; ++col) {
	//	s <<"  " << col;
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
	return "";
}
