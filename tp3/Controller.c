#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* nombre del archivos donde stan los datos
 * \param pArrayListJugador LinkedList* lista donde se guardan los datos leidos
 * \return int retorna -1 si no carga y retorna 0 si carga
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	FILE* pFile;


	pFile=fopen(path,"r");


	if(path!=NULL && pArrayListJugador!=NULL && pFile!=NULL)
	{
		if(!parser_JugadorFromText(pFile, pArrayListJugador))
		{
			retorno=0;

		}

		fclose(pFile);

	}


    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* nombre del archivos donde stan los datos
 * \param pArrayListJugador LinkedList* lista donde se guardan los datos leidos
 * \return int retorna -1 si no carga y retorna 0 si carga
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{

	int retorno = 1;
	FILE* pFile = fopen(path,"rb");


	if(pFile != NULL && path != NULL && pArrayListJugador != NULL)
	{
		if(!parser_JugadorFromBinary(pFile,pArrayListJugador))
		{
			retorno = 0;
		}
		fclose(pFile);
	}
	return retorno;

}

/// @fn int controller_agregarJugador(LinkedList*)
/// @brief pide datos para un nuevo jugador al usuario lo genera y lo guarda en la lista
///
/// @param pArrayListJugador lista de jugadores
/// @return retorna -1 si no lo logra 0 si logra guardar el jugador
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador* aux;

	int auxId;
	char nombreCompletoStr[30];
	int auxEdadStr;
	char posicionStr[30];
	char nacionalidadStr[30];
	int tamCadena;
	char idStr[10];
	char EdadStr[10];
	char IdSelccion[10]="0";
	int retorno=-1;


	if(pArrayListJugador!=NULL)
	{
		auxId=jug_nuevoId("ultimoId.csv");
		itoa(auxId, idStr,10);

		utn_getCadena(nombreCompletoStr, 30, "\nIngrese el nombre: ", "ERROR intenete nuevamente\n", 10);
		tamCadena=strlen(nombreCompletoStr);
		nombreCompletoStr[0]= nombreCompletoStr[0]-32;
		for(int j =0;j<tamCadena;j++)
		{

		if(nombreCompletoStr[j]==' ')
		{
		//	printf("entro\n");
			nombreCompletoStr[j+1]= nombreCompletoStr[j+1]-32;
		}
		}

		jug_ElegirPosicion(posicionStr);

		utn_getNumero(&auxEdadStr, "\nIngrese la edad de jugador: ",  "ERROR intenete nuevamente\n", 1, 99, 10);
		itoa(auxEdadStr, EdadStr,10);

		utn_getCadena(nacionalidadStr,30, "\nIngrese la nacionalidad :", "ERROR intenete nuevamente\n", 10);
		nacionalidadStr[0]= nacionalidadStr[0]-32;

		aux=jug_newParametros(idStr, nombreCompletoStr, EdadStr, posicionStr, nacionalidadStr, IdSelccion);
		if(aux!=NULL)
		{
			ll_add(pArrayListJugador, aux);
			printf("\n\t\tSE AGRESO UN NUEVO JUGADOR A LA LISTA\n\n");
			jug_imprimirUnJugador(aux);
			retorno=0;
		}
		else
		{
			printf("\nHUBO UN ERROR AL AGREGAR EL JUGADOR.\n\n");
		}





	}








    return retorno;
}

