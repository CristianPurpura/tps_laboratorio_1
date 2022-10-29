/*
 * jugadores.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Cris
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "confederaciones.h"

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmply;

}eJugador;

void InicializarJugadores(eJugador jugadores[], int size);

void MostrarJugadores(eJugador jugadores[],int size);

void AltaJugador(eJugador jugadores[],eConfederaciones lista[],int size,int id,int sizeConf);

void ElegirPosicion(eJugador jugadores[],int indice);

void ModificarJugador(eJugador jugadores[],eConfederaciones lista[],int size,int sizeConf);

void BajaJugador(eJugador jugadores[],int size);

void MotrarJugadoresCompleto(eJugador jugadores[],eConfederaciones lista[],int sizeJug , int sizeConfe);


#endif /* JUGADORES_H_ */
