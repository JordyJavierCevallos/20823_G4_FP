#include <stdio.h>

#define MAXCOMPONENTES 10

int main() {
    double vector[MAXCOMPONENTES];
    int n;
    double norma_cuadrado = 0.0;

    do {
        printf("INGRESE EL COMPONENTE ", MAXCOMPONENTES);
        scanf("%d",&n);

        if (n > MAXCOMPONENTES || n <= 0) {
            printf("Cantidad invalida. Debe estar entre 1 y %d.\n", MAXCOMPONENTES);
        }
    } while (n > MAXCOMPONENTES || n <= 0);

    printf("Ingrese los %d componentes del vector:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Componente %d: ", i + 1);
        scanf("%lf", &vector[i]);
    }

    for (int i = 0; i < n; i++) {
        norma_cuadrado += vector[i] * vector[i];
    }

    printf("La norma del cuadrado del vector es: %.2f\n", norma_cuadrado);

    return 0;
}