/// @fn int controller_editarJugador(LinkedList*)
/// @brief muestra la lista de jugadores para seleccionar cual cambiar si encuentra el ide pregunta que dato desea cambia lo cambia y lo guarda en la lista
///
/// @param pArrayListJugador lista de jugadores
/// @return retorna -1 si no logra hacer el cambio 0  si lo logra
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int id;
	int idCompara;
	int ultimoId;
	int cantidad;
	int opcion;
	char nombre[30];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int tamCadena;
	Jugador* jugador;
	int retorno=-1;
	int flagEncontrado=0;

	if(pArrayListJugador!=NULL)
	{
		ultimoId=jug_ultimoId(pArrayListJugador);
		cantidad=ll_len(pArrayListJugador);


		jug_imprimirArrayJugadores(pArrayListJugador);

		utn_getNumero(&id, "\nSeleccionar el id del jugador que desea modificar :", "\nERROR intente nuevamente.\n", 1, ultimoId, 10);

		for(int i=0;i<cantidad;i++)
		{

			jugador=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(jugador, &idCompara);
			if(idCompara==id)
			{
				flagEncontrado=1;
				printf("\n\t\tJUGADOR A MODIFICAR\n\n");

				jug_imprimirUnJugador(jugador);

				do
				{
					utn_getNumero(&opcion, "\n\nQue desea modificar.\n\n\n1- Nombre.\n2- Edad.\n3- Posicion.\n4- Nacionalidad.\n5- SALIR.\n\nSeleccione una opcion :", "\nERROR opciones de 1-5", 1, 5, 10);

					switch(opcion)
					{
					case 1:
						utn_getCadena(nombre, 30, "\nIngrese el nombre: ", "ERROR intenete nuevamente\n", 10);
						tamCadena=strlen(nombre);
						nombre[0]= nombre[0]-32;
						for(int j =0;j<tamCadena;j++)
						{

							if(nombre[j]==' ')
							{
								//	printf("entro\n");
								nombre[j+1]= nombre[j+1]-32;
							}
						}
						jug_setNombreCompleto(jugador, nombre);
						break;
					case 2:
						utn_getNumero(&edad, "\nIngrese la edad de jugador: ",  "ERROR intenete nuevamente\n", 1, 99, 10);
						jug_setEdad(jugador, edad);
						break;
					case 3:
						jug_ElegirPosicion(posicion);
						jug_setPosicion(jugador, posicion);
						break;

					case 4:
						utn_getCadena(nacionalidad, 30, "\nIngrese la nacionalidad :", "ERROR intenete nuevamente\n", 10);
						nacionalidad[0]= nacionalidad[0]-32;
						jug_setNacionalidad(jugador, nacionalidad);
						break;

					}


				}while(opcion!=5);

				printf("\n\t\tJUGADOR A MODIFICADO\n\n");

				jug_imprimirUnJugador(jugador);
				retorno=0;

				break;

			}
			else
			{
				if(cantidad==(i+1) && flagEncontrado==0)
				{
					printf("\n\nID NO ENCONTRADO.\n");
				}


			}


		}



	}



    return retorno;
}

/// @fn int controller_removerJugador(LinkedList*, LinkedList*)
/// @brief muestra la lista de jugadorers para seleccionar un id
/// si encuentra el id pide confirmacion de eliminacion si se confirma se elimina el jugador
/// si el jugador estaba en alguna seleccion se descuenta de la lista de convocados
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSelecciones lista de selecciones
/// @return retorna -1 si no logra eliminar el jugador 0 si lo logra
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones)
{
	int retorno=-1;
	Jugador* jugador;
	int idCompara;
	int ultimoId;
	int cantidad;
	int id;
	int opcion;
	int idSelec;



	if(pArrayListJugador!=NULL)
	{
		ultimoId=jug_ultimoId(pArrayListJugador);
		cantidad=ll_len(pArrayListJugador);


		jug_imprimirArrayJugadores(pArrayListJugador);

		utn_getNumero(&id, "\nSeleccionar el id del jugador que desea eliminar :", "\nERROR intente nuevamente.\n", 1, ultimoId, 10);

		for(int i=0;i<cantidad;i++)
		{

			jugador=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(jugador, &idCompara);
			if(idCompara==id)
			{
				printf("\n\t\tJUGADOR A ELIMINAR\n\n");

				jug_imprimirUnJugador(jugador);
				utn_getNumero(&opcion, "\n\t\tCONFIRMACION\n\n1- Eliminar el jugador.\n2- No eliminar el jugador.\n\nElija la opcion deseada :", "ERROR opciones 1-2", 1, 2, 10);
				if(opcion==1)
				{
					jug_getSIdSeleccion(jugador, &idSelec);
					if(idSelec!=0)
					{
						selec_SacarConvocados(pArrayListSelecciones, idSelec);
					}
					ll_remove(pArrayListJugador, i);



					retorno=0;

					break;
				}
				else
				{

					break;
				}

				}
			}

	}


    return retorno;
}

