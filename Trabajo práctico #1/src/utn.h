/*
 * getData.h
 *
 *      Author: Silvia Rus Mata
 */

#ifndef GETDATA_H_
#define GETDATA_H_

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCadena(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getLetrasYEspacios(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

#endif /* GETDATA_H_ */
