#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[10];
    int i, j, aux;

    for (i = 0; i < 10; i++) {
        printf("Ingrese el valor en la posicion %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    printf("Vector ordenado de mayor a menor:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
    return 0;
}
