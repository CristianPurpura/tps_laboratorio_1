#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "utn.h"
#include "Seleccion.h"







/// @fn int jug_setId(Jugador*, int)
/// @brief setea el id en un jugaor
///
/// @param jugador
/// @param id	id recibido por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setId(Jugador* jugador,int id)
{
	int retorno=-1;

	if(jugador!=NULL && id>0)
	{
		jugador->id=id;

		retorno=0;
	}



	return retorno;

}

/// @fn int jug_getId(Jugador*, int*)
/// @brief  devuleve el valor guardado en el campo id de un jugador
///
/// @param jugador
/// @param id	pupntero donde se devuelve el valor
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getId(Jugador* jugador,int* id)
{
	int retorno=-1;

	if(jugador!=NULL && id!=NULL)
	{
		*id=jugador->id;

		retorno=0;
	}



	return retorno;


}

/// @fn int jug_setNombreCompleto(Jugador*, char*)
/// @brief setea el campo nombrecompleto recibido por parametro en una jugador
///
/// @param jugador
/// @param nombreCompleto nombre recibido por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setNombreCompleto(Jugador* jugador,char* nombreCompleto)
{

	int retorno=-1;

	if(jugador!=NULL && nombreCompleto!=NULL)
	{
		strcpy(jugador->nombreCompleto,nombreCompleto);

		retorno=0;
	}
	return retorno;

}

/// @fn int jug_getNombreCompleto(Jugador*, char*)
/// @brief devuelve el nombre guardado en el campo nombre del jugador
///
/// @param jugador
/// @param nombreCompleto puntero donde devuelve el dato
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getNombreCompleto(Jugador* jugador,char* nombreCompleto)
{

	int retorno=-1;

	if(jugador!=NULL && nombreCompleto!=NULL)
	{
		strcpy(nombreCompleto,jugador->nombreCompleto);

		retorno=0;
	}
	return retorno;

}

/// @fn int jug_setPosicion(Jugador*, char*)
/// @brief setea la pociion del jugador recibida por parametro
///
/// @param jugador
/// @param posicion posicion recivida por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setPosicion(Jugador* jugador,char* posicion)
{

	int retorno=-1;

	if(jugador!=NULL && posicion!=NULL)
	{
		strcpy(jugador->posicion,posicion);

		retorno=0;
	}
	return retorno;

}

/// @fn int jug_getPosicion(Jugador*, char*)
/// @brief devuelve la posicion de un jugador
///
/// @param jugador
/// @param posicion	puntero donde devuelve la posicion
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getPosicion(Jugador* jugador,char* posicion)
{

	int retorno=-1;

	if(jugador!=NULL && posicion!=NULL)
	{
		strcpy(posicion,jugador->posicion);

		retorno=0;
	}
	return retorno;

}

/// @fn int jug_setNacionalidad(Jugador*, char*)
/// @brief setea la nacionalidad recibida por parametro en un jugador
///
/// @param jugador
/// @param nacionalidad nacionalidad recibida por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setNacionalidad(Jugador* jugador,char* nacionalidad)
{

	int retorno=-1;

	if(jugador!=NULL && nacionalidad!=NULL)
	{
		strcpy(jugador->nacionalidad,nacionalidad);

		retorno=0;
	}
	return retorno;

}

/// @fn int jug_getNacionalidad(Jugador*, char*)
/// @brief devuelve la nacionalidad de un jugador
///
/// @param jugador
/// @param nacionalidad	puntero donde devuelve la nacionalidad
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getNacionalidad(Jugador* jugador,char* nacionalidad)
{
	int retorno=-1;

	if(jugador!=NULL && nacionalidad!=NULL)
	{
		strcpy(nacionalidad,jugador->nacionalidad);

		retorno=0;
	}
	return retorno;
}

/// @fn int jug_setEdad(Jugador*, int)
/// @brief  setea la edad recibida por parametro en u jugador
///
/// @param jugador
/// @param edad	edad recibida por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setEdad(Jugador* jugador,int edad)
{
	int retorno=-1;

	if(jugador!=NULL && edad>0 && edad<99 )
	{
		jugador->edad=edad;

		retorno=0;
	}



	return retorno;

}

/// @fn int jug_getEdad(Jugador*, int*)
/// @brief devuelve la edad de un jugador
///
/// @param jugador
/// @param edad puntero donde devuelva la edad
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getEdad(Jugador* jugador,int* edad)
{
	int retorno=-1;

	if(jugador!=NULL && edad!=NULL)
	{
		*edad=jugador->edad;

		retorno=0;
	}



	return retorno;


}

