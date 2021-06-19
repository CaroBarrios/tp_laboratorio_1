#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
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
	int answer=-1;
	int parametros;
	Employee* bufferEmployee;
	char buffer [4][100];

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%s", buffer[0]);
		do
		{
			bufferEmployee = employee_new();
			parametros = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(parametros==4)
			{
				bufferEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
				//printf("\n, %d", bufferEmployee);
				if(bufferEmployee!=NULL)
				{
					ll_add(pArrayListEmployee,bufferEmployee);
					answer=1;
				}
			}
		}while(feof(pFile)==0);
	}

    return answer;
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
	int answer=-1;
    Employee* bufferEmployee;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
    	do
    	{
    		bufferEmployee=employee_new();
    		if(fread(bufferEmployee, sizeof(Employee),1,pFile) != 0)
    		{
    			ll_add(pArrayListEmployee, bufferEmployee);
    			answer = 1;
    		}
    	}while(feof(pFile)==0);
    }
    return answer;
}
