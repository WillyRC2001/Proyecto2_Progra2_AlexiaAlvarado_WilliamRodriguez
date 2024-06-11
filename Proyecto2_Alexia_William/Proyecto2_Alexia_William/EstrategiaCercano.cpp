#include "EstrategiaCercano.h"

EstrategiaCercano::EstrategiaCercano():Estrategia()
{
}

EstrategiaCercano::~EstrategiaCercano()
{
}
void EstrategiaCercano::buscarCerca(int f, int c, TableroJuego* tab) {
	if (tab->GetValorCelda(f - 1, c - 1) == ' ') {
		fila = f - 1;
		columna = c - 1;
	}
	else {
		if (tab->GetValorCelda(f - 1, c + 1) == ' ') {
			fila = f - 1;
			columna = c + 1;
		}
		else {
			if (tab->GetValorCelda(f + 1, c + 1) == ' ') {
				fila = f + 1;
				columna = c + 1;
			}
			else {
				if (tab->GetValorCelda(f + 1, c - 1) == ' ') {
					fila = f + 1;
					columna = c - 1;
				}
			}
		}
	}
}

int EstrategiaCercano::getFila() {
	return fila;
}
int EstrategiaCercano::getColumna() {
	return columna;
}