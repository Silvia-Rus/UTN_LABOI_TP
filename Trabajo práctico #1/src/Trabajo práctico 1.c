/*
 ============================================================================
 Name        : Trabajo pr�ctico 1.c
 Author      : Silvia Rus Mata
 ============================================================================

CALCULADORA
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
	int seleccionOpciones;

	if(getInt(&numero1, "\nIngrese el primer n�mero: ", "\nError ingresando el primer n�mero", INT_MAX, INT_MIN, 3)==0)
	{
		if(getInt(&numero2, "\nIngrese el segundo n�mero: ", "\nError ingresando el segundo n�mero", INT_MAX, INT_MIN, 3)==0)
		{
			if(getInt(&seleccionOpciones,"\nSeleccione una opci�n: \n-> 1 si quiere sumar.\n-> 2 si quiere restar.\n-> 3 si quiere multiplicar.\n-> 4 si quiere dividir.\n-> 5 si quiere ver los factoriales.\n\nOpci�n: ", "\nERROR. Ingrese un n�mero entre el 1 y el 5", 5, 1, 5)==0)
			{
				switch(seleccionOpciones)
				{
					case 1://suma
						if(sumar(&resultadoSuma, numero1, numero2)==0)
						{
							printf("\nEl resultado de %d+%d es: %d.", numero1, numero2, resultadoSuma);
						}
							break;
					case 2://resta
						if(restar(&resultadoResta, numero1, numero2)==0)
						{
							printf("\nEl resultado de %d-%d es: %d.", numero1, numero2, resultadoResta);
						}
							break;
					case 3://multiplicaci�n
						if(multiplicar(&resultadoMultiplicacion, numero1, numero2)==0)
						{
							printf("\nEl resultado de %d*%d es: %d.", numero1, numero2, resultadoMultiplicacion);
						}
							break;
					case 4://divisi�n
						if(dividir(&resultadoDivision, numero1, numero2)==0)
						{
							printf("\nEl resultado de %d/%d es: %f.", numero1, numero2, resultadoDivision);
						}
						else
						{
							printf("\nNo se ha podido realizar la divisi�n.");
						}
							break;
					case 5://factoriales
						if(factorial(&resultadoFactorial1, numero1)==0 && factorial(&resultadoFactorial2, numero2)==0)
						{
							printf("\nEl factorial de %d es %d y el factorial de %d es %d.", numero1, resultadoFactorial1, numero2, resultadoFactorial2);
						}
						else
						{
							printf("\nNo se ha podido calcular el factorial de alguno o de los dos n�meros.");
						}

				}
			}
			else
			{
				printf("\nHa agotado el n�mero de intentos para introducir una opci�n. Reinicie la aplicaci�n.");
			}
		}
		else
		{
			printf("\nHa agotado el n�mero de intentos para el segundo n�mero. Reinicie la aplicaci�n.");
		}
	}
	else
	{
		printf("\nHa agotado el n�mero de intentos para el primer n�mero. Reinicie la aplicaci�n.");
	}
	return EXIT_SUCCESS;
}
