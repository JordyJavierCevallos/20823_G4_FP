Algoritmo MaxMinMedia
	Definir altura, maximo, minimo, suma, contador Como Real
	suma <- 0
	contador <- 0
	Leer altura
	maximo <- altura
	minimo <- altura
	Mientras altura >= 0 Hacer
	suma <- suma + altura
	contador <- contador + 1
	Si altura > maximo Entonces
	maximo <- altura
	FinSi
Si altura < minimo Entonces
	minimo <- altura
	FinSi
	Leer altura
	FinMientras
	media <- suma / contador
	Escribir "Media: ", media, " Maximo: ", maximo, " Minimo: ", mínimo
FinAlgoritmo