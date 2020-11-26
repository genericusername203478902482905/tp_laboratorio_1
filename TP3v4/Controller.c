#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "TP3input.h"
#include "controller.h"
#include "utnInputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *f;
	int ret = -1;
	f = fopen(path, "r+");
	if (f == NULL) {
		printf("Error al abrir el archivo\nVerificar si existe. \n\n");
		system("pause");
	} else {
		ret = 0;
		printf("Archivo abierto. \n");
		ret = parser_EmployeeFromText(f, pArrayListEmployee);
		system("pause");
	}
	fclose(f);
	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int ret = -1;
	FILE *f = NULL;

	if (path != NULL && pArrayListEmployee != NULL) {
		f = fopen(path, "rb");
		if (f != NULL) {
			if (!parser_EmployeeFromBinary(f, pArrayListEmployee)) {
				ret = 0;
			}
		}

	} else {
		printf("Error al abrir el archivo\nVerificar si existe.\n");
	}
	fclose(f);
	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	Employee *enP;
	int resp;
	int cant;
	char var1[50];
	char var2[50];
	char var3[50];
	char var4[50];
	resp = 1;
	while (resp == 1) {
		cant = ll_len(pArrayListEmployee);
		sprintf(var1, "%d", cant);
		printf("\nIngrese el nombre del empleado: ");
		fflush(stdin);
		getString(var2);
		printf("\nIngrese las horas trabajadas del empleado: ");
		fflush(stdin);
		getString(var3);
		printf("\nIngrese el sueldo del empleado: ");
		fflush(stdin);
		getString(var4);
		enP = employee_newParametros(var1, var2, var3, var4);
		ll_add(pArrayListEmployee, enP);
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
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int id;
	int resp;
	char auxNombre[51];
	int auxSueldo;
	int auxHoras;
	Employee *puntero;

	printf("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
	getInt(&resp);
	if (resp == 1) {
		controller_ListEmployee(pArrayListEmployee);
	}
	printf("\nIngrese el ID del empleado a modificar: ");
	getInt(&id);
	if (pArrayListEmployee != NULL) {
		puntero = ll_get(pArrayListEmployee, id);
		printf(
				"1-Para modificar el Nombre\t 2-Para modificar el Sueldo\t 3-Para modificar las horas trabajadas");
		getInt(&resp);
		switch (resp) {
		case 1:
			printf("\nIngrese el nombre a asignar");
			getString(auxNombre);
			employee_setNombre(puntero, auxNombre);
			break;
		case 2:
			printf("\nIngrese el sueldo a asignar");
			getInt(&auxSueldo);
			employee_setSueldo(puntero, auxSueldo);
			break;
		case 3:
			printf("\nIngrese las horas trabajadas a asignar");
			getInt(&auxHoras);
			employee_setHorasTrabajadas(puntero, auxHoras);
			break;
		case 4:
			printf("\n\nIngrese el nombre a asignar");
			getString(auxNombre);
			employee_setNombre(puntero, auxNombre);
			printf("\n\nIngrese el sueldo a asignar");
			getInt(&auxSueldo);
			employee_setSueldo(puntero, auxSueldo);
			printf("\nIngrese las horas trabajadas a asignar");
			getInt(&auxHoras);
			employee_setHorasTrabajadas(puntero, auxHoras);
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
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int cant;
	int id;
	int resp;
	Employee *puntero;
	printf("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
	getInt(&resp);
	if (resp == 1) {
		controller_ListEmployee(pArrayListEmployee);
	}
	printf("\nIngrese el id del empleado a eliminar: ");
	getInt(&id);
	if (pArrayListEmployee != NULL) {
		cant = ll_len(pArrayListEmployee);
		if (id > 0 && id <= cant) {
			puntero = ll_get(pArrayListEmployee, id);
			free(puntero);
			ll_remove(pArrayListEmployee, id);
			printf("\nSe elimino correctamente\n");
			system("pause");
			system("cls");
		} else {
			printf("\nEl id debe ser entre 1 y %d\n\n", cant);
			system("pause");
			system("cls");
		}
	} else {
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
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int i;
	int cant;
	cant = ll_len(pArrayListEmployee);
	Employee *lista;
	for (i = 1; i < cant; i++) {
		lista = (Employee*) ll_get(pArrayListEmployee, i);
		printf("%d\t %s\t %d\t %d\n", employee_getId(lista),
				employee_getNombre(lista), employee_getHorasTrabajadas(lista),
				employee_getSueldo(lista));
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
int controller_sortEmployee(LinkedList *pArrayListEmployee) {

	int ret = 0;
	int subMenu;
	int cant;
	int vRespuestaVolver = 0;

	if (pArrayListEmployee != NULL) {

		cant = ll_len(pArrayListEmployee);
		if (cant > 0) {
			do {

				do {
					system("cls");
					printf("----------------------------------\n"
							"1- ORDENAR POR ID.\n"
							"2- ORDENAR POR NOMBRE.\n"
							"3- ORDENAR POR HORAS TRABAJADAS.\n"
							"4- ORDENAR POR SALARIO.\n"
							"5- VOLVER.\n"
							"----------------------------------\n");
				} while (utn_getInt(&subMenu, "Ingrese la opcion deseada: ",
						"\nIngrese una opcion valida.\n", 1, 5, 5) == -1);
				system("cls");

				switch (subMenu) {
				case 1:
					do {
						system("cls");
						printf("---------------------------------------\n"
								"1- ORDENAR POR ID DE MANERA ASCENDENTE \n"
								"2- ORDENAR POR ID DE MANERA DESCENDENTE\n"
								"3- VOLVER.\n"
								"---------------------------------------\n");
					} while (utn_getInt(&subMenu,
							"Ingrese la opcion deseada: ",
							"\nIngrese una opcion valida.\n", 1, 3, 5) == -1);

					system("cls");
					switch (subMenu) {
					case 1:
						ll_sort(pArrayListEmployee, employee_compareById,1);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;
					case 2:
						ll_sort(pArrayListEmployee, employee_compareById,0);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;

					case 3:
						break;
					}

					break;
				case 2:
					do {
						system("cls");
						printf(
								"-------------------------------------------\n"
								"1- ORDENAR POR NOMBRE DE MANERA ASCENDENTE \n"
								"2- ORDENAR POR NOMBRE DE MANERA DESCENDENTE\n"
								"3- VOLVER.\n"
								"-------------------------------------------\n");
					} while (utn_getInt(&subMenu,
							"Ingrese la opcion deseada: ",
							"\nIngrese una opcion valida.\n", 1, 3, 5) == -1);
					system("cls");

					switch (subMenu) {
					case 1:
						ll_sort(pArrayListEmployee, employee_compareByName,1);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;
					case 2:
						ll_sort(pArrayListEmployee, employee_compareByName,0);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;
					case 3:
						break;
					}
					break;
				case 3:
					do {
						system("cls");
						printf(
								"-----------------------------------------------------\n"
								"1- ORDENAR POR HORAS TRABAJADAS DE MANERA ASCENDENTE \n"
								"2- ORDENAR POR HORAS TRABAJADAS DE MANERA DESCENDENTE\n"
								"3- VOLVER.\n"
								"-----------------------------------------------------\n");
					} while (utn_getInt(&subMenu,
							"Ingrese la opcion deseada: ",
							"\nIngrese una opcion valida.\n", 1, 3, 5) == -1);
					system("cls");

					switch (subMenu) {
					case 1:
						ll_sort(pArrayListEmployee,employee_compareByWorkedTime, 1);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;
					case 2:
						ll_sort(pArrayListEmployee,employee_compareByWorkedTime, 0);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("Sorteo realizado.\n");
						system("pause");
						break;
					case 3:
						break;

					}

					break;
				case 4:

					do {
						system("cls");
						printf(
								"--------------------------------------------\n"
								"1- ORDENAR POR SALARIO DE MANERA ASCENDENTE \n"
								"2- ORDENAR POR SALARIO DE MANERA DESCENDENTE\n"
								"3- VOLVER.\n"
								"--------------------------------------------\n");
					} while (utn_getInt(&subMenu,
							"Ingrese la opcion deseada: ",
							"\nIngrese una opcion valida.\n", 1, 3, 5) == -1);
					system("cls");

					switch (subMenu) {
					case 1:
						ll_sort(pArrayListEmployee, employee_compareBySalary, 1);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("\nSorteo realizado.\n");
						system("pause");
						break;
					case 2:
						ll_sort(pArrayListEmployee, employee_compareBySalary, 0);
						controller_ListEmployee(pArrayListEmployee);
						ret = 0;
						printf("\nSorteo realizado.\n");
						system("pause");
						break;
					case 3:
						break;
					}
					break;

				case 5:

					utn_getInt(&vRespuestaVolver,
							"Desea volver al menu principal?\n"
							"1-Si\n"
							"2-No\n",
							"\nIngrese una opcion valida.\n", 1, 2, 5);
					system("cls");
					if (vRespuestaVolver == 2) {
						vRespuestaVolver = 0;
					}

					break;
				}

			} while (vRespuestaVolver == 0);

		} else {
			printf("\nEs necesario cargar los empleados antes de sortear.\n ");
			system("pause");
		}
	}

	return ret;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int cant;
	int i;
	int total = 0;
	Employee *auxEmpleado;

	cant = ll_len(pArrayListEmployee);

	pArchivo = fopen(path, "r+");
	if (pArchivo == NULL) {
		pArchivo = fopen(path, "w+");
	}
	if (cant > 0) {
		for (i = 0; i < cant; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			fprintf(pArchivo, "%d,%s,%d,%d\n", auxEmpleado->id,
					auxEmpleado->nombre, auxEmpleado->horasTrabajadas,
					auxEmpleado->sueldo);
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
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int cant;
	int i;
	int total = 0;
	Employee *auxEmpleado;
	cant = ll_len(pArrayListEmployee);
	pArchivo = fopen(path, "r+b");
	if (pArchivo == NULL) {
		pArchivo = fopen(path, "w+b");
	}
	if (cant > 0) {
		for (i = 0; i < cant; i++) {
			auxEmpleado = ll_get(pArrayListEmployee, i);
			fprintf(pArchivo, "%d,%s,%d,%d\n", auxEmpleado->id,
					auxEmpleado->nombre, auxEmpleado->horasTrabajadas,
					auxEmpleado->sueldo);
			total++;
		}
		printf("\nSe escribieron %d caracteres\n\n", total);
	}
	fclose(pArchivo);
	return 1;
}

