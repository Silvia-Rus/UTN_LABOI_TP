/*
 * Calculadora.c
 *
 *  Created on: 19 nov. 2020
 *      Author: Silvia Rus Mata
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Suma dos operadores
 * \param Puntero con el resultado de la suma
 * \param El primer operador de la suma
 * \param El segundo operador de la suma
 * \return Si la suma se ha realizado con éxito
 */
int sumar(int* pResultado, int operador1, int operador2)
{
	int resultadoSuma;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoSuma=operador1+operador2;
		//printf("\nSe ha calculado con éxito %d + %d.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %d + %d.", operador1, operador2);
	}
	*pResultado=resultadoSuma;
	return retorno;
}
/**
 * \brief Resta dos operadores
 * \param Puntero con el resultado de la resta
 * \param El primer operador de la resta
 * \param El segundo operador de la resta
 * \return Si la resta se ha realizado con éxito
 */
int restar(int* pResultado, int operador1, int operador2)
{
	int resultadoResta;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoResta=operador1-operador2;
		//printf("\nSe ha calculado con éxito %d - %d.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %d - %d.", operador1, operador2);
	}
	*pResultado=resultadoResta;
	return retorno;
}
/**
 * \brief Multiplica dos operadores
 * \param Puntero con el resultado de la multiplicación
 * \param El primer operador de la multiplicación
 * \param El segundo operador de la multiplicación
 * \return Si la multiplicación se ha realizado con éxito
 */
int multiplicar(int* pResultado, int operador1, int operador2)
{
	int resultadoMultiplicacion;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoMultiplicacion=operador1*operador2;
		//printf("\nSe ha calculado con éxito %d * %d.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %d * %d.", operador1, operador2);
	}
	*pResultado=resultadoMultiplicacion;
	return retorno;
}
/**
 * \brief Divide dos operadores
 * \param Puntero con el resultado de la división
 * \param El primer operador de la división
 * \param El segundo operador de la división
 * \return Si la división se ha realizado con éxito
 */
int dividir(float* pResultado, int operador1, int operador2)
{
	float resultadoDivision;
	int retorno = -1;

	if(pResultado!=NULL && operador2!=0)
	{
		resultadoDivision=(float)operador1/operador2;
		//printf("\nSe ha calculado con éxito %d / %d.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %d / %d (B no puede ser igual a 0).", operador1, operador2);
	}
	*pResultado=resultadoDivision;
	return retorno;
}
/**
 * \brief Saca el factorial de un operador2333errr
 * \param Puntero con el resultado del factorial.
 * \param El operador del que hay que sacar el factorial
 * \return Si el factorial se ha realizado con exito
 */
int factorial(int* pResultado,int operador)
{
	int resultadoFactorial=1;
	int repeticiones;
	int retorno = -1;

	if(pResultado!=NULL && operador>-1)
	{
		if(operador!=0)
		{
			for(repeticiones=operador; repeticiones>1; repeticiones--)
			{
				resultadoFactorial=resultadoFactorial*repeticiones;
			}
			//printf("\nSe ha calculado con éxito el factorial de %d.", operador);
			retorno = 0;
		}
		else
		{
			resultadoFactorial=1;
			//printf("\nSe ha calculado con éxito el factorial de %d.", operador);
			retorno = 0;
		}
	}
	else
	{
		printf("\nHa habido un problema calculando el factorial de %d (el operando no puede ser negativo).", operador);
	}
	*pResultado=resultadoFactorial;
	return retorno;
}




