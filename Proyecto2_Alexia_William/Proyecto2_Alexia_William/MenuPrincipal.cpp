#include "MenuPrincipal.h"

int MenuPrincipal::menuPrincipal()
{
	int op = 0;
	cout << "----> Menu principal <----" << endl;
	cout << "[1] Jugar " << '\n';
	cout << "[2] Reglas " << '\n';
	cout << "[3] Partidas Pasadas" << endl;
	cout << "[4] Salir" << endl;
	cout << "Ingrese la opccion: ";
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}

int MenuPrincipal::menuJuego()
{
	int op = 0;
	cout << "----> Menu Juego <----" << endl;
	cout << "[1] Partida Nueva" << '\n';
	cout << "[2] Ver partida" << '\n';
	cout << "[3] Salir" << '\n';
	cout << "Ingrese la opccion: ";
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}

int MenuPrincipal::menuPartida()
{
	int op = 0;
	cout << "----> Menu <----" << endl;
	cout << "[1] Continuar" << '\t';
	cout << "[2] Cambiar estrategia" << '\t';
	cout << "Ingrese la opccion: ";
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}


TableroCompuesto* MenuPrincipal::creartablero()
{
	int cant = 0, cont = 0, op = 0;
	bool pasa = false;
	TableroCompuesto* tableroCompuesto = new TableroCompuesto();
	while (pasa != true) {
		cout << "----> Se puede ingresar un maxino de 5 tableros <----" << endl;
		cout << "Ingrese la cantida de tablero que desea: "; cin >> cant;
		if (cin.fail() || cant < 0 || cant > 5) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intenar" << '\n';
			system("pause");
			system("cls");
		}
		else {
			pasa = true;
		}
		if (cant <= 5) { /*Tamano del vector del compuesesto */
			while (cont < cant) {
				cout << "Ingrese el tamano del tablero: " << endl;
				cout << "[1] 3x3" << '\t';
				cout << "[2] 3x4" << '\t';
				cout << "[3] 3x5" << '\t';
				cout << endl << "digite opcion: ";
				cin >> op;

				if (cin.fail() || op < 0 || op > 3) {
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					cout << "Error: Vuelva a intenar" << '\n';
					system("pause");
					system("cls");
				}
				if (op == 1) {
					TableroComponente* tab1 = new Tablero3x3();
					tableroCompuesto->AddMatriz(tab1);
					cont++;
				}
				else if (op == 2) {
					TableroComponente* tab2 = new Tablero3x4();
					tableroCompuesto->AddMatriz(tab2);
					cont++;
				}
				else  if (op == 3) {
					TableroComponente* tab3 = new Tablero3x5();
					tableroCompuesto->AddMatriz(tab3);
					cont++;
				}

			}
		}
	}
	return tableroCompuesto;
}


Jugador* MenuPrincipal::crearJugador()
{
	string nombre;
	cout << "----> Creacion de Jugador <---- " << endl;
	cout << "Dijite su nombre: "; cin >> nombre;
	cout << endl;
	Jugador* juga = new JugadorHumano(nombre);
	return juga;
}

Jugador* MenuPrincipal::crearComputadora()
{
	cout << "----> Creacion de Jugador <---- " << endl;
	Jugador* robot = new JugadorComputadora();
	cout << endl;
	return robot;
}

Estrategia* MenuPrincipal::selecionarEstrategia()
{
	int op = 0;
	bool pasa = false;
	while (pasa != true) {
		cout << "----> Seleccion de estrategia <----" << endl;
		cout << "[1] Aleatoria " << '\t';
		cout << "[2] Cercano " << '\t';
		cout << "[3] Central " << '\t';
		cout << "[4] Periferico " << '\t';
		cout << "[5] Isla " << '\n';
		cout << "Ingrese la opccion: ";
		cin >> op;
		if (cin.fail() || op < 0 || op > 5) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intenar" << '\n';
			system("pause");
			system("cls");
		}
		else {
			pasa = true;
		}

		if (op == 1) {
			Estrategia* estragia = new EstrategiaAleatoria();
			return estragia;
		}
		else if (op == 2) {
			Estrategia* estragia = new EstrategiaCercano();
			return estragia;
		}
		else if (op == 3) {
			Estrategia* estragia = new EstrategiaCentral();
			return estragia;
		}
		else if (op == 4) {
			Estrategia* estragia = new EstrategiaPeriferico;
			return estragia;
		}
		else if (op == 5) {
			Estrategia* estragia = new EstrategiaIslas();
			return estragia;
		}
	}
}

void MenuPrincipal::cambiarEstrategia(Jugador* rob)
{
	rob->setearEstrategias(selecionarEstrategia());
}

