int main() {
    int filas, columnas;

    // Solicitar al usuario el numero de filas y columnas de la matriz
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    // Ingresar los valores enteros de cada fila y columna
    printf("\nIngrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Solicitar al usuario el numero de la fila para buscar el valor maximo
    int fila;
    printf("\nIngrese el numero de la fila para buscar el valor maximo: ");
    scanf("%d", &fila);

    // Se valida la fila dentro del rango pedido
    if (fila < 1 || fila > filas) {
        printf("\nNumero de fila invalido.\n");
        return 1;
    }

    // Buscar el valor maximo en la fila
    int maximo = matriz[fila - 1][0];
    for (int j = 1; j < columnas; j++) {
        if (matriz[fila - 1][j] > maximo) {
            maximo = matriz[fila - 1][j];
        }
    }

    // se muestra el valor maximo encontrado
    printf("\nEl valor maximo en la fila %d es: %d\n", fila, maximo);

    return 0;
}
