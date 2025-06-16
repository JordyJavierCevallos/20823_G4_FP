/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
AUTORES: ANA U, BRAYAN M, JORDY C.
GRUPO 4
PROGRAMA PARA OPERAR MATRICES: suma (+), resta (-), producto (x) y potencia (matriz^n)
*/

#include <stdio.h>

#define MAX 5  // Definición del tamaño máximo permitido para las matrices

int main() {
    int dimension, opcion_menu; // Variables para la dimensión de la matriz y la opción del menú
    int matrizX[MAX][MAX], matrizY[MAX][MAX], matrizRes[MAX][MAX]; // Matrices de entrada y resultado
    int exponente; // Variable para la potencia de la matriz

    // Función para ingresar datos en una matriz de tamaño 'dimension' con identificador 'id'
    void ingresarMatriz(int matriz[MAX][MAX], int dimension, char id) {
        printf("Digite los elementos de la matriz %c:\n", id);
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                printf("%c[%d][%d]: ", id, fila, col);
                scanf("%d", &matriz[fila][col]);
            }
        }
    }

    // Función para mostrar una matriz con su identificador (ejemplo: Matriz X)
    void mostrarMatrizConID(int matriz[MAX][MAX], int dimension, char id) {
        printf("Contenido de la matriz %c:\n", id);
        for (int fila = 0; fila < dimension; fila++) {
            printf("[");
            for (int col = 0; col < dimension; col++) {
                printf("%4d", matriz[fila][col]);
            }
            printf(" ]\n");
        }
    }

    // Función para mostrar la matriz resultado sin identificador
    void mostrarMatrizSimple(int matriz[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            printf("[");
            for (int col = 0; col < dimension; col++) {
                printf("%4d", matriz[fila][col]);
            }
            printf(" ]\n");
        }
    }

    // Función para sumar dos matrices elemento a elemento
    void sumarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = m1[fila][col] + m2[fila][col];
            }
        }
    }

    // Función para restar dos matrices elemento a elemento
    void restarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = m1[fila][col] - m2[fila][col];
            }
        }
    }

    // Función para multiplicar dos matrices cuadradas (producto matricial)
    void multiplicarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = 0; // Inicializa el valor antes de acumular la suma de productos
                for (int k = 0; k < dimension; k++) {
                    resultado[fila][col] += m1[fila][k] * m2[k][col]; // Suma de productos para la celda (fila,col)
                }
            }
        }
    }

    // Función para copiar datos de una matriz origen a otra matriz destino
    void copiarDatos(int fuente[MAX][MAX], int destino[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                destino[fila][col] = fuente[fila][col];
            }
        }
    }

    // Función para calcular la potencia de una matriz (matriz^exponente)
    void calcularPotencia(int base[MAX][MAX], int resultado[MAX][MAX], int dimension, int exponente) {
        int temporal[MAX][MAX];
        copiarDatos(base, resultado, dimension);  // Resultado inicia como la matriz base (potencia 1)
        for (int i = 1; i < exponente; i++) {
            copiarDatos(resultado, temporal, dimension); // Copia resultado actual a temporal
            multiplicarMatrices(temporal, base, resultado, dimension); // Multiplica resultado por base para aumentar la potencia
        }
    }

    // Solicitar al usuario el tamaño de la matriz y validar que esté entre 1 y MAX (5)
    do {
        printf("=========== GRUPO 4 ===========\n");
        printf("======= MENU DE OPERACIONES =======\n");
        printf("=== FUNDAMENTOS DE
