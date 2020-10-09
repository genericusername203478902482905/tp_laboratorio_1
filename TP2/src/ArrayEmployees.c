/*
 * ArrayEmployees.c
 *
 *  Created on: Sep 24, 2020
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utnInputs.h"
#include "ArrayEmployees.h"



#define NAMELIMIT 51
#define MAX 1000

void hardCode(Empleado *pArray, int limite) {

	int id[5] = { 1, 2, 3, 4, 5 };
	char name[][NAMELIMIT] = { "Jonathan", "Joseph", "Jotaro", "Josuke", "Giorno" };
	char lastName[][NAMELIMIT] = { "Joestar", "Joestar", "Kujo", "Higashikata",
			"Giovanna" };
	float salary[5] = { 34000.00, 35000.00, 34000.00, 45000.00, 65000.00 };
	int sector[5] = { 2, 1, 1, 3, 3 };
	int isEmpty[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < 5; ++i) {
		pArray[i].id = id[i];
		strcpy(pArray[i].name, name[i]);
		strcpy(pArray[i].lastName, lastName[i]);
		pArray[i].salary = salary[i];
		pArray[i].sector = sector[i];
		pArray[i].isEmpty = isEmpty[i];
	}
}

int alta(Empleado *pArray, int limite, int *contEmpleados) {

	int resultadoAddEmployee = 0;
	int retorno = -1;

	char name[NAMELIMIT];
	char lastname[NAMELIMIT];
	int auxId = 0;
	float salary;
	int sector;

	if (pArray != NULL && limite > 0){
	getString(name, "\nIngrese el nombre: ", "\nError ingresando el nombre", 1,
			50, 10);
	getString(lastname, "\nIngrese el apellido: ",
			"\nError ingresando el apellido", 1, 50, 10);
	getFloat(&salary, "\nIngrese el salario: ",
			"\nERROR: Salario debe ser mayor a $1", 1, 9999, 10);
	getInt(&sector, "\nIngrese el sector: ",
			"\nERROR: Sector debe ser entre 1 y 50", 1, 50, 10);

	resultadoAddEmployee = addEmployee(pArray, limite, auxId, name, lastname,
			salary, sector, contEmpleados);

	if (resultadoAddEmployee != 0) {
		printf("\nError agregando empleado.\n");
		system("pause");
	} else {

		retorno = 0;
		printEmployees(pArray, limite);
		system("pause");
	}
}

	return retorno;

}

int modifyEmployee(Empleado* pArray, int indice)
{
	int retorno = -1;
	int modSeleccion;
	int resultadoModSeleccion = 0;
	char aux[NAMELIMIT] = " ";


	float salario;
	int sect;

	if (pArray != NULL) {
	resultadoModSeleccion = getInt(&modSeleccion, "Seleccione el campo a modificar\n"
					"1- NOMBRE \n"
					"2- APELLIDO \n"
					"3- SALARIO \n"
					"4- SECTOR \n"
			        "5- SALIR \n"
					"Ingrese Opcion: \n",
					"\nError: Seleccione una opcion valida.\n", 1, 5, 3);

	if (resultadoModSeleccion != 0)
	{
		printf("\nError ingresando una opcion.\n");
		system("pause");
	}
	else{
	switch(modSeleccion)
	{
	case 1:

		getString(aux, "\nIngrese el nombre: ", "\nError ingresando el nombre", 1,
					50, 10);
		strncpy(pArray[indice].name,aux,sizeof(pArray[indice].name));
		retorno = 0;
		break;

	case 2:

		getString(aux, "\nIngrese el apellido: ",
					"\nError ingresando el apellido", 1, 50, 10);

		strncpy(pArray[indice].lastName,aux,sizeof(pArray[indice].lastName));
		retorno = 0;
		break;

	case 3:

		getFloat(&salario, "\nIngrese el salario: ", "\nERROR: Salario debe ser mayor a $1", 1, 9999, 10);
		pArray[indice].salary = salario;
		retorno = 0;
		break;

	case 4:

		getInt(&sect, "\nIngrese el sector: ", "\nERROR: Sector debe ser entre 1 y 50", 1, 50, 10);
		pArray[indice].sector = sect;
		retorno = 0;
		break;

	case 5:
		break;

	}
	}
}
	return retorno;

}

int initEmployees(Empleado *pArray, int limite) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int addEmployee(Empleado *pArray, int limite, int id, char name[],
		char lastName[], float salary, int sector, int *contEmpleados) {
	int retorno = -1;
	int i;
	int contador = *contEmpleados;

	if (findEmpty(pArray, limite, &i) == 0) {
		contador++;
		*contEmpleados = contador;

		pArray[i].id = *contEmpleados;
		strncpy(pArray[i].name, name, sizeof(pArray[i].name));
		strncpy(pArray[i].lastName, lastName, sizeof(pArray[i].lastName));
		pArray[i].salary = salary;
		pArray[i].sector = sector;

		pArray[i].isEmpty = 0;
		retorno = 0;

	} else {
		retorno = -1;
		printf("\nNo hay espacio para mas empleados.");
	}

	return retorno;
}

int findEmpty(Empleado *pArray, int limite, int *pos) {
	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0 && pos != NULL) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty == 1) {
				retorno = 0;
				*pos = i;
				break;
			}
		}
	}

	return retorno;
}

int findEmployeeById(Empleado *pArray, int limite, int id) {
	int retorno = -1;
	int i;
	int flag = 0;

	if (pArray != NULL && limite > 0){
	for (i = 0; i < limite; i++) {
		if (pArray[i].isEmpty != 1) {
			if (pArray[i].id == id) {
				flag = 1;
				retorno = i;
				break;
			}
		}
	}}

	if (flag == 0) {
		retorno = -1;
	}

	return retorno;
}

int removeEmployee(Empleado *pArray, int limite, int id) {
	int retorno = -1;

	if (pArray != NULL && limite > 0) {
		pArray[id].isEmpty = 1;
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(Empleado *pArray, int limite, int orden) {
	int retorno = -1;
	int i = 0;
	int j = 0;
	Empleado aux;

	if (pArray != NULL && limite > 0) {
		switch (orden) {
		case 1: //ascendente
			for (i = 0; i < limite - 1; i++) {
				for (j = i + 1; j < limite; j++) {
					if (strcmp(pArray[i].lastName, pArray[j].lastName) > 0) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}

					else if (strcmp(pArray[j].lastName, pArray[i].lastName) == 0
							&& pArray[j].sector < pArray[i].sector) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}
				}
			}
			break;

		case 0: //descendente
			for (i = 0; i < limite - 1; i++) {
				for (j = i + 1; j < limite; j++) {
					if (strcmp(pArray[j].lastName, pArray[i].lastName) > 0) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}

					else if (strcmp(pArray[j].lastName, pArray[i].lastName) == 0
							&& pArray[j].sector > pArray[i].sector) {
						aux = pArray[j];
						pArray[j] = pArray[i];
						pArray[i] = aux;
					}
				}
			}
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int salaryCalculator(Empleado *pArray, int limite) {

	int retorno = -1;
	int i;
	int empleadoActivo = 0;
	float acumSalario = 0;
	float promedio;
	int empleadosPromedio = 0;

	if (pArray != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				empleadoActivo++;
				acumSalario = acumSalario + pArray[i].salary;
			}
		}
		promedio = acumSalario / empleadoActivo;

		for (i = 0; i < limite; i++) {
			if (pArray[i].salary > promedio) {
				empleadosPromedio++;
			}
		}

		if (empleadosPromedio == 1) {
			printf("\nEl total de los salarios es $%.2f"
					"\nEl promedio de los salarios es: $%.2f"
					"\n%d empleado supera el salario promedio.\n", acumSalario,
					promedio, empleadosPromedio);
		} else {
			printf("\nEl total de los salarios es $%.2f"
					"\nEl promedio de los salarios es: $%.2f"
					"\n%d empleados superan el salario promedio.\n",
					acumSalario, promedio, empleadosPromedio);
		}
		retorno = 0;
	}
	return retorno;
}

int printEmployees(Empleado *pArray, int limite) {
	int retorno = -1;
	int i;
	if (pArray != NULL && limite > 0) {
		printf("\n______________________________________________________________________________________________");
		printf("\n| ID:      |     Nombre:    |     Apellido:     |        Salario:       |      Sector:       ||| ");
		printf("\n|__________|________________|___________________|_______________________|____________________||");
		for (i = 0; i < limite; i++) {
			if (pArray[i].isEmpty != 1) {
				printf("|          |\n|%d         |   %s          -       %s           -     $%.2f         -       %d  \n",
										pArray[i].id, pArray[i].name, pArray[i].lastName,
										pArray[i].salary, pArray[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}


