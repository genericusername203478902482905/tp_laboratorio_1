/*
 * Controller.c
 *
 *  Created on: Nov 26, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/utnInputs.h"
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/eArticulos.h"

int controller_loadFromText(char *path, LinkedList *pArrayListArticulo,
		int *lastId) {

	FILE *f;
	int ret = -1;
	f = fopen(path, "r");

	if (ll_len(pArrayListArticulo) == 0) {
		if (f == NULL) {
			printf("Error al abrir el archivo\nVerificar si existe. \n\n");
			system("pause");
		} else {
			ret = 0;
			printf("Archivo abierto. \n");
			ret = parser_articuloFromText(f, pArrayListArticulo, lastId);
			system("pause");
		}
	} else {
		printf("El archivo ya fue cargado!.\n\n");
		system("pause");
	}
	return ret;
}

int controller_saveAsText(char *path, LinkedList *pArrayListArticulo) {
	FILE *f;
	eArticulo *articuloAux;
	int ret = -1;
	int i;

	int id;
	char articulo[50];
	char medida[20];
	float precio;
	int rubroId;
	int cant = ll_len(pArrayListArticulo);

	f = fopen(path, "w");
	if (f != NULL && ll_len(pArrayListArticulo) > 0) {
		fprintf(f, "id,articulo,medida,precio,rubro\n");
		for (i = 0; i < cant; i++) {
			articuloAux = (eArticulo*) ll_get(pArrayListArticulo, i);

			articulo_getId(articuloAux, &id);
			articulo_getArticulo(articuloAux, articulo);
			articulo_getMedida(articuloAux, medida);
			articulo_getPrecio(articuloAux, &precio);
			articulo_getRubroId(articuloAux, &rubroId);

			fprintf(f, "%d,%s,%s,%f,%d\n", id, articulo, medida, precio,
					rubroId);
		}
		printf("\nArchivo guardado correctamente.\n");
		system("pause");
		ret = 0;
	} else {
		printf(" \nNo se pudo guardar el archivo\n");
		system("pause");
	}
	fclose(f);
	return ret;
}

int controller_addArticulo(LinkedList *pArrayList) {
	int ret = -1;

	if (pArrayList != NULL) {
		if (!articulo_add(pArrayList)) {
			ret = 0;
		}
	}
	return ret;
}

int controller_sortArticulo(LinkedList *pArrayList) {
	int ret = -1;
	int opcion = 2;
	int orden = 1;

	if (pArrayList != NULL) {
		system("cls");
		/*
		 utn_getInt(&opcion,
		 "Menu:\n"
		 "1. Ordenar por ID\n"
		 "2. Ordenar por nombre de articulo\n"
		 "3. Ordenar por precio\n"
		 "4. Ordenar por medida\n"
		 "5. Salir\n",
		 "\nError: Seleccione una opcion valida.\n", 1, 5, 5);
		 */

		switch (opcion) {
		case 1:
			system("cls");
			if (!utn_getInt(&orden,
					"\nIngrese el orden:\n1-Ascendente/n0-Descendente\n",
					"\nError. Reingrese : \n", 0, 1, 5)) {
				if (!ll_sort(pArrayList, articulo_sortById, orden)) {
					printf("Ordenamiento por ID realizado con exito\n");
					ret = 0; //EXITO
				} else {
					printf("Error al ordenar por ID\n");
				}
			}
			break;

		case 2:
			system("cls");
			//   if(!utn_getInt(&orden,"\nIngrese el orden:\n1-Ascendente/n0-Descendente\n","\nError. Reingrese : \n",0,1,5))
			//   {
			if (!ll_sort(pArrayList, articulo_sortByArticulo, orden)) {
				printf(
						"Ordenamiento por nombre de articulo realizado con exito\n");
				ret = 0;
			} else {
				printf("Error al ordenar por articulo\n");
			}
			//  }
			break;

		case 3:
			system("cls");
			if (!utn_getInt(&orden,
					"\nIngrese el orden:\n1-Ascendente/n0-Descendente\n",
					"\nError. Reingrese : \n", 0, 1, 5)) {

				if (!ll_sort(pArrayList, articulo_sortByPrecio, orden)) {
					printf("Ordenamiento por precio realizado con exito\n");
					ret = 0;
				} else {
					printf("Error al ordenar por precio\n");
				}

			}
			break;

		case 4:
			system("cls");
			if (!utn_getInt(&orden,
					"\nIngrese el orden:\n1-Ascendente/n0-Descendente\n",
					"\nError. Reingrese : \n", 0, 1, 5)) {
				if (!ll_sort(pArrayList, articulo_sortByMedida, orden)) {
					printf("Ordenamiento por medida realizado con exito\n");
					ret = 0;
				} else {
					printf("Error al ordenar por medida\n");
				}

			}
			break;

		case 5:
			break;
		}
	}
	return ret;
}

