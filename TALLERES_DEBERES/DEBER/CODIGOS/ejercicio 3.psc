Algoritmo divisible
		Definir Num1, Num2 Como Entero
		Escribir "Ingrese el primer número:"
		Leer Num1
		Escribir "Ingrese el segundo número:"
		Leer Num2
		Si Num2 <> 0 Entonces
			Si Num1 % Num2 = 0 Entonces
				Escribir "El número es divisible"
			Sino
				Escribir "El número NO es divisible"
			FinSi
		Sino
			Escribir "No se puede dividir por cero"
		FinSi
FinAlgoritmo