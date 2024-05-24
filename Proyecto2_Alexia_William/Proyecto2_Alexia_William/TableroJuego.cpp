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

   /* if (!Vacio(x, y)) {
        cout << "Ya hay una línea trazada en esa posición" << endl;
        return;
    }*/
    // Determinar si la línea es vertical u horizontal
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

//void TableroJuego::activandoMatriz(TableroCompuesto* vec) {
//    // Matriz para rastrear posiciones ocupadas
//    bool ocupada[20][20] = { false };
//
//    // Inicializar la semilla para la generación de números aleatorios
//    srand(static_cast<unsigned>(time(0)));
//
//    for (int k = 0; k < vec->GetCantidad(); k++) {
//        TableroComponente* matriz = vec->GetMatriz(k);
//
//        // Determinar el tamaño de la matriz
//        const int matrizFilas = 3; // Ajustar según el tamaño esperado de las matrices
//        const int matrizColumnas = 3;
//
//        bool posicionValida;
//        int inicioX, inicioY;
//        do {
//            int maxX = 19 - matrizFilas;
//            int maxY = 19 - matrizColumnas;
//
//            inicioX = (rand() % ((maxX / 2) + 1)) * 2 + 1;
//            inicioY = (rand() % ((maxY / 2) + 1)) * 2 + 1;
//
//            posicionValida = true;
//            for (int i = 0; i < matrizFilas && posicionValida; i++) {
//                for (int j = 0; j < matrizColumnas && posicionValida; j++) {
//                    if (ocupada[inicioX + i][inicioY + j]) {
//                        posicionValida = false;
//                    }
//                }
//            }
//        } while (!posicionValida);
//
//        for (int i = 0; i < matrizFilas; i++) {
//            for (int j = 0; j < matrizColumnas; j++) {
//                string valorCelda = matriz->GetValorCelda(i, j);
//                if (!valorCelda.empty() && valorCelda != " ") {
//                    mat[inicioX + i][inicioY + j] = valorCelda[0];
//                    ocupada[inicioX + i][inicioY + j] = true;
//                }
//            }
//        }
//    }
//}


string TableroJuego::toString() {
    stringstream s;
    // Agregar los números de las columnas
    s << "    ";
    for (int col = 0; col < 20; ++col) {
        if(col <= 9)
            s << "  " << col;
        else
            s << " " << col;
    }
    s << endl;

    for (int i = 0; i < filas; i++) {
        s << endl;
        if(i <= 9)  // Un if-else extra solo para que quede bonita la mega matriz
            s << "  " << i << "   "; // Número de la fila
        else 
            s << "  " << i << "  "; // Número de la fila
        for (int j = 0; j < columnas; j++) {
            s << mat[i][j] << "  "; 
        }
    }
    return s.str();
}


void TableroJuego::activandoMatriz(TableroCompuesto* vec) {

    // Matriz para rastrear posiciones ocupadas
    bool ocupada[20][20] = { false };

    // Inicializar la semilla para la generación de números aleatorios
    srand(static_cast<unsigned>(time(0)));

    // Copiando las matrices de vec a mat en posiciones aleatorias
    for (int x = 0; x < vec->GetCantidad(); x++) {
        int filas = vec->obtenerMatriz(x)->getAlto();
        int columnas = vec->obtenerMatriz(x)->getAncho();

        // Generando posiciones aleatorias para la matriz
        if (filas <= 20 && columnas <= 20) {
            bool posicionValida;
            int inicioX = 0;
            int inicioY = 0;
            // La valores para que la matriz se inicialice en una
            // fila y columna impar y respetar las casillas de puntos
            do {


                int maxX = 19 - filas;     // Limite de filas de la matriz
                int maxY = 19 - columnas;  // Limite de columnas de la matriz

                inicioX = (rand() % ((maxX / 2) + 1)) * 2 + 1;
                inicioY = (rand() % ((maxY / 2) + 1)) * 2 + 1;

                posicionValida = true;
                for (int i = 0; i < filas && posicionValida; i++) {
                    for (int j = 0; j < columnas && posicionValida; j++)
                        if (ocupada[inicioX + i][inicioY + j]) {
                            posicionValida = false;
                        }
                }

            } while (!posicionValida);

            // Dibujando la matriz...
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    mat[inicioX + i][inicioY + j] = *vec->obtenerMatriz(x)->GetValorCelda(i,j);
                }
            }
        }
    }
}