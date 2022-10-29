/*
 * confederaciones.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Cris
 */

#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "utn.h"
#include "confederaciones.h"

#define CONF 6


/// @fn void MostrarConfederaciones(eConfederaciones[], int)
/// @brief muestra el listado de confederaciones activas
///
/// @param lista lista de confederaciones
/// @param size tamaño de la lista de confederaciones
void MostrarConfederaciones(eConfederaciones lista[],int size)


{
	printf("  ========================================================================================\n");
	printf(" | ID   |        NOMBRE       |            REGION                  |     A%cIO DE CREACION |  \n  ",165);
	printf("----------------------------------------------------------------------------------------\n");
	for(int i=0;i<size;i++)
	{
		printf(" |  %-4d|      %-15s| %-35s|%15d       |\n",lista[i].id,lista[i].nombre,lista[i].region,lista[i].aniosCreacion);
	}
	printf("  ========================================================================================\n");
}

/// @fn void AltaConfederaciones(eConfederaciones[], int, int)
/// @brief busca espacio en la lista si lo encuentra da de alta una nueva confederacion con todos sus campos
///
/// @param lista lista de confederaciones
/// @param size tamaño de la lista de confederaciones
/// @param id is interno autoicremental
void AltaConfederaciones(eConfederaciones lista[],int size,int id)
{
	for(int i=0;i<size;i++)
	{
		if(lista[i].isEmply==0)
		{
			lista[i].id=id;
			lista[i].isEmply=1;
			utn_getCadena(lista[i].nombre, 50, "\nIngrese el nombre de la confederacion :", "ERROR intente nuevamente\n", 10);
			utn_getCadena(lista[i].region, 50, "\nIngrese el nombre de la region :", "ERROR intente nuevamente\n", 10);
			utn_getNumero(&lista[i].aniosCreacion, "\nIngresar el anio de creacion de la confederacion :", "Error intente nuevamente", 1900, 2022, 10);

		}
	}

}

/// @fn void BajaConfederaciones(eConfederaciones[], int)
/// @brief  muestra la lista de confederaciones y pide el id de la confederacion para dar de baja
///
/// @param lista lista de confederaciones
/// @param size tamaño de la lista de confederaciones
void BajaConfederaciones(eConfederaciones lista[],int size)
{
	int id;
	int control;
	MostrarConfederaciones(lista,size);
	utn_getNumero(&id, "Seleccione el ID de la confederacion que eliminar :", "\nERROR ID invalido\n", 1, size, 10);


	for(int i=0;i<size;i++)
	{
		if(lista[i].id==id && lista[i].isEmply==1)
		{
			lista[i].isEmply =-1;
			control=1;
			break;
		}
		else
		{
			control= -1;
		}
	}
	if(control==-1)
	{
		printf("ERROR Id No encontrado Intente nuevamente.\n");
	}



}

/// @fn void Modificarfederaciones(eConfederaciones[], int)
/// @brief miestra lista de confederaciones pide el id a modificar
/// 		despliega un menu de opciones para elegir cual desea modificar
///
/// @param lista lista de confederaciones
/// @param size tamaño de la lista de confederaciones
void Modificarfederaciones(eConfederaciones lista[],int size)
{

	int indice;
	int control;
	int id;
	int opcion;


	do
	{
		MostrarConfederaciones(lista, size);
		utn_getNumero(&id,"Seleccione el ID de confederacion que desea modificar :", "\nERROR ID invalido\n", 1, size, 10);


		for(int i=0;i<size;i++)
		{
			if(lista[i].id==id && lista[i].isEmply==1)
			{
				indice=i;
				control=1;
				break;
			}
			else
			{
				control= -1;
			}
		}
		if(control==-1)
		{
			printf("ERROR Id No encontrado Intente nuevamente.\n");
		}




	}while(control!=1);


	do
	{

		utn_getNumero(&opcion, "\nSELECCIONE LA OPCION DESEADA.\n\n1- Nombre de la confederacion.\n2- Region de la confederacion.\n3- Anio de creacion de la confederacion.\n4- Salir.\n- Elija una opcion :\n", "ERROR Opcion invalida 1-4\n", 1, 4, 10);

		switch(opcion)
		{
		case 1:
			utn_getCadena(lista[indice].nombre, 50, "\nIngrese el nombre de la confederacion :", "ERROR intente nuevamente\n", 10);

			break;
		case 2:
			utn_getCadena(lista[indice].region, 50, "\nIngrese el nombre de la region :", "ERROR intente nuevamente\n", 10);

			break;
		case 3:
			utn_getNumero(&lista[indice].aniosCreacion, "\nIngresar el anio de creacion de la confederacion :", "Error intente nuevamente", 1900, 2022, 10);

			break;
		}



	}while(opcion!=4);
}