/// @fn int jug_setIdSeleccion(Jugador*, int)
/// @brief setea el id de seleccion de un jugador
///
/// @param jugador
/// @param idSeleccion	valor del ide recibido por parametro
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_setIdSeleccion(Jugador* jugador,int idSeleccion)
{


	int retorno=-1;

	if(jugador!=NULL && idSeleccion>=0)
	{
		jugador->idSeleccion=idSeleccion;

		retorno=0;
	}



	return retorno;

}

/// @fn int jug_getSIdSeleccion(Jugador*, int*)
/// @brief devuelve el valor del campo id seleccion de un jugador
///
/// @param jugador
/// @param idSeleccion	puntero donde devuelve el valor del id
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_getSIdSeleccion(Jugador* jugador,int* idSeleccion)
{

	int retorno=-1;

	if(jugador!=NULL && idSeleccion!=NULL)
	{
		*idSeleccion=jugador->idSeleccion;

		retorno=0;
	}



	return retorno;


}


/// @fn Jugador jug_new*()
/// @brief genera espacio en memoria para un jugador
///
/// @return devuelve un jugador
Jugador* jug_new()
{
	Jugador* aux;

	aux=(Jugador*) calloc(sizeof(Jugador),1);//0x102

	return aux;

}

/// @fn void jug_delete(Jugador*)
/// @brief  elimina de memoria un jugador
///
/// @param this jugador a ser eliminado
void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// @fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
/// @brief genera un nuevo jugador y le carga todos los campos recibidos por parametro
///
/// @param idStr id recibida por parametro
/// @param nombreCompletoStr nombre recibida por parametro
/// @param edadStr edad recibida por parametro
/// @param posicionStr posicion recibida por parametro
/// @param nacionalidadStr nacionalidad recibida por parametro
/// @param idSelccionStr id de seleccion recibida por parametro
/// @return devuelve un jugador con los datos cargados
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* jugador=NULL;

	if(idStr!=NULL&&nombreCompletoStr!=NULL&&edadStr!=NULL&&posicionStr!=NULL&&nacionalidadStr!=NULL&&idSelccionStr!=NULL)
	{
		jugador=jug_new();//0x200

		jug_setId(jugador, atoi(idStr));
		jug_setNombreCompleto(jugador, nombreCompletoStr);
		jug_setEdad(jugador, atoi(edadStr));
		jug_setPosicion(jugador, posicionStr);
		jug_setNacionalidad(jugador, nacionalidadStr);
		jug_setIdSeleccion(jugador, atoi(idSelccionStr));

	}

	return jugador;
}

/// @fn int jug_imprimirUnJugador(Jugador*)
/// @brief imprime por pantalla un jugador con sus datos
///
/// @param unJugador
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirUnJugador(Jugador* unJugador)
{
	int retorno=-1;
	int id;
	int idSelec;
	char nombreCompletoStr[30];
	int edad;
	char posicionStr[30];
	char nacionalidadStr[30];

	if(unJugador!=NULL)
	{
		jug_getId(unJugador, &id);
		jug_getSIdSeleccion(unJugador, &idSelec);
		jug_getEdad(unJugador, &edad);
		jug_getNombreCompleto(unJugador, nombreCompletoStr);
		jug_getPosicion(unJugador, posicionStr);
		jug_getNacionalidad(unJugador, nacionalidadStr);

		retorno=0;

		printf("%3d   %-30s   %-10d    %-30s   %-30s %4d \n",id,nombreCompletoStr,edad,posicionStr,nacionalidadStr,idSelec);
	}

	return retorno;
}

/// @fn int jug_imprimirArrayJugadores(LinkedList*)
/// @brief imprime una lista de jugadores con sus datos
///
/// @param pArrayListJugador
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirArrayJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int cantidad;
	Jugador* aux;

	cantidad=ll_len(pArrayListJugador);

	if(pArrayListJugador!=NULL && cantidad>0)
	{
		retorno=0;
		for(int i=0;i<cantidad;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_imprimirUnJugador(aux);
		}
	}

	return retorno;

}

