/*
 * jugadores.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Cris
 */
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "utn.h"
#include "confederaciones.h"

/// @fn void InicializarJugadores(eJugador[], int)
/// @brief inicialista la lista de jugadores el estado en 0
///
/// @param jugadores lista de jugadores
/// @param size tamaño de la lista
void InicializarJugadores(eJugador jugadores[], int size)
{
	for(int i =10  ; i<size ; i++ ) //   i esta apartir de 10 para mantener los datos harcodeados
	{
		jugadores[i].isEmply=0;
	}
}

/// @fn void MostrarJugadores(eJugador[], int)
/// @brief muesta un listado de jugadores activos
///
/// @param jugadores lista de jugadores
/// @param size tamaño de la lista
void MostrarJugadores(eJugador jugadores[],int size)
{

	printf("   +======================================================================================================================================+\n");
	printf("   | ID   |        NOMBRE            |    POSICION      |    N° CAM.   |    SUELDO    |       CONFEDERACION       |    A%cIOS DE CONTRATO  |  \n  ",165);
	printf(" +--------------------------------------------------------------------------------------------------------------------------------------+\n");
	for(int i=0;i<size;i++)
	{
		if(jugadores[i].isEmply==1)
		printf("   |  %-4d|%-26s|    %-14s|     %-9d|%14.2f|            %-15d|          %-13d|\n",jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,jugadores[i].idConfederacion,jugadores[i].aniosContrato);
	}
	printf("   +======================================================================================================================================+\n");
}

/*int SeleccionConfederacion(eJugador jugadores[], eConfederaciones lista[], int indice)
{
	char aux[50];
	int control=0;
	MostrarConfederaciones(lista);
	utn_getCadena(aux, 50,"Seleccionar la confederacion :", "ERROR CONF no valida", 10);
	for(int i=0 ;aux[i]!='\0';i++)
	{
		aux[i]=toupper(aux[i]);
	}
	for(int i=0;i<6;i++)
	{
		if(strcmp(lista[i].nombre,aux)==0)
		{
			control =1;
			strcpy(jugadores[indice].,aux);
			break;
		}
	}
	if(control==0)
	{
		printf("ERROR\n");

		return control;
	}

	return control;
}*/

/// @fn void ElegirPosicion(eJugador[], int)
/// @brief  despliega un menu de opciones sobre la posicion del jugador
///
/// @param jugadores listado de jugadores
/// @param indice indice de la lista de jugadores
void ElegirPosicion(eJugador jugadores[],int indice)
{
	int opcion;
	printf("Seleccione una Opcion :\n");
	printf("1- Arquero.\n2- Defensor .\n3- Mediocampista. \n4- Delantero.\n");
	utn_getNumero(&opcion, "Seleccionar opcion :", "ERROR opciones 1-4", 1, 4, 10);

	switch(opcion)
	{
	case 1:
		strcpy(jugadores[indice].posicion,"Arquero");
		break;
	case 2:
		strcpy(jugadores[indice].posicion,"Defensor");
		break;
	case 3:
		strcpy(jugadores[indice].posicion,"Mediocampista");
		break;
	case 4:
		strcpy(jugadores[indice].posicion,"Delantero");
		break;


	}

}

/// @fn void AltaJugador(eJugador[], eConfederaciones[], int, int, int)
/// @brief  recibe el id autoincremental para asignarlo al id intgerno de la lista y carga los datos de la lista de jugadores completos
///
/// @param jugadores lista de jugadores
/// @param lista lista de confederaciones
/// @param size tamaño de la lista de jugadores
/// @param id id interno de cada jugador
/// @param sizeConf tamaño lista confederaciones
void AltaJugador(eJugador jugadores[],eConfederaciones lista[],int size,int id,int sizeConf)
{

	//int control;
	int tamanioCadena;

	for(int i = 0 ; i<size ; i++)
	{
		if(jugadores[i].isEmply==0)
		{
			jugadores[i].id= id;

			jugadores[i].isEmply=1;

			utn_getCadena(jugadores[i].nombre, 50, "Ingrese el nombre del jugador :", "ERROR intente nuevamente\n", 10);
			tamanioCadena=strlen(jugadores[i].nombre);
			jugadores[i].nombre[0]= jugadores[i].nombre[0]-32;
			for(int j =0;j<tamanioCadena;j++)
			{

			if(jugadores[i].nombre[j]==' ')
			{
			//	printf("entro\n");
				jugadores[i].nombre[j+1]= jugadores[i].nombre[j+1]-32;
			}
			}

			MostrarConfederaciones(lista,sizeConf);
			utn_getNumero(&jugadores[i].idConfederacion, "Ingrese el id de la confederacion:  ", "ERROR ID invalido 100-105", 100, 105, 10);

			utn_getNumeroCorto(&jugadores[i].numeroCamiseta, "Ingrese el numero de camiseta :", "ERROR entre 1-100\n", 1, 100, 10);

			ElegirPosicion(jugadores, i);

			utn_getNumeroFloat(&jugadores[i].salario, "Ingrese el salario del jugador :", "Error intente nuevamente no menor a 0\n", 1, 10000000, 10);

			utn_getNumeroCorto(&jugadores[i].aniosContrato, "Ingrese los años de contrato del jugador :", "ERROR entre 1-100\n", 1, 100, 10);

			break;
		}
	}

}

