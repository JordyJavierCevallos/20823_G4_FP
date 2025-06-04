#include <stdio.h>

int main() {
    int i, n;
    float vector[10];
    float norma2 = 0;

    printf("¿Cuantos componentes debe ingresar?\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ingresar el componente %d:\n", i);
        scanf("%f", &vector[i]);
        norma2 = norma2 + (vector[i] * vector[i]);
    }

    printf("La norma al cuadrado del vector es: %.2f\n", norma2);

    return 0;
}
