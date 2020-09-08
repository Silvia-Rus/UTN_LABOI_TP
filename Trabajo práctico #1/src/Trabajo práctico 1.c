/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Silvia Rus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Hacer una calculadora. Para ello el progr iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)

2. Ingresar 2do operando (B=y)

3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B
e) Calcular el factorial (A!)

4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas
que contenga las funciones para r
• En el menú deberán aparecer los
(donde dice “x” e “y” en el ejemp
• Deberán contemplarse los casos d
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorial1;
	int resultadoFactorial2;

	numero1=getInt("\nIngrese el primer número: ");
	numero2=getInt("\nIngrese el segundo número: ");


	if(sumar(&resultadoSuma, numero1, numero2)==0)
	{
		printf("\nEl resultado de %d+%d es: %d.", numero1, numero2, resultadoSuma);
	}
	else
	{
		printf("\nNo se ha podido realizar la suma.");
	}

	if(restar(&resultadoResta, numero1, numero2)==0)
	{
		printf("\nEl resultado de %d-%d es: %d.", numero1, numero2, resultadoResta);
	}
	else
	{
		printf("\nNo se ha podido realizar la resta.");
	}

	if(multiplicar(&resultadoMultiplicacion, numero1, numero2)==0)
	{
		printf("\nEl resultado de %d*%d es: %d.", numero1, numero2, resultadoMultiplicacion);
	}
	else
	{
		printf("\nNo se ha podido realizar la multiplicación.");
	}

	if(dividir(&resultadoDivision, numero1, numero2)==0)
	{
		printf("\nEl resultado de %d/%d es: %f.", numero1, numero2, resultadoDivision);
	}
	else
	{
		printf("\nNo se ha podido realizar la división.");
	}

	if(factorial(&resultadoFactorial1, numero1)==0 && factorial(&resultadoFactorial2, numero2)==0)
	{
		printf("\nEl factorial de %d es %d y el factorial de %d es %d.", numero1, resultadoFactorial1, numero2, resultadoFactorial2);
	}
	else
	{
			printf("\nNo se ha podido calcular el factorial de alguno o de los dos números.");


	}

	return EXIT_SUCCESS;
}
