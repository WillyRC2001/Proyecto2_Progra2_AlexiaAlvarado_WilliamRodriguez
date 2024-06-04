#include "MenuPrincipal.h"

int MenuPrincipal::menuPrincipal()
{
	int op = 0;
	cout << "----> Menu principal <----" << endl;
	/*cout << "[1] Continuar" << '\t';
	cout << "[2] Estrategias" << '\t';
	cout << "[3] Ver jugador" << '\t';
	cout << "[4] Salir" << endl;*/
	cout << "[1] Iniciar" << '\t';
	cout << "[2] En Que Consiste El Juego?" << '\t';
	cout << "[3] Salir" << endl;
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}

void MenuPrincipal::OpcionIniciar(){
}
void MenuPrincipal::OpcionEnQueConsi(){
	cout << "================En Que Consiste El Juego?===============" << endl;
	cout << "Es un juego de Estrategia en el que consiste en formar cuadrados dentro de un tablero marcado por filas y columnas," << endl;
	cout << "uno o dos jugadores deberan trazar lineas verticales y horizontales para formar los cuadrados, " << endl;
	cout << "cada jugador solo puede trazar una linea por turno." << endl;
	cout << "Puedes aprovechar lineas de otro jugador a tu beneficio para formar el cuadrado" << endl;
	cout << "Una vez que un jugador haya formado dicha figura, este se le asignara la inicial de su nombre y ganara un punto." << endl;
	cout << "El juego termina cuando ya no hayan mas movimientos en el tablero y el jugador que tenga mas puntos, gana" << endl << endl;
	cout << "  1 2 3 4 5" << endl;
	cout << "1 + - +   +" << endl;
	cout << "2 | A |    " << endl;
	cout << "3 + - +   +" << endl;
	cout << endl;
}
void MenuPrincipal::OpcionSalir(){}
TableroCompuesto* MenuPrincipal::creartablero()
{
	int cant = 0, cont = 0, op = 0;
	TableroCompuesto* tableroCompuesto = new TableroCompuesto();
	cout << "Se puede ingresar un maximo de 5 tableros." << endl;
	cout << "Digite la cantidad de tableros que desea: "; cin >> cant;
	comprobarInt(cant);
	if (cant <= 5) { /*Tamano del vector del compuesto */
		while (cont < cant) {
			cout << "Dijite el tamano del Tablero <----" << endl;
			cout << "[1] 3x3" << '\t';
			cout << "[2] 3x4" << '\t';
			cout << "[3] 3x5" << '\t';
			cout << endl << ": ";
			cin >> op;
			if (op == 1) {
				TableroComponente* tab1 = new Tablero3x3();
				tableroCompuesto->AddMatriz(tab1);
				cont++;
			}
			if (op == 2) {
				TableroComponente* tab2 = new Tablero3x4();
				tableroCompuesto->AddMatriz(tab2);
				cont++;
			}
			if (op == 3) {
				TableroComponente* tab3 = new Tablero3x5();
				tableroCompuesto->AddMatriz(tab3);
				cont++;
			}
			if(op >= 4 || op<= 0){
				cout << endl << "Numero mal digitado vuelva a intentar" << '\t';
			}
		}
	}
	else {
		throw new ExcepcionFueraRango();
	}
	return tableroCompuesto;
}


Jugador* MenuPrincipal::crearJugador()
{
	string nombre;
	cout << "Dijite su nombre "; getline(cin, nombre);
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el búfer
	Jugador* juga = new JugadorHumano(nombre);
	return juga;
}

void MenuPrincipal::MostrarReglas(){
	Jugada* jugada = new Jugada(NULL);
	jugada->MostrarReglas();
	delete jugada;
}
void MenuPrincipal::JugadaJugador(Juego* juego, int fila, int columna, Jugador* jug){
	juego->HacerJugada(jug, fila, columna);
}


void MenuPrincipal::excepcionRango(Excepcion* e)
{
	cout << e->toString() << '\n';
}

void MenuPrincipal::error()
{
	cout << "ERROR DESCONOCIDO.\n";
}

void MenuPrincipal::comprobarInt(int entero)
{
	if (cin.fail() || entero <= 0.0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		throw new ExcepcionFueraRango();
	}
}

void MenuPrincipal::compronarDouble(double entero)
{
	if (cin.fail() || entero <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		throw new ExcepcionFueraRango();
	}
}

void MenuPrincipal::Bienvenida()
{
	cout << "----> Bienvenida <----" << endl;
}

void MenuPrincipal::salir()
{
	cout << "---------------------> C R E A D O R E S <---------------------" << endl << endl;
	cout << "Alexia Alvarado Alfaro  || Grupo 05 (1pm)" << endl;
	cout << "William Rodriguez Campos  || Grupo 06 (3pm)" << endl;
	cout << endl << "----------> G R A C I A S   P O R   U T I L I Z A R <----------" << endl << endl;
}
