//UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
//GRUPO 4
//NOMBRE: BRYAN MIGUITAMA , ANA ULLOA, JORDY CEVALLOS


#include <stdio.h>

int main() {
    int N, i, j, k, aux;

    // Solicita al usuario el tama�o de la matriz (N x N)
    printf("Ingrese el tamano de la matriz N: ");
    scanf("%d", &N);

    int mat[N][N];  // Declaraci�n de la matriz cuadrada

    // Entrada de los elementos de la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }

    // Solicita las filas a intercambiar
    printf("Ingrese la fila i: ");
    scanf("%d", &i);
    printf("Ingrese la fila j: ");
    scanf("%d", &j);

    i--;  // Ajuste del �ndice (de 1-based a 0-based)
    j--;

    // Intercambio de las filas i y j
    for (k = 0; k < N; k++) {
        aux = mat[i][k];      // Guarda temporalmente el valor de la posici�n [i][k]
        mat[i][k] = mat[j][k]; // Asigna el valor de la fila j a la fila i
        mat[j][k] = aux;       // Asigna el valor temporal a la fila j
    }

    // Muestra la matriz resultante despu�s del intercambio
    printf("Matriz resultante:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");  // Salto de l�nea por fila
    }

    return 0; // Fin del programa
}
