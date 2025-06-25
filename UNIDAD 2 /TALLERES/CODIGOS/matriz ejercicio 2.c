// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
// GRUPO 4
// NOMBRE: BRYAN MIGUITAMA , ANA ULLOA, JORDY CEVALLOS


#include <stdio.h>

// Prototipos de funciones
void ingresarManual(int matriz[100][100], int N);
void mostrarMatriz(int matriz[100][100], int N);
void mostrarMaximosPorFila(int matriz[100][100], int N);

int main() {
    int N;
    int matriz[100][100];

    // Pedir tamaño
    printf("Ingrese el tamano ne la matriz (N x N): ");
    scanf("%d", &N);

    // Ingresar valores manualmente
    ingresarManual(matriz, N);

    // Mostrar matriz
    mostrarMatriz(matriz, N);

    // Mostrar máximos por fila
    mostrarMaximosPorFila(matriz, N);

    return 0;
}

void ingresarManual(int matriz[100][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[100][100], int N) {
    printf("\nMatriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarMaximosPorFila(int matriz[100][100], int N) {
    printf("\nMaximos por fila:\n");
    for (int i = 0; i < N; i++) {
        int max = matriz[i][0];
        for (int j = 1; j < N; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
        printf("El valor maximo de la fila %d es: %d\n", i + 1, max);
    }
}
