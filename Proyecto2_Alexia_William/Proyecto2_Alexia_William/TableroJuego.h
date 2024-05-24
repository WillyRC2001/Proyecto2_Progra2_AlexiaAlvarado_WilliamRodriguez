#pragma once
#include "ClasesUtiles.h"
#include "TableroCompuesto.h"

class TableroJuego {
private:
    char** mat;
    int filas;
    int columnas;

public:
    TableroJuego();
    virtual ~TableroJuego();
    bool Vacio(int x, int y);
    string GetValorCelda(int x, int y);
    void SetLineaCelda(int x, int y);
    void activandoMatriz(TableroCompuesto* vec);
    string toString();
   
};