#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif // UTN_H_INCLUDED
