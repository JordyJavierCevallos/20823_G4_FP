#include <stdio.h>
int main() {
int n, i;
printf("Ingrese el número de terminos a calcular (maximo 100): "); scanf("%d", &n);
if (n > 0 && n <= 100) { int vec[n];
for (i = 0; i < n; i++) { vec[i] = (i + 1) * (i + 1) + 3;
}
printf("Valores generados en el vector:\n"); for (i = 0; i < n; i++) { printf("vec[%d] = %d\n", i + 1, vec[i]);
}
} else {
printf("Error: El numero de terminos debe estar entre 1 y 100.\n");
}
return 0;
}
