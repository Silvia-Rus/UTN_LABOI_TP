/*
 ============================================================================
 Name        : Trabajo práctico 1.c
 Author      : Silvia Rus Mata
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "Calculadora.h"

int main(void)
{
	setbuf(stdout, NULL);
	float numero1;
	float numero2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorial1;
	float resultadoFactorial2;
	int seleccionOpciones;
	int flagProgreso=0;

	printf("---¡¡Bienvenido a la calculadora!!---\n");
	do
	{
		if(!utn_getNumeroInt(&seleccionOpciones,"\n\nSeleccione una opción: "
									 "\n-> 1. Ingresar 1er operando (A=x)"
									 "\n-> 2. Ingresar 2do operando (B=y)"
									 "\n-> 3. Calcular todas las operaciones"
									 "\n-> 4. Informar resultados."
									 "\n-> 5. Salir"
									 "\n\nOpción: ",
									 "\nERROR. Ingrese un número entre el 1 y el 5",
									 1, 5, 3))
		{
			switch(seleccionOpciones)
			{
			case 1://ingresar primer operando
				if(!utn_getNumeroFloat(&numero1, "\nIngrese el operando A: ",
										"\nERROR. Ingrese un número. Las comas deben ser un punto.",
										INT_MIN,
										INT_MAX,
										3))
				{
					printf("\nOperando A cargado con éxito: A=%f. \nProceda a cargar el operando B (opción 2).", numero1);
					flagProgreso=1;
				}
				break;
			case 2://ingresar segundo operando
				if(flagProgreso==1)
				{
					if(!utn_getNumeroFloat(&numero2, "\nIngrese el operando B: ",
											"\nERROR. Ingrese un número. Las comas deben ser un punto.",
											INT_MIN,
											INT_MAX,
											3))
					{
						printf("\nOperando B cargado con éxito: B=%f. \nProceda a realizar las operaciones (opción 3).", numero1);
						flagProgreso=2;
					}
				}
				else
				{
					printf("\nSiga los pasos tal y cómo aparecen en el menú.");
				}
				break;
			case 3://Calcular todas las operaciones"
				if(flagProgreso==2)
				{
					//int operaciones(float numero1, float numero2, float* pResultadoSuma, float* pResultadoResta, float* pResultadoMultiplicacion, float* pResultadoDivision, float* pResultadoFactorial1, float pResultadoFactorial2)
					if(!operaciones(numero1, numero2,
									&resultadoSuma,
									&resultadoResta,
									&resultadoMultiplicacion,
									&resultadoDivision,
									&resultadoFactorial1,
									&resultadoFactorial2))
					{
						flagProgreso=3;
						printf("\n\nOperaciones realizadas. Ya puede imprimir los resultados (opción 4).");
					}
				}
				else
				{
					printf("\nSiga los pasos tal y cómo aparecen en el menú.");
				}
				break;
			case 4://Informar resultados
				if(flagProgreso==3)
				{
					resultados (numero1,
								numero2,
								resultadoSuma,
								resultadoResta,
								resultadoMultiplicacion,
								resultadoDivision,
								resultadoFactorial1,
								resultadoFactorial2);
					flagProgreso=0;
					printf("\nResultados informados. Ingrese nuevos operandos.");
				}
				else
				{
					printf("Siga los pasos tal y cómo aparecen en el menú.");
				}
				break;
			}
		}
	}while(seleccionOpciones!=5);
	printf("\n¡Hasta la próxima!");
	return EXIT_SUCCESS;
}
