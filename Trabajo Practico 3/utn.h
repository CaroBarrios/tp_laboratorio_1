/*
 * utn.h
 *
 *  Created on: 8 jun. 2021
 *      Author: carolina
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int esString(char* cadena,int longitud);
int esNumerica(char* cadena, int limite);

#endif /* UTN_H_ */
