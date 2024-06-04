#include "ClasesUtiles.h"
#include "MenuPrincipal.h"

int main() {
	MenuPrincipal::Bienvenida();
	system("pause");
	system("cls");
	int op;
	do {
		op = MenuPrincipal::menuPrincipal();
		system("cls");
		switch (op) {
		case 1:
			MenuPrincipal::OpcionIniciar();
			break;
		case 2:
			MenuPrincipal::OpcionEnQueConsi();
			system("pause");
			break;
		case 3:
			MenuPrincipal::OpcionSalir();
			system("pause");
			break;
		}
		system("cls");
	} while (op!=3);
	system("pause");
	return 0;
}