#include "TableroJuego.h"

TableroJuego::TableroJuego() : filas(20), columnas(20) {
    mat = new char* [filas];
    for (int i = 0; i < filas; i++) {
        mat[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            mat[i][j] = char('O');
        }
    }
}

TableroJuego::~TableroJuego() {
    for (int i = 0; i < filas; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

bool TableroJuego::Vacio(int x, int y) const{
    return (mat[x][y] != '|' && mat[x][y] != '-');
}

char TableroJuego::GetValorCelda(int x, int y) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        throw out_of_range("Posicion fuera del tablero habilitado...");
    }
    else {
        return mat[x][y];
    }
}
bool TableroJuego::SetLineaCelda(int x, int y) {
    bool verificar = false;
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        throw std::out_of_range("Posición fuera del tablero habilitado...");
    }

    if (mat[x][y] == ' ') {
        if ((x % 2 == 0 && y % 2 == 1) || (x % 2 == 1 && y % 2 == 0)) {
            mat[x][y] = (x % 2 == 0) ? '|' : '-';
            verificar = true;
        }
    }
    return verificar;
}

bool TableroJuego::CasillaLlena(char nom) {
    bool verificacion = false;
    //Recorre la matriz 20X20
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            //los centros de la matriz son cuando las filas y columnas son impares
            if (i % 2 == 0 && j % 2 == 0 && mat[i][j] == ' ') { //La condicion mat[i][j] == ' ' es para verificar si está dentro del rango y no esté ya ocupado
                if (mat[i][j - 1] != ' ' && mat[i][j + 1] != ' ' && mat[i - 1][j] != ' ' && mat[i + 1][j] != ' ') {
                    mat[i][j] = nom;
                    verificacion = true;
                }
            }
        }
    }
    return verificacion;
}

void TableroJuego::ActivarMatriz(TableroCompuesto* vec) {

    bool ocupada[20][20] = { false }; //Verifica posiciones ocupadas
    srand(static_cast<unsigned>(time(0)));  //Genera numeros aleatorios

    //Ingresando las matrices del vector en posiciones aleatorias
    for (int a = 0; a < vec->GetCantidad(); a++) {
        int filas = vec->obtenerMatriz(a)->AlturaFilas();
        int columnas = vec->obtenerMatriz(a)->AnchuraColumnas();
        if (filas <= 20 && columnas <= 20) {
            bool Pos_Valida;
            int x = 0;
            int y = 0;
            // Los valores para que la matriz se inicialice en una fila y columna impar y respetar las casillas de puntos
            do {
                int X_Max = 19 - filas;     // Limite de filas de la matriz
                int Y_Max = 19 - columnas;  // Limite de columnas de la matriz
                x = (rand() % ((X_Max / 2) + 1)) * 2 + 1;
                y = (rand() % ((Y_Max / 2) + 1)) * 2 + 1;
                Pos_Valida = true;
                for (int i = 0; i < filas && Pos_Valida; i++) {
                    for (int j = 0; j < columnas && Pos_Valida; j++)
                        if (ocupada[x + i][y + j]) {
                            Pos_Valida = false;
                        }
                }
            } while (!Pos_Valida);

            //Imprimiendo la matriz
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    mat[x + i][y + j] = *vec->obtenerMatriz(a)->GetValorCelda(i, j);
                }
            }
        }
    }
}

bool TableroJuego::HayEspacios()
{
    /*bool espacio = false;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (mat[i][j] == ' ')
                espacio = true;
        }
    }
    return espacio;*/
    for (int fila = 0; fila < filas; fila++) {
        for (int col = 0; col < 23; col++) {
            if (mat[fila][col] != 'O') {
                if ((fila % 2 == 1 && col % 2 == 0) || (fila % 2 == 0 && col % 2 == 1)) {
                    if (mat[fila][col] == ' ')
                        return true;
                }
            }

        }
    }
    return false;
}

string TableroJuego::toString() const {
    stringstream ss;
    cout << "TABLERO JUGADA" << endl;
    // Agrega números de las columnas para más estética
    cout << "    ";
    for (int col = 0; col < 20; ++col) {
        if (col <= 9)
            cout << "  " << col; // Número de la columna de 0 a 9
        else
            cout << " " << col; // Número de la columna de 10 a 19
    }
    cout << endl;

    for (int i = 0; i < filas; i++) {
        if (i <= 9)
            cout << "  " << i << "   "; // Número de la fila de 0 a 9
        else
            cout << "  " << i << "  "; // Número de la fila de 10 a 19
        for (int j = 0; j < columnas; j++) {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
    return "";
}

int TableroJuego::AnchuraColumnas() const
{
    return 0;
}

int TableroJuego::AlturaFilas() const
{
    return 0;
}

