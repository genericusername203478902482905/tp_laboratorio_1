#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/utnInputs.h"
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/eArticulos.h"


int parser_articuloFromText(FILE *pFile, LinkedList *pArrayListArticulo,
		int *lastId) {

	int ret = 0;
	eArticulo *pArticulo;

	char auxId[99];
	char auxArticulo[99];
	char auxMedida[99];
	char auxPrecio[99];
	char auxIdRubro[99];

	int auxLastId = -1;

	if (pFile != NULL && pArrayListArticulo != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxId, auxId,
				auxId, auxId); //trae headers

		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,
					auxArticulo, auxMedida, auxPrecio, auxIdRubro);

			pArticulo = articulo_newParametros(auxId, auxArticulo, auxMedida,
					auxPrecio, auxIdRubro);

			if (pArticulo != NULL) {
				if (ll_add(pArrayListArticulo, pArticulo) == 0) {
					if (atoi(auxId) > auxLastId) {
						auxLastId = atoi(auxId);
					}
					ret++;
				}
			}
		}
	}
	if (ret > 0) {
		*lastId = auxLastId;
	}
	return ret;
}

