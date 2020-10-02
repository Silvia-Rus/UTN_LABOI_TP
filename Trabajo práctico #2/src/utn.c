/*
 *
 * utn.c
 *
 *  Created on: 28 sept. 2020
 *      Author: Silvia Rus Mata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena, int limite);
static int esNumericaFloat(char* cadena, int limite);
static int esLetrasYEspacios(char* cadena, int limite);
static int getInt(int *pResultado);
static int getFloat(float *pResultado);
static int getLetrasYEspacios(char *pResultado, int longitud);


/*
 * \brief valida que la cadena recibida no excede la memoria del array.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 0 si ha salido ok. -1 si no.
 */
static int myGets(char* cadena, int len)
{
	int retorno = -1;
	char buffer[4096];
	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(cadena !=NULL &&
				len>0 &&
				(fgets(buffer, sizeof(buffer), stdin) != NULL) &&
				buffer[0] !='\n')
		{
			if(buffer[strnlen(buffer, sizeof(buffer))-1] == '\n')
			{
				(buffer[strnlen(buffer, sizeof(buffer))-1] = '\0');
			}

			if(strnlen(buffer, sizeof(buffer)) <= len)
			{
				strncpy(cadena, buffer, len);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/*
 * \brief valida que la cadena recibida es un n�mero entero.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si es un n�mero entero. 0 (falso) si no lo es.
 */
static int esNumerica(char* cadena, int len)
{
	int retorno=1;
	int i;
	for(i=0; i<len && cadena[i]!='\0'; i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
				break;
		}
	}
	return retorno;
}
/*
 * \brief valida que la cadena recibida es un n�mero flotante.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si es un n�mero entero. 0 (falso) si no lo es.
 */
static int esNumericaFloat(char* cadena, int len)
{
	int retorno=1;
	int i;
	int contadorPuntos=0;
	for(i=0; i<len && cadena[i]!='\0'; i++)
	{
		if(cadena[i]=='.')
		{
			contadorPuntos++;
		}
		if((i==0 && (cadena[i]=='+' || cadena[i]=='-')) ||
				(i>0 && cadena[i]=='.'))
		{
			continue;
		}
		if(contadorPuntos>1 || cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
				break;
		}
	}
	return retorno;
}
/*
 * \brief Valida que la cadena recibida est� compuesta solo por letras o espacios..
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */
static int esLetrasYEspacios(char* cadena, int len)
{
	int retorno = 1;
	int i;

	for(i=0 ;  i<len && cadena[i] != '\0'; i++)
	{
		if((cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			(cadena[i] != ' ') &&
			(cadena[i] < '�' || cadena[i] > '�') &&
			(cadena[i] != '�'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/**
 * \brief convierte la cadena recibida en un n�mero entero con la funci�n atoi.
 * \param puntero con el string validado.
 * \return 0 si ha salido ok. -1 si no.
 */
static int getInt(int *pResultado)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
			myGets(buffer, sizeof(buffer))==0 &&
			esNumerica(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}
/*
 * \brief convierte la cadena recibida en un n�mero flotante con la funci�n atof.
 * \param puntero con el string validado.
 * \return 0 si ha salido ok. -1 si no.
 */
static int getFloat(float *pResultado)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
		myGets(buffer, sizeof(buffer))==0 &&
		esNumericaFloat(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atof(buffer);
	}
	return retorno;
}
/*
 * \brief convierte la cadena recibida en un n�mero flotante con la funci�n atof.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 0 si ha salido ok. -1 si no.
 */
static int getLetrasYEspacios(char *pResultado, int len)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
		myGets(buffer, sizeof(buffer))==0 &&
		esLetrasYEspacios(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		strncpy(pResultado, buffer, len);
	}
	return retorno;
}
/*
 * \brief solicita un n�mero entero.
 * \param puntero con el n�mero.
 * \param mensaje para solicitar el n�mero entero.
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cifra m�nima que se puede introducir.
 * \param cifra m�xima que se puede introducir.
 * \param cantidad de reintentos para introducir un valor v�lido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getNumero(int* pResultado,
					char* mensaje,
					char* mensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getInt(&buffer) == 0 &&
					buffer >= minimo &&
					buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * \brief solicita un n�mero flotante..
 * \param puntero con el n�mero.
 * \param mensaje para solicitar el n�mero flotante..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cifra m�nima que se puede introducir.
 * \param cifra m�xima que se puede introducir.
 * \param cantidad de reintentos para introducir un valor v�lido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getNumeroFloat(float* pResultado,
						char* mensaje,
						char* mensajeError,
						int minimo,
						int maximo,
						int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getFloat(&buffer) == 0 &&
					buffer >= minimo &&
					buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * \brief solicita una cadena de valores.
 * \param puntero con la cadena.
 * \param mensaje para solicitar la cadena..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cantidad de reintentos para introducir un valor v�lido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getCadena(char* pResultado,
					int longitud,
					char* mensaje,
					char* mensajeError,
					int reintentos)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);
			if(myGets(buffer,sizeof(buffer))==0 && strlen(buffer) < longitud)
			{
				strncpy(pResultado,buffer,longitud-1);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
/*
 * \brief solicita una cadena de valores.
 * \param puntero con la cadena.
 * \param mensaje para solicitar la cadena..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cantidad de reintentos para introducir un valor v�lido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getLetrasYEspacios(char* pResultado,
							int longitud,
							char* mensaje,
							char* mensajeError,
							int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);
			if(getLetrasYEspacios(buffer, longitud)==0  && strlen(buffer) < longitud)
			{
				strncpy(pResultado,buffer,longitud-1);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



