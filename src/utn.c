/*
 * utn.c
 *
 *  Created on: 7 sept. 2020
 *      Author: usuario
 */

//FUNCIONES PARA TOMAR VALORES
/**
 * \brief Solicita un n�mero entero y lo retorna
 * \param El mensaje que debe salir por pantalla al pedir el n�mero
 * \return N�mero ingresado por el usuario
 */
#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[])
{
    int auxiliar;
    int respuestaScan;
    printf("%s", mensaje);
    fflush(stdin);
    respuestaScan = scanf("%d", &auxiliar);
    while(respuestaScan == 0)
    {
    	printf("\nERROR. Ingrese un n�mero entero: ");
    	fflush(stdin);
    	respuestaScan = scanf("%d", &auxiliar);
    }
    return auxiliar;
}
/**
 * \brief Solicita un n�mero con decimales y lo retorna
 * \param El mensaje que debe salir por pantalla al pedir el n�mero
 * \return N�mero ingresado por el usuario.
 */
float getFloat(char mensaje[])
{
	float auxiliar;
    int respuestaScan;
    printf("%s", mensaje);
    fflush(stdin);
    respuestaScan = scanf("%f", &auxiliar);
    while(respuestaScan == 0)
    {
    	printf("\nERROR. Ingrese un n�mero: ");
    	fflush(stdin);
    	respuestaScan = scanf("%f", &auxiliar);
    }
    return auxiliar;
}
/**
 * \brief Solicita un caracter y lo retorna
 * \param El mensaje que debe salir por pantalla al pedir el caracter
 * \return Caracter ingresado por el usuario
 */
char getChar(char mensaje[])
{
	char auxiliar;
    int respuestaScan;
    printf("%s", mensaje);
    fflush(stdin);
    respuestaScan = scanf("%c", &auxiliar);
    while(respuestaScan == 0)
    {
    	printf("\nERROR. Ingrese un caracter: ");
    	fflush(stdin);
    	respuestaScan = scanf("%c", &auxiliar);
    }
    return auxiliar;
}
//CALCULADORA
/**
 * \brief Suma dos operadores
 * \param Puntero con el resultado de la suma
 * \param El primer operador de la suma
 * \param El segundo operador de la suma
 * \return Si la suma se ha realizado con �xito
 */
int sumar(int* pResultado, int operador1, int operador2)
{
	int resultadoSuma;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoSuma=operador1+operador2;
		retorno = 0;
	}

	*pResultado=resultadoSuma;
	return retorno;
}
/**
 * \brief Resta dos operadores
 * \param Puntero con el resultado de la resta
 * \param El primer operador de la resta
 * \param El segundo operador de la resta
 * \return Si la resta se ha realizado con �xito
 */
int restar(int* pResultado, int operador1, int operador2)
{
	int resultadoResta;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoResta=operador1-operador2;
		retorno = 0;
	}

	*pResultado=resultadoResta;
	return retorno;
}
/**
 * \brief Multiplica dos operadores
 * \param Puntero con el resultado de la multiplicaci�n
 * \param El primer operador de la multiplicaci�n
 * \param El segundo operador de la multiplicaci�n
 * \return Si la multiplicaci�n se ha realizado con �xito
 */
int multiplicar(int* pResultado, int operador1, int operador2)
{
	int resultadoMultiplicacion;
	int retorno = -1;

	if(pResultado!=NULL)
	{
		resultadoMultiplicacion=operador1*operador2;
		retorno = 0;
	}

	*pResultado=resultadoMultiplicacion;
	return retorno;
}


/**
 * \brief Divide dos operadores
 * \param Puntero con el resultado de la divisi�n
 * \param El primer operador de la divisi�n
 * \param El segundo operador de la divisi�n
 * \return Si la divisi�n se ha realizado con �xito
 */
int dividir(float* pResultado, int operador1, int operador2)
{
	float resultadoDivision;
	int retorno = -1;

	if(pResultado!=NULL && operador2!=0)
	{
		resultadoDivision=(float)operador1/operador2;
		retorno = 0;
	}

	*pResultado=resultadoDivision;
	return retorno;
}

/**
 * \brief Saca el factorial de un operador
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
			retorno = 0;
		}
		else
		{
			resultadoFactorial=1;
			retorno = 0;
		}
	}

	*pResultado=resultadoFactorial;
	return retorno;
}





