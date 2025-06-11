#include <stdio.h>

int main() {
    int filas, columnas,fila;

    // Solicitar el numero de filas y columnas
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    // Llenar la matriz con datos ingresados por el usuario
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Solicitar el n�mero de la fila para encontrar el valor m�ximo
    printf("Ingrese el numero de la fila (0 a %d): ", filas - 1);
    scanf("%d", &fila);

    // Verificar que la fila ingresada sea v�lida
    if (fila < 0 && fila >= filas) {
        printf("Numero de fila invalido.\n");
        return 1;
    }

    // Encontrar el valor m�ximo de dicha fila
    int max = matriz[fila][0];
    for (int j = 1; j < columnas; j++) {
        if (matriz[fila][j] > max) {
            max = matriz[fila][j];
        }
    }

    // Mostrar el valor m�ximo encontrado
    printf("El valor maximo en la fila %d es: %d\n", fila, max);

    return 0;
}
