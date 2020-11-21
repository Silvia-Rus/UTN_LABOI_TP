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
int sumar(float* pResultado, float operador1, float operador2)
{
	float resultadoSuma;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoSuma=operador1+operador2;
		printf("\nSe ha calculado con éxito %f + %f.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %f + %f.", operador1, operador2);
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
int restar(float* pResultado, float operador1, float operador2)
{
	float resultadoResta;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoResta=operador1-operador2;
		printf("\nSe ha calculado con éxito %f - %f.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %f - %f.", operador1, operador2);
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
int multiplicar(float* pResultado, float operador1, float operador2)
{
	float resultadoMultiplicacion;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoMultiplicacion=operador1*operador2;
		printf("\nSe ha calculado con éxito %f * %f.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %f * %f.", operador1, operador2);
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
int dividir(float* pResultado, float operador1, float operador2)
{
	float resultadoDivision;
	int retorno = -1;

	if(pResultado!=NULL && operador2!=0)
	{
		resultadoDivision=operador1/operador2;
		printf("\nSe ha calculado con éxito %f / %f.", operador1, operador2);
		retorno = 0;
	}
	else
	{
		printf("\nHa habido un problema calculando %f / %f (B no puede ser igual a 0).", operador1, operador2);
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
int factorial(float* pResultado,float operador)
{
	float resultadoFactorial=1;
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
			printf("\nSe ha calculado con éxito el factorial de %f.", operador);
			retorno = 0;
		}
		else
		{
			resultadoFactorial=1;
			printf("\nSe ha calculado con éxito el factorial de %f.", operador);
			retorno = 0;
		}
	}
	else
	{
		printf("\nHa habido un problema calculando el factorial de %f (el operando no puede ser negativo).", operador);
	}
	*pResultado=resultadoFactorial;
	return retorno;
}
/**
 * \brief Hace los cálculos de dos operandos pasados por parámetros. (Suma, resta, multiplicación, división y factorial de cada uno de los operandos).
 * \param Primer operando.
 * \param Segundo operando.
 * \param puntero al resultado de la suma.
 * \param puntero al resultado de la resta.
 * \param puntero al resultado de la multiplicación.
 * \param puntero al resultado de la división.
 * \param puntero al resultado del factorial del primer operando.
 * \param puntero al resultado del factorial del segundo operando.
 * \return 0 si se hicieron las operaciones (incluso si no se puede) y -1 si no se puedo (los punteros eran nulos).
 */
int operaciones(float numero1, float numero2, float* pResultadoSuma, float* pResultadoResta, float* pResultadoMultiplicacion, float* pResultadoDivision, float* pResultadoFactorial1, float* pResultadoFactorial2)
{
	int retorno=-1;
	float bufferSuma;
	float bufferResta;
	float bufferMultiplicacion;
	float bufferDivision;
	float bufferFactorial1;
	float bufferFactorial2;

	if(pResultadoSuma != NULL &&
		pResultadoResta != NULL &&
		pResultadoMultiplicacion != NULL &&
		pResultadoDivision != NULL &&
		pResultadoFactorial1 != NULL &&
		pResultadoFactorial2 != NULL)
	{
		//Suma, resta y multiplicación
		if(!sumar (&bufferSuma, numero1, numero2) &&
		  !restar (&bufferResta, numero1, numero2) &&
		  !multiplicar (&bufferMultiplicacion, numero1, numero2))
		{
			*pResultadoSuma=bufferSuma;
			*pResultadoResta=bufferResta;
			*pResultadoMultiplicacion=bufferMultiplicacion;
		}
		//División
		if(!dividir (&bufferDivision, numero1, numero2))
		{
			*pResultadoDivision=bufferDivision;
		}
		//Factorial del primer operando
		if(!factorial (&bufferFactorial1, numero1))
		{
			*pResultadoFactorial1=bufferFactorial1;
		}
		//Factorial del segundo operando
		if(!factorial (&bufferFactorial2, numero2))
		{
			*pResultadoFactorial2=bufferFactorial2;
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los resultados de las operaciones con los valores que entran por parámetro.
 * \param Primer operando.
 * \param Segundo operando.
 * \param resultado de la suma.
 * \param resultado de la resta.
 * \param resultado de la multiplicación.
 * \param resultado de la división.
 * \param resultado del factorial del primer operando.
 * \param resultado del factorial del segundo operando.
 */
void resultados (float numero1,
				float numero2,
				float resultadoSuma,
				float resultadoResta,
				float resultadoMultiplicacion,
				float resultadoDivision,
				float resultadoFactorial1,
				float resultadoFactorial2)
{
	//Suma
	printf("\nEl resultado de %f + %f es: %f.", numero1, numero2, resultadoSuma);
	//Resta
	printf("\nEl resultado de %f - %f es: %f.", numero1, numero2, resultadoResta);
	//División
	if(numero2!=0)
	{
		printf("\nEl resultado de %f / %f es: %f.", numero1, numero2, resultadoDivision);
	}
	else
	{
		printf("\nNo es posible dividir entre 0.");
	}
	//Multiplicación
	printf("\nEl resultado de %f * %f es: %f.", numero1, numero2, resultadoMultiplicacion);
	//Factoriales
	if(numero1>-1 && numero2<0)
	{
		printf("\nEl factorial de %f es: %f. \nEl factorial de %f (operando 2) no se ha podido calcular por ser un número negativo.",numero1, resultadoFactorial1, numero2);
	}
	else if(numero2>-1 && numero1<0)
	{
		printf("\nEl factorial de %f es: %f. \nEl factorial de %f (operando 1) no se ha podido calcular por ser un número negativo.",numero2, resultadoFactorial2, numero1);
	}
	else if(numero1>-1 && numero2>-1)
	{
		printf("\nEl factorial de %f es: %f y el factorial de %f es: %f.", numero1, resultadoFactorial1, numero2, resultadoFactorial2);
	}
	else
	{
		printf("\nNo se pudieron calcular ninguno de los dos factoriales por ser los dos números negativos.");
	}
}



