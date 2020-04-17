#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int suma (int operador1, int operador2);
int resta (int operador1, int operador2);
int division (int operador1, int operador2, float* result);
int multiplicar (int operador1, int operador2);
int factorialUno (int operador1);
int factorialDos (int operador2);

#endif // UTN_H_INCLUDED
