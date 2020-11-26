/*
 * parser.h
 *
 *  Created on: Nov 7, 2020
 *      Author: david
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los articulos desde el archivo .csv (modo texto).
 *
 * \param pFile puntero FILE*
 * \param pArrayListArticulo puntero LinkedList* de articulos
 * \param lastId puntero int* que almacena el ultimo Id en el LinkedList
 * \return int
 *
 */
int parser_articuloFromText(FILE* pFile, LinkedList* pArrayListArticulo, int* lastId);

#endif /* PARSER_H_ */



