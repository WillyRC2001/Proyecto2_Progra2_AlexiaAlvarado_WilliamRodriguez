#include "Juego.h"
#include <string>

Juego* Juego::juego = nullptr;

Juego::Juego()
{
	this->tablero = new TableroJuego();
	this->rm = nullptr;
	this->org = nullptr;
	this->con = 1;
}

Juego::~Juego()
{
}

Juego* Juego::getJuego()
{
	if (juego == nullptr) {
		juego = new Juego();
	}
	return juego;
}

Jugador* Juego::getJugador1()
{
	return jugador1;
}

Jugador* Juego::getJugador2()
{
	return jugador2;
}

TableroJuego* Juego::getCampo()
{
	return tablero;
}

void Juego::activarTablero(TableroCompuesto* comp)
{
	tablero->ActivarMatriz(comp);
}

string Juego::InfoJugador_1()
{
	return jugador1->toString();
}

string Juego::InfoJugador_2()
{
	return jugador2->toString();
}

string Juego::MostrarTablero()
{
	return tablero->toString();
}

int Juego::HacerJugada(Jugada* jug, int f,int c)
{
	int resultado = jug->anatorPunto(f, c);
	if (resultado == 1) { return 1; }
	else if (resultado == 2) { return 2; }
	else { return 0; }
}
int Juego::HacerJugadaCompu(JugadorComputadora* jug, int f, int c, int tip_estrategia)
{
	string opreglas;
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLineaCompu(jug, tablero, f, c, tip_estrategia);
	delete jugada;
	return 0;

}

int Juego::comanotarPosicion(Jugada* jug, int f, int c)
{
	int resultado = jug->comanatorPunto(f, c);
	if (resultado == 1) { return 1; }
	else if (resultado == 2) { return 2; }
	else { return 0; }
}

bool Juego::HayJugada() {
	if (tablero->HayEspacios() == true) {
		return true;
	}
	else {
		return false;
	}
}

void Juego::crearMemento()
{
	if (rm) delete rm;
	if (org)delete org;
	this->rm = new RepositorioMementos();
	this->org = new Originador();
}

void Juego::getMemento()
{
	org->setEstado(getCampo());
	rm->agregaMemento(org->retornarMemento());
}

void Juego::verMemento() { cout << rm->toString(); }
int Juego::getCont() { return con; }

void Juego::guarda()
{
	auto nuevo = std::to_string(con);
	std::string estado = rm->toString(); // Obtener el estado del juego como cadena
	std::ofstream archivo("Partida Guardada " + nuevo + ".txt"); // Crear y abrir el archivo
	if (archivo.is_open()) {
		archivo << estado; // Escribir el estado en el archivo
		archivo.close(); // Cerrar el archivo
		con++;
		guardaCont();
	}
	else {
		throw new ExcepcionArchivo();
	}

}

void Juego::carga(int cont)
{
	auto nuevo = std::to_string(cont);
	std::ifstream archivo("Partida Guardada " + nuevo + ".txt");
	if (archivo.is_open()) {
		std::stringstream buffer;
		buffer << archivo.rdbuf();
		std::string estado = buffer.str();
		std::cout << estado << std::endl; // Mostrar el estado guardado
		archivo.close();
	}
	else {
		throw new ExcepcionArchivo();
	}
}

void Juego::guardaCont()
{
	std::ofstream archivo("guardado.txt");
	if (archivo.is_open()) {
		archivo << con << "!";
		archivo.close();
	}
	else {
		throw new ExcepcionArchivo();
	}
}

void Juego::cargaCont()
{
	std::ifstream archivo("guardado.txt");
	if (archivo.is_open()) {
		std::string a;
		std::getline(archivo, a, '!');
		this->con = std::stoi(a);
		archivo.close();
	}
}
