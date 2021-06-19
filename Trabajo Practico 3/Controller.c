#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "Controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int answer=-1;
	FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
			{
				answer = 1;
				printf("Se cargaron correctamente los empleados\n");
			}
			else
			{
				printf("No se pudieron cargar los datos\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("El archivo no pudo abrirse\n");
		}
	}
    return answer;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int answer=-1;
	FILE* pFile;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile=fopen(path,"rb");
	    if(pFile!=NULL)
	    {
	    	if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1)
	    	{
	    		answer=1;
	    		printf("Empleados cargados correctamnente. \n");
	    	}
	    	else
	    	{
	    		printf("No se pudieron cargar los empleados.\n");
	    	}
	    }
	    else
	    {
	    	printf("\nEl archivo no pudo abrirse.\n");
	    }
	    fclose(pFile);
	}
	return answer;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int answer = -1;
	int id;
	char nombre[NOMBRE_LEN];
	int horasTrabajadas;
	int sueldo;
	int nuevoNombre;
	int nuevoHorasTrabajadas;
	int nuevoSueldo;
	char horasTrabajadasStr[20];
	char sueldoStr[20];
	char idStr[20];
	Employee* bufferEmployeeloyee;

	if (pArrayListEmployee != NULL)
	{
		nuevoNombre = utn_getString(nombre,NOMBRE_LEN,"Ingrese nombre: ",
	                                  	  	  	  	 "El nombre solo puede contener letras y debe tener una longitud menor a 128.\n", 2);
	    nuevoHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ",
	                                           	   	   	   	   "La cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 2);
	    nuevoSueldo = utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: ",
	    									 "El sueldo debe ser un numero entre 1 y 500000.\n", 1, 500000, 2);

	    if(nuevoNombre == 0 && nuevoHorasTrabajadas == 0 && nuevoSueldo == 0)
	    {
	    	getIdFromArchive(&id);
	        strlwr(nombre);
	        nombre[0]= toupper(nombre[0]);
	        itoa(horasTrabajadas, horasTrabajadasStr, 10);
	        itoa(sueldo, sueldoStr, 10);
	        itoa(id, idStr, 10);
	        bufferEmployeeloyee = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
	        if(bufferEmployeeloyee!=NULL)
	        {
	        	ll_add(pArrayListEmployee, bufferEmployeeloyee);
	            printf("Se ha agregado satisfactoriamente el empleado.\n");
	            updateId(id);
	            answer = 1;
	        }
	    }
	    else
	    {
	    	printf("Se produjeron errores durante la carga del empleado. Por favor intentelo de nuevo\n");
	    }
	}
	system("pause");
	return answer;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int answer = -1;
	int index;
	int id;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		if(utn_getNumero(&id,"Ingrese el id del empleado que desea modificar: ",
							 "\nError, por favor ingrese un id valido.\n",0,20000,2)==0)
		{
			index = findEmployeeById(pArrayListEmployee, id);

	        if(index == -1)
	        {
	        	printf("Se produjo un error durante la modificacion. Por favor, vuelva a intentarlo.\n");
	        }
	        else
	        {
	        	printf("El empleado a modificar es el siguiente:\n");
	        	printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");

	        	employee_Print((Employee*) ll_get(pArrayListEmployee, index));

	        	modifyEmployee((Employee*) ll_get(pArrayListEmployee,index));

	        	printf("\nEmpleado modificado exitosamente.\n\n");
	        	answer = 1;
	        }
		}
	}
	else
	{
		printf("No se ha ingresado un Id correspondiente a un empleado activo. Por favor intentelo de nuevo.\n");
	}
	return answer;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int answer = -1;
	int index;
	int id;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		if(utn_getNumero(&id,"Ingrese el id del empleado que desea eliminar: ",
							 "\nError, por favor ingrese un id valido.\n",0,20000,2)==0)
		{
			index = findEmployeeById(pArrayListEmployee, id);

	        if(index == -1)
	        {
	        	printf("Se produjo un error durante la baja. Por favor, vuelva a intentarlo.\n");
	        }
	        else
	        {
	        	printf("El empleado a eliminar es el siguiente:\n");
	        	printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");

	        	employee_Print((Employee*) ll_get(pArrayListEmployee, index));

	        	ll_remove(pArrayListEmployee, index);
	        	printf("\nEmpleado dado de baja exitosamente.\n\n");
	        	answer = 1;
	        }
		}
	}
	else
	{
		printf("No se ha ingresado un Id correspondiente a un empleado activo. Por favor intentelo de nuevo.\n");
	}
	return answer;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int answer=-1;
	int len = ll_len(pArrayListEmployee);
	Employee* bufferEmployee;

	if(pArrayListEmployee!=NULL)
	{
	    printf("\n  Id                Nombre  Horas Trabajadas          Sueldo \n");
	    printf("------------------------------------------------------------------------\n");
	    for(int i=0; i<len; i++)
	    {
	    	bufferEmployee = (Employee*) ll_get(pArrayListEmployee, i);
	        if(bufferEmployee!=NULL)
	        {
	        	employee_Print(bufferEmployee);
	        	answer = 1;
	        }
	    }
	}
	return answer;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int answer=-1;
	int ordenamiento;

	if(pArrayListEmployee != NULL)
	{
		if(utn_getNumero(&ordenamiento, "Ingrese el orden en el que desea ordenar los empleados.\n0. Ascendente\n1. Descendete\n",
										"Error. Ingrese 0 o 1.", 0, 1, 2) == 0)
	    {
			ll_sort(pArrayListEmployee, compareEmployeesByName, ordenamiento);
			answer=1;
	    }
		else
		{
			printf("No se ingreso un ordenamiento valido. Por favor intentelo nuevamente.");
		}
	}
	return answer;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int answer=-1;
	int len= ll_len(pArrayListEmployee);
	Employee* bufferEmployee;
	FILE* f = fopen(path,"w") ;

	if(f!=NULL)
	{
		fprintf(f,"  Id     Nombre           Horas Trabajadas          Sueldo \n");
	    for (int i =0; i<len; i++)
	    {
	    	bufferEmployee = (Employee*) ll_get(pArrayListEmployee, i);
	        if(bufferEmployee!=NULL)
	        {
	        	fprintf(f, "%d,%s,%d,%d\n", bufferEmployee->id, bufferEmployee->nombre, bufferEmployee->horasTrabajadas, bufferEmployee->sueldo);
	            answer = 1;
	        }
	    }
	    fclose(f);
	}
	return answer;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int answer = -1;
	int len =  ll_len(pArrayListEmployee);
	Employee* bufferEmployee;
	FILE* f = fopen(path,"wb");

	if(f!=NULL)
	{
		for(int i=0; i<len; i++)
	    {
			bufferEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(bufferEmployee!=NULL)
			{
				fwrite(bufferEmployee, sizeof(Employee), 1, f);
				answer = 1;
			}
	    }
		fclose(f);
	}
	return answer;
}

/*\brief Lee ultimo ID dado de alta
 *
 * \param int* id
 * \return int
 */
int getIdFromArchive(int* id)
{
	int answer = -1;
	*id = 1001;
    FILE* f;

    f = fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        answer = 1;
    }
    return answer;
}

/*\brief Guarda proximo ID
 *
 * \param int id
 * \return int
 */
int updateId(int id)
{
	int answer=-1;
	int proxId=id;
    proxId++;
    FILE* f;

    f = fopen("proximoid.bin","wb");

    if(f != NULL)
    {
        fwrite(&proxId,sizeof(int),1,f);
        fclose(f);
        answer = 1;
    }
    return answer;
}
