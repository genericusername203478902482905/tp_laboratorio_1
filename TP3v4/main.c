#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Employee.h"
#include "utnInputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int resultadoMenu = 0;
    int flag = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    system("cls");
	resultadoMenu = utn_getInt(&option,
		    "Menu:\n"
		     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
		     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
		     "3. Alta de empleado\n"
		     "4. Modificar datos de empleado\n"
		     "5. Baja de empleado\n"
		     "6. Listar empleados\n"
		     "7. Ordenar empleados\n"
		     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
		     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
		     "10. Salir\n",
					"\nError: Seleccione una opcion valida.\n", 1, 10, 5);

	if (resultadoMenu != 0) {
		printf("\nERROR FATAL");
		system("pause");
		break;
	}

	switch (option) {
            case 1:
                if (flag == 1){
                    printf ("\nSolo se puede cargar una vez\n\n");
                }else{
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag = 1;
                }
                break;

         case 2:
                if (flag == 1){
                    printf ("\nSolo se puede cargar una vez\n\n");
                }else{
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    flag = 1;
                }
                break;

            case 3:
                if (flag == 1){
                controller_addEmployee(listaEmpleados);
                }
                break;

            case 4:
                if (flag == 1){
                controller_editEmployee(listaEmpleados);
                }
                break;

            case 5:
                if (flag == 1){
                controller_removeEmployee(listaEmpleados);
                }
                break;

            case 6:
                if (flag == 1){
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                }
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                break;

            case 8:
                controller_saveAsText("data.csv", listaEmpleados);
                break;

            case 9:
                controller_saveAsBinary("bin.dat",listaEmpleados);
                break;
        }

    }while(option != 10);

    return 0;
}
