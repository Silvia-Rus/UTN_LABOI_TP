/*
 * utn.c
 *
 *  Created on: 7 sept. 2020
 *      Author: Silvia Rus Mata
 */

//FUNCIONES PARA TOMAR VALORES
/**
 * \brief Solicita un número entero y lo retorna
 * \param Puntero con el número entero introducido.
 * \param Mensaje para pedir el número entero.
 * \param Mensaje de error.
 * \param Número máximo de intentos permitidos.
 * \return Si el número se introdujo con éxito.
 */
#include <stdio.h>
#include <stdlib.h>

int getInt(int* pResultado, char* mensaje, char* mensajeError,  int maximo, int minimo, int reintentos)
{
    int buffer;
    int retorno=-1;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
    	do
    	{
    		printf("%s", mensaje);
    		fflush(stdin);
    		if(scanf("%d", &buffer)==1 && buffer<=maximo && buffer>=minimo)
    		{
    			*pResultado=buffer;
    			retorno=0;
    			break;
    		}
    		else
    		{
    			if(reintentos==1)
    			{
    				reintentos--;
    			}
    			else
    			{
    			printf("%s", mensajeError);
    			reintentos--;
    			}
    		}
    	}while(reintentos>0);

    }
    return retorno;
}

/**
 * \brief Solicita un número con decimales y lo retorna
 * \param El mensaje que debe salir por pantalla al pedir el número
 * \return Número ingresado por el usuario.
 */
float getFloat(char mensaje[])//EN CONSTRUCCIÓN
{
	float auxiliar;
    int respuestaScan;
    printf("%s", mensaje);
    fflush(stdin);
    respuestaScan = scanf("%f", &auxiliar);
    while(respuestaScan == 0)
    {
    	printf("\nERROR. Ingrese un número: ");
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
char getChar(char mensaje[])//EN CONSTRUCCIÓN
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
 * \return Si la suma se ha realizado con éxito
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
 * \return Si la resta se ha realizado con éxito
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
		retorno = 0;
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