/// @fn int controller_listarJugadores(LinkedList*)
/// @brief lista los jugadores con id de seleccion no con nombre de la seleccion
///
/// @param pArrayListJugador lista de jugadores
/// @return retorna 0 si lo logra -1  si no
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\tID SELECCION\n\n");
		jug_imprimirArrayJugadores(pArrayListJugador);

		retorno=0;
	}



    return retorno;
}

/// @fn int controller_listarJugadoresCompleto(LinkedList*, LinkedList*)
/// @brief lista los jugadores con todos sus campos completos muestra nombre de seleccion o no convodaco
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1  si no
int controller_listarJugadoresCompleto(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
		jug_imprimirArrayJugCompleto(pArrayListJugador, pArrayListSeleccion);

		retorno=0;
	}



    return retorno;

}

/// @fn int controller_listarJugadoresConvocados(LinkedList*, LinkedList*)
/// @brief  lista los jugadores que tiene asignada una seleccion
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1  si no
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
		jug_imprimirArrayJugCoconvocados(pArrayListJugador, pArrayListSeleccion);

		retorno=0;
	}



    return retorno;

}

/// @fn int controller_listarJugadoresSinConvocados(LinkedList*)
/// @brief lista los jugadores que no estan convocados en ninguna seleccion
///
/// @param pArrayListJugador lista de jugadores
/// @return retorna 0 si lo logra -1  si no
int controller_listarJugadoresSinConvocados(LinkedList* pArrayListJugador)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		printf(" ID\tNOMBRE COMPLETO\t\tNUM CAMISETA\t\tPOSICION\t\t\tNACIONALIDAD\t\t\t SELECCION\n\n");
		jug_imprimirArrayJugSinCoconvocados(pArrayListJugador);
		retorno=0;
	}



    return retorno;

}

/// @fn int controller_ordenarJugadores(LinkedList*)
/// @brief
///
/// @param pArrayListJugador
/// @return
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{










    return 1;
}

/// @fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
/// @brief  guarda la lista de jugadores en un archivo en modo texto
///
/// @param path nombre del archivo
/// @param pArrayListJugador lista de jugadores
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int idAux;
	char nombreAux[50];
	int edadAux;
	char posicionAux[50];
	char nacionalidadAux[50];
	int idSeleccionAux;
	int cantidad;

	FILE* pFile;

	Jugador* jugAux;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pFile=fopen(path,"w");
		cantidad=ll_len(pArrayListJugador);
		fprintf(pFile,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
		for(int i=0;i<cantidad;i++)
		{
			jugAux=(Jugador*)ll_get(pArrayListJugador, i);
			if(jugAux!=NULL)
			{
				jug_getId(jugAux, &idAux);
				jug_getNombreCompleto(jugAux, nombreAux);
				jug_getEdad(jugAux, &edadAux);
				jug_getPosicion(jugAux, posicionAux);
				jug_getNacionalidad(jugAux, nacionalidadAux);
				jug_getSIdSeleccion(jugAux, &idSeleccionAux);
				fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",idAux,nombreAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux);
				retorno=0;

			}
		}
		fclose(pFile);

	}


	if(retorno==0)
	{
		printf("\n\n\tARCHIVO JUGADORES GUARDADO.\n\n");
	}





    return retorno;
}

/// @fn int controller_guardarJugadoresModoBinario(char*, LinkedList*)
/// @brief guarda la lista de jugadores en un archivo en modo binario
///
/// @param path nombre del archivo
/// @param pArrayListJugador lista de jugadores
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* unJugador;
	FILE* pFile = fopen(path,"wb");
	int cantidad;


	cantidad = ll_len(pArrayListJugador);

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		for(int i=0;i<cantidad;i++)
		{
			unJugador = ll_get(pArrayListJugador,i);
			if(unJugador != NULL)
			{
				fwrite(unJugador,sizeof(Jugador),1,pFile);
			}
		}
		retorno = 0;
		fclose(pFile);
	}else
	{
		printf("ERROR");
	}
	return retorno;

}

