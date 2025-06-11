//Este pograma en lenguaje c permite al usuario ingresar una matriz de valores enteros con f filas y c columnas.posteriormente, solicita al usuario que indique el numero de una fila especifica y muestra el valor maximo presente en dicha fila
//requisitos funcionales:
//1. El programa debe pedir al usuario ingresar una matriz de valores enteros con un numero definido de fila y columna
//2. ingresar valores enteros para cada fila y columna.
//3. el sistema debe solicitar al usuarion el numero de fila especifica
//4.el programa debera mostrar o imprimir por pantalla "numero de las filas como valor maximo "

#include <stdio.h>

int main() {
    int i, j, f, c;
    int filaSeleccionada, maximo;

    printf("Ingrese el número de filas: ");
    scanf("%d", &f);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &c);

    int matriz[f][c];

    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Ingrese el número de la fila que desea analizar (0 a %d): ", f - 1);
    scanf("%d", &filaSeleccionada);

    maximo = matriz[filaSeleccionada][0];

    for (j = 1; j < c; j++) {
        if (matriz[filaSeleccionada][j] > maximo) {
            maximo = matriz[filaSeleccionada][j];
        }
    }

    printf("El valor máximo en la fila %d es: %d\n", filaSeleccionada, maximo);

    return 0;
}
