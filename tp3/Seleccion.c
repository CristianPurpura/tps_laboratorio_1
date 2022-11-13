#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"









/// @fn int selec_getId(Seleccion*, int*)
/// @brief toma el id de un seleccion y lo devuelve
///
/// @param seleccion
/// @param id puntero donde devuelve el valor
/// @return 0 si lo logra -1 si no
int selec_getId(Seleccion* seleccion,int* id)
{
	int retorno=-1;
	if(seleccion!=NULL && id!=NULL)
	{
		*id=seleccion->id;
		retorno=0;
	}

	return retorno;

}

/// @fn int selec_getPais(Seleccion*, char*)
/// @brief  toma el nombre del pais de una seleccion
///
/// @param seleccion
/// @param pais puntero donde devuelve el dato
/// @return 0 si lo logra -1 si no
int selec_getPais(Seleccion* seleccion,char* pais)
{
	int retorno=-1;


	if(seleccion!=NULL && pais!=NULL)
	{
		strcpy(pais,seleccion->pais);
		retorno=0;
	}



	return retorno;


}

/// @fn int selec_getConfederacion(Seleccion*, char*)
/// @brief  toma el nombre de la confederacon de una seleccion
///
/// @param seleccion
/// @param confederacion puntero donde devuelve el dato
/// @return 0 si lo logra -1 si no
int selec_getConfederacion(Seleccion* seleccion,char* confederacion)
{

	int retorno=-1;


	if(seleccion!=NULL && confederacion!=NULL)
	{
		strcpy(confederacion,seleccion->confederacion);
		retorno=0;
	}

	return retorno;

}

/// @fn int selec_setConvocados(Seleccion*, int)
/// @brief asigna un valor en el campo convocados de una seleccion
///
/// @param seleccion
/// @param convocados	parametro a setear en la seleccion
/// @return 0 si lo logra -1 si no
int selec_setConvocados(Seleccion* seleccion,int convocados)
{
	int retorno=-1;

	if(seleccion!=NULL)
	{
		seleccion->convocados=convocados;
		retorno=0;
	}


	return retorno;
}


/// @fn int selec_getConvocados(Seleccion*, int*)
/// @brief 	toma el valor de el campo convocados de una seleccion
///
/// @param seleccion
/// @param convocados	puntero donde devuelve el valor
/// @return 0 si lo logra -1 si no
int selec_getConvocados(Seleccion* seleccion,int* convocados)
{
	int retorno=-1;


	if(seleccion!=NULL && convocados!=NULL)
	{
		*convocados=seleccion->convocados;
		retorno=0;
	}

	return retorno;

}



/// @fn Seleccion selec_new*()
/// @brief genera espacio en memoria para 1 seleccion
///
/// @return devuleve estacio en memoria para una seleccion
Seleccion* selec_new()
{
	Seleccion* aux;

	aux=(Seleccion*) malloc(sizeof(Seleccion));

	return aux;
}

/// @fn void selec_delete(Seleccion*)
/// @brief libera el espacio en memoria de una seleccion
///
/// @param this seleccion a eliminar
void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// @fn Seleccion selec_newParametros*(char*, char*, char*, char*)
/// @brief  genera una nueva seleccion y le seta los datos recibidos por parametro
///
/// @param idStr id de la seleccion
/// @param paisStr pais de la seleccion
/// @param confederacionStr confederacion de la seleccion
/// @param convocadosStr cantidad de convocados de la seleccion
/// @return 0 si lo logra -1 si no
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{

	Seleccion* aux;


	aux=(Seleccion*)malloc(sizeof(Seleccion));

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		aux->id=atoi(idStr);
		strcpy(aux->pais,paisStr);
		strcpy(aux->confederacion,confederacionStr);
		aux->convocados=atoi(convocadosStr);





	}

	return aux;
}

/// @fn int selec_imprimirUnaSeleccion(Seleccion*)
/// @brief imprime todos los campos de una seleccion
///
/// @param unaSeleccion seleccion a se imprimida
/// @return 0 si lo logra -1 si no
int selec_imprimirUnaSeleccion(Seleccion* unaSeleccion)
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	int retorno=-1;


	if(unaSeleccion!=NULL)
	{

		selec_getId(unaSeleccion, &id);
		selec_getPais(unaSeleccion, pais);
		selec_getConfederacion(unaSeleccion, confederacion);
		selec_getConvocados(unaSeleccion, &convocados);

		retorno=0;


		printf("%3d   %-30s   %-30s   %5d\n",id,pais,confederacion,convocados);

	}

	return retorno;

}

/// @fn int selec_imprimirArraySelecciones(LinkedList*)
/// @brief  imprime una lista de selecciones
///
/// @param pArrayListSelecciones	lista de selecciones
/// @return 0 si lo logra -1 si no
int selec_imprimirArraySelecciones(LinkedList* pArrayListSelecciones)
{
	int retorno=-1;
	int cantidad;
	Seleccion* aux;

	cantidad=ll_len(pArrayListSelecciones);

	if(pArrayListSelecciones!=NULL && cantidad>0)
	{
		retorno=0;
		for(int i=0;i<cantidad;i++)
		{
			aux=(Seleccion*)ll_get(pArrayListSelecciones, i);
			selec_imprimirUnaSeleccion(aux);
		}
	}

	return retorno;
}

