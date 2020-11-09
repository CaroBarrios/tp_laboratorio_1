#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/**
 *\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int answer = -1;
    int cantidadParametros;
    Employee* auxEmployee;
    char buffer[4][100];

    if (pFile != NULL  && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            cantidadParametros = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantidadParametros == 4)
            {
                auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(pArrayListEmployee, auxEmployee);
                answer = 1;
            }
            else
            {
                break;
            }
        }
    }
    return answer;
}

/**
 *\brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
