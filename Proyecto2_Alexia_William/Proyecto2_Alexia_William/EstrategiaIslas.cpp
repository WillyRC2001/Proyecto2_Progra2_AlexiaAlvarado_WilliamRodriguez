#include "EstrategiaIslas.h"
#include <random>

EstrategiaIslas::EstrategiaIslas() : afila(0), acol(0), con(0), a(0) {
    this->tipo = 4;
}
EstrategiaIslas::~EstrategiaIslas() {}
int EstrategiaIslas::getFila() { return fila; }
int EstrategiaIslas::getColumna() { return columna; }
int EstrategiaIslas::getTipo() { return tipo; }

void EstrategiaIslas::buscarCerca(int f, int c, TableroJuego* tab) {
    bool exitLoop = false;
    while (!exitLoop) {
        if (con == 0) {
            a = 0;

            // Contar posiciones libres
            int count = tab->countPosicionesLibres();

            // Crear arreglo dinámico para posiciones libres
            std::pair<int, int>* libres = new std::pair<int, int>[count];
            tab->fillPosicionesLibres(libres);

            std::random_device rd;  // Semilla del generador
            std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
            std::uniform_int_distribution<> dis(0, count - 1);
            // Obtener un índice aleatorio
            int ale = dis(gen);
            // Obtener la posición aleatoria del arreglo
            std::pair<int, int> pos_ale = libres[ale];
            fila = pos_ale.first;
            columna = pos_ale.second;
            afila = fila;
            acol = columna;
            con++;
            delete[] libres;  // Liberar memoria
            exitLoop = true;
        }
        if (con == 1) {
            a = cuadrado(tab);
            if (a == 0) {
                con = 0;
                continue;
            }
        }
        if (a == 1) {
            int aux = izquierda(tab);
            con++;
            if (aux == 0) {
                con = 0;
                continue;
            }
        }
        else if (a == 2) {
            int aux = derecha(tab);
            con++;
            if (aux == 0) {
                con = 0;
                continue;
            }
        }
        else if (a == 3) {
            int aux = arriba(tab);
            con++;
            if (aux == 0) {
                con = 0;
                continue;
            }
        }
        else if (a == 4) {
            int aux = abajo(tab);
            con++;
            if (aux == 0) {
                con = 0;
                continue;
            }
        }
        else if (a == 5) {
            int aux = cero(tab);
            con++;
            if (aux == 0) {
                con = 0;
                continue;
            }
        }
        exitLoop = true;
    }
}

int EstrategiaIslas::cuadrado(TableroJuego* tab) {
    if ((acol - 2 >= 0) && (tab->GetValorCelda(afila, acol - 2) == ' ') &&
        (afila - 1 >= 0 && acol - 1 >= 0) && (tab->GetValorCelda(afila - 1, acol - 1) == ' ') &&
        (afila + 1 < 23 && acol - 1 >= 0) && (tab->GetValorCelda(afila + 1, acol - 1) == ' ') &&
        (tab->GetValorCelda(afila, acol) == ' '))
        return 1;

    else if ((acol + 2 < 23) && (tab->GetValorCelda(afila, acol + 2) == ' ') &&
        (afila - 1 >= 0 && acol + 1 < 23) && (tab->GetValorCelda(afila - 1, acol + 1) == ' ') &&
        (afila + 1 < 23 && acol + 1 < 23) && (tab->GetValorCelda(afila + 1, acol + 1) == ' ') &&
        (tab->GetValorCelda(afila, acol) == ' '))
        return 2;

    else if ((afila + 2 < 23 && tab->GetValorCelda(afila + 2, acol) == ' ') &&
        (afila - 1 >= 0 && acol + 1 < 23 && tab->GetValorCelda(afila - 1, acol + 1) == ' ') &&
        (afila - 1 >= 0 && acol - 1 >= 0 && tab->GetValorCelda(afila - 1, acol - 1) == ' ') &&
        (tab->GetValorCelda(afila, acol) == ' '))
        return 3;

    else if ((afila - 2 >= 0 && tab->GetValorCelda(afila - 2, acol) == ' ') &&
        (afila - 1 >= 0 && acol + 1 < 23 && tab->GetValorCelda(afila - 1, acol + 1) == ' ') &&
        (afila - 1 >= 0 && acol - 1 >= 0 && tab->GetValorCelda(afila - 1, acol - 1) == ' ') &&
        (tab->GetValorCelda(afila, acol) == ' '))
        return 4;

    else if ((afila + 2 < 23 && tab->GetValorCelda(afila + 2, acol) == ' ') &&
        (afila + 1 < 23 && acol - 1 >= 0 && tab->GetValorCelda(afila + 1, acol - 1) == ' ') &&
        (afila + 1 < 23 && acol + 1 < 23 && tab->GetValorCelda(afila + 1, acol + 1) == ' ') &&
        (tab->GetValorCelda(afila, acol) == ' '))
        return 4;

    return 0;
}

// Implementación de las funciones restantes (izquierda, derecha, arriba, abajo, cero)

