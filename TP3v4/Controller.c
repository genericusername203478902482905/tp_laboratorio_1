#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "TP3input.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int ret=-1;
    f = fopen(path, "r+");
    if(f == NULL){
        printf("Error al abrir el archivo\nVerificar si existe. \n\n");
        system("pause");
    }else{
        ret = 0;
         printf("Archivo abierto. \n");
         ret= parser_EmployeeFromText(f, pArrayListEmployee);
         system("pause");
    }
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int ret=-1;
    f= fopen(path, "rb");

    if(f==NULL)
    {
        ret=0;
        printf("Error al abrir el archivo\nVerificar si existe.\n");

    }
    else{
        ret=1;
        ret= parser_EmployeeFromBinary(f, pArrayListEmployee);
        printf("Archivo de texto abierto\n");

    }

    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* enP;
   int resp;
   int cant;
   char var1[50];
   char var2[50];
   char var3[50];
   char var4[50];
   resp = 1;
   while (resp == 1){
        cant = ll_len(pArrayListEmployee);
        sprintf(var1,"%d",cant);
        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        getString(var2);
        printf("\nIngrese las horas trabajadas del empleado: ");
        fflush(stdin);
        getString(var3);
        printf("\nIngrese el sueldo del empleado: ");
        fflush(stdin);
        getString(var4);
        enP = employee_newParametros(var1,var2,var3,var4);
        ll_add(pArrayListEmployee,enP);
        printf("\nPara continuar ingresando datos ingrese1 : ");
        getInt(&resp);
        system("cls");
   }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int resp;
    char auxNombre[51];
    int auxSueldo;
	int auxHoras;
    Employee* puntero;

    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el ID del empleado a modificar: ");
    getInt(&id);
    if (pArrayListEmployee != NULL){
        puntero = ll_get(pArrayListEmployee,id);
        printf("1-Para modificar el Nombre\t 2-Para modificar el Sueldo\t 3-Para modificar las horas trabajadas");
        getInt(&resp);
        switch(resp){
            case 1:
                printf("\nIngrese el nombre a asignar");
                getString(auxNombre);
                employee_setNombre(puntero,auxNombre);
                break;
            case 2:
                printf("\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                break;
            case 3:
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
            case 4:
                printf("\n\nIngrese el nombre a asignar");
                getString(auxNombre);
                employee_setNombre(puntero,auxNombre);
                printf("\n\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
        }
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant;
    int id;
    int resp;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a eliminar: ");
    getInt(&id);
    if (pArrayListEmployee != NULL){
        cant = ll_len(pArrayListEmployee);
        if (id >0 && id <= cant){
            puntero = ll_get(pArrayListEmployee,id);
            free(puntero);
            ll_remove(pArrayListEmployee,id);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
        }
        else{
            printf("\nEl id debe ser entre 1 y %d\n\n",cant);
            system("pause");
            system("cls");
        }
    }
    else{
        printf("\n\nError al eliminar el registro \n\n");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
	int cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
    }
    return 1;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int j;
	int cant;

	Employee* empleadoActual;
	Employee* empleadoSiguiente;
	Employee* aux;
	cant = ll_len(pArrayListEmployee);

	for (i=1; i<cant; i++){
		empleadoActual = ll_get(pArrayListEmployee, i);
		for (j=i+1; j<cant; j++){
			empleadoSiguiente = ll_get(pArrayListEmployee, j);
			if (employee_getSueldo(empleadoActual) > employee_getSueldo(empleadoSiguiente)){
				aux = empleadoActual;
				empleadoActual = empleadoSiguiente;
				empleadoSiguiente = aux;
			}
		}
	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int cant;
	int i;
    int total = 0;
    Employee* auxEmpleado;

    cant = ll_len(pArrayListEmployee);

    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (cant>0){
        for (i=0;i<cant;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int cant;
	int i;
    int total= 0;
    Employee* auxEmpleado;
    cant = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"r+b");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+b");
    }
    if (cant>0){
        for (i=0;i<cant;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

