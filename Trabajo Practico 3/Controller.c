#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "utn.h"
#include "parser.h"
#include <ctype.h>
#include<string.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int answer = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
            {
                answer = 1;
                printf("Se cargaron los empleados correctamente.\n");
            }
            else
            {
                printf("No se pudieron cargar los empleados.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
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
    return 1;
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
    int id;
    char nombre[NAME_LEN];
    int horasTrabajadas;
    int sueldo;

    int newNombre;
    int newHorasTrabajadas;
    int newSueldo;

    char horasTrabajadasStr[20];
    char sueldoStr[20];
    char idStr[20];

    int empAddedOk = -1;
    Employee* auxEmployee;
    system("cls");
    printf("**** Alta de nuevo empleado **** \n\n");

    if (pArrayListEmployee != NULL)
    {
        newNombre = utn_getNombre(nombre,NAME_LEN,"Ingrese nuevo nombre: ",
                                  "El nombre solo puede contener letras y debe tener una longitud menor a 128.\n",  3);
        newHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese la nueva cantidad de horas trabajadas: ",
                                           "La cantidad de horas debe ser un numero del 1 al 2000.\n", 1, 2000, 3);
        newSueldo = utn_getNumero(&sueldo, "Ingrese el nuevo sueldo: ", "El sueldo debe ser un numero entre 1 y 500000.\n", 1, 500000, 3);

        if(newNombre && newHorasTrabajadas && newSueldo  )
        {
            getIdFromArchive(&id);
            strlwr(nombre);
            nombre[0]= toupper(nombre[0]);
            itoa(horasTrabajadas, horasTrabajadasStr, 10);
            itoa(sueldo, sueldoStr, 10);
            itoa(id, idStr, 10);
            auxEmployee = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
            if (auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                printf("Se ha agregado satisfactoriamente el empleado.\n");
                updateId(id);
                empAddedOk = 1;
            }
        }
        else
        {
            printf("Se produjeron errores durante la carga del empleado. Por favor intentelo de nuevo\n");
        }
    }
    system("pause");
    return empAddedOk;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