/// @fn int controller_guardarSeleccionesModoBinario(char*, LinkedList*)
/// @brief guarda la lista de selecciones en un archivo en modo binario
///
/// @param path nombre del archivo
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_guardarSeleccionesModoBinario(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* unaSeleccion;
	FILE* pFile = fopen(path,"wb");
	int cantidad;


	cantidad = ll_len(pArrayListSeleccion);

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		for(int i=0;i<cantidad;i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion,i);
			if(unaSeleccion != NULL)
			{
				fwrite(unaSeleccion,sizeof(Seleccion),1,pFile);
			}
		}
		retorno = 0;
		fclose(pFile);
	}else
	{
		printf("ERROR");
	}
    return retorno;



}

/// @fn int controller_listaConfeConvocados(LinkedList*, LinkedList*)
/// @brief crea una lista de jugadores que esten convocados de una confederacion que elije el usuario
/// 		guarda la lista en modo binario en un archivo y borra la lista auxiliar
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_listaConfeConvocados(LinkedList* pArrayListJugador , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	LinkedList* listaFiltrada;

	listaFiltrada=ll_newLinkedList();

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && listaFiltrada!=NULL)
	{
		retorno=0;
		jug_listaConvocadosConfe(pArrayListJugador, pArrayListSeleccion, listaFiltrada);

		controller_guardarJugadoresModoBinario("jugadoresFiltrados.bin", listaFiltrada);


	}

	ll_clear(listaFiltrada);
	ll_deleteLinkedList(listaFiltrada);

	return retorno;

}


/// @fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)
/// @brief carga la lista de selecciones desde un archivo de texto y la guarda en una lista de selecciones
///
/// @param path nombre del archivo
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE* pFile;


	pFile=fopen(path,"r");
	if(path!=NULL && pArrayListSeleccion!=NULL)
	{
		if(!parser_SeleccionFromText(pFile, pArrayListSeleccion))
		{
			retorno=0;
		}

		fclose(pFile);

	}

    return retorno;
}

/// @fn int controller_editarSeleccion(LinkedList*)
/// @brief
///
/// @param pArrayListSeleccion
/// @return
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{








    return 1;
}


/// @fn int controller_listarSelecciones(LinkedList*)
/// @brief imprime una lista de selecciones
///
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListSeleccion!=NULL)
	{
		printf(" ID\t\tPAIS\t\t\tCONFEDERACION\t\t\tCONVOCADOS\n\n");
		selec_imprimirArraySelecciones(pArrayListSeleccion);

		retorno=0;
	}



	return retorno;
}

/// @fn int controller_listarSelecConLugar(LinkedList*)
/// @brief imprime un listado de selecciones que tienen lugar para convocar jugadores
///
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_listarSelecConLugar(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListSeleccion!=NULL)
	{
		printf(" ID\t\tPAIS\t\t\tCONFEDERACION\t\t\tCONVOCADOS\n\n");
		selec_imprimirArraySelecConLugar(pArrayListSeleccion);

		retorno=0;
	}



	return retorno;

}

/// @fn int controller_ordenarSelecciones(LinkedList*)
/// @brief
///
/// @param pArrayListSeleccion
/// @return
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{







    return 1;
}

/// @fn int controller_guardarSeleccionesModoTexto(char*, LinkedList*)
/// @brief guarda la lista de selecciones en un archivo de texto
///
/// @param path nombre del archivo
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{

	int retorno=-1;
	int idAux;
	char paisAux[50];
	char confederacionAux[50];
	int convocadosAux;
	int cantidad;

	Seleccion* selecAux;
	FILE* pFile;

	if(path!=NULL && pArrayListSeleccion!=NULL)
	{
		cantidad=ll_len(pArrayListSeleccion);
		pFile=fopen(path,"w");
		fprintf(pFile,"id,pais,confederacion,convocados\n");
		for(int i=0;i<cantidad;i++)
		{
			selecAux=(Seleccion*)ll_get(pArrayListSeleccion, i);
			selec_getId(selecAux, &idAux);
			selec_getPais(selecAux, paisAux);
			selec_getConfederacion(selecAux, confederacionAux);
			selec_getConvocados(selecAux, &convocadosAux);

			fprintf(pFile,"%d,%s,%s,%d\n",idAux,paisAux,confederacionAux,convocadosAux);
			retorno=0;
		}

		fclose(pFile);
	}
	if(retorno==0)
	{
		printf("\n\n\t\tARCHIVO SELECCIONES GUARDADO.\n\n");
	}




    return retorno;
}

