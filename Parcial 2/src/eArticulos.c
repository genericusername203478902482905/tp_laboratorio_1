#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/utnInputs.h"
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/eArticulos.h"


int printRubros(eRubro *pArray) {
	int ret = -1;
	int i;
	if (pArray != NULL) {
		printf("\n__________________________________"
			   "\n| ID: | Descripcion:              |"
		       "\n|---------------------------------|\n");
		for (i = 0; i < 4; i++) {
			printf("|%d    | %26s|\n",
							pArray[i].id,    pArray[i].desc);
		}
		ret = 0;
	}
	return ret;
}

int findRubroById(eRubro *pArray, int id) {
	int ret = -1;
	int i;

	if (pArray != NULL) {
		for (i = 0; i < 4; i++) {
			if (pArray[i].id == id) {
				ret = i;
				break;
			}
		}
	}
	return ret;
}

eArticulo* articulo_new() {
	eArticulo *articulo = malloc(sizeof(eArticulo));
	return articulo;
}

int articulo_delete(eArticulo *this) {
	int ret = -1;
	if (this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

eArticulo* articulo_newParametros(char *idStr, char *articuloStr,
		char *medidaStr, char *precioStr, char *rubroIdStr) {
	eArticulo *this = NULL;

	this = articulo_new();

	if (idStr != NULL && articuloStr != NULL && precioStr != NULL
			&& medidaStr != NULL && rubroIdStr != NULL) {
		if (!(!articulo_setId(this, atoi(idStr))
				&& !articulo_setArticulo(this, articuloStr)
				&& !articulo_setPrecio(this, atoi(precioStr))
				&& !articulo_setMedida(this, medidaStr)
				&& !articulo_setRubroId(this, atoi(rubroIdStr)))) {
			articulo_delete(this);
		}
	}

	return this;
}

int articulo_setId(eArticulo *this, int id) { // SET ID
	int ret = -1;

	if (this != NULL && id >= 0) {
		this->id = id;
		ret = 0;
	}
	return ret;
}

int articulo_getId(eArticulo *this, int *id)  // GET ID
{
	int ret = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		ret = 0;
	}
	return ret;
}

int articulo_setArticulo(eArticulo *this, char *articulo) // SET ARTICULO
{
	int ret = -1;

	if (this != NULL && articulo != NULL) {
		strcpy(this->articulo, articulo);
		ret = 0;
	}
	return ret;
}

int articulo_getArticulo(eArticulo *this, char *articulo) // GET ARTICULO
{
	int ret = -1;

	if (this != NULL && articulo != NULL) {
		strcpy(articulo, this->articulo);
		ret = 0;
	}
	return ret;
}

int articulo_setPrecio(eArticulo *this, float precio) { // SET PRECIO
	int ret = -1;

	if (this != NULL && precio >= 0) {
		this->precio = precio;
		ret = 0;
	}
	return ret;
}

int articulo_getPrecio(eArticulo *this, float *precio) // GET PRECIO
{
	int ret = -1;

	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		ret = 0;
	}
	return ret;
}

int articulo_setMedida(eArticulo *this, char *medida) // SET MEDIDA
{
	int ret = -1;

	if (this != NULL && medida != NULL) {
		strcpy(this->medida, medida);
		ret = 0;
	}
	return ret;
}

int articulo_getMedida(eArticulo *this, char *medida) // GET MEDIDA
{
	int ret = -1;

	if (this != NULL && medida != NULL) {
		strcpy(medida, this->medida);
		ret = 0;
	}
	return ret;
}

int articulo_setRubroId(eArticulo *this, int rubroId) { // SET RUBRO ID
	int ret = -1;

	if (this != NULL && rubroId >= 1 && rubroId <= 4) {
		this->rubroId = rubroId;
		ret = 0;
	}
	return ret;
}

int articulo_getRubroId(eArticulo *this, int *rubroId)  // GET RUBRO ID
{
	int ret = -1;

	if (this != NULL && rubroId != NULL) {
		*rubroId = this->rubroId;
		ret = 0;
	}
	return ret;
}

