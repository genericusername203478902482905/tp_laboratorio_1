/*
 * utnInputs.h
 *
 *  Created on: Sep 24, 2020
 *      Author: david
 */

#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_

/** \brief Solicita un numero Int al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param min Es el numero minimo a ser aceptado
 * \param max Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos);


/** \brief Solicita un numero Float al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param min Es el numero minimo a ser aceptado
 * \param max Es el numero maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos);

/** \brief Solicita un "string" al usuario, luego de verificarlo devuelve el resultado
 *
 * \param input Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param min Es la cantidad de caracteres del string minimo a ser aceptado
 * \param max Es la cantidad de caracteres del string maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el "string" y -1 si no
 *
 */
int getString(char* input,char mensaje[],char mensajeError[],int min,int max,int reintentos);

/** \brief Valida un "string" ingresado, luego de verificarlo devuelve si es un string valido o no
 *
 * \param string Puntero al espacio de memoria del "string" a validar
 * \param max Es la cantidad de caracteres del string maximo
 * \return Retorna 0 si es un "string" valido y -1 si no
 *
 */
int valCharacter(char* string,int max);


#endif /* UTNINPUTS_H_ */
