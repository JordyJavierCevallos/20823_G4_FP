/* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
INTEGRANTES: ANA ULLOA, JORDY CEVALLOS, BRYAN MIGUITAMA
GRUPO N° 4
NRC: 20823
JUEGO 4 EN RAYA */



#include <stdio.h>

#define FILAS 6
#define COLUMNAS 7

void inicializarTablero(char tablero[FILAS][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = '-';
        }
    }
}

void mostrarTablero(char tablero[FILAS][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

int verificarGanador(char tablero[FILAS][COLUMNAS], int fila, int columna, char ficha) {
    int i, j, cuenta;

    // Verificar horizontal
    cuenta = 0;
    for (j = 0; j < COLUMNAS; j++) {
        if (tablero[fila][j] == ficha) {
            cuenta++;
            if (cuenta == 4) return 1;
        } else {
            cuenta = 0;
        }
    }

    // Verificar vertical
    cuenta = 0;
    for (i = 0; i < FILAS; i++) {
        if (tablero[i][columna] == ficha) {
            cuenta++;
            if (cuenta == 4) return 1;
        } else {
            cuenta = 0;
        }
    }

    return 0; // No hay ganador
}

int main() {
    char tablero[FILAS][COLUMNAS];
    int turno = 1;
    int fila, columna;
    char ficha;
    int ganador = 0;

    inicializarTablero(tablero);

    while (!ganador) {
        mostrarTablero(tablero);
        printf("Turno del jugador %d\n", turno);
        printf("Elige una columna (1 a 7): ");
        scanf("%d", &columna);

        if (columna < 1 || columna > 7) {
            printf("Columna invalida. Intenta otra.\n");
            continue;
        }

        columna--; // Convertir a índice de 0 a 6
        fila = FILAS - 1;

        while (fila >= 0 && tablero[fila][columna] != '-') {
            fila--;
        }

        if (fila < 0) {
            printf("Columna llena. Intenta otra.\n");
            continue;
        }

        if (turno == 1) {
            ficha = 'X';
        } else {
            ficha = 'O';
        }

        tablero[fila][columna] = ficha;

        if (verificarGanador(tablero, fila, columna, ficha)) {
            ganador = turno;
            break;
        }

        // Cambiar turno
        if (turno == 1) {
            turno = 2;
        } else {
            turno = 1;
        }
    }

    mostrarTablero(tablero);
    printf("¡El jugador %d gana!\n", ganador);

    return 0;
}