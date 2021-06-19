#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/**
* \brief menu
* \return Returns the opcion of the menu and -1 in case of error
*
*/
int menu()
{
    int respuesta = -1;
    int opcion;

    if ((utn_getNumero(&opcion,"\n***********MENU***********\n\n"
                                "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    							"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    							"3. Alta de empleado\n"
    							"4. Modificar datos de empleado\n"
    							"5. Baja de empleado\n"
    							"6. Listar empleados\n"
    							"7. Ordenar empleados\n"
    							"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    							"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                                "10. Salir\n\n\n"
                                "Ingrese una opcion: ",
                                "No es una opcion valida. Ingrese una opcion entre 1 y 10. Intentelo de nuevo.\n\n", 1, 10, 2))==0)
    {
        respuesta = opcion;
    }
    return respuesta;
}

/*
 *
 */
Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

/*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = NULL;

	newEmployee = employee_new();

	if(newEmployee!=NULL)
	{
		if((employee_setId(newEmployee, atoi(idStr)) == -1) ||
	       (employee_setNombre(newEmployee, nombreStr) == -1) ||
	       (employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) == -1)||
	       (employee_setSueldo(newEmployee, atoi(sueldoStr)) == -1))
	    {
			employee_delete(newEmployee);
	        newEmployee = NULL;
	    }
	}
	return newEmployee;
}


/*
 *
 *
 */
int employee_setId(Employee* this,int id)
{
	int answer=-1;

	if(this!=NULL && id>=0)
	{
		answer = 0;
		this->id = id;
	}
	return answer;
}

/*
 *
 *
 */
int employee_getId(Employee* this,int* id)
{
    int answer = -1;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        answer = 0;
    }
    return answer;
}

/*
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int answer = -1;

	if(this!=NULL && nombre!=NULL)
	{
		if(esString(nombre, NOMBRE_LEN))
		{
			strncpy(this->nombre, nombre, NOMBRE_LEN);
			answer = 0;

		}
	}
	return answer;
}

/*
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int answer = -1;

	if(this!=NULL && horasTrabajadas>=0)
	{
		answer = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return answer;
}

/*
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int answer = -1;

	if(this!=NULL && sueldo>=0)
	{
		answer = 0;
		this->sueldo = sueldo;
	}
	return answer;
}

/**
 *\brief
 * \param
 * \return
 *
 */
void employee_delete(Employee* this)
{
    if (this!=NULL)
    {
        free(this);
    }
}

/*
 *
 */
int employee_Print(Employee* this)
{
	int answer =-1;

	if(this!=NULL)
	{
		answer = 1;
		printf("%4d  %20s  %4d                     %5d \n", this->id, this->nombre, this-> horasTrabajadas, this->sueldo);
	}
	return answer;
}

/*
 *
 */
int findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	int answer = -1;
	int len = ll_len(pArrayListEmployee);
	int index;
	Employee* bufferEmployee;

	if(pArrayListEmployee!= NULL && id>=0)
	{
		for(index=0;index<len;index++)
		{
			bufferEmployee = (Employee*) ll_get(pArrayListEmployee, index);

			employee_getId(bufferEmployee, &id);

			answer = index;
		}
	}
	return answer;
}
