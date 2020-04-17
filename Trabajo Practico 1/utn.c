#include <stdio.h>
#include <stdlib.h>

int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf ("%s", mensaje);
			fflush (stdin);
			scanf ("%d", &bufferInt);
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf ("%s", mensajeError);
				reintentos--;
			}
        }while (reintentos>=0);
	}
	return retorno;
}
int suma (int operador1, int operador2)
{
    int resultadoSuma;
    resultadoSuma = operador1 + operador2;
    return resultadoSuma;
}

int resta (int operador1, int operador2)
{
    int resultadoResta;
    resultadoResta = operador1 - operador2;
    return resultadoResta;
}

int division (int operador1, int operador2, float* result)
{
	float resultadoDivision;
	int retorno;
	retorno = -1;

	if (operador2 != 0)
    {
		resultadoDivision = (float) operador1 / operador2;
		(* result) = resultadoDivision;
    }
    else
    {
    	retorno = 0;
    }
    return retorno;
}

int multiplicar (int operador1, int operador2)
{
    int resultadoMultiplicacion;
    resultadoMultiplicacion = operador1 * operador2;
    return resultadoMultiplicacion;
}

int factorialUno (int operador1)
{
    int factUno;

    if (operador1==1)
    {
        factUno=1;
    }
    else
    {
        factUno = operador1*factorialUno (operador1-1);
    }

    return factUno;
}

int factorialDos (int operador2)
{
    int factDos;

    if (operador2==1)
    {
        factDos=1;
    }
    else
    {
        factDos = operador2*factorialDos (operador2-1);
    }

    return factDos;
}