/// @fn int selec_imprimirArraySelecConLugar(LinkedList*)
/// @brief
///
/// @param pArrayListSelecciones
/// @return 0 si lo logra -1 si no
int selec_imprimirArraySelecConLugar(LinkedList* pArrayListSelecciones)
{
	int retorno=-1;
	int cantidad;
	Seleccion* aux;
	int convocados;

	cantidad=ll_len(pArrayListSelecciones);

	if(pArrayListSelecciones!=NULL && cantidad>0)
	{
		retorno=0;
		for(int i=0;i<cantidad;i++)
		{
			aux=(Seleccion*)ll_get(pArrayListSelecciones, i);
			selec_getConvocados(aux, &convocados);
			if(convocados<=21)
			{

				selec_imprimirUnaSeleccion(aux);
			}

		}
	}

	return retorno;

}

/// @fn int selec_AgregarConvocados(LinkedList*, int)
/// @brief incrementa el numero de convocados de la seleccion segun la id pasada por parametro
///
/// @param pArrayListSelecciones	lista de selecciones
/// @param idSelec	id de la seleccion a incrementar
/// @return 0 si lo logra -1 si no
int selec_AgregarConvocados(LinkedList* pArrayListSelecciones,int idSelec)
{
	int retorno=-1;
	int cantidad;
	Seleccion* seleccion;
	int idCompara;
	int convocados;

	if(pArrayListSelecciones!=NULL && idSelec>0)
	{
		cantidad=ll_len(pArrayListSelecciones);
		for(int i;i<cantidad;i++)
		{
			seleccion=ll_get(pArrayListSelecciones, i);

			selec_getId(seleccion, &idCompara);

			if(idSelec==idCompara)
			{
				retorno=0;
				selec_getConvocados(seleccion, &convocados);
				convocados++;
				selec_setConvocados(seleccion, convocados);
				break;
			}
		}
	}

	return retorno;

}

/// @fn int selec_SacarConvocados(LinkedList*, int)
/// @brief  decrementa el numero de convocados de la seleccion segun la id pasada por parametro
///
/// @param pArrayListSelecciones	lista de selecciones
/// @param idSelec	id de la seleccion a decrementar
/// @return 0 si lo logra -1 si no
int selec_SacarConvocados(LinkedList* pArrayListSelecciones,int idSelec)
{
	int retorno=-1;
	int cantidad;
	Seleccion* seleccion;
	int idCompara;
	int convocados;

	if(pArrayListSelecciones!=NULL && idSelec>0)
	{
		cantidad=ll_len(pArrayListSelecciones);
		for(int i;i<cantidad;i++)
		{
			seleccion=ll_get(pArrayListSelecciones, i);

			selec_getId(seleccion, &idCompara);

			if(idSelec==idCompara)
			{
				retorno=0;
				selec_getConvocados(seleccion, &convocados);
				convocados--;
				selec_setConvocados(seleccion, convocados);
				break;
			}
		}
	}

	return retorno;

}

/// @fn int selec_criterioConfederacion(void*, void*)
/// @brief funcion criterio, ordena por nombre de confederacion
///
/// @param seleccion1
/// @param seleccion2
/// @return 1 si la seleccion1 es mas grande que la seleccion2 0 si es alreves
int selec_criterioConfederacion(void* seleccion1,void* seleccion2)
{

	int retorno;
	char confeUno[30];
	char confeeDos[30];

	selec_getConfederacion(((Seleccion*)seleccion1), confeUno);
	selec_getConfederacion(((Seleccion*)seleccion2), confeeDos);

		retorno=stricmp(confeUno,confeeDos);


		return retorno;



}

/// @fn int selec_ordenarConfederacion(LinkedList*)
/// @brief genera un listado de selecciones ordenado alfabeticamente por confederacion en un listado auxiliar lo muestrea y elimina el listado
///
/// @param pArrayListSelecciones lista de seleccion
/// @return 0 si lo logra -1 si no
int selec_ordenarConfederacion(LinkedList* pArrayListSelecciones)
{
	LinkedList* listaAux=NULL;
	int retorno=-1;



	if(pArrayListSelecciones!=NULL)
	{
		listaAux=(LinkedList*)ll_clone(pArrayListSelecciones);

		if(listaAux!=NULL)
		{
			ll_sort(listaAux, selec_criterioConfederacion, 1);

			printf(" ID\t\tPAIS\t\t\tCONFEDERACION\t\t\tCONVOCADOS\n\n");
			selec_imprimirArraySelecciones(listaAux);
			retorno=0;
		}



	}

	ll_clear(listaAux);
	ll_deleteLinkedList(listaAux);


	return retorno;



}





