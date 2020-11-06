/*
 * getData.h
 *
 *      Author: Silvia Rus Mata
 */

#ifndef GETDATA_H_
#define GETDATA_H_

#define ARRAY_SIZE 4096
#define INTENTOS 2

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCadena(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getLetrasYEspacios(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getCuit(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int len);
int esLetrasYEspacios(char* cadena, int len);
int esNombreValido(char* string, int len);
int esNumericaInt(char* cadena, int len);
#endif /* GETDATA_H_ */
