Algoritmo divisible
		Definir Num1, Num2 Como Entero
		Escribir "Ingrese el primer n�mero:"
		Leer Num1
		Escribir "Ingrese el segundo n�mero:"
		Leer Num2
		Si Num2 <> 0 Entonces
			Si Num1 % Num2 = 0 Entonces
				Escribir "El n�mero es divisible"
			Sino
				Escribir "El n�mero NO es divisible"
			FinSi
		Sino
			Escribir "No se puede dividir por cero"
		FinSi
FinAlgoritmo