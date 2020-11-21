/*
 * Calculadora.h
 *
 *  Created on: 19 nov. 2020
 *      Author: usuario
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

int sumar(float* pResultado, float operador1, float operador2);
int restar(float* pResultado, float operador1, float operador2);
int multiplicar(float* pResultado, float operador1, float operador2);
int dividir(float* pResultado, float operador1, float operador2);
int factorial(float* pResultado,float operador);
int operaciones(float numero1,
				float numero2,
				float* pResultadoSuma,
				float* pResultadoResta,
				float* pResultadoMultiplicacion,
				float* pResultadoDivision,
				float* pResultadoFactorial1,
				float* pResultadoFactorial2);
void resultados (float numero1,
				float numero2,
				float resultadoSuma,
				float resultadoResta,
				float resultadoMultiplicacion,
				float resultadoDivision,
				float resultadoFactorial1,
				float resultadoFactorial2);

#endif /* CALCULADORA_H_ */
