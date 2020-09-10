/*
 * calculos.h
 *
 *  Created on: Sep 4, 2020
 *      Author: david
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
 *\brief: Realiza la suma de 2 numeros.
 *\param: operador1 y operador2 seran reemplazado por los numeros ingresados.
 *\return: 0 si la suma se realiza con exito, -1 si hubo algun error y el resultado de la suma en la variable pResultado
 */
int sumar(int *pResultado, int operador1, int operador2);

/**
 *\brief: Realiza la resta de 2 numeros.
 *\param: operador1 y operador2 seran reemplazado por los numeros ingresados.
 *\return: 0 si la resta se realiza con exito, -1 si hubo algun error y el resultado de la resta en la variable pResultado
 */
int restar(int *pResultado, int operador1, int operador2);

/**
 *\brief: Realiza la division de 2 numeros.
 *\param: operador1 y operador2 seran reemplazado por los numeros ingresados.
 *\return: 0 si la division se realiza con exito, -1 si hubo algun error y el resultado de la division en la variable pResultado
 */
int dividir(float *pResultado, int operador1, int operador2);

/**
 *\brief: Realiza la multiplicacion de 2 numeros.
 *\param: operador1 y operador2 seran reemplazado por los numeros ingresados.
 *\return: 0 si la multiplicacion se realiza con exito, -1 si hubo algun error y el resultado de la multiplicacion en la variable pResultado
 */
int multiplicar(int *pResultado, int operador1, int operador2);

/**
 *\brief: Realiza el factorial del valor ingresado.
 *\param: n sera reemplazado por el numero ingresado.
 *\return: El resultado.
 */
long int factorial(int n);

#endif /* CALCULOS_H_ */