int articulo_add(LinkedList *this) {
	int ret = -1;
	eArticulo *pArticulo = NULL;
	char id[99];
	char articulo[99];
	char precio[99];
	char medida[99];
	char rubroId[99];
	eRubro rubros[] = { { 1, "CUIDADO DE ROPA           " }, { 2,
			"LIMPIEZA Y DESINFECCION   " }, { 3, "CUIDADO PERSONAL E HIGIENE" },
			{ 4, "CUIDADO DEL AUTOMOTOR     " } };

	if (this != NULL) {
		printf("\nALTA DE ARTICULO:\n\n");

		sprintf(id, "%d", ll_len(this));

		if (!utn_getString(articulo, "Ingrese el nombre del articulo: ",
				"\nError, ingrese nombre valido: ", 1, strlen(articulo), 5)) {
			if (!utn_getString(precio, "Ingrese el precio del articulo: ",
					"\nError, ingrese precio valido: ", 1, strlen(precio), 5)) {
				if (!utn_getString(medida, "Ingrese la medida del articulo: ",
						"\nError, ingrese medida valida: ", 1, strlen(medida),
						5)) {
					printRubros(rubros);
					if (!utn_getString(rubroId, "Ingrese el ID del rubro: ",
							"\nError, ingrese medida valida: ", 1,
							strlen(rubroId), 5)) {
						pArticulo = articulo_newParametros(id, articulo, precio,
								medida, rubroId);
						if (pArticulo != NULL) {
							if (!ll_add(this, pArticulo)) {
								ret = 0;
							}
						}
					}
				}
			}
		}

	}
	return ret;
}

int articulo_sortById(void *articulo1, void *articulo2) {
	int ret = 0;

	eArticulo *pArt1;
	eArticulo *pArt2;

	if (articulo1 != NULL && articulo2 != NULL) {
		pArt1 = (eArticulo*) articulo1;
		pArt2 = (eArticulo*) articulo2;

		if (pArt1->id == pArt2->id) {
			ret = 0;  //SI ES IGUAL
		} else if (pArt1->id > pArt2->id) {
			ret = 1;  //SI ES MAYOR EL PRIMER ARTICULO
		} else {
			ret = -1;  //SI ES MAYOR EL SEGUNDO ARTICULO
		}
	}
	return ret;
}

int articulo_sortByArticulo(void *articulo1, void *articulo2) {
	int ret = 0;
	eArticulo *pArt1;
	eArticulo *pArt2;

	if (articulo1 != NULL && articulo2 != NULL) {
		pArt1 = (eArticulo*) articulo1;
		pArt2 = (eArticulo*) articulo2;

		ret = strcmp(pArt1->articulo, pArt2->articulo);
	}
	return ret;
}

int articulo_sortByPrecio(void *articulo1, void *articulo2) {
	int ret = 0;
	eArticulo *pArt1;
	eArticulo *pArt2;

	if (articulo1 != NULL && articulo2 != NULL) {
		pArt1 = (eArticulo*) articulo1;
		pArt2 = (eArticulo*) articulo2;

		if (pArt1->precio == pArt2->precio) {
			ret = 0; //SI ES IGUAL
		} else if (pArt1->precio > pArt2->precio) {
			ret = 1; //SI ES MAYOR EL PRIMER ARTICULO
		} else {
			ret = -1; //SI ES MAYOR EL SEGUNDO ARTICULO
		}
	}
	return ret;
}

int articulo_sortByMedida(void *articulo1, void *articulo2) {
	int ret = 0;
	eArticulo *pArt1;
	eArticulo *pArt2;

	if (articulo1 != NULL && articulo2 != NULL) {
		pArt1 = (eArticulo*) articulo1;
		pArt2 = (eArticulo*) articulo2;

		ret = strcmp(pArt1->medida, pArt2->medida);
	}
	return ret;
}

int articulo_contadorPrecio(void *articulo) {
	int ret;
	float auxPrecio;
	eArticulo *pArticulo = (eArticulo*) articulo;
	if (pArticulo != NULL) {
		articulo_getPrecio(pArticulo, &auxPrecio);
		if (auxPrecio > 100) {
			ret = 1;
		} else {
			ret = 0;
		}
	}
	return ret;
}

int articulo_contadorRubro(void *articulo) {
	int ret;
	int auxIdRubro;
	eArticulo *pArticulo = (eArticulo*) articulo;
	if (pArticulo != NULL) {
		articulo_getRubroId(pArticulo, &auxIdRubro);
		if (auxIdRubro == 1) {
			ret = 1;
		} else {
			ret = 0;
		}
	}
	return ret;
}
