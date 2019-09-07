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
    if (* numero2 == 0)
    {
    printf ("\nNo se puede dividir por cero. Vuelva a la opcion 2 y reingrese otro numero.\n");
    }
    else
    {
    int resultadoDivision;
    resultadoDivision = (*numero1) / (*numero2);
    return resultadoDivision;
    }
    return 1;
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
