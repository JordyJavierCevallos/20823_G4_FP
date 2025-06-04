#include <stdio.h>

int main() {
    int vec[15], i, j;
    unsigned long long fact[15]; // Usamos unsigned long long para almacenar factoriales grandes

    // Llenar el vector con los primeros 15 números naturales
    for (i = 0; i < 15; i++) {
        vec[i] = i + 1;
    }

    // Calcular el factorial de cada número
    for (i = 0; i < 15; i++) {
        fact[i] = 1;
        for (j = 1; j <= vec[i]; j++) {
            fact[i] *= j;
        }
    }

    // Mostrar los resultados
    for (i = 0; i < 15; i++) {
        printf("%d! = %llu\n", vec[i], fact[i]);
    }

    return 0;
}
