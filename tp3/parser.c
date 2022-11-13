#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/// @fn int parser_JugadorFromText(FILE*, LinkedList*)
/// @brief parcea los datos de un archivo de texto y los guarda en una lista
///
/// @param pFile archivo a leer
/// @param pArrayListJugador lista donde se guardan los datos
/// @return retorna 0 si lo logra -1 si no lo logra
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	Jugador* aux=NULL;
	char id[10];
	char idSelec[10];
	char nombreCompletoStr[30];
	char edadStr[10];
	char posicionStr[30];
	char nacionalidadStr[30];


	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelec);

		while(!feof(pFile))
		{



			if((fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelec))==6)
			{
				aux=jug_newParametros(id, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelec);
				if(aux!=NULL)
				{
					ll_add(pArrayListJugador, aux);
				}

			}
			else
			{
				retorno=-1;
				break;
			}




		}
		retorno=0;

	}


    return retorno;
}

/// @fn int parser_JugadorFromBinary(FILE*, LinkedList*)
/// @brief parcea los datos de un archivo binario y los guarda en una lista
///
/// @param pFile archivo a leer
/// @param pArrayListJugador	lista donde se guardan los datos
/// @return retorna 0 si lo logra -1 si no lo logra
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		do
		{
			unJugador = jug_new();
			if(unJugador != NULL)
			{
				if(fread(unJugador,sizeof(Jugador),1,pFile))
				{
					ll_add(pArrayListJugador,unJugador);
				}else
				{
					jug_delete(unJugador);
				}
			}
		}while(!feof(pFile));
		retorno = 0;
	}
    return retorno;

}

/// @fn int parser_SeleccionFromText(FILE*, LinkedList*)
/// @brief parcea los datos de un archivo de texto y los guarda en una lista
///
/// @param pFile archivo a leer
/// @param pArrayListSeleccion lista donde se guardan los datos
/// @return retorna 0 si lo logra -1 si no lo logra
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* aux;
	char id[10];
	char pais[30];
	char confederacion[30];
	char convocados[10];
	int retorno=-1;


	if(pFile!=NULL && pArrayListSeleccion!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

		while(!feof(pFile))
		{
			aux=selec_new();
			if(aux!=NULL)
			{
				if((fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados))==4)
				{
					aux=selec_newParametros(id, pais, confederacion, convocados);
					ll_add(pArrayListSeleccion, aux);
				}
				else
				{
					retorno=-1;
					break;
				}

			}

			retorno=0;
		}
	}



    return retorno;
}

/// @fn int parser_SeleccionFromBinary(FILE*, LinkedList*)
/// @brief parcea los datos de un archivo binario y los guarda en una lista
///
/// @param pFile archivo a leer
/// @param pArrayListSeleccion lista donde se guardan los datos
/// @return retorna 0 si lo logra -1 si no lo logra
int parser_SeleccionFromBinary(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* unaSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		do
		{
			unaSeleccion = selec_new();
			if(unaSeleccion != NULL)
			{
				if(fread(unaSeleccion,sizeof(Seleccion),1,pFile))
				{
					ll_add(pArrayListSeleccion,unaSeleccion);
				}else
				{
					selec_delete(unaSeleccion);
				}
			}
		}while(!feof(pFile));
		retorno = 0;
	}
    return retorno;

}


