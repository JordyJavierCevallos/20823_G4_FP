#include <stdio.h>

int main() {
    int matriz[10][10];
    int i, j;
    int suma = 0;
    int adivinanza;

    printf("Ingrese los valores de la matriz 10x10:\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
            suma += matriz[i][j];
        }
    }

    printf("Adivine la suma total de los elementos de la matriz: ");
    scanf("%d", &adivinanza);

    if (adivinanza == suma) {
        printf("¡Correcto! La suma es %d\n", suma);
    } else {
        printf("Incorrecto. La suma correcta es %d\n", suma);
    }

    return 0;
}