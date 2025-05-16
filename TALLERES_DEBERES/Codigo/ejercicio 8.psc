Algoritmo RaizCuadradaEntera
	Definir x, i, num Como Real
	Escribir 'Ingrese un numero'
	Leer x
	i <- 1
	Repetir
	i <- i+1
	num <- i*i
	Hasta Que num>=x
	i <- i-1
	Escribir 'La raiz cuadrada de ', x, ' es ', i
FinAlgoritmo