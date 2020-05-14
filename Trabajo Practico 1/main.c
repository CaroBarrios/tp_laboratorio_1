#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	int respuesta;
	int opcion;
	int numero1;
	int numero2;
	int retornoSuma;
	int retornoResta;
	float resultadoDivision;
	int retornoDivision;
	int retornoMultiplicacion;
	int retornoFactorialUno;
	int retornoFactorialDos;
	int flag1=0;

	do
	{
		respuesta = utn_getNumero (&opcion,"\n*****MENU DE OPCIONES*****\n\n1. Ingrese el primer numero\n2. Ingrese el segundo numero\n3. Calcular todas las operaciones\n4. Informar los resultados:\n5. Salir\n\nIngrese una opcion: ", "No es una opcion valida. Vuelva a intentarlo.\n\n", 1, 5, 4);
		if (respuesta==0)
		{
			switch (opcion)
			{
			case 1:
			    if (flag1 ==0)
                {
                printf("\nIngrese un numero: ");
                fflush (stdin);
                scanf("%d",&numero1);
                system ("cls");
                }
                else
                {
                    flag1==1;
                }
				break;
			case 2:
				printf("\nIngrese un numero: ");
				fflush(stdin);
				scanf("%d",&numero2);
				system ("cls");
				break;
			case 3:
				if (flag1 == 0)
                {
                    printf ("Vuelva a la opcion 1, falta ingresar el primer numero");
                }
                else
                {
                printf ("\n\nSe calcularan las siguientes operaciones:\n\n");
				printf ("a) La suma de %d con el %d\n", numero1, numero2);
				retornoSuma = suma(numero1, numero2);
				printf ("b) La resta de %d con %d\n", numero1, numero2);
				retornoResta = resta (numero1, numero2);
				printf ("c) La division de %d con %d\n", numero1, numero2);
				retornoDivision = division (numero1, numero2, &resultadoDivision);
				printf ("d) La multiplicacion de %d con %d\n", numero1, numero2);
				retornoMultiplicacion = multiplicar (numero1, numero2);
				printf ("e) El factorial de %d y el factorial de %d\n\n", numero1, numero2);
				retornoFactorialUno = factorialUno (numero1);
				retornoFactorialDos = factorialDos (numero2);
				system ("pause");
				system ("cls");
                }
				break;
			case 4:
				printf ("\nEl resultado de %d + %d es: %d\n", numero1, numero2, retornoSuma);
				printf ("El resultado de %d - %d es: %d\n", numero1, numero2, retornoResta);
				if (retornoDivision==0)
						{
							printf ("\nNo se puede dividir por cero. Vuelva a la opcion 2 y reingrese otro numero.\n");
						}
						else
						{
							printf ("El resultado de %d / %d es: %.2f\n", numero1, numero2, resultadoDivision);
						}
				printf ("El resultado de %d * %d es: %d\n", numero1, numero2, retornoMultiplicacion);
				printf ("El factorial de %d es: %d y el factorial de %d es: %d\n\n", numero1, retornoFactorialUno, numero2, retornoFactorialDos);
				system ("pause");
				system ("cls");
				break;
			}
		}
	}while (opcion!=5);

	return EXIT_SUCCESS;
}