int MenuPrincipal::Oponente()
{
	int op = 0;
	bool pasa = false;
	while (pasa != true) {
		cout << "----> Seleccion de oponente <----" << endl;
		cout << "[1] Jugador" << '\n';
		cout << "[2] Computadora" << '\n';
		cout << "Ingrese la opcion: ";
		cin >> op;
		if (cin.fail() || op < 0 || op > 2) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intentar" << '\n';
			system("pause");
			system("cls");
		}
		else {
			pasa = true;
		}
	}
	return op;
}

int MenuPrincipal::Cambiar()
{
	int op = 0;
	bool pasa = false;
	while (pasa != true) {
		cout << "[1] Continuar" << '\n';
		cout << "[2] Cambiar estrategia " << '\n';
		cout << "Ingrese la opccion: ";
		cin >> op;
		if (cin.fail() || op < 0 || op > 2) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intenar" << '\n';
			system("pause");
			system("cls");
		}
		else {
			pasa = true;
		}
	}
	return op;
}

int MenuPrincipal::GuardarPartida()
{
	int opcion = 0;
	cout << "----> Guardar Partida <----" << endl;
	cout << " [1] Si \t";
	cout << " [2] No " << endl;
	cout << " Ingrese su opcion: ";
	cin >> opcion;
	comprobarInt(opcion);
	return opcion;
}


int MenuPrincipal::fila()
{
	int op = 0;
	bool pasa = false;
	while (pasa != true) {
		cout << "Ingrese la fila: "; cin >> op;
		if (cin.fail() || op < 0 || op > 23) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intenar" << '\n';
		}
		else {
			pasa = true;
		}
	}

	return op;
}

int MenuPrincipal::columna()
{
	int op = 0;
	bool pasa = false;
	while (pasa != true) {
		cout << "Ingrese la columna: ";  cin >> op;
		if (cin.fail() || op < 0.0 || op > 23) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			pasa = false;
			cout << "Error: Vuelva a intenar." << '\n';
		}
		else {
			pasa = true;
		}
	}
	return op;
}

void MenuPrincipal::FinalDePartida(Jugador* ju1, Jugador* ju2)
{
	cout << "El jugador: " << ju1->getNombreJugador() << " tiene: " << ju1->getPuntos() << " puntos." << '\n';
	cout << "El jugador: " << ju2->getNombreJugador() << " tiene: " << ju2->getPuntos() << " puntos." << '\n';
	cout << endl;
	cout << "----> Ganador <----" << endl;
	if (ju1->getPuntos() > ju2->getPuntos()) {
		cout << "El jugador: " << ju1->getNombreJugador() << " es el ganador." << '\n';
	}
	else if (ju1->getPuntos() == ju2->getPuntos()) {
		cout << "Es un empate " << '\n';
	}
	else {
		cout << "El jugador: " << ju2->getNombreJugador() << " es el ganador." << '\n';
	}

}

void MenuPrincipal::excepcionRango(Excepcion* e)
{
	cout << e->toString() << '\n';
}

void MenuPrincipal::error()
{
	cout << "ERROR DESCONOCIDO.\n";
}

void MenuPrincipal::errorFoC()
{
	cout << "ERROR: Fila o columna no disponible.\n";
}

void MenuPrincipal::comprobarInt(int entero)
{
	if (cin.fail() || entero <= 0.0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		throw new ExcepcionFueraRango();
	}
}

void MenuPrincipal::comprobarDouble(double entero)
{
	if (cin.fail() || entero <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		throw new ExcepcionFueraRango();
	}
}

void MenuPrincipal::Bienvenida()
{
	cout << "----> Bienvenidos <----" << endl;
	cout << "Juego Dots and Boxes" << endl;
	cout << "Proyecto #2 Programacion 2 " << endl;

}

void MenuPrincipal::salir()
{
	cout << "---------------------> C R E A D O R E S <---------------------" << endl << endl;
	cout << "Alexia Alvarado Alfaro  || Grupo 05 (1pm)" << endl;
	cout << "William Rodriguez Campos  || Grupo 06 (3pm)" << endl;
	cout << endl << "----------> G R A C I A S   P O R   U T I L I Z A R <----------" << endl << endl;
}

int MenuPrincipal::Archivos(int cant)
{
	int opcion = 0;
	cout << " Lista de Partidas jugadas" << endl;
	cout << endl;
	for (int i = 1; i < cant; i++) {
		cout << " [" << i << "] Partida " << i << endl;
	}
	cout << " [0] salir " << endl;
	cout << endl;
	cout << " Ingrese su opcion: ";
	cin >> opcion;
	if (cin.fail() || opcion < 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		throw new ExcepcionFueraRango();
	}
	return opcion;
}

void MenuPrincipal::noArchivos() { cout << "No hay partidas guardadas" << endl; }

void MenuPrincipal::noMemento() { cout << "No se ha realiza una partida" << endl; }

