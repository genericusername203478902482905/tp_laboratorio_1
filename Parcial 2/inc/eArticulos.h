/*
 * eArticulos.h
 *
 *  Created on: Nov 26, 2020
 *      Author: david
 */

#ifndef INC_EARTICULOS_H_
#define INC_EARTICULOS_H_

typedef struct
{
    int id;
    char articulo[50];
    float precio;
    char medida[20];
    int rubroId;
}eArticulo;

typedef struct
{
    int id;
    char desc[50];
}eRubro;

/** \brief Printea una tabla de los rubros
 *
 * \param path char*
 * \param pArray puntero eRubro* de rubros
 * \return int
 *
 */
int printRubros(eRubro *pArray);
int findRubroById(eRubro *pArray, int id);

eArticulo* articulo_new();

int articulo_add(LinkedList* this);
int articulo_delete(eArticulo *this);

eArticulo* articulo_newParametros(char* idStr,char* articuloStr,char* precioStr,char* medidaStr,char* rubroIdStr);

int articulo_setId(eArticulo* this,int id);
int articulo_setArticulo(eArticulo* this,char* articulo);
int articulo_setPrecio(eArticulo* this,float precio);
int articulo_setMedida(eArticulo *this, char *medida);
int articulo_setRubroId(eArticulo* this,int rubroId);

int articulo_getId(eArticulo *this, int *id);
int articulo_getArticulo(eArticulo *this, char *articulo);
int articulo_getPrecio(eArticulo *this, float *precio);
int articulo_getMedida(eArticulo *this, char *medida);
int articulo_getRubroId(eArticulo *this, int *rubroId);

int articulo_sortById(void* articulo1,void* articulo2);
int articulo_sortByArticulo(void* articulo1,void* articulo2);
int articulo_sortByPrecio(void* articulo1,void* articulo2);
int articulo_sortByMedida(void* articulo1,void* articulo2);

int articulo_contadorPrecio(void* articulo);
int articulo_contadorRubro(void* articulo);

#endif /* INC_EARTICULOS_H_ */
