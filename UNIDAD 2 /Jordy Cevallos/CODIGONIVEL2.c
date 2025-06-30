/* UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
NOMBRE: JORDY CEVALLOS
REQUISITOS FUNCIONALES NIVEL 2 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int minRango, maxRango;
    int numeroSecreto;
    int intentoUsuario;
    int intentosRealizados = 0;
    int adivinado = 0;
    int maxIntentos;
    int intentos[10]; // Vector para almacenar hasta 10 intentos


    // RF01 – Usuario elige el rango
    do {
        printf("Ingrese el valor mínimo del rango: ");
        scanf("%d", &minRango);
        printf("Ingrese el valor máximo del rango: ");
        scanf("%d", &maxRango);

        if (minRango >= maxRango) {
            printf("El valor mínimo debe ser menor que el máximo. Intenta de nuevo.\n");
        }
    } while (minRango >= maxRango);

    // Generar número secreto dentro del rango definido
    numeroSecreto = rand() % (maxRango - minRango + 1) + minRango;

    // RF02 – permite que el usuario ingrese el numero de intentos
    do {
        printf("¿Cuántos intentos deseas tener? (Máximo 10): ");
        scanf("%d", &maxIntentos);
        if (maxIntentos < 1 || maxIntentos > 10) {
            printf("Número no válido. Debe estar entre 1 y 10.\n");
        }
    } while (maxIntentos < 1 || maxIntentos > 10);

    printf("Adivina el número entre %d y %d. Tienes %d intentos.\n", minRango, maxRango, maxIntentos);
// RF03 valida que cada dato este entre el rango y el max de intentos
    for (int i = 0; i < maxIntentos; ) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &intentoUsuario);

        if (intentoUsuario < minRango || intentoUsuario > maxRango) {
            printf("Por favor ingresa un número entre %d y %d.\n", minRango, maxRango);
            continue; //RF04 No guardar en vector
        }

        intentos[i] = intentoUsuario; //RF04 Guardar intento en el vector
        intentosRealizados = i + 1;

        printf("Ingresaste: %d\n", intentoUsuario);

        if (intentoUsuario == numeroSecreto) {
            printf("¡Correcto! Has adivinado el número.\n");
            printf("Mensaje secreto: ¡Eres un genio!\n");
            printf("Felicidades, eres un ganador. ¡Sigue así!\n");
            adivinado = 1;
            break;
        } else if (intentoUsuario < numeroSecreto) {
            printf("Muy bajo.\n");
        } else {
            printf("Muy alto.\n");
        }

        i++; // Solo si el intento fue válido
    }

    // RF05 Mostrar resumen del juego
    printf("\n----- RESUMEN DEL JUEGO -----\n");
    printf("Número secreto: %d\n", numeroSecreto);
    printf("Intentos realizados: %d\n", intentosRealizados);
    printf("Tus datos fueron: ");
    for (int j = 0; j < intentosRealizados; j++) {
        printf("%d ", intentos[j]);
    }
    printf("\n");

    if (!adivinado) {
        printf("No adivinaste el número. ¡Sigue participando!\n");
    }

    return 0;
}
