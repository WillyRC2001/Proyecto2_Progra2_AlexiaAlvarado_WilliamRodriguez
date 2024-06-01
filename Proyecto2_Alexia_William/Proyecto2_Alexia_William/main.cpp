#include "ClasesUtiles.h"
#include "Juego.h"
#include "Tableros.h"
#include "JugadorHumano.h"

int main() {

	// Crear instancias de los tableros
	Tablero3x3* tablero3x3 = new Tablero3x3();
	Tablero3x4* tablero3x4 = new Tablero3x4();
	Tablero3x5* tablero3x5 = new Tablero3x5();

	cout << "--- TABLERO 3X3 ---" << endl;
	cout << tablero3x3->toString() << endl;

	cout << "--- TABLERO 3X4 ---" << endl;
	cout << tablero3x4->toString() << endl;

	cout << "--- TABLERO 3X5 ---" << endl;
	cout << tablero3x5->toString() << endl;


	TableroCompuesto* compuesto = new TableroCompuesto();
	compuesto->AddMatriz(tablero3x3);
	compuesto->AddMatriz(tablero3x4);
	compuesto->AddMatriz(tablero3x5);

	cout << "cantidad de elementos de la matriz: " << compuesto->GetCantidad() << endl << endl;

	system("pause");
	system("cls");


	Jugador* jugador1 = new JugadorHumano("William");
	Jugador* jugador2 = new JugadorHumano("Alexia");
	TableroJuego* tab = new TableroJuego();
	tab->ActivarMatriz(compuesto);
	Juego* juego1 = new Juego(jugador1, jugador2, tab);
	cout<< juego1->MostrarTablero() << endl;
	int fila;
	int columna;
	system("pause");
	system("cls");
	do {
		cout << juego1->MostrarTablero() << endl;
		cin >> fila;
		cin >> columna;
		juego1->HacerJugada(jugador1, fila, columna);
		cout << juego1->MostrarTablero() << endl;
		system("pause");
		system("cls");
	} while (juego1->HayJugada() != false);

	/*cout << " --- TABLERO GRANDE ALEATORIO ---" << endl;
	TableroJuego* juego = new TableroJuego();
	juego->ActivarMatriz(compuesto);
	juego->SetLineaCelda(1, 0);
	cout << juego->toString() << endl;
	int a;
	int b;
	int i = 1;
	string nom = "William";
	char Fnom = nom[0];
	do {
		cout << endl << endl;
		cout << "digite fila: ";
		cin >> a;
		cout << "digite columna: ";
		cin >> b;
		juego->SetLineaCelda(a, b);
		system("pause");
		system("cls");
		cout << juego->toString() << endl;
		i++;
	} while (i <= 4);
	cout << "Matriz con la letra" << endl << endl;
	juego->CasillaLlena(Fnom);
	cout << juego->toString() << endl;*/

	system("pause");
	return 0;
}