#include <stdio.h>

int main() {
    int N, i, j, max;
    int matriz[100][100];

    // Ingreso del tamaño de la matriz
    printf("Ingrese el tamano de la matriz (N x N): ");
    scanf("%d", &N);

    // Ingreso de los elementos de la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Encontrar el máximo de cada fila
    for (i = 0; i < N; i++) {
        max = matriz[i][0]; // Primer elemento de la fila
        for (j = 1; j < N; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
        printf("El valor maximo de la fila %d es: %d\n", i + 1, max);
    }

    return 0;
}
