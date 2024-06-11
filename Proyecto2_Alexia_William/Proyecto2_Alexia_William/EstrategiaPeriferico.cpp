#include "EstrategiaPeriferico.h"

EstrategiaPeriferico::EstrategiaPeriferico()
{
}

EstrategiaPeriferico::~EstrategiaPeriferico()
{
}
bool EstrategiaPeriferico::buscarPeriferico(TableroJuego* tab) {
	bool verificar;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 19; j++) {
			if (tab->GetValorCelda(i, j) == ' ') {
				fila = i;
				columna = j;
				verificar = true;
				return verificar;
			}
		}
	}
	for (int i = 15; i <= 19; i++) {
		for (int j = 0; j <= 19; j++) {
			if (tab->GetValorCelda(i, j) == ' ') {
				fila = i;
				columna = j;
				verificar = true;
				return verificar;
			}
		}
	}
	for (int i = 0; i <= 19; i++) {
		for (int j = 0; j <= 4; j++) {
			if (tab->GetValorCelda(i, j) == ' ') {
				fila = i;
				columna = j;
				verificar = true;
				return verificar;
			}
		}
	}
	for (int i = 0; i <= 19; i++) {
		for (int j = 15; j <= 19; j++) {
			if (tab->GetValorCelda(i, j) == ' ') {
				fila = i;
				columna = j;
				verificar = true;
				return verificar;
			}
		}
	}
	fila = 0;
	columna = 0;
	verificar = false;
	return verificar;
}
int EstrategiaPeriferico::getFila() {
	return fila;
}
int EstrategiaPeriferico::getColumna() {
	return columna;
}
