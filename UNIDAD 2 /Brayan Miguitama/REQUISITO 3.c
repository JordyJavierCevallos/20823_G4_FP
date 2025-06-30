#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int minimo, maximo;
    int intentosMax, numeroSecreto;
    int intentos[10];       // valores ingresados
    int resultados[10];     // 0 = bajo, 1 = alto, 2 = correcto
    int i, intento, j, repetido, acierto = 0;

    // RF01 – Configuración dinámica del rango
    printf("Ingrese el numero minimo: ");
    scanf("%d", &minimo);
    printf("Ingrese el numero maximo: ");
    scanf("%d", &maximo);

    // RF02 – Configuración dinámica de intentos
    do {
        printf("Ingrese cantidad de intentos (1 a 10): ");
        scanf("%d", &intentosMax);
    } while (intentosMax < 1 || intentosMax > 10);

    // Generar número secreto
    srand(time(NULL));
    numeroSecreto = minimo + rand() % (maximo - minimo + 1);

    // RF03 – Validación de rango y duplicados
    for (i = 0; i < intentosMax; ) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &intento);

        if (intento < minimo || intento > maximo) {
            printf("Fuera del rango.\n");
            continue;
        }

        repetido = 0;
        for (j = 0; j < i; j++) {
            if (intento == intentos[j]) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            printf("Numero repetido.\n");
            continue;
        }

        intentos[i] = intento;

        if (intento == numeroSecreto) {
            resultados[i] = 2;
            acierto = 1;
            break;
        } else if (intento < numeroSecreto) {
            resultados[i] = 0;
        } else {
            resultados[i] = 1;
        }

        i++;
    }

    // RF05 – Visualización de resumen detallado
    printf("\nResumen:\n");
    printf("Intento | Valor | Resultado\n");
    for (j = 0; j <= i - 1; j++) {
        printf("   %d    |  %d   |  ", j + 1, intentos[j]);
        if (resultados[j] == 0) {
            printf("Bajo\n");
        } else if (resultados[j] == 1) {
            printf("Alto\n");
        } else {
            printf("Correcto\n");
        }
    }

    if (acierto == 0) {
        printf("No adivinaste. El numero era: %d\n", numeroSecreto);
    } else {
        printf("¡Adivinaste el numero!\n");
    }

    return 0;
}
