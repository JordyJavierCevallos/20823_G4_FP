// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE//
// ANA SOFIA ULLOA
// 30/06/2025
//NRC: 20823

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10  // Define el maximo numero de intentos 

int main() {
    int minimo, maximo;

    // Pide al usuario que ingrese el valor minimo 
    printf("Ingrese el valor minimo del rango: ");
    scanf("%d", &minimo);

    // Pide al usuario que ingrese el valor maximo 
    printf("Ingrese el valor maximo del rango: ");
    scanf("%d", &maximo);

    // Valida que el minimo sea menor que el maximo
    if (minimo >= maximo) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 1; // acaba el programa si el rango es invalido
    }

    int intentosPermitidos;

    // Pide al usuario la cantidad de intentos que va a usar
    // Valida que este entre 1 y 10
    do {
        printf("Ingrese la cantidad de intentos : ");
        scanf("%d", &intentosPermitidos);

        if (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS) {
            printf("Numero de intentos no valido. Intente nuevamente.\n");
        }
    } while (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS);

    int numeros[MAX_INTENTOS] = {0};  // guarda los intentos
    int intento, numeroSecreto;
    int adivinado = 0;         // aqui se sabe si se adivino el numero 
    int intentosRealizados = 0; // Contador de intentos

    srand(time(NULL)); // hace que la secuencia de numeros sea diferente
    numeroSecreto = rand() % (maximo - minimo + 1) + minimo; // Genere el numero secreto

    // es un ciclo para que el usuario intente adivinar el numero
    for (int i = 0; i < intentosPermitidos; i++) {
        printf("Intento %d: Ingresa un numero entre %d y %d: ", i + 1, minimo, maximo);
        scanf("%d", &intento);

        // Verifica que el intento este dentro del rango valido
        if (intento < minimo || intento > maximo) {
            printf("Numero fuera del rango.\n");
            i--; 
            continue; // Vuelve a pedir el numero
        }

        // Guarda el intento valido 
        numeros[intentosRealizados] = intento;
        intentosRealizados++;

        // Compara el intento con el numero secreto
        if (intento == numeroSecreto) {
        	
            printf("\nAdivinaste ,el numero secreto es %d.\n");
            
            adivinado = 1; // se adivino el numero
            break; // sale del ciclo
        } else if (intento < numeroSecreto) {
            printf("Demasiado bajo.\n");
        } else {
            printf("Demasiado alto.\n");
        }
    }

    // Rellenar con 0 los intentos que quedan
    for (int k = intentosRealizados; k < intentosPermitidos; k++) {
        numeros[k] = 0;
    }

    // Muestra todos los intentos 
    printf("\nResumen:\n");
    for (int j = 0; j < intentosPermitidos; j++) {
        printf("Intento %d: %d\n", j + 1, numeros[j]);
    }

    // Si no se adivino, muestra el numero secreto
    if (!adivinado) {
        printf("\nNo lograste adivinar el numero secreto.\n");
        printf("El numero secreto era: %d\n", numeroSecreto);
    }

    return 0; // Fin del programa
}