/// @fn int jug_ElegirPosicion(char*)
/// @brief  despliega un menu deposiciones para que el usuario elija la posicion del jugador
///
/// @param posicion guarda la posicion elejida por el usuario
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_ElegirPosicion(char* posicion)
{
	int opcion;
	int retorno=-1;

	utn_getNumero(&opcion, "SELECCIONAR LA POSICION DEL JUGADOR.\n\n1- Portero.\n2- Defensa central.\n3- Lateral izquierdo.\n4- Lateral derecho.\n5- Pivote.\n6- Medio centro\n7- Extremo izquierdo\n8- Extremo derecho.\n9- Mediopunta.\n10- Delantero centro.\n-Seleecione la opcion deseada:  ", "\n\n\tError opciones 1-10", 1, 10, 10);

	switch(opcion)
	{
	case 1:
		strcpy(posicion,"Portero");
		retorno=0;
		break;
	case 2:
		strcpy(posicion,"Defensa central");
		retorno=0;
		break;
	case 3:
		strcpy(posicion,"Lateral izquierdo");
		retorno=0;
		break;
	case 4:
		strcpy(posicion,"Lateral derecho");
		retorno=0;
		break;
	case 5:
		strcpy(posicion,"Pivote");
		retorno=0;
		break;
	case 6:
		strcpy(posicion,"Medio centro");
		retorno=0;
		break;
	case 7:
		strcpy(posicion,"Extremo izquierdo");
		retorno=0;
		break;
	case 8:
		strcpy(posicion,"Extremo derecho");
		retorno=0;
		break;
	case 9:
		strcpy(posicion,"Mediopunta");
		retorno=0;
		break;
	case 10:
		strcpy(posicion,"Delantero centro");
		retorno=0;
		break;

	}

	return retorno;

}

/// @fn int jug_ultimoId(LinkedList*)
/// @brief busca el id mas grande y lo devuelve
///
/// @param pArrayListJugador
/// @return retorna el id mas grande encontrado
int jug_ultimoId(LinkedList* pArrayListJugador)
{
	Jugador* aux;
	int cantidad;
	int id;
	int idMax=0;

	cantidad=ll_len(pArrayListJugador);


	if(pArrayListJugador!=NULL)
	{
		for(int i=0;i<cantidad;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(aux,&id);
			if(id>idMax)
			{
				idMax=id;
			}



		}


	}

	return idMax;
}

/// @fn int jug_nuevoId(char*)
/// @brief genera un nuevo id lo guarda en un archivo para que persista y lo devuelve
///
/// @param patch archivo donde se guarda el id
/// @return retorna un nuevo numero de ID
int jug_nuevoId(char* patch)
{
	char ultimoId[10];
	int idEntero;
	FILE* pFile;

	pFile=fopen(patch,"r");


	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,]",ultimoId);
		fclose(pFile);
		idEntero=atoi(ultimoId);
		idEntero++;
		pFile=fopen(patch,"w");
		fprintf(pFile,"%d,",idEntero);


	}

	fclose(pFile);




	return idEntero;
}

/// @fn int jug_imprimirUnJugCompleto(Jugador*, char*)
/// @brief imprime un jugador agregando nombre de seleccion si corresponde o "no convocado"
///
/// @param unJugador jugador a ser impreso
/// @param seleccion nombre de la seleccion del jugador
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirUnJugCompleto(Jugador* unJugador,char* seleccion)
{
	int retorno=-1;
	int id;
	char nombreCompletoStr[30];
	int edad;
	char posicionStr[30];
	char nacionalidadStr[30];

	if(unJugador!=NULL)
	{
		jug_getId(unJugador, &id);
		jug_getEdad(unJugador, &edad);
		jug_getNombreCompleto(unJugador, nombreCompletoStr);
		jug_getPosicion(unJugador, posicionStr);
		jug_getNacionalidad(unJugador, nacionalidadStr);

		retorno=0;

		printf("%3d   %-30s   %-10d    %-30s   %-30s %-30s \n",id,nombreCompletoStr,edad,posicionStr,nacionalidadStr,seleccion);
	}

	return retorno;
}

/// @fn int jug_imprimirArrayJugCompleto(LinkedList*, LinkedList*)
/// @brief busca el nombre de la seleccion que le conrresponda al jugador llama a imprimir un jugador y se la pasa
/// 		de no tener seleccion le asigna no convocado e imprime una lista de jugadores con todos sus campos
///
/// @param pArrayListJugador	lista de jugadores
/// @param pArrayListSelecciones	lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirArrayJugCompleto(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones)
{
	int retorno=-1;
	int cantidad;
	Jugador* aux;
	Seleccion* auxSelec;
	int cantidadSelec;
	int idSelec;
	int idCompara;
	char nombreSelec[30];

	cantidad=ll_len(pArrayListJugador);
	cantidadSelec=ll_len(pArrayListSelecciones);

	if(pArrayListJugador!=NULL && cantidad>0 && pArrayListSelecciones!=NULL && cantidadSelec>0)
	{
		retorno=0;
		for(int i=0;i<cantidad;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(aux, &idSelec);
			if(idSelec!=0)
			{
				for(int j=0;j<cantidadSelec;j++)
				{
					auxSelec=(Seleccion*)ll_get(pArrayListSelecciones, j);
					selec_getId(auxSelec, &idCompara);
					if(idSelec==idCompara)
					{
						selec_getPais(auxSelec, nombreSelec);
						break;
					}

				}
			}
			else
			{
				strcpy(nombreSelec,"No convocado");
			}

			jug_imprimirUnJugCompleto(aux,nombreSelec);
		}
	}

	return retorno;

}

