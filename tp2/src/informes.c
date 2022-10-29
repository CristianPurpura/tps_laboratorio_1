/*
 * informes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Cris
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "confederaciones.h"
#include "jugadores.h"

/// @fn void RegionMasJugadores(eJugador[], eConfederaciones[], int, int)
/// @brief buscca la region que tenga mas jugadores y la imprime con su lista de jugadores en el caso de haber mas de
/// 		una region con la misma cantidad de jugadores loa visa
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void RegionMasJugadores(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{

	int contadorJug=0;
	int maximoJugador=0;
	char auxConf[50];
	int cantidadMaximo;
	int flag=0;
	//char auxConfDos[50];
	int indice;


	for(int i=0;i<sizeConfe;i++)
	{
		contadorJug=0;

		for(int j=0;j<sizeJug;j++)
		{
			if(jugadores[j].isEmply==1 && jugadores[j].idConfederacion==lista[i].id)
			{
				contadorJug++;

			}
		}

		if(maximoJugador<contadorJug)
		{
			maximoJugador=contadorJug;
			strcpy(auxConf,lista[i].nombre);
			cantidadMaximo=contadorJug;
			indice=i;
			flag=0;

		}
		else
		{
			if(maximoJugador==contadorJug)
			{
				flag=1;

			}
		}

		printf("La %s tiene %d Jugadores.\n",lista[i].nombre,contadorJug);
	}

	if(flag==1 )
	{
		printf("\nHay mas de una confederacion con la misma cantidad de jugadores.\n");

	}
	else
	{
		printf("\nLa confederacion con mas jugadores es %s teniendo %d jugadores.\n",auxConf,cantidadMaximo);
	//	for(int i=0;i<sizeConfe;i++)
		//	{
				printf("\n\n\t CONFEDERACION :%s\n",auxConf);
				printf("  =================================================================================================================================\n");
				printf(" | ID   |        NOMBRE       |    POSICION      |    N° CAM.   |    SUELDO    |       CONFEDERACION       |    A%cIOS DE CONTRATO  |  \n  ",165);
				printf("---------------------------------------------------------------------------------------------------------------------------------\n");
				for(int j=0;j<sizeJug;j++)
				{
					if(lista[indice].id==jugadores[j].idConfederacion && jugadores[j].isEmply==1)
					{

						printf(" |  %-4d|%-15s      |   %-15s|     %-9d| %.2f   |          %-15s  |         %-10d    |\n",jugadores[j].id,jugadores[j].nombre,jugadores[j].posicion,jugadores[j].numeroCamiseta,jugadores[j].salario,lista[indice].nombre,jugadores[j].aniosContrato);
					}
				}
				printf("  =================================================================================================================================\n");
		//	}

	}






}

/// @fn void PorcentajeJugadorConfe(eJugador[], eConfederaciones[], int, int)
/// @brief imprime los porcentajes de jugadores por confederacion
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void PorcentajeJugadorConfe(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{
	int contadorJugadores=0;
	int contjugConf=0;
	char auxConf[50];
	float porcentaje;




	for(int i =0;i<sizeJug;i++)
	{
		if(jugadores[i].isEmply==1)
		{
			contadorJugadores++;
		}
	}

	printf("\n\t\tPorcentaje de cada confederacion sobre %d jugadores.\n\n",contadorJugadores);


		for(int i=0;i<sizeConfe;i++)
		{


			for(int j=0;j<sizeJug;j++)
			{
				if(jugadores[j].idConfederacion==lista[i].id &&jugadores[j].isEmply==1)
				{

					contjugConf++;
					strcpy(auxConf,lista[i].nombre);


				}

			}

		//	printf("%d\n",contjugConf);

			porcentaje=(float) contjugConf*100/contadorJugadores;

			printf("Cantidad de jugadores de %s es : %.2f%c teniendo %d jugadores. \n",auxConf,porcentaje,37,contjugConf);
			contjugConf=0;


			//	printf("%s\n",auxConf);
		}










}

/// @fn void ConfeMasAnios(eJugador[], eConfederaciones[], int, int)
/// @brief imprime la confederacion con mas años decontrato en el caso de haber mas de una con la misma cantidad lo avisa
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ConfeMasAnios(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{
	char confeMasAnioos[50];
	int acumulador;
	int maximoAnioos=0;
	//int contadorentrada=0;
	int flag=0;
	int posicion;

	printf("\n\n\tA%cOS DE CONTRATO DE CADA CONFEDERACION\n\n",165);

	for(int i=0;i<sizeConfe;i++)
	{
		acumulador=0;
		for(int j=0;j<sizeJug;j++)
		{
			if(lista[i].id==jugadores[j].idConfederacion && jugadores[j].isEmply==1)
			{
				acumulador+=(int)jugadores[j].aniosContrato;
			//	flag=1;

			}
		//	printf("%d\n",acumulador);

		}
		if(maximoAnioos<acumulador )
		{
			//contadorentrada++;
			maximoAnioos =acumulador;
			posicion=i;
			strcpy(confeMasAnioos,lista[posicion].nombre);

			flag=0;
		}
		else
		{
			if(maximoAnioos==acumulador)
			{
				flag=1;
			}
		}


		printf("%-10s  A%cos de contrato: %d\n",lista[i].nombre,165,acumulador);
	}

	if(flag==1)
	{
		printf("\nHay mas de una confederacion con la misma cantidad de anios de contrato.\n");
	}
	else
	{
		printf("\n\nLa confederacion con mas a%cos de contrato es : %s",165,confeMasAnioos);
	}

	//printf("\n\nLa confederacion con mas a%cos de contrato es : %s",165,confeMasAnioos);
}

/// @fn void TotalPromedioSalario(eJugador[], eConfederaciones[], int, int)
/// @brief imprime el total de los sueldos el promedio y cantidad de jugadores que superan ese promedio
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void TotalPromedioSalario(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{
	int contador=0;
	float acumulador=0;
	float promedioSalarios;
	int contadorMasPromedio=0;


	for(int i=0;i<sizeJug;i++)
	{
		if(jugadores[i].isEmply==1)
		{
			contador++;
			acumulador+=jugadores[i].salario;
		}
	}

	promedioSalarios=acumulador/contador;

	for(int i=0;i<sizeJug;i++)
	{
		if(jugadores[i].isEmply==1 && jugadores[i].salario>promedioSalarios)
		{
			contadorMasPromedio++;

		}
	}

	printf("\n\nEl total de los salarios es: $ %.2f\n\n",acumulador);
	printf("El promedio de los salarios es: $ %.2f\n\n",promedioSalarios);
	printf("La cantidad de jugadores que superan el promedio es: %d\n\n",contadorMasPromedio);





}

/// @fn void ListadoConfeJugador(eJugador[], eConfederaciones[], int, int)
/// @brief   imprime de cada confederacion un listado de todos sus jugadores activos
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ListadoConfeJugador(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{
	for(int i=0;i<sizeConfe;i++)
	{
		printf("\n\n\t CONFEDERACION :%s\n",lista[i].nombre);
		printf("  =================================================================================================================================\n");
		printf(" | ID   |        NOMBRE       |    POSICION      |    N° CAM.   |    SUELDO    |       CONFEDERACION       |    A%cIOS DE CONTRATO  |  \n  ",165);
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		for(int j=0;j<sizeJug;j++)
		{
			if(lista[i].id==jugadores[j].idConfederacion && jugadores[j].isEmply==1)
			{

				printf(" |  %-4d|%-15s      |   %-15s|     %-9d| %.2f   |          %-15s  |         %-10d    |\n",jugadores[j].id,jugadores[j].nombre,jugadores[j].posicion,jugadores[j].numeroCamiseta,jugadores[j].salario,lista[i].nombre,jugadores[j].aniosContrato);
			}
		}
		printf("  =================================================================================================================================\n");
	}
}

/// @fn void ListadoAlfaConfeJugador(eJugador[], eConfederaciones[], int, int)
/// @brief ordena e imprime un listado ordenado alfaveticamente por confederaciones en el caso de repetirce ordena por nombre
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ListadoAlfaConfeJugador(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{

	eJugador buffer;
	int flagSwap=0;
	int nuevoLimite;
	char auxconfeUno[50];
	char auxconfeDos[50];
	int j;
	int x;


	nuevoLimite=sizeJug-1;



	//MotrarJugadoresCompleto(jugadores, lista, sizeJug, sizeConfe);





	do
	{
		flagSwap=0;

		for(int i=0;i<nuevoLimite;i++)
		{
			for( j=0;j<sizeConfe;j++)
			{
				if(jugadores[i].idConfederacion == lista[j].id)
				{
					//printf("confe1\n");
					strcpy(auxconfeUno,lista[j].nombre);
					//printf("1  %s\n",auxconfeUno);
					break;
				}
			//	printf("\n1 salgo");


			}
			for( x=0;x<sizeConfe;x++)
			{
				if(jugadores[i+1].idConfederacion == lista[x].id)
				{
					//printf("confe2\n");
					strcpy(auxconfeDos,lista[x].nombre);
					//printf("2  %s\n",auxconfeDos);
					break;
				}
				//printf("\n2 salgo");

			}

			if( (strcmp(auxconfeUno,auxconfeDos)>0) || (  strcmp(auxconfeUno,auxconfeDos)==0  &&  strcmp(jugadores[i].nombre,jugadores[i+1].nombre)>0 )  )
			{
				flagSwap=1;
				buffer = jugadores[i];
				jugadores[i] = jugadores[i+1];
				jugadores[i+1] = buffer;
			//	printf("\tEntro\n");
			}

		}

			nuevoLimite--;
		}while(flagSwap);





	printf("\t\tLISTADO ORDENADO\n\n\n");

	MotrarJugadoresCompleto(jugadores, lista, sizeJug, sizeConfe);





}

/// @fn void MenuInformes(eJugador[], eConfederaciones[], int, int)
/// @brief imprime un menu de informes a seleccionar por el usuario
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void MenuInformes(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe)
{
	int opcion;

	do
	{
		utn_getNumero(&opcion, "\n\n\tSELECCIONAR EL INFORME QUE DESEA.\n\n1- Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador.\n2- Listado de confederaciones con sus jugadores.\n3- Total y promedio de todos los salarios y cuántos jugadores cobran más delsalario promedio.\n4- Informar la confederación con mayor cantidad de años de contratos total.\n5- Informar porcentaje de jugadores por cada confederación.\n6- Informar cual es la región con más jugadores y el listado de los mismos.\n\n7- SALIR.\n\nSELECCIONE UNA OPCION: ","\nERROR opciones 1-7\n", 1, 7, 10);

		switch(opcion)
		{
		case 1:
			ListadoAlfaConfeJugador(jugadores, lista, sizeJug, sizeConfe);

			break;
		case 2:
			ListadoConfeJugador(jugadores, lista, sizeJug, sizeConfe);
			break;
		case 3:
			TotalPromedioSalario(jugadores, lista, sizeJug, sizeConfe);
			break;
		case 4:
			ConfeMasAnios(jugadores, lista, sizeJug, sizeConfe);
			break;
		case 5:
			PorcentajeJugadorConfe(jugadores, lista, sizeJug, sizeConfe);
			break;
		case 6:
			RegionMasJugadores(jugadores, lista, sizeJug, sizeConfe);

			break;

		}

	}while(opcion!=7);


}

























