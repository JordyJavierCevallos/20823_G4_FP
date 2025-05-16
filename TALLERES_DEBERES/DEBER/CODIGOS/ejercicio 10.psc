Algoritmo numerosprimos
	Definir num1, num2, i, j, esPrimo Como Entero
	Escribir "Ingrese el primer número entero:"
	Leer num1
	Escribir "Ingrese el segundo número entero:"
	Leer num2
	Si num1 > num2 Entonces
	i <- num1
	num1 <- num2
	num2 <- i
	FinSi
	Para i <- num1 Hasta num2 Con Paso 1 Hacer
	Si i > 1 Entonces
	esPrimo <- 1
	Para j <- 2 Hasta i - 1 Con Paso 1 Hacer
	Si i % j = 0 Entonces
		esPrimo <- 0
		FinSi
		FinPara
	Si esPrimo = 1 Entonces
	Escribir "El número primo es: ", i
	FinSi
	FinSi
	FinPara
FinAlgoritmo