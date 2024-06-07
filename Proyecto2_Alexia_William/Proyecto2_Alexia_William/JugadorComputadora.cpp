#include "JugadorComputadora.h"

JugadorComputadora::JugadorComputadora():Jugador("Computadora")
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
char JugadorComputadora::getInicial(){
	return Letra;
}
int JugadorComputadora::getPuntos(){
	return puntos;
}
void JugadorComputadora::setPuntos(int punt){
	puntos = punt;
}
string JugadorComputadora::toString() const { return " "; }
Estrategia* JugadorComputadora::getestrategia() {
	return estrategia;
}
void JugadorComputadora::setNombreJugador(string jug){}
void JugadorComputadora::aumentarPuntos(){}

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


