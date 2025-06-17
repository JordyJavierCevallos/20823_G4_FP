/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
AUTORES: ANA U, BRAYAN M, JORDY C.
GRUPO 4
PROGRAMA PARA OPERAR MATRICES: suma (+), resta (-), producto (x) y potencia (matriz^n)
*/

#include <stdio.h>

#define MAX 5  // Tamaño máximo permitido para las matrices (5x5)

int main() {
    int dimension, opcion_menu;
    int matrizX[MAX][MAX], matrizY[MAX][MAX], matrizRes[MAX][MAX];
    int exponente;

    // Función para ingresar elementos en una matriz
    void ingresarMatriz(int matriz[MAX][MAX], int dimension, char id) {
        printf("Digite los elementos de la matriz %c:\n", id);
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                printf("%c[%d][%d]: ", id, fila, col);
                scanf("%d", &matriz[fila][col]);
            }
        }
    }

    // Función para mostrar una matriz con su identificador (X o Y)
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

    // Función para mostrar una matriz sin identificador
    void mostrarMatrizSimple(int matriz[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            printf("[");
            for (int col = 0; col < dimension; col++) {
                printf("%4d", matriz[fila][col]);
            }
            printf(" ]\n");
        }
    }

    // Función para sumar dos matrices
    void sumarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = m1[fila][col] + m2[fila][col];
            }
        }
    }

    // Función para restar dos matrices
    void restarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = m1[fila][col] - m2[fila][col];
            }
        }
    }

    // Función para multiplicar dos matrices
    void multiplicarMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                resultado[fila][col] = 0;
                for (int k = 0; k < dimension; k++) {
                    resultado[fila][col] += m1[fila][k] * m2[k][col];
                }
            }
        }
    }

    // Copia los elementos de una matriz fuente a una matriz destino
    void copiarDatos(int fuente[MAX][MAX], int destino[MAX][MAX], int dimension) {
        for (int fila = 0; fila < dimension; fila++) {
            for (int col = 0; col < dimension; col++) {
                destino[fila][col] = fuente[fila][col];
            }
        }
    }

    // Función para calcular la potencia de una matriz
    void calcularPotencia(int base[MAX][MAX], int resultado[MAX][MAX], int dimension, int exponente) {
        int temporal[MAX][MAX];
        copiarDatos(base, resultado, dimension);  // Inicializa resultado como la base
        for (int i = 1; i < exponente; i++) {
            copiarDatos(resultado, temporal, dimension);  // Copia resultado actual a temporal
            multiplicarMatrices(temporal, base, resultado, dimension);  // Multiplica temporal por la base
        }
    }

    // Solicita al usuario la dimensión N de las matrices (entre 1 y 5)
    do {
        printf("=========== GRUPO 4 ===========\n");
        printf("======= MENU DE OPERACIONES =======\n");
        printf("=== FUNDAMENTOS DE PROGRAMACION ===\n");
        printf("\nCalculadora de matrices cuadradas NxN (max 5x5)\n");
        printf("Ingrese el tamaño N (1 a 5): ");
        scanf("%d", &dimension);
        if (dimension < 1 || dimension > MAX) {
            printf("ERROR: El tamaño debe ser entre 1 y 5.\n\n");
        }
    } while (dimension < 1 || dimension > MAX);

    // Menú principal para seleccionar operaciones con matrices
    do {
        printf("\nOpciones:\n");
        printf("1. Suma de matrices\n");
        printf("2. Resta de matrices\n");
        printf("3. Producto de matrices\n");
        printf("4. Potencia de matriz\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion_menu);

        switch (opcion_menu) {
            case 1:
                // Realiza la suma de dos matrices
                ingresarMatriz(matrizX, dimension, 'X');
                ingresarMatriz(matrizY, dimension, 'Y');
                mostrarMatrizConID(matrizX, dimension, 'X');
                mostrarMatrizConID(matrizY, dimension, 'Y');
                sumarMatrices(matrizX, matrizY, matrizRes, dimension);
                printf("Resultado (X + Y):\n");
                mostrarMatrizSimple(matrizRes, dimension);
                break;
            case 2:
                // Realiza la resta de dos matrices
                ingresarMatriz(matrizX, dimension, 'X');
                ingresarMatriz(matrizY, dimension, 'Y');
                mostrarMatrizConID(matrizX, dimension, 'X');
                mostrarMatrizConID(matrizY, dimension, 'Y');
                restarMatrices(matrizX, matrizY, matrizRes, dimension);
                printf("Resultado (X - Y):\n");
                mostrarMatrizSimple(matrizRes, dimension);
                break;
            case 3:
                // Realiza el producto de dos matrices
                ingresarMatriz(matrizX, dimension, 'X');
                ingresarMatriz(matrizY, dimension, 'Y');
                mostrarMatrizConID(matrizX, dimension, 'X');
                mostrarMatrizConID(matrizY, dimension, 'Y');
                multiplicarMatrices(matrizX, matrizY, matrizRes, dimension);
                printf("Resultado (X * Y):\n");
                mostrarMatrizSimple(matrizRes, dimension);
                break;
            case 4:
                // Calcula la potencia de una matriz
                ingresarMatriz(matrizX, dimension, 'X');
                mostrarMatrizConID(matrizX, dimension, 'X');
                printf("Ingrese el exponente (entero positivo): ");
                scanf("%d", &exponente);
                if (exponente < 1) {
                    printf("Exponente no válido.\n");
                    break;
                }
                calcularPotencia(matrizX, matrizRes, dimension, exponente);
                printf("Resultado (X^%d):\n", exponente);
                mostrarMatrizSimple(matrizRes, dimension);
                break;
            case 0:
                // Sale del programa
                printf("Finalizando programa.\n");
                break;
            default:
                // Manejo de opción inválida
                printf("Opción inválida.\n");
        }
    } while (opcion_menu != 0);

    return 0;
}

