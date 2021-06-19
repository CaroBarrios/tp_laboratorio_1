#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    setbuf(stdout, NULL);

	int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option=menu();
    	switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("La lista de empleados esta vacia. Debe cargar al menos un empleado primero.\n");
            	}
            	break;
            case 7:
            	break;
            case 8:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            	    printf("Se han guardado satisfactoriamente los empleados.\n");
            	}
            	else
            	{
            		printf("Debe cargar al menos un empleado primero.\n");
            	}
            	break;
            case 9:
            	if(!ll_isEmpty(listaEmpleados))
            	{
            		if(controller_saveAsBinary("data.bin",listaEmpleados))
            		{
            			printf("Se han guardado satisfactoriamente los empleados.\n");
            		}else
            		{
            			printf("Se produjeron errores en el guardado de datos. Por favor intentelo de nuevo.\n");
            		}
            	}
            	else
            	{
            		printf("La lista de empleados esta vacia. Debe cargar al menos un empleado primero.\n");
            	}
            	break;
        }
    	printf("Presione la tecla enter para continuar: ...");
        getchar();/*Aca lee el enter*/
    }while(option!=10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