/// @fn int jug_imprimirArrayJugCoconvocados(LinkedList*, LinkedList*)
/// @brief imprime una lista de jugadores que esten convocados en alguna seleccion
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSelecciones	lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirArrayJugCoconvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones)
{
	int retorno=-1;
	int cantidad;
	Jugador* aux;
	Seleccion* auxSelec;
	int cantidadSelec;
	int idSelec;
	int idCompara;
	char nombreSelec[30];

	cantidad=ll_len(pArrayListJugador);
	cantidadSelec=ll_len(pArrayListSelecciones);

	if(pArrayListJugador!=NULL && cantidad>0 && pArrayListSelecciones!=NULL && cantidadSelec>0)
	{

		for(int i=0;i<cantidad;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(aux, &idSelec);
			if(idSelec!=0)
			{
				retorno=0;
				for(int j=0;j<cantidadSelec;j++)
				{
					auxSelec=(Seleccion*)ll_get(pArrayListSelecciones, j);
					selec_getId(auxSelec, &idCompara);
					if(idSelec==idCompara)
					{
						selec_getPais(auxSelec, nombreSelec);
						break;
					}

				}
				jug_imprimirUnJugCompleto(aux,nombreSelec);
			}


		}
	}

	return retorno;

}

/// @fn int jug_imprimirArrayJugSinCoconvocados(LinkedList*)
/// @brief imprime lista de jugadores que no esten convocados en ninguna seleccion
///
/// @param pArrayListJugador	lista de jugadores
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_imprimirArrayJugSinCoconvocados(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int cantidad;
	Jugador* aux;
	int idSelec;



	cantidad=ll_len(pArrayListJugador);


	if(pArrayListJugador!=NULL && cantidad>0 )
	{

		for(int i=0;i<cantidad;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getSIdSeleccion(aux, &idSelec);
			if(idSelec==0)
			{
				retorno=0;

				jug_imprimirUnJugador(aux);

			}


		}
	}

	return retorno;

}

/// @fn int jug_criterioNacionalidad(void*, void*)
/// @brief funcion criterio evalua por nacionalidad de jugador
///
/// @param jugador1
/// @param jugador2
/// @return retorna 1 si el jugador 1 es mas grande que el jugador 2 0 si son iguales -1 si el jugador 2 es mas grande que el 1
int jug_criterioNacionalidad(void* jugador1,void* jugador2)
{
	int retorno;
	char nacionalidadUno[30];
	char nacionalidadDos[30];

	jug_getNacionalidad(((Jugador*)jugador1), nacionalidadUno);
	jug_getNacionalidad(((Jugador*)jugador2), nacionalidadDos);

		retorno=strcmp(nacionalidadUno,nacionalidadDos);


		return retorno;

}

/// @fn int jug_criterioNombre(void*, void*)
/// @brief funcion criterio evalua por nombre
///
/// @param jugador1
/// @param jugador2
/// @return 1 si el jugador 1 es mas grande que el jugador 2 0 si son iguales -1 si el jugador 2 es mas grande que el 1
int jug_criterioNombre(void* jugador1,void* jugador2)
{
	int retorno;
	char nombredUno[30];
	char nombreDos[30];

	jug_getNombreCompleto(((Jugador*)jugador1), nombredUno);
	jug_getNombreCompleto(((Jugador*)jugador2), nombreDos);

		retorno=stricmp(nombredUno,nombreDos);


		return retorno;

}

/// @fn int jug_criterioEdad(void*, void*)
/// @brief funcion criterio evalua por edad
///
/// @param jugador1
/// @param jugador2
/// @return 1 si el jugador 1 es mas grande que el jugador 2 0 si son iguales -1 si el jugador 2 es mas grande que el 1
int jug_criterioEdad(void* jugador1,void* jugador2)
{
	int retorno;
	int edaddUno;
	int edadDos;

	jug_getEdad(((Jugador*)jugador1), &edaddUno);
	jug_getEdad(((Jugador*)jugador2), &edadDos);

		if(edaddUno<edadDos)
		{
			retorno=1;
		}


		return retorno;

}

