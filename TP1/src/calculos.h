/*
 * calculos.h
 *
 *  Created on: Sep 4, 2020
 *      Author: david
 */

/**
 *brief: Funciones para
 *param: pResultado
 *param: operador1
 *param: operador2
 *return: pResultado
 *return: n
 */
#ifndef CALCULOS_H_
#define CALCULOS_H_

int sumar(int *pResultado, int operador1, int operador2);

int restar(int *pResultado, int operador1, int operador2);

int dividir(float *pResultado, int operador1, int operador2);

int multiplicar(int *pResultado, int operador1, int operador2);

long int factorial(int n);

#endif /* CALCULOS_H_ */
