Algoritmo numerosprimos
	Definir x, z, i, j, esPrimo, aux Como Entero
	Escribir "Ingrese dos números enteros:"
	Leer x, z
	Si x > z Entonces
		aux <- x
		x <- z
		z <- aux
	FinSi
	Escribir "Los números primos entre ", x, " y ", z, " son:"
	Para i <- x + 1 Hasta z - 1 Hacer
		esPrimo <- 1
	Si i <= 1 Entonces
		esPrimo <- 0
	FinSi
	Para j <- 2 Hasta i - 1 Hacer
		Si i MOD j = 0 Entonces
			esPrimo <- 0
	FinSi
	FinPara
	Si esPrimo = 1 Entonces
		Escribir i
		FinSi
    FinPara
FinAlgoritmo