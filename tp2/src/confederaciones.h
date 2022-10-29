/*
 * confederaciones.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Cris
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int aniosCreacion;
	int isEmply;

}eConfederaciones;

void MostrarConfederaciones(eConfederaciones lista[],int size);

void AltaConfederaciones(eConfederaciones lista[],int size,int id);

void Modificarfederaciones(eConfederaciones lista[],int size);







#endif /* CONFEDERACIONES_H_ */
