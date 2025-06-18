/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
INTEGRANTES: ANA U, BRAYAN M, JORDY C.
EQUIPO 4
CALCULADORA DE MATRICES (+, -, *, A^n)
*/

#include <stdio.h>

#define LIMITE 5  // Tamaño máximo permitido para las matrices

int main() {
    int tam, eleccion;  // Tamaño de la matriz y opción del menú
    int matA[LIMITE][LIMITE], matB[LIMITE][LIMITE], salida[LIMITE][LIMITE];  // Matrices de entrada y resultado
    int exponente;  // Variable para guardar la potencia

    void ingresarMatriz(int matriz[LIMITE][LIMITE], int tam, char etiqueta) {  // Carga de datos de una matriz
        printf("Introduzca los elementos de la matriz %c:\n", etiqueta);
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                printf("%c[%d][%d]: ", etiqueta, i, j);  // Entrada de valores
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    void mostrarMatrizConEtiqueta(int matriz[LIMITE][LIMITE], int tam, char etiqueta) {  // Muestra matriz con nombre
        printf("Matriz %c:\n", etiqueta);
        for (int i = 0; i < tam; i++) {
            printf("(");
            for (int j = 0; j < tam; j++) {
                printf("%4d", matriz[i][j]);  // Imprime cada elemento
            }
            printf(" )\n");
        }
    }

    void mostrarMatrizResultado(int matriz[LIMITE][LIMITE], int tam) {  // Muestra solo la matriz resultado
        for (int i = 0; i < tam; i++) {
            printf("(");
            for (int j = 0; j < tam; j++) {
                printf("%4d", matriz[i][j]);
            }
            printf(" )\n");
        }
    }

    void sumar(int a[LIMITE][LIMITE], int b[LIMITE][LIMITE], int res[LIMITE][LIMITE], int tam) {  // Suma A + B
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++)
                res[i][j] = a[i][j] + b[i][j];
    }

    void restar(int a[LIMITE][LIMITE], int b[LIMITE][LIMITE], int res[LIMITE][LIMITE], int tam) {  // Resta A - B
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++)
                res[i][j] = a[i][j] - b[i][j];
    }

    void multiplicar(int a[LIMITE][LIMITE], int b[LIMITE][LIMITE], int res[LIMITE][LIMITE], int tam) {  // Multiplicación A * B
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++) {
                res[i][j] = 0;  // Inicializa en 0
                for (int k = 0; k < tam; k++)
                    res[i][j] += a[i][k] * b[k][j];  // Acumula el producto
            }
    }

    void clonar(int origen[LIMITE][LIMITE], int destino[LIMITE][LIMITE], int tam) {  // Copia una matriz en otra
        for (int i = 0; i < tam; i++)
            for (int j = 0; j < tam; j++)
                destino[i][j] = origen[i][j];
    }

    void elevarMatriz(int matriz[LIMITE][LIMITE], int res[LIMITE][LIMITE], int tam, int potencia) {  // Eleva matriz a potencia n
        int temp[LIMITE][LIMITE];  // Matriz temporal para el cálculo
        clonar(matriz, res, tam);  // Copia inicial
        for (int p = 1; p < potencia; p++) {
            clonar(res, temp, tam);  // Actualiza matriz temporal
            multiplicar(temp, matriz, res, tam);  // Multiplica la matriz
        }
    }

    do {  // Solicita tamaño de la matriz hasta que sea válido
        printf("========= EQUIPO 4 =========\n");
        printf("======= OPERACIONES DE MATRICES =======\n");
        printf("==== FUNDAMENTOS DE LA PROGRAMACION ====\n");
        printf("\nCalculadora para matrices cuadradas hasta 5x5\n");
        printf("Ingrese el valor N para el tamaño de las matrices (1 a 5): ");
        scanf("%d", &tam);
        if (tam < 1 || tam > LIMITE) {
            printf("Tamaño inválido. Intente con un número entre 1 y 5.\n\n");
        }
    } while (tam < 1 || tam > LIMITE);

    do {  // Menú de opciones
        printf("\nOpciones disponibles:\n");
        printf("1. Sumar dos matrices\n");
        printf("2. Restar dos matrices\n");
        printf("3. Multiplicar dos matrices\n");
        printf("4. Potenciar una matriz\n");
        printf("0. Salir del sistema\n");
        printf("Seleccione una opción: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:  // Opción suma
                ingresarMatriz(matA, tam, 'A');
                ingresarMatriz(matB, tam, 'B');
                mostrarMatrizConEtiqueta(matA, tam, 'A');
                mostrarMatrizConEtiqueta(matB, tam, 'B');
                sumar(matA, matB, salida, tam);
                printf("Resultado (A + B):\n");
                mostrarMatrizResultado(salida, tam);
                break;
            case 2:  // Opción resta
                ingresarMatriz(matA, tam, 'A');
                ingresarMatriz(matB, tam, 'B');
                mostrarMatrizConEtiqueta(matA, tam, 'A');
                mostrarMatrizConEtiqueta(matB, tam, 'B');
                restar(matA, matB, salida, tam);
                printf("Resultado (A - B):\n");
                mostrarMatrizResultado(salida, tam);
                break;
            case 3:  // Opción multiplicación
                ingresarMatriz(matA, tam, 'A');
                ingresarMatriz(matB, tam, 'B');
                mostrarMatrizConEtiqueta(matA, tam, 'A');
                mostrarMatrizConEtiqueta(matB, tam, 'B');
                multiplicar(matA, matB, salida, tam);
                printf("Resultado (A * B):\n");
                mostrarMatrizResultado(salida, tam);
                break;
            case 4:  // Opción potencia
                ingresarMatriz(matA, tam, 'A');
                mostrarMatrizConEtiqueta(matA, tam, 'A');
                printf("Ingrese el exponente (entero positivo): ");
                scanf("%d", &exponente);
                if (exponente < 1) {
                    printf("Potencia inválida.\n");
                    break;
                }
                elevarMatriz(matA, salida, tam, exponente);
                printf("Resultado (A^%d):\n", exponente);
                mostrarMatrizResultado(salida, tam);
                break;
            case 0:  // Salida
                printf("Programa finalizado. ¡Gracias por usarlo!\n");
                break;
            default:  // Opción inválida
                printf("Opción incorrecta. Intente nuevamente.\n");
        }
    } while (eleccion != 0);

    return 0;  // Fin del programa
}