/// @fn void ModificarJugador(eJugador[], eConfederaciones[], int, int)
/// @brief  imprime la lista de jugadores para dar opcion a seleccionar el id que se desa modificar, despliega menu para elegir que desea modificar del jugador
/// 		modifica la oipcion elegida lo modifica y lo muestra al salir
///
/// @param jugadores lista de jugadores
/// @param lista lista de confederacons
/// @param size tamaño lista de jugadores
/// @param sizeConf tamaño lista de confederaciones
void ModificarJugador(eJugador jugadores[],eConfederaciones lista[],int size,int sizeConf)
{
	int id;
	int opcion;
	int control=0;
	int indice;
	int tamanioCadena;

	do
	{
		MostrarJugadores(jugadores, size);
		utn_getNumero(&id,"Seleccione el ID del jugador que desea modificar :", "\nERROR ID invalido\n", 1, size, 10);


		for(int i=0;i<size;i++)
		{
			if(jugadores[i].id==id && jugadores[i].isEmply==1)
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
		utn_getNumero(&opcion, "SELECCIONE UNA OPCION.\n\n1- Nombre. \n2- Confederacion. \n3- Numero de camiseta. \n4- Posicion. \n5- Salario. \n6- Anios de contrato. \n7- SALIR. \n\n- SELECCIONE UNA OPCION :", "\nERROR opciones 1-7\n", 1, 7, 10);

		switch(opcion)
		{
		case 1:
			utn_getCadena(jugadores[indice].nombre, 50, "Ingrese el nombre del jugador :", "ERROR intente nuevamente\n", 10);
			tamanioCadena=strlen(jugadores[indice].nombre);
						jugadores[indice].nombre[0]= jugadores[indice].nombre[0]-32;
						for(int j =0;j<tamanioCadena;j++)
						{

						if(jugadores[indice].nombre[j]==' ')
						{
						//	printf("entro\n");
							jugadores[indice].nombre[j+1]= jugadores[indice].nombre[j+1]-32;
						}
						}
			break;
		case 2:
			MostrarConfederaciones(lista,sizeConf);
			utn_getNumero(&jugadores[indice].idConfederacion, "Ingrese el id de la confederacion:  ", "ERROR ID invalido 100-105", 100, 105, 10);
			break;
		case 3:
			utn_getNumeroCorto(&jugadores[indice].numeroCamiseta, "Ingrese el numero de camiseta :", "ERROR entre 1-100\n", 1, 100, 10);
			break;
		case 4:
			ElegirPosicion(jugadores, (indice));
			break;
		case 5:
			utn_getNumeroFloat(&jugadores[indice].salario, "Ingrese el salario del jugador :", "Error intente nuevamente no menor a 0\n", 1, 10000000, 10);
			break;
		case 6:
			utn_getNumeroCorto(&jugadores[indice].aniosContrato, "Ingrese los años de contrato del jugador :", "ERROR entre 1-100\n", 1, 100, 10);
			break;


		}

	}while(opcion!=7);

	printf("                                                         JUGADOR MODIFICADO\n\n");
	printf("  =================================================================================================================================\n");
	printf(" | ID   |        NOMBRE       |    POSICION      |    N° CAM.   |    SUELDO    |       CONFEDERACION       |    A%cIOS DE CONTRATO  |  \n  ",165);
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" |  %-4d|      %-15s|   %-15s|     %-9d| %.2f   |          %-15d  |         %-10d    |\n",jugadores[indice].id,jugadores[indice].nombre,jugadores[indice].posicion,jugadores[indice].numeroCamiseta,jugadores[indice].salario,jugadores[indice].idConfederacion,jugadores[indice].aniosContrato);
	printf("  =================================================================================================================================\n");
}

/// @fn void BajaJugador(eJugador[], int)
/// @brief muesta la lista de jugadores para señeccionar el id que se desea eliminar, si lo encuentra le da una baja logica cambiando el estado a -1 en la lista de jugadores
///
/// @param jugadores lista de jugadores
/// @param size tamaño lista de jugadores
void BajaJugador(eJugador jugadores[],int size)
{
	int id;
	int control=0;

	do
	{
		MostrarJugadores(jugadores, size);
		utn_getNumero(&id, "Seleccione el ID del jugador que eliminar :", "\nERROR ID invalido\n", 1, size, 10);


		for(int i=0;i<size;i++)
		{
			if(jugadores[i].id==id && jugadores[i].isEmply==1)
			{
				jugadores[i].isEmply =-1;
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





}

/// @fn void MotrarJugadoresCompleto(eJugador[], eConfederaciones[], int, int)
/// @brief  muesta listado de jugadores activos completos con el nombre de la confederacion
///
/// @param jugadores listado de jugadores
/// @param lista listado confederaciones
/// @param sizeJug tamaño lista jugadores
/// @param sizeConfe tamaño lista confederaciones
void MotrarJugadoresCompleto(eJugador jugadores[],eConfederaciones lista[],int sizeJug , int sizeConfe)
{
	printf("  =========================================================================================================================================\n");
	printf(" | ID   |        NOMBRE            |    POSICION      |    N° CAM.   |      SUELDO     |       CONFEDERACION       |    A%cIOS DE CONTRATO  |  \n  ",165);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<sizeJug;i++)
	{
		if(jugadores[i].isEmply==1)
		{
			for(int j=0;j<sizeConfe;j++)
			{
				if(jugadores[i].idConfederacion==lista[j].id)
				{
					printf(" |  %-4d|%-26s|  %-16s|      %-8d| $ %-14.2f|        %-19s|            %-11d|\n",jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,lista[j].nombre,jugadores[i].aniosContrato);

				}
			}
		}
	}
	printf("  =========================================================================================================================================\n");

}