int EstrategiaIslas::izquierda(TableroJuego* tab) {
    if ((acol - 2 >= 0) && (tab->GetValorCelda(afila, acol - 2) == ' ')) {
        fila = afila;
        columna = acol - 2;
        return 1;
    }
    else if ((afila - 1 >= 0 && acol - 1 >= 0) && (tab->GetValorCelda(afila - 1, acol - 1) == ' ')) {
        fila = afila - 1;
        columna = acol - 1;
        return 2;
    }
    else if ((afila + 1 < 23 && acol - 1 >= 0) && (tab->GetValorCelda(afila + 1, acol - 1) == ' ')) {
        fila = afila + 1;
        columna = acol - 1;
        return 3;
    }
    else if ((tab->GetValorCelda(afila, acol) == ' ')) {
        fila = afila;
        columna = acol;
        return 4;
    }
    else return 0;
}

int EstrategiaIslas::derecha(TableroJuego* tab) {
    if ((acol + 2 < 23) && (tab->GetValorCelda(afila, acol + 2) == ' ')) {
        fila = afila;
        columna = acol + 2;
        return 1;
    }
    else if ((afila - 1 >= 0 && acol + 1 < 23) && (tab->GetValorCelda(afila - 1, acol + 1) == ' ')) {
        fila = afila - 1;
        columna = acol + 1;
        return 2;
    }
    else if ((afila + 1 < 23 && acol + 1 < 23) && (tab->GetValorCelda(afila + 1, acol + 1) == ' ')) {
        fila = afila + 1;
        columna = acol + 1;
        return 3;
    }
    else if ((tab->GetValorCelda(afila, acol) == ' ')) {
        fila = afila;
        columna = acol;
        return 4;
    }
    else return 0;
}

int EstrategiaIslas::arriba(TableroJuego* tab) {
    if ((afila + 2 < 23) && (tab->GetValorCelda(afila + 2, acol) == ' ')) {
        fila = afila + 2;
        columna = acol;
        return 1;
    }
    else if ((afila - 1 >= 0 && acol + 1 < 23) && (tab->GetValorCelda(afila - 1, acol + 1) == ' ')) {
        fila = afila - 1;
        columna = acol + 1;
        return 2;
    }
    else if ((afila - 1 >= 0 && acol - 1 >= 0) && (tab->GetValorCelda(afila - 1, acol - 1) == ' ')) {
        fila = afila - 1;
        columna = acol - 1;
        return 3;
    }
    else if ((tab->GetValorCelda(afila, acol) == ' ')) {
        fila = afila;
        columna = acol;
        return 4;
    }
    else return 0;
}

int EstrategiaIslas::abajo(TableroJuego* tab) {
    if ((afila - 2 >= 0) && (tab->GetValorCelda(afila - 2, acol) == ' ')) {
        fila = afila - 2;
        columna = acol;
        return 1;
    }
    else if ((afila + 1 < 23 && acol - 1 >= 0) && (tab->GetValorCelda(afila + 1, acol - 1) == ' ')) {
        fila = afila + 1;
        columna = acol - 1;
        return 2;
    }
    else if ((afila + 1 < 23 && acol + 1 < 23) && (tab->GetValorCelda(afila + 1, acol + 1) == ' ')) {
        fila = afila + 1;
        columna = acol + 1;
        return 3;
    }
    else if ((tab->GetValorCelda(afila, acol) == ' ')) {
        fila = afila;
        columna = acol;
        return 4;
    }
    else return 0;
}

int EstrategiaIslas::cero(TableroJuego* tab) {
    if ((afila - 2 >= 0) && (tab->GetValorCelda(afila - 2, acol) == ' ')) {
        fila = afila - 2;
        columna = acol;
        return 1;
    }
    else if ((afila - 1 >= 0 && acol - 1 >= 0) && (tab->GetValorCelda(afila - 1, acol - 1) == ' ')) {
        fila = afila - 1;
        columna = acol - 1;
        return 2;
    }
    else if ((afila - 1 >= 0 && acol + 1 < 23) && (tab->GetValorCelda(afila - 1, acol + 1) == ' ')) {
        fila = afila - 1;
        columna = acol + 1;
        return 3;
    }
    else if ((afila + 1 < 23 && acol + 1 < 23) && (tab->GetValorCelda(afila + 1, acol + 1) == ' ')) {
        fila = afila + 1;
        columna = acol + 1;
        return 4;
    }
    else if ((afila + 1 < 23 && acol - 1 >= 0) && (tab->GetValorCelda(afila + 1, acol - 1) == ' ')) {
        fila = afila + 1;
        columna = acol - 1;
        return 5;
    }
    else if ((afila + 2 < 23) && (tab->GetValorCelda(afila + 2, acol) == ' ')) {
        fila = afila + 2;
        columna = acol;
        return 6;
    }
    else if ((tab->GetValorCelda(afila, acol) == ' ')) {
        fila = afila;
        columna = acol;
        return 7;
    }
    else return 0;
}

int EstrategiaIslas::posicionRandom(TableroJuego* tab, int& fila, int& columna)
{
    int count = tab->countPosicionesLibres();
    if (count == 0) return 0; // No hay posiciones libres

    std::pair<int, int>* libres = new std::pair<int, int>[count];
    tab->fillPosicionesLibres(libres);

    int randomIndex = rand() % count;
    fila = libres[randomIndex].first;
    columna = libres[randomIndex].second;

    delete[] libres;
    return 1;
}
