//UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
//NOMBRE: BRYAN MIGUITAMA, JORDY CEVALLOS, ANA ULLOA
//NRC:20823

#include <stdio.h>
#include <stdlib.h>

#define MAX_INTENTOS 5

int main() {
    // RF2.1 - Generar un numero aleatorio entre 1 y 100
    int numeroSecreto = rand() % 100 + 1; // numero aleatorio entre 1 y 100

    int intentoUsuario;
    int intentosRealizados = 0;
    int adivinado = 0;

    printf("Adivina el numero entre 1 y 100. Tienes %d intentos.\n", MAX_INTENTOS);

    // RF2.2 - Permitir hasta 5 intentos usando un ciclo for
    for (int i = 1; i <= MAX_INTENTOS; ) {
        printf("Intento %d: ", i);
        scanf("%d", &intentoUsuario);

        // Validar que el numero este en el rango permitido (1-100)
        if (intentoUsuario < 1 || intentoUsuario > 100) {
            printf("Por favor ingresa un numero entre 1 y 100.\n");
            continue; // no cuenta este intento
        }

        // RF2.4 - Mostrar cada intento del usuario durante el juego
        printf("Ingresaste: %d\n", intentoUsuario);

        intentosRealizados = i;

        // RF2.3 - Indicar si el intento es correcto, bajo o alto
        if (intentoUsuario == numeroSecreto) {
            // RF2.5 - Mostrar mensaje secreto si acierta
            printf("Correcto! Has adivinado el numero.\n");
            printf("Mensaje secreto: Eres un genio!\n");
            printf("Felicidades, eres un ganador! Sigue asi!\n");
            adivinado = 1;
            break;
        } else if (intentoUsuario < numeroSecreto) {
            printf("Muy bajo.\n");
        } else {
            printf("Muy alto.\n");
        }

        i++; // solo se incrementa si el intento fue valido
    }

    // RF2.4 - Mostrar cantidad de intentos usados al final
    printf("Intentos realizados: %d\n", intentosRealizados);

    // RF2.5 - Si no adivina, mostrar mensaje motivador
    if (!adivinado) {
        printf("No adivinaste el numero, era %d.\n", numeroSecreto);
        printf("SIGUE PARTICIPANDO LA PROXIMA TE IRA MEJOR ;).\n");
    }

    return 0;
}
