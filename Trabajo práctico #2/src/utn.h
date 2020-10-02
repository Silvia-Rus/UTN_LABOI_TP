/*
 * utn.h
 *
 *  Created on: 28 sept. 2020
 *      Author: Silvia Rus Mata
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCadena(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);
int utn_getLetrasYEspacios(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);

#endif /* UTN_H_ */