/// @fn void controller_menuListados(LinkedList*, LinkedList*)
/// @brief  despliega un menu para que el usurio elija que listado desea ver
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSeleccion lista de selecciones
void controller_menuListados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;

	do
	{
		utn_getNumero(&opcion, "\n\n\t\tMENU LISTADOS.\n\n1- TODOS LOS JUGADORES.\n2- TODAS LAS SELECCIONES.\n3- JUGADORES CONVOCADOS.\n4- SALIR.\nSELECCIONE LA OPCION DESEADA :", "\nERROR opciones 1-4\n", 1, 4, 10);

		switch(opcion)
		{
		case 1:
			controller_listarJugadoresCompleto(pArrayListJugador, pArrayListSeleccion);
			break;
		case 2:
			controller_listarSelecciones(pArrayListSeleccion);
			break;
		case 3:
			controller_listarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion);
			break;

		}

	}while(opcion!=4);
}

/// @fn int controller_convocarJugadores(LinkedList*, LinkedList*)
/// @brief  muestra una lista de jugadores que no estan convocados para queel usuario elija cual convocar
/// 		muestra una lista de selecciones con lugar para que el usuario elija en cual convocarlo
/// 		cambia la cantidad de convocados de la seleccion elegida
/// @param pArrayListJugador	lista de jugadores
/// @param pArrayListSeleccion lista de selecciones
/// @return retorna 0 si lo logra -1 si no lo logra
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int cantidadJug;
	Jugador* aux;
	int id;
	int idCompara;
	int idSelec;
	int cantidadSelec;
	int ultimoId;
	int idSelecCompara;


	cantidadJug=ll_len(pArrayListJugador);
	cantidadSelec=ll_len(pArrayListSeleccion);
	ultimoId=jug_ultimoId(pArrayListJugador);


	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		controller_listarJugadoresSinConvocados(pArrayListJugador);
		utn_getNumero(&id, "\nSeleccionar el ID del jugador a convocar :", "ERROR Intente nuevamente", 1, ultimoId, 10);
		for(int i=0;i<cantidadJug;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(aux, &idCompara);
			jug_getSIdSeleccion(aux, &idSelecCompara);
			if(idCompara==id && idSelecCompara==0)
			{
				selec_imprimirArraySelecConLugar(pArrayListSeleccion);
				utn_getNumero(&idSelec, "\nSeleccione el Id de la seleccion :", "\nERROR Intenete nuevamente", 1, cantidadSelec, 10);
				jug_setIdSeleccion(aux, idSelec);
				selec_AgregarConvocados(pArrayListSeleccion, idSelec);
				retorno=0;

			}

		}

	}




	return retorno;
}

/// @fn int controller_sacarDeLaSeleccion(LinkedList*, LinkedList*)
/// @brief  muestra una lista de los jugadores que estan convocados para que el usuario elija por ID
/// 		si lo encuentra pide confirmacion para eliminarlo de la lista
/// 		resta de la seleccion el jugador de los convocados
///
/// @param pArrayListJugador lista de jugadores
/// @param pArrayListSeleccion	lista de selecciones
/// @return
int controller_sacarDeLaSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int id;
	int cantidadJug;
	Jugador* aux;
	int idCompara;
	int idSelec;


	cantidadJug=ll_len(pArrayListJugador);


	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && !jug_imprimirArrayJugCoconvocados(pArrayListJugador, pArrayListSeleccion))
	{

		utn_getNumero(&id, "\nSeleccionar el ID del jugador a sacar de la seleccion :", "ERROR Intente nuevamente", 1, 1000, 10);
		for(int i=0;i<cantidadJug;i++)
		{
			aux=(Jugador*)ll_get(pArrayListJugador, i);
			jug_getId(aux, &idCompara);
			jug_getSIdSeleccion(aux, &idSelec);
			if(idCompara==id )
			{
				selec_SacarConvocados(pArrayListSeleccion, idSelec);
				idSelec=0;
				printf("\n%d",idSelec);
				jug_setIdSeleccion(aux, idSelec);
				jug_getSIdSeleccion(aux, &idSelec);
				printf("\n%d",idSelec);

				retorno=0;

			}

		}




	}
	else
	{
		printf("\n\n\tNO HAY JUGADORES CONVOCADOS.\n");
	}







	return retorno;
}

