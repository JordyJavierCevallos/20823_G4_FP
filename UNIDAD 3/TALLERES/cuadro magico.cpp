// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
//INTEGRANTES: JORDY CEVALLOS , ANA ULLOA, BRYAN MIGUITAMA
//NRC: 20823
//FECHA: 07/07/2025
//CUADRADO PERFECTO 


#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int sumaFila1 = 0, sumaFila2 = 0, sumaFila3 = 0;
    int sumaCol1 = 0, sumaCol2 = 0, sumaCol3 = 0;
    int sumaDiag1 = 0, sumaDiag2 = 0;

    // Leer los valores de la matriz
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            do {
                printf("Introduce un valor entre 1 y 9 para la posicion [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                if (matriz[i][j] < 1 || matriz[i][j] > 9) {
                    printf("Valor fuera de rango. Intenta de nuevo.\n");
                }
            } while (matriz[i][j] < 1 || matriz[i][j] > 9);
        }
    }

    // Sumar filas
    sumaFila1 = matriz[0][0] + matriz[0][1] + matriz[0][2];
    sumaFila2 = matriz[1][0] + matriz[1][1] + matriz[1][2];
    sumaFila3 = matriz[2][0] + matriz[2][1] + matriz[2][2];

    // Sumar columnas
    sumaCol1 = matriz[0][0] + matriz[1][0] + matriz[2][0];
    sumaCol2 = matriz[0][1] + matriz[1][1] + matriz[2][1];
    sumaCol3 = matriz[0][2] + matriz[1][2] + matriz[2][2];

    // Sumar diagonales
    sumaDiag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
    sumaDiag2 = matriz[0][2] + matriz[1][1] + matriz[2][0];

    // Mostrar las sumas
    printf("\nSuma de filas:\n");
    printf("Fila 1: %d\n", sumaFila1);
    printf("Fila 2: %d\n", sumaFila2);
    printf("Fila 3: %d\n", sumaFila3);

    printf("\nSuma de columnas:\n");
    printf("Columna 1: %d\n", sumaCol1);
    printf("Columna 2: %d\n", sumaCol2);
    printf("Columna 3: %d\n", sumaCol3);

    printf("\nSuma de la diagonal principal: %d\n", sumaDiag1);
    printf("Suma de la diagonal secundaria: %d\n", sumaDiag2);

    // Verificar si es cuadrado mágico
    if (sumaFila1 == 15 && sumaFila2 == 15 && sumaFila3 == 15 &&
        sumaCol1 == 15 && sumaCol2 == 15 && sumaCol3 == 15 &&
        sumaDiag1 == 15 && sumaDiag2 == 15) {
        printf("La matriz es un CUADRADO MAGICO.\n");
    } else {
        printf("La matriz NO es un cuadrado magico.\n");
    }

    return 0;
}