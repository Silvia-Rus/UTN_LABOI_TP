/*
 * utn.c
 *
 *  Created on: 7 sept. 2020
 *      Author: Silvia Rus Mata
 */

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






