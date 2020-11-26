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

/** \brief Crea un articulo nuevo sin parametros
 * \return un articulo
 *
 */
eArticulo* articulo_new();

int articulo_add(LinkedList* this);
int articulo_delete(eArticulo *this);

/** \brief Crea un nuevo articulo con parametros
 *
 * \param id como string
 * \param articulo como string
 * \param precio como string
 * \param medida como string
 * \param rubroId como string
 * \return retorna una articulo nuevo
 *
 */
eArticulo* articulo_newParametros(char* idStr,char* articuloStr,char* precioStr,char* medidaStr,char* rubroIdStr);

/* FUNCIONES SET
 * \brief Setea diferentes parametros
 * \param puntero eArticulo* this
 * \param int id, char* articulo, float precio, char* medida, int rubroId
 * \return 0 si esta ok,-1 si hay un error
 *
 */
int articulo_setId(eArticulo* this,int id);
int articulo_setArticulo(eArticulo* this,char* articulo);
int articulo_setPrecio(eArticulo* this,float precio);
int articulo_setMedida(eArticulo *this, char *medida);
int articulo_setRubroId(eArticulo* this,int rubroId);

/* FUNCIONES GET
 * \brief Obtiene diferentes parametros de eArticulo* y guarda en puntero de parametro
 * \param puntero eArticulo* this
 * \param int* id, char* articulo, float* precio, char* medida, int* rubroId
 * \return 0 si esta ok,-1 si hay un error
 *
 */
int articulo_getId(eArticulo *this, int *id);
int articulo_getArticulo(eArticulo *this, char *articulo);
int articulo_getPrecio(eArticulo *this, float *precio);
int articulo_getMedida(eArticulo *this, char *medida);
int articulo_getRubroId(eArticulo *this, int *rubroId);

/* FUNCIONES SORT */
/* \brief Sortea 2 articulos por diferentes parametros
 * \param puntero void* articulo1
 * \param puntero void* articulo2
 * \return: 0 si son igual,
 *          1 si articulo 1 es mayor,
 *         -1 si articulo 2 es mayor
 */
int articulo_sortById(void* articulo1,void* articulo2);
int articulo_sortByArticulo(void* articulo1,void* articulo2);
int articulo_sortByPrecio(void* articulo1,void* articulo2);
int articulo_sortByMedida(void* articulo1,void* articulo2);

/* CONTADORES DE ARTICULOS */
int articulo_contadorPrecio(void* articulo);
int articulo_contadorRubro(void* articulo);

#endif /* INC_EARTICULOS_H_ */
