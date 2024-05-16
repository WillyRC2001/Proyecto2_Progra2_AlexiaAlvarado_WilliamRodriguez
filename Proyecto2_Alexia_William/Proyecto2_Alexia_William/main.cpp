#include "ClasesUtiles.h"
#include "Linea.h"
#include "Vertice.h"

int main() {
	Linea* lin = new Linea();
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
	}


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