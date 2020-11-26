/*
 * Controller.h
 *
 *  Created on: Nov 26, 2020
 *      Author: david
 */

#include "../inc/eArticulos.h"

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

/** \brief Carga los datos de los articulos desde el archivo .csv
 *
 * \param path puntero char* nombre de archivo .csv
 * \param pArrayListArticulo puntero LinkedList* de articulos
 * \param lastId puntero int* ultimo Id
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListArticulo, int *lastId);

/** \brief Guarda los datos de los articulos en el archivo .csv
 *
 * \param path puntero char* nombre de archivo .csv
 * \param pArrayListArticulo puntero LinkedList* de articulos
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListArticulo);

/** \brief Alta de articulo
 *
 * \param path char*
 * \param pArrayList puntero LinkedList* de articulos
 * \return int
 *
 */
int controller_addArticulo(LinkedList *pArrayList);

/** \brief Sorteo de articulos
 *
 * \param path char*
 * \param pArrayList puntero LinkedList* de articulos
 * \return int
 *
 */
int controller_sortArticulo(LinkedList *pArrayList);

/** \brief Printeo de articulos
 *
 * \param path char*
 * \param pArrayList puntero LinkedList* de articulos
 * \return int
 *
 */
int controller_listArticulo(LinkedList *pArrayList);

int controller_mapArticulo(LinkedList *pArrayList);

int controller_contadorArticulos(LinkedList *pArrayList, int tipo);

int calcularDescuento(void *pArticulo);

#endif /* INC_CONTROLLER_H_ */
