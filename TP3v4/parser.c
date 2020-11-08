#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
	int i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                Employee* p = employee_newParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while(!feof(pFile));
    }
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = 0;
    Employee* pBinario;

        do{
                pBinario = employee_new();
                if(fread(pBinario,sizeof(Employee),1, pFile)==1)
                {
                    ll_add(pArrayListEmployee,pBinario);
                }
                   else
                   {
                       employee_delete(pBinario);
                   }


            }while( !feof(pFile));

    return ret;
}
