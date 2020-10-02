/*
 * calc.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Silvia Rus Mata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#include "calc.h"

/*
 * \brief: calcula la suma de todos los valores de un array que no estén marcados como isEmpty.
 * \param el array en el que están los valores que se quieren sumar.
 * \param longitud del array.
 * \param puntero con el resultado de la suma.
 * \return functionReturn : devuelve 0 si todo ha salido OK (puntero no nulo y array con longitud mayor a 0) y -1 si no.
 */
int calc_sumaArray(Employee *list, int len,float *pTotal)
{
	int retorno=-1;
	float buffer=0;

	if (list != NULL && len > 0)
		{
			for (int i = 0; i < len; i++)
			{
				if (list[i].isEmpty == 0)
				{
					buffer += list[i].salary;
				}
			}
			*pTotal = buffer;
			retorno = 0;
		}
		return retorno;
}
/*
 * \brief: calcula el promedio entre todos los valores de un array que no están marcados como isEmpty.
 * \param el array en el que están los valores que se quieren promediar-
 * \param longitud del array.
 * \param puntero con el resultado del promedio.
 * \return functionReturn : devuelve 0 si todo ha salido OK (puntero no nulo y array con longitud mayor a 0) y -1 si no.
 */
int calc_promedioArray(Employee *list, int len, float *pTotal)
{
	int retorno=-1;
	float contador=0;
	float suma;

	for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0 && !calc_sumaArray(list, len, &suma) )
			{
				contador++;
			}
		}
		*pTotal = (float) suma / contador;
		retorno=0;
	return retorno;
}
/* \brief: calcula el promedio entre todos los valores de un array que no están marcados como isEmpty.
 * \param el array en el que están los valores que se quieren promediar-
 * \param longitud del array.
 * \param puntero con el resultado del promedio.
 * \return functionReturn : devuelve 0 si todo ha salido OK (puntero no nulo y array con longitud mayor a 0) y -1 si no.
 */
int calc_cantidadEncimaMedia(Employee *list, int len, int *pResultado)
{
	int retorno = -1;
	int buffer = 0;
	float promedio;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(!calc_promedioArray(list, len, &promedio))
			{
				if (list[i].isEmpty == 0 && list[i].salary > promedio)
				{
					buffer++;
				}
			}
		}
		*pResultado = buffer;
		retorno = 0;
	}
	return retorno;
}
