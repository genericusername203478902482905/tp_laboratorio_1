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
 * \return int 0 si cargo archivo con exito, -1 si hubo algun error
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListArticulo, int *lastId);

/** \brief Guarda los datos de los articulos en el archivo .csv
 *
 * \param path puntero char* nombre de archivo .csv
 * \param pArrayListArticulo puntero LinkedList* de articulos
 * \return int 0 si guardo archivo con exito, -1 si hubo algun error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListArticulo);

/** \brief Alta de articulo
 *
 * \param pArrayList puntero LinkedList* de articulos
 * \return int 0 si agrego articulo con exito, -1 si hubo algun error
 *
 */
int controller_addArticulo(LinkedList *pArrayList);

/** \brief Sorteo de articulos
 *
 * \param pArrayList puntero LinkedList* de articulos
 * \return int 0 si sorteo con exito, -1 si hubo algun error
 *
 */
int controller_sortArticulo(LinkedList *pArrayList);

/** \brief Printeo de articulos
 *
 * \param pArrayList puntero LinkedList* de articulos
 * \return int 0 si printeo con exito, -1 si hubo algun error
 *
 */
int controller_listArticulo(LinkedList *pArrayList);

/** \brief Mapeo de funcion en LinkedList
 *
 * \param pArrayList puntero LinkedList* de articulos
 * \return int 1
 *
 */
int controller_mapArticulo(LinkedList *pArrayList);

/** \brief Mapeo de funcion en LinkedList
 *
 * \param pArrayList puntero LinkedList* de articulos
 * \param int tipo 1 si desea aplicar conteo de precios >$100, 2 si desea contar rubroIds "1"
 * \return int 0 si conto con exito, -1 si hubo algun error
 *
 */
int controller_contadorArticulos(LinkedList *pArrayList, int tipo);

/** \brief Funcion que calcula es descuento aplicado depiendo del rubroId 1 o 2
 *
 * \param puntero void* pArticulo
 * \return int -1 si hubo algun error, int 1 si tuvo exito el calculo
 *
 */
int calcularDescuento(void *pArticulo);

#endif /* INC_CONTROLLER_H_ */