/// @fn void controller_menuConvocar(LinkedList*, LinkedList*)
/// @brief  menu de opciones para convocar o quitar jugadores
///
/// @param pArrayListJugador	lista de jugadores
/// @param pArrayListSeleccion	lista de selecciones
void controller_menuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;

	do
	{
		utn_getNumero(&opcion, "\n\n\t\tMENU CONVOCAR.\n\n1- CONVOCAR JUGADORES:\n2- QUITAR DE LA SELECCIÓN:\n3- SALIR.\n\nSELECCIONE UNA OPCION :", "\nERROR opciones 1-3", 1, 3, 10);

		switch(opcion)
		{
		case 1:
			if(controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion))
			{
				printf("\n\tJUGADOR NO ENCONTRADO\n");
			}
			break;
		case 2:
			if(controller_sacarDeLaSeleccion(pArrayListJugador, pArrayListSeleccion))
			{
				printf("\n\tJUGADOR NO ENCONTRADO\n");
			}

			break;
		}

	}while(opcion!=3);

}

/// @fn void controller_menuOrdenarListar(LinkedList*, LinkedList*)
/// @brief  muestra un menu de listados para que el usuario elija
///
/// @param pArrayListJugador	lista jugadores
/// @param pArrayListSeleccion	lista selecciones
void controller_menuOrdenarListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

	int opcion;


	do
	{
		utn_getNumero(&opcion, "\n\n\t\tMENU ORDENAR Y LISTAR.\n\n1- JUGADORES POR NACIONALIDAD.\n2- SELECCIONES POR CONFEDERACIÓN.\n3- JUGADORES POR EDAD.\n4- JUGADORES POR NOMBRE.\n5- SALIR\n\nSeleccione la opcion deseada :", "\nERROR opciones 1-5\n\n", 1, 5, 10);

		switch(opcion)
		{
		case 1:
			jug_ordenarNacionalidad(pArrayListJugador, pArrayListSeleccion);
			break;
		case 2:
			selec_ordenarConfederacion(pArrayListSeleccion);
			break;
		case 3:
			jug_ordenarEdad(pArrayListJugador, pArrayListSeleccion);
			break;
		case 4:
			jug_ordenarNombre(pArrayListJugador, pArrayListSeleccion);
			break;
		}

	}while(opcion!=5);



}

/// @fn int controller_confirmarSalir(LinkedList*, LinkedList*, int)
/// @brief  controla que los listados si fueron modificados se hayan guardado si no es asi avisa al usuario si los
/// 		quiere guardar y pide confirmacion apra salir
///
/// @param pArrayListJugador	lista jugadores
/// @param pArrayListSeleccion	lista selecciones
/// @param flag bandera para saber si los listados fueron modificados
/// @return	retorna 0 si lo logra -1 si no lo logra
int controller_confirmarSalir(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,int flag)
{
	int salida=0;
	int opcion;

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL && flag==0)
	{
		printf("\n\nNO SE GUARDARON LOS CAMBIOS EN LOS ARCHIVOS.\n\n");
		utn_getNumero(&opcion, "\nDESEA GUARDAR LOS CAMBIOS.\n\n1- SI.\n2- NO.\nSeleccione una opcion: ", "\n\nERROR opciones 1-2.", 1, 2, 10);
		switch(opcion)
		{
		case 1:
		    controller_guardarJugadoresModoTexto("jugadores.csv", pArrayListJugador);
		    controller_guardarSeleccionesModoTexto("selecciones.csv",pArrayListSeleccion);
		    salida=11;

			printf("\n\n                        GRACIAS POR USAR NUESTRO SISTEMA.                          \n");
			printf("\n                                VAMOS ARGENTINA.                          \n");

			break;
		case 2:
			salida=11;
			printf("\n\n                        GRACIAS POR USAR NUESTRO SISTEMA.                          \n");
			printf("\n                                VAMOS ARGENTINA.                          \n");
			break;
		}
	}
	else
	{
		utn_getNumero(&opcion, "\nDESEA SALIR DEL SISTEMA.\n\n1- SI.\n2- NO.\nSeleccione una opcion: ", "\n\nERROR opciones 1-2.", 1, 2, 10);
		switch(opcion)
		{
		case 1:
		    salida=11;
			printf("\n\n                        GRACIAS POR USAR NUESTRO SISTEMA.                          \n");
			printf("\n                                VAMOS ARGENTINA.                          \n");
			break;
		case 2:
			salida=0;
			break;
		}
	}


	return salida;
}


