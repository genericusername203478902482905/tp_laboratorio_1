/*
 utest example : Unit test examples.
 Copyright (C) <2018>  <Mauricio Davila>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/utnInputs.h"
#include "../inc/Controller.h"
#include "../inc/Parser.h"
#include "../inc/eArticulos.h"

int main(void) {
	setbuf(stdout, NULL);
//	eRubro rubros[]={{1, "CUIDADO DE ROPA           "}, {2, "LIMPIEZA Y DESINFECCION   "}, {3, "CUIDADO PERSONAL E HIGIENE"}, {4, "CUIDADO DEL AUTOMOTOR     "}};
	int option = 0;
	int option2;
	int resultadoMenu = 0;
	int flag = 0;
	int flag2 = 0;
	char nomArchivo[99]; // Datos_SP_LABO1.csv
	int contadorID = 0;

	LinkedList *listaArticulos = ll_newLinkedList();

	do {
		system("cls");
		resultadoMenu = utn_getInt(&option, "Menu:\n"
				"1. Cargar los datos desde archivo\n"
				"2. Ordenar la lista de articulos\n"
				"3. Imprimir articulos\n"
				"4. Aplicar descuentos\n"
				"5. Generar archivo de salida\n"
				"6. Informe de articulos\n"
				"7. Salir\n", "\nError: Seleccione una opcion valida.\n", 1, 7,
				5);

		if (resultadoMenu != 0) {
			printf("\nERROR FATAL");
			system("pause");
			break;
		}

		switch (option) {
		case 1:
			if (!utn_getString(nomArchivo,
					"\nEscriba el nombre del archivo a cargar: ",
					"\nERROR: Escriba un nombre valido.(Datos_SP_LABO1.csv)\n",
					4, 100, 5)) {
				flag = 1;
				controller_loadFromText(nomArchivo, listaArticulos,
						&contadorID);
			} else {
				printf("\nError fatal.\n");
				system("pause");
				system("cls");
			}

			break;

		case 2:
			if (flag == 1) {
				if (!controller_sortArticulo(listaArticulos)) {
					printf(
							"\nSorteado articulos por nombre de manera ascendente.\n");
					utn_getInt(&option2,
							"Desea ver la lista ordenada de una vez?\n"
									"1. Si\n"
									"2. No\n",
							"\nError: Seleccione una opcion valida.\n", 1, 2,
							3);
					if (option2 == 1) {
						controller_listArticulo(listaArticulos);
					}
				}

			} else {
				printf("\nError. Carga un archivo si desea ordenar\n");
				system("pause");
			}
			break;

		case 3:
			if (flag == 1) {
				controller_listArticulo(listaArticulos);
			} else {
				printf("\nError. Carga un archivo si desea listar\n");
				system("pause");
			}

			break;

		case 4:
			if (flag == 1) {
				if (flag2 == 0) {
					controller_mapArticulo(listaArticulos);
					flag2 = 1;
				} else {
					printf("Error. Solo puede aplicar el descuento una vez.\n");
					system("pause");
				}
			} else {
				printf(
						"Error. Debe cargar un archivo si desea aplicar descuento.\n");
				system("pause");
			}
			break;

		case 5:
			if (flag == 1) {
				controller_saveAsText("mapeado.csv", listaArticulos);
			} else {
				printf("Error. Debe cargar un archivo para guardar mapeo.\n");
				system("pause");
			}
			break;

		case 6:
			if (flag == 1) {
				utn_getInt(&option2,
						"\nCual informe desea realizar?\n"
								"1. Cantidad de Articulos cuyo precio sea mayor a $100\n"
								"2. Cantidad de Articulos del Rubro 1 – CUIDADO DE ROPA\n"
								"3. Salir\n",
						"\nError: Seleccione una opcion valida.\n", 1, 3, 3);
				switch (option2) {
				case 1:
					controller_contadorArticulos(listaArticulos, option2);
					system("pause");
					break;

				case 2:
					controller_contadorArticulos(listaArticulos, option2);
					system("pause");
					break;

				case 3:
					break;
				}
			}
			break;

		case 7:

			break;
		}

	} while (option != 7);

	return 0;
}

