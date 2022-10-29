
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUT_H_
#define INPUT_H_
int getInt(int* pResultado);
int esNumerica(char* cadena,int tam);
int myGets(char* cadena,int longitud);
int getFloat(float* pFloat);
int esFlotante(char* array,int limite);
int getString(char* pResultado,int longitud);
int esSoloLetras(char* pResultado,int limite);




int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCadena(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);
int utn_getNumeroCorto(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif
