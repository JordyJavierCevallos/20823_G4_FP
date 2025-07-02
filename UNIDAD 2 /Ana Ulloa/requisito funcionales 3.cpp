// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
// NOMBRE: ANA ULLOA
// NRC:20823
// FECHA: 30/06/2025

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int minimo, maximo;

    printf("Ingrese el valor minimo : ");  // RF01 - Configuración dinámica del rango
    scanf("%d", &minimo);
    printf("Ingrese el valor maximo : ");
    scanf("%d", &maximo);

    if (minimo >= maximo) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 1;
    }

    int intentosPermitidos;

    do {  // RF02 - Configuración dinámica de intentos
        printf("Ingrese la cantidad de intentos (max %d): ", MAX_INTENTOS);
        scanf("%d", &intentosPermitidos);
        if (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS) {
            printf("Numero de intentos no valido. Intente nuevamente.\n");
        }
    } while (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS);

    int intentos[MAX_INTENTOS][3];  // RF04 - Registro de intentos en matriz

    int numeroSecreto;
    int adivinado = 0;
    int numIntentosValidos = 0;

    srand(time(NULL));
    numeroSecreto = rand() % (maximo - minimo + 1) + minimo;

    for (int i = 0; i < intentosPermitidos;) {
        int intento;
        printf("Intento %d: Ingresa un numero entre %d y %d: ", i + 1, minimo, maximo);
        scanf("%d", &intento);

        if (intento < minimo || intento > maximo) {
            printf("Numero fuera del rango.\n");
            continue;
        }

        int repetido = 0;
        for (int j = 0; j < numIntentosValidos; j++) {
            if (intentos[j][1] == intento) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            printf("Ya ingresaste ese numero. Intenta con otro.\n");
            continue;
        }

        intentos[i][0] = i + 1;
        intentos[i][1] = intento;

        if (intento == numeroSecreto) {
            intentos[i][2] = 2;
            printf("\nAdivinaste, el numero secreto es %d.\n", numeroSecreto);
            adivinado = 1;
            numIntentosValidos++;
            i++;
            break;
        } else if (intento < numeroSecreto) {
            intentos[i][2] = 0;
            printf("bajo.\n");
        } else {
            intentos[i][2] = 1;
            printf("alto.\n");
        }

        numIntentosValidos++;
        i++;
    }

    printf("\nResumen:\n");  // RF05 - Visualización de resumen detallado
    printf("Intento | Valor  | Resultado\n");

    for (int k = 0; k < numIntentosValidos; k++) {
        printf("%6d | %6d | ", intentos[k][0], intentos[k][1]);
        switch (intentos[k][2]) {
            case 0:
                printf("bajo\n");
                break;
            case 1:
                printf("alto\n");
                break;
            case 2:
                printf("Correcto\n");
                break;
        }
    }

    if (!adivinado) {
        printf("\nNo lograste adivinar el numero secreto.\n");
        printf("El numero secreto era: %d\n", numeroSecreto);
    }

    return 0;
}
