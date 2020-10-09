/*
 ============================================================================
 Name        : TP2.c
 Author      : Juan Carlos Carruyo
 Seccion     : 1E
 Description : TP2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "ArrayEmployees.h"

#define MAX 1000
#define NAMELIMIT 51

int main(void) {
	setbuf(stdout, NULL);

	int resultadoInicializar = 0;
	int resultadoMenu = 0;
	int resultadoFindEmployeeById = 0;
	int resultadoID = 0;
	int resultadoRemoveEmployee = 0;
	int resultadoOrder = 0;
	int resultadoSort = 0;
	int resultadoCarga = 0;
	int resultadoPrintEmployee = 0;
	int resultadoSalaryCalculator = 0;

	int opcion;
	int flagAltas = 0;
	int contEmpleados = 0;

	int id;
	int orden;

	Empleado arrayEmpleados[MAX];

	resultadoInicializar = initEmployees(arrayEmpleados, MAX);
//	hardCode(arrayEmpleados, MAX);

	do {
		if (resultadoInicializar == -1) {
			printf("\nERROR AL INICIALIZAR EMPLEADOS");
			system("pause");
			break;
		}
		system("CLS");
		resultadoMenu = getInt(&opcion, "Menu de Opciones\n"
				"1- ALTAS \n"
				"2- MODIFICAR \n"
				"3- BAJA \n"
				"4- INFORMAR \n"
				"Ingrese Opcion: \n",
				"\nError: Seleccione una opcion valida.\n", 1, 4, 3);
		if (resultadoMenu != 0) {
			printf("\nERROR FATAL");
			system("pause");
			break;
		}

		switch (opcion) {
		case 1:
			flagAltas = 1;

			resultadoCarga = alta(arrayEmpleados, MAX, &contEmpleados);
			if (resultadoCarga != 0) {
				printf("\nError en la Carga.\n");
				system("pause");
			}

			break;

		case 2:
			if (flagAltas == 1) {

				resultadoID = getInt(&id, "\nIngrese el ID del empleado: ",
						"\nERROR: Ingrese un ID valido", 1, MAX, 10);

				if (resultadoID != 0) {
					printf("\nError ingresando ID.\n");
					system("pause");
				} else {
					resultadoFindEmployeeById = findEmployeeById(arrayEmpleados,
					MAX, id);

					if (resultadoFindEmployeeById == -1) {
						printf("\nNo se encontro empleado con ese ID.");
						system("pause");
					} else {
						modifyEmployee(arrayEmpleados,
								resultadoFindEmployeeById);
						printf("\nSe modifico un empleado con exito.\n");
						system("pause");
					}
				}

			} else {
				printf("\nDebe cargar algun empleado antes de Modificar. \n");
				system("pause");
			}
			break;
		case 3:
			if (flagAltas == 1) {

				resultadoID = getInt(&id, "\nIngrese el ID del empleado: ",
						"\nERROR: Ingrese un ID valido", 1, MAX, 10);

				if (resultadoID != 0) {
					printf("\nError ingresando ID.\n");
					system("pause");
				} else {
					resultadoFindEmployeeById = findEmployeeById(arrayEmpleados,
					MAX, id);

					if (resultadoFindEmployeeById == -1) {
						printf("\nNo se encontro empleado con ese ID.");
						system("pause");
					} else {
						resultadoRemoveEmployee = removeEmployee(arrayEmpleados,
						MAX, resultadoFindEmployeeById);
						if (resultadoRemoveEmployee != 0) {
							printf("\nError removiendo empleado.\n");
							system("pause");
						}
						printf("\nSe dio de baja a un empleado con exito.\n");
						system("pause");
					}
				}

			} else {
				printf("\nDebe cargar algun empleado antes de Bajar. \n");
				system("pause");
			}
			break;
		case 4:
			if (flagAltas == 1) {

				resultadoOrder =
						getInt(&orden,
								"\nDesea ordenar de manera ascendente (1) o descendente (0)?: ",
								"\nERROR: Ingrese una opcion valida. ascendente - 1 | descendente 0",
								0, 1, 10);
				if (resultadoOrder != 0) {
					printf("\nError en la seleccion.\n");
					system("pause");
				}
				resultadoSort = sortEmployees(arrayEmpleados, MAX, orden);
				if (resultadoSort != 0) {
					printf("\nError en el ordenamiento.\n");
					system("pause");
				}

				resultadoPrintEmployee = printEmployees(arrayEmpleados, MAX);
				if (resultadoPrintEmployee != 0) {
					printf("\nError mostrando los empleados.\n");
					system("pause");
				}

				resultadoSalaryCalculator = salaryCalculator(arrayEmpleados,
						MAX);
				if (resultadoSalaryCalculator != 0) {
					printf("\nError calculando salarios.\n");
					system("pause");
				}
				system("pause");

			} else {
				printf("\nDebe cargar algun empleado antes de Informar. \n");
				system("pause");
			}
			break;
		}

	} while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4);

	return EXIT_SUCCESS;
}
