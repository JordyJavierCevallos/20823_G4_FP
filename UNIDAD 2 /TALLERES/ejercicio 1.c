#include <stdio.h>

int main() {
    int vector[11];
    int num1, num2, bandera1 = 0, bandera2 = 0;
    int i;

    printf("Ingrese 11 n�meros para el vector:\n");
    for (i = 0; i < 11; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("Ingrese el primer n�mero a buscar: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo n�mero a buscar: ");
    scanf("%d", &num2);

    for (i = 0; i < 11; i++) {
        if (vector[i] == num1) {
            bandera1 = 1;
        }
        if (vector[i] == num2) {
            bandera2 = 1;
        }
    }

    if (bandera1 == 1 && bandera2 == 1) {
        printf("Ambos n�meros pertenecen al vector.\n");
    } else {
        printf("Uno o ambos n�meros no pertenecen al vector.\n");
    }

    return 0;
}