/// @fn void controller_menuPrincipal(LinkedList*, LinkedList*)
/// @brief  despliega menu de opciones principales
///
/// @param pArrayListJugador	lista jugadores
/// @param pArrayListSeleccion	lista selecciones
void controller_menuPrincipal(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	int flagGuardaArchivos=0;
	LinkedList* listaFiltrada = ll_newLinkedList();

	if(pArrayListJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		do
		{
			utn_getNumero(&opcion, "\t\tMENU PRINCIPAL.\n\n\n1- CARGA DE ARCHIVOS:\n2- ALTA DE JUGADOR:\n3- MODIFICACIÓN DE JUGADOR:\n4- BAJA DE JUGADOR:\n5- LISTADOS:\n6- CONVOCAR JUGADORES:\n7- ORDENAR Y LISTAR:\n8- GENERAR ARCHIVO BINARIO:\n9- CARGAR ARCHIVO BINARIO:\n10- GUARDAR ARCHIVOS .CSV:\n11- SALIR.\n\n SELECCIONE UNA OPCION: ", "ERROR Opciones 1-11", 1, 11, 10);

			switch(opcion)
			{
			case 1:
				if(!controller_cargarJugadoresDesdeTexto("jugadores.csv", pArrayListJugador) &&
						!controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccion))
				{

					printf("\nARCHIVOS CARGADOS EXITOSAMENTE.\n");
				}
				else
				{
					printf("\nERROR AL CARGAR LOS ARCHIVOS.\n");
				}
				break;
			case 2:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_agregarJugador(pArrayListJugador);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 3:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_editarJugador(pArrayListJugador);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}


				break;
			case 4:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					if(!controller_removerJugador(pArrayListJugador,pArrayListSeleccion))
					{
						printf("\t\nEL JUGADOR FUE ELIMINADO EXITOSAMENTE\n\n\n");
						flagGuardaArchivos=0;
					}
					else
					{
						printf("\t\nEL JUGADOR NO FUE ELIMINADO\n");
					}
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}


				break;
			case 5:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_menuListados(pArrayListJugador, pArrayListSeleccion);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 6:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_menuConvocar(pArrayListJugador, pArrayListSeleccion);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 7:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_menuOrdenarListar(pArrayListJugador, pArrayListSeleccion);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 8:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_listaConfeConvocados(pArrayListJugador, pArrayListSeleccion);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 9:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_cargarJugadoresDesdeBinario("jugadoresFiltrados.bin", listaFiltrada);
					controller_listarJugadoresCompleto(listaFiltrada, pArrayListSeleccion);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 10:
				if((ll_isEmpty(pArrayListJugador))==0 && (ll_isEmpty(pArrayListSeleccion))==0)
				{
					controller_guardarJugadoresModoTexto("jugadores.csv", pArrayListJugador);
					controller_guardarSeleccionesModoTexto("selecciones.csv",pArrayListSeleccion);
					flagGuardaArchivos=1;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 11:
				controller_confirmarSalir(pArrayListJugador, pArrayListSeleccion, flagGuardaArchivos);
				break;

			}

		}while(opcion!=11);

		ll_deleteLinkedList(listaFiltrada);
	}

}







