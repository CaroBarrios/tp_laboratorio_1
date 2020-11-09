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
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        if ((utn_getNumero (&option,"\n*****MENU DE EMPLEADOS*****\n\n"
                            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
                            "3. Alta de empleado\n"
                            "4. Modificar datos de empleado\n"
                            "5. Baja de empleado\n"
                            "6. Listar empleados\n"
                            "7. Ordenar empleados\n"
                            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
                            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
                            "10. Salir\n\n\n"
                            "Ingrese una opcion: ",
                            "No es una opcion valida. Intente nuevamente.\n\n", 1, 10, 3))==0)
        {
            switch(option)
            {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                system("pause");
                break;
            }
        }
    }
    while(option != 10);
    return 0;
}
