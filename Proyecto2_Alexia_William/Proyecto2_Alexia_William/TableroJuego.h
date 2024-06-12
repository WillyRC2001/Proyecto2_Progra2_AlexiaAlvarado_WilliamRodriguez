#pragma once
#include "ClasesUtiles.h"
#include "TableroCompuesto.h"

class TableroJuego:public ObjetoBase {
private:
    char** mat;
    int filas;
    int columnas; 
    int checkPunto;

public:
    TableroJuego();
    virtual ~TableroJuego();
    bool Vacio(int x, int y) const;
    char GetValorCelda(int x, int y); //get casillas
    bool SetLineaCelda(int x, int y); //set casillas
    bool CasillaLlena(char nom); //verifica gane nombre en la casilla
    void ActivarMatriz(TableroCompuesto* vec);
 
    //Metodo para verificar si hay espacios sin lineas
    bool HayEspacios(); //posiciones libres
    virtual int AnchuraColumnas() const; //get columna
    virtual int AlturaFilas() const; //get filas
    string toString() const ;

    friend ostream& operator << (ostream& os, const  TableroJuego& obj) {
        os << obj.toString();
        return os;
    }

    // Nuevas funciones
    int countPosicionesLibres() {
        int count = 0;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (mat[i][j] == ' ') {
                    ++count;
                }
            }
        }
        return count;
    }
    void fillPosicionesLibres(std::pair<int, int>* libres) {
        int index = 0;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (mat[i][j] == ' ') {
                    libres[index++] = std::make_pair(i, j);
                }
            }
        }
    }
   
};