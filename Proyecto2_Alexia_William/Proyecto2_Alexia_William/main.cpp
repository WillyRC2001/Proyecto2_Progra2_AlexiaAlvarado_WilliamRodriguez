#include "ClasesUtiles.h"
#include "MenuPrincipal.h"

int main() {
	MenuPrincipal menu;  // Crear una instancia de MenuPrincipal
	menu.Bienvenida();
	system("pause");
	system("cls");
	int op;
	do {
		op = MenuPrincipal::menuPrincipal();
		system("cls");
		switch (op) {
		case 1:
			MenuPrincipal::OpcionIniciar(&menu);
			break;
		case 2:
			MenuPrincipal::OpcionEnQueConsi();
			system("pause");
			break;
		case 3:
			MenuPrincipal::OpcionRecuperarJugada();
			system("pause");
			break;
		case 4:
			MenuPrincipal::OpcionSalir();
			system("pause");
			break;
		}
		system("cls");
	} while (op!=4);
	system("pause");
	return 0;
}