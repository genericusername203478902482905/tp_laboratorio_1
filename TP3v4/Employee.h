#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_





typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4);

int employee_delete(Employee*  this);

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

void employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

void employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

int employee_compareById(void* pEmpleado1,void* pEmpleado2);
int employee_compareByName(void* pEmpleado1,void* pEmpleado2);
int employee_compareByWorkedTime(void* pEmpleado1,void* pEmpleado2);
int employee_compareBySalary(void* pEmpleado1,void* pEmpleado2);


#endif /* EMPLOYEE_H_ */