int controller_listArticulo(LinkedList *pArrayList) {
	int i;
	int cant;
	eArticulo *lista;
	eRubro rubros[] = { { 1, "CUIDADO DE ROPA            |" },
			            { 2, "LIMPIEZA Y DESINFECCION    |" },
						{ 3, "CUIDADO PERSONAL E HIGIENE |" },
						{ 4, "CUIDADO DEL AUTOMOTOR      |" } };
	int auxId;
	char auxArticulo[99];
	char auxMedida[99];
	float auxPrecio;
	int auxIdRubro;
	int posRubroDesc;
	int ret = -1;
	cant = ll_len(pArrayList);

	if (pArrayList != NULL && cant > 0) {

		printf(" ____________________________________________________________________________________________\n"
		       "|    LISTA DE ARTICULOS:                                                                     |\n"
		       "|____________________________________________________________________________________________|\n"
		       "| ID  | Articulo                            |MEDIDA  | PRECIO   | RUBRO                      | \n");
		for (i = 0; i < cant; i++) {
			lista = (eArticulo*) ll_get(pArrayList, i);

			if (lista != NULL) {
				if (!articulo_getId(lista, &auxId)) {
					if (!articulo_getArticulo(lista, auxArticulo)) {
						if (!articulo_getMedida(lista, auxMedida)) {
							if (!articulo_getPrecio(lista, &auxPrecio)) {
								if (!articulo_getRubroId(lista, &auxIdRubro)) {
									posRubroDesc = findRubroById(rubros,
											auxIdRubro);

									if (auxPrecio <= 99) { // contemplando diferencia de espacio en precio
										printf(
												"|%-3d  | %-35s | %-7s| $ %.2f  | %-s\n",
												auxId, auxArticulo, auxMedida,
												auxPrecio,
												rubros[posRubroDesc].desc);
									} else {
										printf(
												"|%-3d  | %-35s | %-7s| $ %.2f | %-s\n",
												auxId, auxArticulo, auxMedida,
												auxPrecio,
												rubros[posRubroDesc].desc);
									}
									lista = NULL;
									ret = 0;
								}
							}
						}
					}
				}
			}
		}
		system("pause");
	}
	return ret;
}

int controller_mapArticulo(LinkedList *pArrayList) {
	int len;
	len = ll_len(pArrayList);
	if (pArrayList != NULL && len > 0) {

		ll_map(pArrayList, calcularDescuento);
		controller_listArticulo(pArrayList);
		printf("\nCalculado correctamente.\n");
		system("pause");
	} else {
		printf("\nNo hay datos para calcular.\n");
		system("pause");
	}
	return 1;
}

int controller_contadorArticulos(LinkedList *pArrayList, int tipo) {
	int ret = -1;
	int cantLista = ll_len(pArrayList);
	int resCount = 0;

	if (pArrayList != NULL && cantLista > 0) {
		switch (tipo) {
		case 1:
			resCount = ll_count(pArrayList, articulo_contadorPrecio);
			if (resCount > 0) {
				printf(
						"\nLa cantidad de articulos con un precio mayor a $100 es: %d \n",
						resCount);
			}
			break;

		case 2:
			resCount = ll_count(pArrayList, articulo_contadorRubro);
			if (resCount > 0) {
				printf(
						"\nLa cantidad de articulos del rubro Cuidado De Ropa es: %d \n",
						resCount);
			}
			break;
		}
	}
	return ret;
}

int calcularDescuento(void *pArticulo) {
	int ret = -1;
	if (pArticulo != NULL) {
		eArticulo *articuloAux = (eArticulo*) pArticulo;
		int rubroId;
		float precio;
		articulo_getRubroId(articuloAux, &rubroId);
		articulo_getPrecio(articuloAux, &precio);
		if (rubroId == 1 && precio >= 120) {
			precio = precio * 0.8;
			articulo_setPrecio(articuloAux, precio);
			ret = 1;
		} else if (rubroId == 2 && precio <= 200) {
			precio = precio * 0.9;
			articulo_setPrecio(articuloAux, precio);
			ret = 1;
		}
	} else {
		printf("\nError.\n");
	}
	return ret;
}
