#include "MenuPrincipal.h"

int MenuPrincipal::menuPrincipal()
{
	int op = 0;
	cout << "----> Menu principal <----" << endl;
	cout << "[1] Continuar" << '\t';
	cout << "[2] Estrategias" << '\t';
	cout << "[2] Ver jugados" << '\t';
	cout << "[4] Salir" << endl;
	cin >> op;
	if (cin.fail() || op <= 0) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return op;
}


TableroCompuesto* MenuPrincipal::creartablero()
{
	//int cant = 0, cont = 0, op = 0;
	//TableroCompuesto* tableroCompuesto = new TableroCompuesto();
	//cout << "Se puede ingresar un maxino de 5 tableros." << endl;
	//cout << "Dijite la cantida de tablero que desea: "; cin >> cant;
	//comprobarInt(cant);
	//if (cant <= 5) { /*Tamano del vector del compuesesto */
	//	while (cont < cant) {
	//		cout << "Dijite el tamano del Tablero <----" << endl;
	//		cout << "[1] 3x3" << '\t';
	//		cout << "[2] 3x4" << '\t';
	//		cout << "[3] 3x5" << '\t';
	//		cin >> op;
	//		if (op == 1) {
	//			TableroComponente* tab1 = new Tablero3X3(); //no me deja poner new tablero3x3 ni con los demas
	//			tableroCompuesto->AddMatriz(tab1);
	//			cont++;
	//		}
	//		if (op == 2) {
	//			TableroComponente* tab2 = new Tablero3X4();
	//			tableroCompuesto->AddMatriz(tab2);
	//			cont++;
	//		}
	//		if (op == 3) {
	//			TableroComponente* tab3 = new Tablero3x5();
	//			tableroCompuesto->AddMatriz(tab3);
	//			cont++;
	//		}
	//		else {
	//			cout << "Numero mal dijitado vuelva a intenar" << '\t';
	//		}
	//	}
	//}
	//else {
	//	throw new ExcepcionFueraRango();
	//}
	//return tableroCompuesto;
	return 0; //pa que no de errores
}


Jugador* MenuPrincipal::crearJugador()
{
	string nombre;
	cout << "Dijite su nombre "; getline(cin, nombre);
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el búfer
	Jugador* juga = new JugadorHumano(nombre);
	return juga;
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
