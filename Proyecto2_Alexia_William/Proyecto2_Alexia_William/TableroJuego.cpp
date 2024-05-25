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
        for (int j = 0; j < columnas; ) {
            delete mat[i];
        }
    }
}

bool TableroJuego::Vacio(int x, int y) {
    return (mat[x][y] != '|' && mat[x][y] != '-');
}

string TableroJuego::GetValorCelda(int x, int y) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        throw out_of_range("Posicion fuera del tablero habilitado...");
    }
    else {
        return &mat[x][y];
    }
}
void TableroJuego::SetLineaCelda(int x, int y) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        throw out_of_range("Posición fuera del tablero habilitado...");
    }

    //Verificar si se puede agregar la linea vertical o horizontal
    if (mat[x][y] != 'O') {
        if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
            if (x % 2 == 0 && y % 2 == 1) {
                mat[x][y] = '|';  // Línea vertical
            }
            else {
                mat[x][y] = '-';  // Línea horizontal
            }
        }
        else {
            cout << "No se puede agregar la línea en los vértices o centro" << endl;
        }
    }
    else
        cout << "Fuera de Rango" << endl;
}

string TableroJuego::toString() {
    stringstream s;

    // Agrega números de las columnas para mas estética
    s << "    ";
    for (int col = 0; col < 20; ++col) {
        if(col <= 9)            // Un if-else extra solo para que quede bonita la matriz
            s << "  " << col;   // Número de la columna de 0 a 9
        else
            s << " " << col;    // Número de la columna de 10 a 19
    }
    s << endl;

    for (int i = 0; i < filas; i++) {
        s << endl;
        if(i <= 9)                      // Un if-else extra solo para que quede bonita la matriz
            s << "  " << i << "   ";    // Número de la fila de 0 a 9
        else
            s << "  " << i << "  ";     // Número de la fila de 10 a 19
        for (int j = 0; j < columnas; j++) {
            s << mat[i][j] << "  "; 
        }
    }
    return s.str();
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
                    mat[x + i][y + j] = *vec->obtenerMatriz(a)->GetValorCelda(i,j);
                }
            }
        }
    }
}