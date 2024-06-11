#include "Juego.h"

Juego::Juego(Jugador* jug1, Jugador* jug2, TableroJuego* tab)
{
	jugador1 = jug1;
	jugador2 = jug2;
	juego = tab;
}

Juego::~Juego()
{
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
	return juego;
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
	return juego->toString();
}

void Juego::HacerJugada(Jugador* jug, int f,int c)
{
	string opreglas;
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLinea(f, c, juego);
	delete jugada;
}
void Juego::HacerJugadaCompu(JugadorComputadora* jug, int f, int c, int tip_estrategia)
{
	string opreglas;
	Jugada* jugada = new Jugada(jug);
	jugada->AgregarLineaCompu(jug, juego, f, c, tip_estrategia);
	delete jugada;
}

bool Juego::HayJugada() {
	return juego->HayEspacios();
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
