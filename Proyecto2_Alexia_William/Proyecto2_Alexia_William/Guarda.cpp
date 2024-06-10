#include "Guarda.h"

Guarda::Guarda(int cont) {
	this->cont = cont;
}
int Guarda::getCont() {
	return cont;
}
void Guarda::guardando(string guardado) {
	auto nuevo = std::to_string(cont);
	string nombre = "Partida Guardada " + nuevo + ".txt";
	writte.open(nombre, ios::out);
	writte << guardado;
	writte.close();
	cont++;
	guardaImportante(); //guardo el contador, aqui para evitar perdida de datos
}
void Guarda::guardaImportante() {
	writte.open("guardado.txt", ios::out);
	writte << cont << "!";
	writte.close();
}
void Guarda::recuperaImportante() {
	read.open("guardado.txt", ios::in);
	if (read.is_open()) {
		string a;
		getline(read, a, '!');
		this->cont = atoi(a.c_str());
		read.close();
	}
}
void Guarda::guardaJugada(const string& jugador, int fila, int columna, int puntos) {
	writte.open("jugadas.txt", ios::app); // Abrir en modo append para no sobreescribir
	if (writte.is_open()) {
		writte << "Jugador: " << jugador << ", Fila: " << fila << ", Columna: " << columna << ", Puntos: " << puntos << endl;
		writte.close();
	}
}

void Guarda::recuperaJugadas() {
	read.open("jugadas.txt", ios::in);
	if (read.is_open()) {
		string linea;
		while (getline(read, linea)) {
			// Aquí puedes procesar cada línea leída
			writte << linea << endl;
		}
		read.close();
	}
}
Guarda::~Guarda() {
}