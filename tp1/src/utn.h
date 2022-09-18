/*
 * utn_purpura.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Cris
 */




#ifndef UTN_PURPURA_H_
#define UTN_PURPURA_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);


int myGets(char* cadena, int longitud);

int getInt(int* pResultado);

int esNumerica(char* cadena);


#endif /* UTN_PURPURA_H_ */
