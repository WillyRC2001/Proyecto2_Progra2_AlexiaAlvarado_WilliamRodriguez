#include "ClasesUtiles.h"
#include "TableroCompuesto.h"
#include "TableroComponente.h"
#include "TableroJuego.h"
#include "Tablero3X3.h"
#include "Tablero3X4.h"
#include "Tablero3X5.h"

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

	cout << " --- TABLERO GRANDE ALEATORIO ---" << endl;
	TableroJuego* juego = new TableroJuego();
	juego->ActivarMatriz(compuesto);
	juego->SetLineaCelda(1, 0);
	cout << juego->toString() << endl;
	int a;
	int b;
	cout << endl<<endl;
	cout << "digite fila: ";
	cin >> a;
	cout << "digite columna: ";
	cin >> b;
	juego->SetLineaCelda(a, b);
	system("cls");
	cout << juego->toString() << endl;

	system("pause");
	return 0;
}