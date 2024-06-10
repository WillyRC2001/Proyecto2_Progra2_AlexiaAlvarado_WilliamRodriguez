#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
{
	tableroJuego = new TableroJuego();
	guardado = new Guarda();
	guardado->recuperaImportante();  //recupero el contador
}

int MenuPrincipal::menuPrincipal()
{
	int op = 0;
	cout << "----> Menu principal <----" << endl;
	cout << "[1] Iniciar" << '\t';
	cout << "[2] En Que Consiste El Juego?" << '\t';
	cout << "[3] Recuperar Jugada anterior" << '\t';
	cout << "[4] Salir" << endl;
	cout << endl << "Ingrese la opcion: " << endl;
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}

void MenuPrincipal::OpcionIniciar(MenuPrincipal* instancia) {
	Juego* juego;
	TableroCompuesto* compuesto;
	TableroJuego* tablero = new TableroJuego();
	Jugador* jug1 = NULL;
	Jugador* jug2 = NULL;
	JugadorComputadora* jug3 = NULL;
	int opJugador;
	cout << "Elige la modalidad: " << endl;
	cout << "[1] Jugador vs Jugador" << endl;
	cout << "[2] Jugador vs Computadora" << endl;
	cout << endl << "Ingrese la opcion: " << endl;
	cin >> opJugador;
	system("cls");
	switch (opJugador) {
	case 1:	//Opcion de JvsJ
		cout << "Jugador 1" << endl;
		jug1 = MenuPrincipal::crearJugador();
		cout << "Jugador 2" << endl;
		jug2 = MenuPrincipal::crearJugador();
		break;
	case 2:	//Opcion de JvsPC
		cout << "Jugador 1" << endl;
		jug1 = MenuPrincipal::crearJugador();
		jug2 = NULL;
		jug3 = new JugadorComputadora();
		break;
	}//Fin del switch

	cout << "Creando El Tablero de Juego..." << endl;
	compuesto = MenuPrincipal::creartablero();
	tablero->ActivarMatriz(compuesto);
	juego = new Juego(jug1, jug2, tablero);
	system("pause");
	system("cls");
	//A partir de aqui empieza el juego
	int fila;
	int columna;
	if (jug2 != NULL) {	//Juego de JvsJ
		do {
			Jugada* jugadaReglas = new Jugada(NULL);	//Para mostrar las reglas
			jugadaReglas->MostrarReglas();
			cout << endl << endl;
			cout << juego->MostrarTablero() << endl;
			cout << "==============TURNO JUGADOR 1==============" << endl;
			cout << "Digite la fila: "; cin >> fila;
			cout << "Digite la columna:"; cin >> columna;
			juego->HacerJugada(jug1, fila, columna);
			system("cls");
			jugadaReglas->MostrarReglas();
			cout << endl << endl;
			cout << juego->MostrarTablero() << endl;
			cout << "==============TURNO JUGADOR 2==============" << endl;
			cout << "Digite la fila: "; cin >> fila;
			cout << "Digite la columna:"; cin >> columna;
			juego->HacerJugada(jug2, fila, columna);
			system("cls");
			delete jugadaReglas;
		} while (juego->HayJugada() != false);
		//Fin del juego JvsJ, Revisando quien es el ganador
		cout << juego->MostrarTablero() << endl;
		if (jug1->getPuntos() > jug2->getPuntos()) {
			cout << "Ganador es: " << jug1->getNombreJugador() << "!!!!!" << endl;
		}
		else {
			cout << "Ganador es: " << jug2->getNombreJugador() << "!!!!!" << endl;
		}
	}
	else {		//Juego JvsPC
		cout << "Jugador vs Computadora, proximamente...." << endl;
		//Aqui vendría todo el proceso del juego contra la computadora
		cout << jug3->getPuntos() << endl;;
		do {
			Jugada* jugadaReglas = new Jugada(NULL);	//Para mostrar las reglas
			jugadaReglas->MostrarReglas();
			cout << endl << endl;
			cout << juego->MostrarTablero() << endl;
			cout << "==============TURNO JUGADOR==============" << endl;
			cout << "Digite la fila: "; cin >> fila;
			cout << "Digite la columna:"; cin >> columna;
			juego->HacerJugada(jug1, fila, columna);
			juego->HacerJugadaCompu(jug3, fila, columna);
			system("cls");
			delete jugadaReglas;
		} while (juego->HayJugada() != false);
		//Fin del juego JvsJ, Revisando quien es el ganador
		cout << juego->MostrarTablero() << endl;
		if (jug1->getPuntos() > jug3->getPuntos()) {
			cout << "Ganador es: " << jug1->getNombreJugador() << "!!!!!" << endl;
		}
		else {
			cout << "Ganador es: " << jug3->getNombreJugador() << "!!!!!" << endl;
		}
	}

		// Guardar la jugada
	instancia->guardado->guardaJugada(jug1->getNombreJugador(), fila, columna, jug1->getPuntos());
	if (jug2 != NULL) {
		instancia->guardado->guardaJugada(jug2->getNombreJugador(), fila, columna, jug2->getPuntos());
	}
	else {
		instancia->guardado->guardaJugada(jug3->getNombreJugador(), fila, columna, jug3->getPuntos());
	}

	system("pause");
	system("cls");
	MenuPrincipal::menuPrincipal(); //En teoria esto lo devolvería al menu principal una vez que ya terminó la partida
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
void MenuPrincipal::OpcionSalir()
{
	cout << "---------------------> C R E A D O R E S <---------------------" << endl << endl;
	cout << "Alexia Alvarado Alfaro  || Grupo 05 (1pm)" << endl;
	cout << "William Rodriguez Campos  || Grupo 06 (3pm)" << endl;
	cout << endl << "----------> G R A C I A S   P O R   U T I L I Z A R <----------" << endl << endl;
}
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
	cout << "Digite su nombre: "; getline(cin, nombre);
	cin >> nombre;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el búfer
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

int MenuPrincipal::estrategiasComputadora()
{
	int opcion=0;
	cout << "-------Seleccion Modo de Juego-------" << endl;
	cout << " Seleccione el modo de juego de la computadora :" << endl;
	cout << endl;
	cout << " [1] Estrategia Aleatorio" << endl;
	cout << " [2] Estrategia Cercano" << endl;
	cout << " [3] Estrategia Central" << endl;
	cout << " [4] Estrategia Pereferico" << endl;
	cout << " [5] Estrategia Islas" << endl;
	cout << endl;
	cout << " Ingrese su opcion: ";
	while (opcion!=5) {
		cout << " opcion invalida" << endl;
		cout << " Ingrese su opcion: ";
	}
	return opcion;
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
	cout << "----> Bienvenidos <----" << endl;
	cout << "Juego Dots and Boxes" << endl; 
	cout << "Proyecto #2 Programacion 2 " << endl;
}

void MenuPrincipal::recuperarJugadas(MenuPrincipal* instancia) {
	instancia->guardado->recuperaJugadas();
}
