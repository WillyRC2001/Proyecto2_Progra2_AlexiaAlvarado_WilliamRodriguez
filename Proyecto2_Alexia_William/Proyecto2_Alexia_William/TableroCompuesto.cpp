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

char* TableroCompuesto::GetValorCelda(int f, int c){
	return new char(' ');
}

void TableroCompuesto::SetLineaCelda(int f, int c){
	for (int i = 0; i < can; ++i) {
		if (vec[i]->Vacio(f, c)) {
			vec[i]->SetLineaCelda(f, c);
			return;
		}
	}
}

bool TableroCompuesto::Vacio(int f, int c){
	for (int i = 0; i < can; ++i) {
		if (!vec[i]->Vacio(f, c)) {
			return false;
		}
	}
	return true;
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

TableroComponente* TableroCompuesto::GetMatriz(int i) const
{
	if (i >= 0 && i < can) {
		return vec[i];
	}
	return nullptr;
}

string TableroCompuesto::toString() const{
	stringstream s;
	for (int i = 0; i < can; ++i) {
		s << vec[i]->toString() << "\n";
	}
	return s.str();
	return "";
}
int TableroCompuesto::AnchuraColumnas() const { return 0; }
int TableroCompuesto::AlturaFilas() const { return 0; }
