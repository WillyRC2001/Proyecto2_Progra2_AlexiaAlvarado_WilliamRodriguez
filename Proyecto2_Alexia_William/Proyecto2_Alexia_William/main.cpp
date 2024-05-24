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

	juego->activandoMatriz(compuesto);
	cout << juego->toString()<<endl;

	

	/*Tablero3x5 tableroCompuesto;

	cout << tableroCompuesto.toString() << endl;
	tableroCompuesto.SetLineaCelda(1,0);
	cout << tableroCompuesto.toString() << endl;
	tableroCompuesto.SetLineaCelda(0,1);
	cout << tableroCompuesto.toString() << endl;*/


	/*tableroCompuesto.setValorCelda(0, 3, "-");
	tableroCompuesto.setValorCelda(0, 4, "-");
	tableroCompuesto.setValorCelda(1, 3, "|");
	tableroCompuesto.setValorCelda(1, 4, "|");
	tableroCompuesto.setValorCelda(4, 3, "-");
	tableroCompuesto.setValorCelda(4, 4, "-");
	cout << tableroCompuesto.toString() << endl;*/



	/*Tablero3X3* prueba1 = new Tablero3X3();
	cout << prueba1->toString();*/
	/*Linea* lin = new Linea();
	Vertice* ver = new Vertice();
	int fila = 5;
	int columna = 5;
	string vec[10][10];
	for (int i = 1; i <= fila*2+1; i++) {
		for (int j = 1; j <= columna*2+1; j++) {
			if ( i%2 != 0 && j%2 !=0) {
				vec[i][j] = ver->toString();
			}
			else {
				if (i%2 != 0 && j%2 == 0) {
					vec[i][j] = lin->getHorizontal();
				}
				else {
					if (i % 2 == 0 && j % 2 != 0)
						vec[i][j] = lin->getVertical();
					else
						vec[i][j] = "   ";
				}
			}
		}
	}
	for (int i = 1; i <= fila*2+1; i++) {
		for (int j = 1; j <= columna*2+1; j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}*/

	system("pause");
	return 0;
}

//Elemento*** vec = new Elemento **[fila];
	//for (int i = 0; i < fila; i++) {
	//	vec[i] = new Elemento * [columna];
	//	for (int j = 0; j < columna; j++) {
	//		vec[i][j] = nullptr; // Inicializa cada elemento como nulo
	//		if (i % 2 != 0 && j % 2 != 0) {
	//			vec[i][j] = ver;
	//		}
	//		else {
	//			vec[i][j] = lin;
	//		}
	//	}
	//}