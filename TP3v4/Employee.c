#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* persona = malloc(sizeof(Employee));
    return persona;
}

int employee_delete(Employee* this){
    int retorno = -1;
    if(this!=NULL)
    {
    free(this);
    retorno=0;
    }
    return retorno;
}
Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4)
{
    int idAux;
	int sueldoAux;
	int horasAux;
    Employee* p = employee_new();
    idAux = atoi(var1);
    horasAux = atoi(var3);
    sueldoAux = atoi(var4);
    employee_setId(p, idAux);
    employee_setNombre(p, var2);
    employee_setSueldo(p, sueldoAux);
    employee_setHorasTrabajadas(p, horasAux);
    return p;
}

/********FUNCIONES SET***********/

void employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
}

void employee_setNombre(Employee* this, char* nombre)
{
    if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

void employee_setSueldo(Employee* this, int sueldo)
{
    if(sueldo > 0)
        this->sueldo = sueldo;
}

void employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    if(horasTrabajadas > 0)
        this->horasTrabajadas = horasTrabajadas;
}

/*********FUNCIONES GET**********/

int employee_getId(Employee* this)
{
    return this->id;
}

char* employee_getNombre(Employee* this)
{
    return this->nombre;
}

int employee_getSueldo(Employee* this)
{
    return this->sueldo;
}

int employee_getHorasTrabajadas(Employee* this)
{
    return this->horasTrabajadas;
}



