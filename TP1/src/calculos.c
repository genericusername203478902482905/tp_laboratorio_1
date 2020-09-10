/*
 * calculos.c
 *
 *  Created on: Sep 4, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>



int sumar(int *pResultado, int operador1, int operador2) {
	int resultado;
	int retorno = -1;
	if (pResultado != NULL) {
		resultado = operador1 + operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int restar(int *pResultado, int operador1, int operador2) {
	int resultado;
	int retorno = -1;
	if (pResultado != NULL) {
		resultado = operador1 - operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int dividir(float *pResultado, int operador1, int operador2) {

	float resultado;
	int retorno = -1;
	if (pResultado != NULL && operador2 != 0) {

		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int multiplicar(int *pResultado, int operador1, int operador2) {
	int resultado;
	int retorno = -1;
	if (pResultado != NULL) {
		resultado = operador1 * operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

long int factorial(int n) {
	long int resultado;
	if (n >= 1) {
		resultado = n * factorial(n - 1);
		return resultado;
	} else {
		return 1;
	}
}

