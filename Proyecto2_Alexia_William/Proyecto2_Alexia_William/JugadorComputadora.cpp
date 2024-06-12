#include "JugadorComputadora.h"

JugadorComputadora::JugadorComputadora(string nom, Estrategia* est) : Jugador(nom)
{
	this->estrategia = new EstrategiaAleatoria();
	this->Letra = '#';
}
JugadorComputadora::~JugadorComputadora(){
	delete estrategia;
}
string JugadorComputadora::getNombreJugador(){
	return this->getNombreJugador();
}
void JugadorComputadora::setNombreJugador(string jug) { nombre = jug; }
char JugadorComputadora::getInicial(){
	return Letra;
}
int JugadorComputadora::getPuntos(){
	return puntos;
}
void JugadorComputadora::setPuntos(int punt){
	puntos = punt;
}
void JugadorComputadora::aumentarPuntos() { puntos++; }
string JugadorComputadora::toString() const 
{
	stringstream s;
	s << "\t" << nombre << " , tiene " << puntos << " puntos" << endl;
	return s.str();
}
Estrategia* JugadorComputadora::obtenerEstrategias() {
	return estrategia;
}

void JugadorComputadora::setearEstrategias(Estrategia* estra)
{
	if (estrategia != nullptr) delete estrategia;
	estrategia = estra;
}

//Estrategias
void JugadorComputadora::estrategiaAleatoria(){
	delete this->estrategia;
	this->estrategia = new EstrategiaAleatoria();
}
void JugadorComputadora::estrategiaCercano(){
	delete this->estrategia;
	this->estrategia = new EstrategiaCercano();
}
void JugadorComputadora::estrategiaPeriferico(){
	delete this->estrategia;
	this->estrategia = new EstrategiaPeriferico();
}
void JugadorComputadora::estrategiaCentral(){
	delete this->estrategia;
	this->estrategia = new EstrategiaCentral();
}
void JugadorComputadora::estrategiaIslas(){
	delete this->estrategia;
	this->estrategia = new EstrategiaIslas();
}


