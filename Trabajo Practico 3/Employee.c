#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/**
 *\brief Busca un espacio en la memoria dinamica y devuelve un puntero a empleado en el espacio encontrado.
 * \return Employee* puntero al array empleado
 *
 */
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/**
 *\brief constructor de empleados con parametros, crea un empleado a partir de los parametros que se les pasa
 * \param id char*
 * \param nombre char*
 * \param horasTrabajadas char*
 * \param sueldo char*
 * \return
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee = NULL;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if((employee_setId(newEmployee, idStr) == -1) ||
            (employee_setNombre(newEmployee, nombreStr) == -1) ||
            (employee_setHorasTrabajadas(newEmployee, horasTrabajadasStr) == -1)||
            (employee_setSueldo(newEmployee, sueldo) == -1))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}


/**
 *\brief
 * \param
 * \param nombre char*
 * \return
 *
 */
int employee_setId(Employee* this, char* id)
{
    int answer=-1;

    if(this!=NULL &&
       id !=NULL&&
       (esNumerica(id, 1000)==0)
       {
           this->id = atoi(id); // con atoi convierto el string a numero una vez que lo copio a this
           answer=0;
       }
    return answer;
}


/**
 *\brief
 * \param
 * \param nombre char*
 * \return
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
    int answer=-1;

    if(this!=NULL &&
       nombre!=NULL &&
       (esString(nombre, NAME_LEN))==0)
    {
        strncpy(this->nombre, nombre, NAME_LEN);
        answer=1;
    }
    return answer;
}


/**
 *\brief
 * \param
 * \param nombre char*
 * \return
 *
 */
int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int answer=-1;

    if(this!=NULL &&
       horasTrabajadas !=NULL &&
       (esNumerica(id, 2000)==0)
       {
           this->horasTrabajadas = atoi(horasTrabajadas); // con atoi convierto el string a numero una vez que lo copio a this
           answer=0;
       }
    return answer;
}


/**
 *\brief
 * \param
 * \param nombre char*
 * \return
 *
 */
int employee_setSueldo(Employee* this, char* sueldo)
{
    int answer=-1;

    if(this!=NULL &&
       sueldo !=NULL &&
       (esNumerica(id, 500000)==0)
       {
           this->sueldo = atoi(sueldo); // con atoi convierto el string a numero una vez que lo copio a this
           answer=0;
       }
    return answer;
}


/**
 *\brief
 * \param
 * \return
 *
 */
void employee_delete(Employee* this )
{
    if ( this != NULL)
    {
        free(this);
    }
}