/// @fn int jug_ordenarNombre(LinkedList*, LinkedList*)
/// @brief ordena por nombre los jugadores y los imprime con todos sus datos
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_ordenarNombre(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	LinkedList* listaAux=NULL;
	int retorno=-1;



	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		listaAux=(LinkedList*)ll_clone(pArrayListJugador);

		if(listaAux!=NULL)
		{
			ll_sort(listaAux, jug_criterioNombre, 1);

			printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
			jug_imprimirArrayJugCompleto(listaAux, pArrayListSeleccion);
			retorno=0;
		}



	}

	ll_clear(listaAux);
	ll_deleteLinkedList(listaAux);


	return retorno;




}

/// @fn int jug_ordenarEdad(LinkedList*, LinkedList*)
/// @brief ordena por edad los jugadores y los imprime con todos sus datos
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_ordenarEdad(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	LinkedList* listaAux=NULL;
	int retorno=-1;



	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		listaAux=(LinkedList*)ll_clone(pArrayListJugador);

		if(listaAux!=NULL)
		{
			ll_sort(listaAux, jug_criterioEdad, 1);

			printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
			jug_imprimirArrayJugCompleto(listaAux, pArrayListSeleccion);
			retorno=0;
		}



	}

	ll_clear(listaAux);
	ll_deleteLinkedList(listaAux);


	return retorno;




}

/// @fn int jug_ordenarNacionalidad(LinkedList*, LinkedList*)
/// @brief ordena por nacionalidad los jugadores y los imprime con todos sus datos
///
/// @param pArrayListJugador
/// @param pArrayListSeleccion
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_ordenarNacionalidad(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	LinkedList* listaAux=NULL;
	int retorno=-1;



	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		listaAux=(LinkedList*)ll_clone(pArrayListJugador);

		if(listaAux!=NULL)
		{
			ll_sort(listaAux, jug_criterioNacionalidad, 1);

			printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
			jug_imprimirArrayJugCompleto(listaAux, pArrayListSeleccion);
			retorno=0;
		}



	}

	ll_clear(listaAux);
	ll_deleteLinkedList(listaAux);


	return retorno;
}

/// @fn int jug_listaConvocadosConfe(LinkedList*, LinkedList*, LinkedList*)
/// @brief genera una lista de jugadores que estan convocados en una confederacion que elije el usuario
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSelecciones lista de selecciones
/// @param listaFiltrada puntero donde devuelve la lista
/// @return retorna 0 si lo logra -1 si no lo logra
int jug_listaConvocadosConfe(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones,LinkedList* listaFiltrada)
{

	int retorno=-1;
	Seleccion* auxConfe;
	Jugador* auxJug;
	int cantidadJug;
	int opcion;
	char confeCompara[30];
	char confe[30];
	int cantidadConfe;
	int idConfe;
	int idSelecJug;

	cantidadConfe=ll_len(pArrayListSelecciones);
	cantidadJug=ll_len(pArrayListJugador);

	utn_getNumero(&opcion, "\n\n\t\tSELECCIONE QUE CONFEDERACION DESEA FILTRAR\n\n1- AFC.\n2- CAF.\n3- CONCACAF.\n4- CONMEBOL.\n5- UEFA.\n\nSleccione una opcion :", "Error opciones 1-5.\n", 1, 5, 10);


	switch(opcion)
	{
	case 1:
		strcpy(confe,"AFC");
		break;
	case 2:
		strcpy(confe,"CAF");
		break;
	case 3:
		strcpy(confe,"CONCACAF");
		break;
	case 4:
		strcpy(confe,"CONMEBOL");
		break;
	case 5:
		strcpy(confe,"UEFA");
		break;
	}

	if(pArrayListJugador!=NULL && pArrayListSelecciones!=NULL && listaFiltrada)
	{
		for(int i=0;i<cantidadConfe;i++)
		{
			auxConfe=(Seleccion*)ll_get(pArrayListSelecciones, i);
			selec_getConfederacion(auxConfe, confeCompara);
			if((strcmp(confeCompara,confe))==0)
			{
				selec_getId(auxConfe, &idConfe);
				for(int j=0;j<cantidadJug;j++)
				{
					auxJug=(Jugador*)ll_get(pArrayListJugador, j);
					jug_getSIdSeleccion(auxJug, &idSelecJug);
					if(idSelecJug==idConfe)
					{
						retorno=0;
						//jug_imprimirUnJugador(auxJug);
						ll_add(listaFiltrada, auxJug);
					//	break;
					}

				}

			}


		}


	}

	return retorno;

}

