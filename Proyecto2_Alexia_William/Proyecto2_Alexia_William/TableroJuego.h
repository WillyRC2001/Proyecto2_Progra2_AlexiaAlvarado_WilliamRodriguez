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
    bool SetLineaCelda(int x, int y);
    //void activandoMatriz(TableroCompuesto* vec);
    void ActivarMatriz(TableroCompuesto* vec);
    //Metodo para agregar la letra (hecho por william)
    bool CasillaLlena(char nom);
    //Metodo para verificar si hay espacios sin lineas
    bool HayEspacios();
    virtual int AnchuraColumnas() const;
    virtual int AlturaFilas() const;
    string toString();
   
};