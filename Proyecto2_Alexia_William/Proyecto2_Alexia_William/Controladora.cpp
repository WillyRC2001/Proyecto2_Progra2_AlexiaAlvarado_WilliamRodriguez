#include "Controladora.h"

Controladora::Controladora()
{
	juego = Juego::getJuego();
	opcion = 0;
	juego->cargaCont();
	comm = 0;
}

Controladora::~Controladora()
{
	if (juego != nullptr) delete juego;
}

void Controladora::controlPrincipal()
{
	MenuPrincipal::Bienvenida();
	system("pause");
	system("cls");
	do {
		opcion = MenuPrincipal::menuPrincipal();
		system("pause");
		system("cls");
		try {
			switch (opcion) {
			case 1:
				controlJugar();
				system("cls");
				opcion = 0;
				break;
			case 2:
				verReglas();
				system("cls");
				break;
			case 3:
				if (juego->getCont() > 1) {
					Archivos1();
					system("cls");
				}
				else {
					MenuPrincipal::noArchivos();
					system("pause");
					system("cls");
				}
				break;
			case 4:
				Finalizar();
				break;
			default:
				throw new ExcepcionFueraRango();
				break;
			}
		}
		catch (Excepcion* e) {
			MenuPrincipal::excepcionRango(e);
			system("pause");
			system("cls");
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 4);
}


void Controladora::controlJugar()
{
	do {
		opcion = MenuPrincipal::menuJuego();
		system("pause");
		system("cls");
		try {
			switch (opcion) {
			case 1:
				Jugar1();
				system("cls");
				break;
			case 2:
				Jugar2();
				system("cls");
				break;
			case 3:
				break;
			default:
				throw new ExcepcionFueraRango();
				break;
			}
		}
		catch (Excepcion* e) {
			MenuPrincipal::excepcionRango(e);
			system("pause");
			system("cls");
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 3);
}

void Controladora::Jugar1()
{
	int op = MenuPrincipal::Oponente();
	system("pause");
	system("cls");
	do {
		if (op == 1) {
			// Dos jugadores 
			Jugar1vs1();
			system("pause");
			system("cls");
		}
		else if (op == 2) {
			//Computadora
			Jugar1vsC();
			system("pause");
			system("cls");
		}
		else {
			op = 3;
		}
	} while (op == 3);
}

void Controladora::Jugar1vs1()
{
	int par = 0;
	int op = 0, op2 = 2;
	int resultado = 0;
	juego->crearMemento();
	Jugador* jugador1 = MenuPrincipal::crearJugador();
	Jugador* jugador2 = MenuPrincipal::crearJugador();
	system("pause");
	system("cls");
	/*Se crea tablero*/
	TableroCompuesto* tab = MenuPrincipal::creartablero();
	juego->activarTablero(tab);
	system("pause");
	system("cls");
	Punto* punto = new Punto(juego->getCampo());
	Punto* punto2 = new Punto(juego->getCampo());
	Jugada* jugada = new Jugada(jugador1);
	Jugada* jugada2 = new Jugada(jugador2);
	jugada->setPunto(punto);
	jugada2->setPunto(punto2);
	do {
		if (par % 2 == 0) {
			cout << juego->MostrarTablero() << endl;
			cout << "\nTurno de jugador: " << jugada->MostrarInfoJugador() << endl;
			int fila = MenuPrincipal::fila();
			int columna = MenuPrincipal::columna();
			int resultado = juego->HacerJugada(jugada, fila, columna);
			if (resultado == 1) {
				par++;
				juego->getMemento();
			}
			else if (resultado == 2) {
				juego->getMemento();
			}
			else if (resultado == 0) {
				MenuPrincipal::errorFoC();
			}
		}
		else {
			cout << juego->MostrarTablero() << endl;
			cout << "\nTurno de jugador: " << jugada2->MostrarInfoJugador() << endl;
			int fila = MenuPrincipal::fila();
			int columna = MenuPrincipal::columna();
			resultado = juego->HacerJugada(jugada2, fila, columna);
			if (resultado == 1) {
				par++;
				juego->getMemento();
			}
			else if (resultado == 2) {
				juego->getMemento();
			}
			else if (resultado == 0) {
				MenuPrincipal::errorFoC();
			}
		}
		system("pause");
		system("cls");
	} while (juego->HayJugada() == true);
	cout << juego->MostrarTablero() << endl;
	system("pause");
	system("cls");
	MenuPrincipal::FinalDePartida(jugador1, jugador2);
	comm++;
	delete jugada;
	delete jugada2;
	system("pause");
	system("cls");
}

void Controladora::Jugar1vsC()
{
	int par = 0;
	int op = 0, op2 = 2;
	int fila = 0;
	int columna = 0;
	int resultado = 0;
	cout << juego->MostrarTablero() << endl;
	Jugador* jugador1 = MenuPrincipal::crearJugador();
	Jugador* jugador2 = MenuPrincipal::crearComputadora();
	system("pause");
	system("cls");
	/*Se crea tablero*/
	Punto* punto = new Punto(juego->getCampo());
	Punto* punto2 = new Punto(juego->getCampo());
	Jugada* jugada = new Jugada(jugador1);
	Jugada* jugada2 = new Jugada(jugador2);
	jugada->setPunto(punto);
	jugada2->setPunto(punto2);
	TableroCompuesto* tab = MenuPrincipal::creartablero();
	juego->activarTablero(tab);
	system("pause");
	system("cls");
	do {
		if (par % 2 == 0) {
			resultado = 0;
			cout << juego->MostrarTablero() << endl;
			cout << "\nTurno de jugador: " << jugada->MostrarInfoJugador() << endl;
			fila = MenuPrincipal::fila();
			columna = MenuPrincipal::columna();
			resultado = juego->HacerJugada(jugada, fila, columna);
			if (resultado == 1) {
				par++;
				juego->getMemento();
				op2 = MenuPrincipal::Cambiar();
				if (op2 == 2) {
					jugador2 = MenuPrincipal::crearComputadora();
				}
			}
			else if (resultado == 2) {
				juego->getMemento();
			}
			else if (resultado == 0) {
				MenuPrincipal::errorFoC();
			}
		}
		else {
			resultado = 0;
			cout << juego->MostrarTablero() << endl;
			cout << "\nTurno de jugador: " << jugada2->MostrarInfoJugador() << endl;
			resultado = juego->comanotarPosicion(jugada2, fila, columna);
			if (resultado == 1) {
				par++;
				juego->getMemento();
			}
			else if (resultado == 2) {
				juego->getMemento();
			}
			else if (resultado == 0) {
				MenuPrincipal::errorFoC();
			}
		}
		system("pause");
		system("cls");
	} while (juego->HayJugada() == true);
	juego->MostrarTablero();
	system("pause");
	system("cls");
	MenuPrincipal::FinalDePartida(jugador1, jugador2);
	comm++;
	delete jugada;
	delete jugada2;
	system("pause");
	system("cls");
}


void Controladora::Jugar2() {

	if (comm >= 1) {
		juego->verMemento();
		int op = MenuPrincipal::GuardarPartida();
		if (op == 1) {
			juego->guarda();
		}
	}
	else
		MenuPrincipal::noMemento();
	system("pause");
	system("cls");
}




void Controladora::verReglas()
{
	Jugada* reglas = new Jugada();
	reglas->MostrarReglas();
	system("pause");
	system("cls");
	delete reglas;

}

void Controladora::Finalizar()
{
	MenuPrincipal::salir();
}

void Controladora::Archivos1() {
	int cont = MenuPrincipal::Archivos(juego->getCont());
	system("cls");
	if (cont > 0) {
		juego->carga(cont);
		system("pause");
		system("cls");
	}

}