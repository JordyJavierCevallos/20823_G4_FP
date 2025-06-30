#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    // RF01: El sistema debe permitir definir el rango mínimo y máximo del número secreto.
    int minimo, maximo;
    printf("Ingrese el rango minimo: ");
    scanf("%d", &minimo);
    printf("Ingrese el rango maximo: ");
    scanf("%d", &maximo);

    // Validar que el rango sea correcto
    while (maximo <= minimo) {
        printf("Rango invalido. El maximo debe ser mayor al minimo.\n");
        printf("Ingrese el rango minimo: ");
        scanf("%d", &minimo);
        printf("Ingrese el rango maximo: ");
        scanf("%d", &maximo);
    }

    // RF02: El sistema debe permitir seleccionar el número de intentos (máximo 10).
    int intentos;
    do {
        printf("Ingrese el numero de intentos (maximo %d): ", MAX_INTENTOS);
        scanf("%d", &intentos);
    } while (intentos < 1 || intentos > MAX_INTENTOS);

    // Generar número secreto aleatorio dentro del rango
    srand(time(NULL));
    int secreto = minimo + rand() % (maximo - minimo + 1);

    // RF04: El sistema debe almacenar los intentos en una matriz
    int registro[MAX_INTENTOS][2]; // columna 0 = intento, columna 1 = resultado (0=menor, 1=mayor, 2=correcto)

    int intento, correcto = 0;

    // RF03: Validar que los intentos estén dentro del rango y registrar en matriz
    for (int i = 0; i < intentos; i++) {
        do {
            printf("Intento #%d: Ingrese un numero entre %d y %d: ", i + 1, minimo, maximo);
            scanf("%d", &intento);
        } while (intento < minimo || intento > maximo);

        registro[i][0] = intento;

        if (intento < secreto) {
            printf("Muy bajo.\n");
            registro[i][1] = 0;
        } else if (intento > secreto) {
            printf("Muy alto.\n");
            registro[i][1] = 1;
        } else {
            printf("¡Correcto!\n");
            registro[i][1] = 2;
            correcto = 1;
            break;
        }
    }

    // RF05: Mostrar un resumen de los intentos y el número secreto al final
    printf("\nResumen de intentos:\n");
    printf("Intento\tValor\tResultado\n");
    for (int i = 0; i < intentos; i++) {
        if (registro[i][0] == 0 && i > 0) break; // si no hubo más intentos
        printf("%d\t%d\t", i + 1, registro[i][0]);
        if (registro[i][1] == 0) {
            printf("Muy bajo\n");
        } else if (registro[i][1] == 1) {
            printf("Muy alto\n");
        } else if (registro[i][1] == 2) {
            printf("Correcto\n");
        }
    }

    // Mensajes finales según acierto
    if (!correcto) {
        printf("\nNo lograste adivinar el numero secreto.\n");
        printf("El numero secreto era: %d\n", secreto);
    }

    return 0;
}
