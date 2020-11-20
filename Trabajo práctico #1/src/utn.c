/*
 * utn.c
 *
 *  Created on: 7 sept. 2020
 *      Author: Silvia Rus Mata
 */

/**
 * \brief Solicita un n�mero entero y lo retorna
 * \param Puntero con el n�mero entero introducido.
 * \param Mensaje para pedir el n�mero entero.
 * \param Mensaje de error.
 * \param N�mero m�ximo de intentos permitidos.
 * \return Si el n�mero se introdujo con �xito.
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
 * \brief Solicita un n�mero con decimales y lo retorna
 * \param El mensaje que debe salir por pantalla al pedir el n�mero
 * \return N�mero ingresado por el usuario.
 */
float getFloat(char mensaje[])//EN CONSTRUCCI�N
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
char getChar(char mensaje[])//EN CONSTRUCCI�N
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






