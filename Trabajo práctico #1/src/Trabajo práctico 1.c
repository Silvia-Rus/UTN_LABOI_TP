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
#include "Calculadora.h"

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
	int flagProgreso=0;

	printf("---��Bienvenido a la calculadora!!---\n");

	do
	{
		if(!getInt(&seleccionOpciones,"\n\nSeleccione una opci�n: "
									 "\n-> 1. Ingresar 1er operando (A=x)"
									 "\n-> 2. Ingresar 2do operando (B=y)"
									 "\n-> 3. Calcular todas las operaciones"
									 "\n-> 4. Informar resultados."
									 "\n-> 5. Salir"
									 "\n\nOpci�n: ",
									 "\nERROR. Ingrese un n�mero entre el 1 y el 5",
									 5, 1, 5))
		{
			switch(seleccionOpciones)
			{
			case 1://ingresar primer operando
				if(!getInt(&numero1, "\nIngrese el operando A: ",
										"\nERROR. Ingrese un n�mero entero.",
										INT_MAX,
										INT_MIN,
										3))
				{
					printf("\nOperando A cargado con �xito: A=%d. \nProceda a cargar el operando B (opci�n 2).", numero1);
					flagProgreso=1;
				}
				break;
			case 2://ingresar segundo operando
				if(flagProgreso==1)
				{
					if(!getInt(&numero2, "\nIngrese el segundo n�mero: ",
											"\nError ingresando el segundo n�mero",
											INT_MAX,
											INT_MIN,
											3))
					{
						printf("\nOperando B cargado con �xito: B=%d. \nProceda a realizar las operaciones (opci�n 3).", numero1);
						flagProgreso=2;
					}
				}
				else
				{
					printf("Siga los pasos tal y c�mo aparecen en el men�.");
				}
				break;
			case 3://Calcular todas las operaciones"
				if(flagProgreso==2)
				{
					if(!sumar (&resultadoSuma, numero1, numero2) &&
					  !restar (&resultadoResta, numero1, numero2) &&
					  !multiplicar (&resultadoMultiplicacion, numero1, numero2))
					{
						printf("\nSuma entre %d y %d realizada con �xito.", numero1, numero2);
						printf("\nResta entre %d y %d realizada con �xito.", numero1, numero2);
						printf("\nMultiplicaci�n entre %d y %d realizada con �xito.", numero1, numero2);
					}
					if(!dividir (&resultadoDivision, numero1, numero2))
					{
						printf("\nDivisi�n entre %d y %d realizada con �xito.", numero1, numero2);
					}
					if(!factorial (&resultadoFactorial1, numero1))

					{
						printf("\nFactorial de %d realizado con �xito.", numero1);
					}
					if(!factorial (&resultadoFactorial2, numero2))
					{
						printf("\nFactorial de %d realizado con �xito.", numero2);
					}
					flagProgreso=3;
				}
				else
				{
					printf("Siga los pasos tal y c�mo aparecen en el men�.");
				}
				break;
			case 4://Informar resultados
				if(flagProgreso==3)
				{
					printf("\nEl resultado de %d + %d es: %d.", numero1, numero2, resultadoSuma);
					printf("\nEl resultado de %d - %d es: %d.", numero1, numero2, resultadoResta);
					if(numero2!=0)
					{
						printf("\nEl resultado de %d / %d es: %f.", numero1, numero2, resultadoDivision);
					}
					else
					{
						printf("\nNo es posible dividir por 0");
					}
					printf("\nEl resultado de %d * %d es: %d.", numero1, numero2, resultadoMultiplicacion);
					if(numero1>-1 && numero2>-1)
					{
						printf("\nEl factorial de %d es: %d y el factorial de %d es: %d.", numero1, resultadoFactorial1, numero2, resultadoFactorial2);
					}
					else
					{
						printf("\nNo se pudieron calcular los dos factoriales.");
					}
					printf("\nVuelva a introducir operandos para calcular.");
					flagProgreso=0;
				}
				else
				{
					printf("Siga los pasos tal y c�mo aparecen en el men�.");
				}
				break;
			}
		}
	}while(seleccionOpciones!=5);

	printf("\n�Hasta la pr�xima!");
	return EXIT_SUCCESS;
}
