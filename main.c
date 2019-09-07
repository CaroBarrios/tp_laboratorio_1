/*******************************************************
* Programa: Trabajo Práctico N°1 - Calculadora
*
* Objetivo: Crear una calculadora con menú que permita
*           ingresar dos números y con ellos realizar
*           las funciones de suma, resta, multiplicación,
*           división y factorial.
*
* Versión: 1.0.0 del 06 de Septiembre de 2019
*
* Autor: Carolina Antonela Barrios
*
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int main()
{
    int opcion = 0;
    int salida = 1;
    int numero1 = 0;
    int numero2 = 0;
    int resultadoSuma = 0;
    int resultadoResta = 0;
    int resultadoDivision = 0;
    int resultadoMultiplicacion = 0;
    int resultadoFactorial = 0;

    while (salida)
    {
        printf ("*****MENU DE OPCIONES*****\n");
        printf ("1. Ingrese el primer numero:\n");
        printf ("2. Ingrese el segundo numero:\n");
        printf ("3. Calcular todas las operaciones:\n");
        printf ("4. Informar los resultados:\n");
        printf ("5. Salir:\n");
        printf ("Elija una opcion:\n");
        scanf ("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d",&numero1);
                break;
            case 2:
                printf("Ingrese un numero: ");
                scanf("%d",&numero2);
                break;
            case 3:
                printf ("Se calcularan las siguientes operaciones:\n");
                printf ("a) La suma de %d con el %d:\n", numero1, numero2);
                resultadoSuma = suma(&numero1, &numero2);
                printf ("b) La resta de %d con %d\n", numero1, numero2);
                resultadoResta = resta (&numero1, &numero2);
                printf ("c) La division de %d con %d:\n", numero1, numero2);
                resultadoDivision = division (&numero1, &numero2);
                printf ("\nd) La multiplicacion de %d con %d:\n", numero1, numero2);
                resultadoMultiplicacion = multiplicar (&numero1, &numero2);
                printf ("e) El factorial de %d y el factorial de %d\n", numero1, numero2);
                resultadoFactorial = factorial (&numero1);
                break;
            case 4:
                printf ("El resultado de %d + %d es: %d\n", numero1, numero2, resultadoSuma);
                printf ("El resultado de %d - %d es: %d\n", numero1, numero2, resultadoResta);
                printf ("El resultado de %d / %d es: %d\n", numero1, numero2, resultadoDivision);
                printf ("El resultado de %d * %d es: %d\n", numero1, numero2, resultadoMultiplicacion);
                printf ("El factorial de %d es: %d y el factorial de %d es:\n", numero1, resultadoFactorial, numero2);
                break;
            case 5:
                salida = 0;
                break;
            default:
                printf ("El valor ingresado es invalido\n");
                break;
        }
    }
}
