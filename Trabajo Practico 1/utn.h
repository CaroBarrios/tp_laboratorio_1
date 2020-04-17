#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** brief Solicita un numero al usuario, lo verfica y lo valida y devuelve un resultado
 * param pResultado Puntero al resultado, alli se dejara el numero ingresado por el usuario
 * param mensaje Puntero al mensaje a mostrar para pedirle el dato al usuario
 * param mensajeError Puntero al mensaje a mostrar al usuario en caso de error
 * param minimo Valor minimo aceptado
 * param maximo Valor maximo aceptado
 * param reintentos Cantidad de reintentos en caso de error
 * return Devuelve el valor -1 en caso de error y 0 en caso de exito
 */
int utn_getNumero (int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* brief Realiza la suma de dos numeros enteros
* param operador1 es el primer numero a sumar
* param operador2 es el segundo numero a sumar
* return Devuelve un valor entero del resultado de la suma
*/
int suma (int operador1, int operador2);

/**
* brief Realiza la resta de dos numeros enteros
* param operador1 es el primer numero a restar
* param operador2 es el segundo numero a restar
* return Devuelve un valor entero del resultado de la resta
*/
int resta (int operador1, int operador2);

/**
* brief Realiza la división de dos numeros enteros
* param operador1 es el dividendo
* param operador2 es el divisor
* param result Puntero al result, alli se dejara el resultado de la division
* return Devuelve el valor -1 si operador2 es distinto a 0 y 0 si operando2 es igual a 0
*/
int division (int operador1, int operador2, float* result);

/**
* brief Realiza la multiplicacion de dos numeros enteros
* param operador1 es el primer factor
* param operador2 es el segundo factor
* return Devuelve el valor del producto de la multiplicacion
*/
int multiplicar (int operador1, int operador2);

/**
* brief Realiza el factorial del primer numero
* param operador1 a ser factoreado
* return Devuelve el valor factorizado del primer numero
*/
int factorialUno (int operador1);

/**
* brief Realiza el factorial del segundo numero
* param operador2 a ser factoreado
* return Devuelve el valor factorizado del segundo numero
*/
int factorialDos (int operador2);

#endif // UTN_H_INCLUDED
