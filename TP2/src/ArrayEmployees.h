/*
 * ArrayEmployees.h
 *
 *  Created on: Sep 24, 2020
 *      Author: david
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Empleado;


/** \brief Hardcode de array Empleado para testeo
 *
 * \param pArray Array de Empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return 0 Es void
 *
 */
void hardCode(Empleado* pArray,int limite);

/** \brief Funcion para dar de alta a un empleado
 *
 * \param pArray Array de Empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param contEmpleados Contador de empleados usado para obtener ID
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int alta(Empleado *pArray, int limite, int *contEmpleados);

/** \brief Funcion para modificar a un empleado
 *
 * \param pArray Array de Empleados a ser actualizado
 * \param indice ID de empleado a ser modificado
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int modifyEmployee(Empleado* pArray, int indice);

/** \brief Setea flag (isEmpty) en 1 para todos para inicializar array
 * \param pArray Array de Empleados a ser inicializado
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int initEmployees(Empleado* pArray, int limite);

/** \brief Agrega en la lista de empleados los valores recibidos como parametros
 * en la primera posicion vacia
 * \param pArray Array de Empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param id ID de empleado
 * \param name[] Nombre de empleado
 * \param lastName[] Apellido de empleado
 * \param salary Salario de empleado
 * \param sector Sector de empleado
 * \return Retorna -1 (ERROR si Array invalido o no hay espacio disponible) y 0 (EXITO)
 */
int addEmployee(Empleado* pArray, int limite, int id, char name[],char
lastName[],float salary,int sector, int *contEmpleados);

/** \brief Encuentra la primera posicion vacia del array buscando el primer
 * flag (isEmpty) en 1
 * \param pArray Array de Empleados en el que hace la busqueda
 * \param limite Limite del array de empleados
 * \param guarda la posicion en este parametro para ser utilizado en otras funciones
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int findEmpty(Empleado *pArray, int limite, int* position);

/** \brief Encuentra un empleado por ID y retorna la posicion de indice del array
 *
 * \param pArray Array de Empleados en el que hace la busqueda
 * \param limite Limite del array de empleados
 * \param id ID que busca en el array
 * \return Retorna posicion de indice del empleado en el array y -1 (ERROR si Array invalido
 * o empleado no encontrado)
 *
 */
int findEmployeeById(Empleado* pArray, int limite,int id);

/** \brief Remueve empleado por ID (setea isEmpty Flag en 1)
 *
 * \param pArray Array de Empleados en el que hace la busqueda
 * \param limite Limite del array de empleados
 * \param id ID que busca en el array
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int removeEmployee(Empleado* pArray, int limite, int id);

/** \brief Calcula el total y promedio de los salarios, y cuantos empleados
 * superan el salario promedio
 *
 * \param pArray Array de Empleados en el que se hace el calculo
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int salaryCalculator(Empleado *pArray, int limite);

/** \brief Sortea los elementos en el array de empleados alfabeticamente por apellido
 * y sector en forma ascendiente o descendiente, dependiendo del orden seleccionado
 *
 * \param pArray Array de Empleados que se sortea
 * \param limite Limite del array de empleados
 * \param orden [1] sortear ascendiente - [0] sortear descendiente
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int sortEmployees(Empleado* pArray, int limite, int orden);

/** \brief Imprime el contenido del array de empleados en una tabla
 *
 * \param pArray Array de Empleados que se imprime
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 *
 */
int printEmployees(Empleado* pArray, int limite);


#endif /* ARRAYEMPLOYEES_H_ */
