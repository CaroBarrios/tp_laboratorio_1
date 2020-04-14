#include <stdio.h>
#include <stdlib.h>

int suma (int* numero1, int* numero2)
{
    int resultadoSuma;
    resultadoSuma = *numero1 + *numero2;
    return resultadoSuma;
}

int resta (int* numero1, int* numero2)
{
    int resultadoResta;
    resultadoResta = (*numero1) - (*numero2);
    return resultadoResta;
}

int division (int* numero1, int* numero2)
{
	int resultadoDivision;
	int retorno;
	retorno = -1;
	if (* numero2 == 0)
    {
    printf ("\nNo se puede dividir por cero. Vuelva a la opcion 2 y reingrese otro numero.\n");
    retorno = 0;
    }
    else
    {
    resultadoDivision = (*numero1) / (*numero2);
    }
    return retorno;
}

int multiplicar (int* numero1, int* numero2)
{
    int resultadoMultiplicacion;
    resultadoMultiplicacion = (*numero1) * (*numero2);
    return resultadoMultiplicacion;
}

int factorial (int* numero1)
{
    int valor = 1;
    int resultadoFactorial = 0;
    int i;
    for (i=1;i<=valor;i++)
    {
       resultadoFactorial = resultadoFactorial * i;
    }
    return resultadoFactorial;
}
