Algoritmo CalculoUnidadesTiempo
	Definir x, resi, dias, horas, minu, segund Como entero
	Escribir 'Ingrese un numero'
	Leer x
	dias <- x/(24*60*60)
	resi <- x MOD (24*60*60)
	horas <- resi/(60*60)
	resi <- resi MOD (60*60)
	minu <- resi/(60)
	segund <- resi MOD 60
	Escribir 'El valor del numero ', x, ' equivale a ', dias, ' dias, ', horas, ' horas,', minu, ' minutos y ', segund, ' segundos'
FinAlgoritmo