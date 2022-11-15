#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"

int main()
{
	setbuf(stdout,NULL);

	int opcion;
	int flagGuardaArchivos=0;
	int flagArchivoBin=0;


	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaSelecciones = ll_newLinkedList();
	LinkedList* listaFiltrada = ll_newLinkedList();



	if(listaJugadores!=NULL && listaSelecciones!=NULL)
	{
		do
		{
			utn_getNumero(&opcion, "\t\tMENU PRINCIPAL.\n\n\n1- CARGA DE ARCHIVOS:\n2- ALTA DE JUGADOR:\n3- MODIFICACIÓN DE JUGADOR:\n4- BAJA DE JUGADOR:\n5- LISTADOS:\n6- CONVOCAR JUGADORES:\n7- ORDENAR Y LISTAR:\n8- GENERAR ARCHIVO BINARIO:\n9- CARGAR ARCHIVO BINARIO:\n10- GUARDAR ARCHIVOS .CSV:\n11- SALIR.\n\n SELECCIONE UNA OPCION: ", "ERROR Opciones 1-11", 1, 11, 10);

			switch(opcion)
			{
			case 1:
				if(!controller_cargarJugadoresDesdeTexto("jugadores.csv", listaJugadores) &&
						!controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones))
				{

					printf("\nARCHIVOS CARGADOS EXITOSAMENTE.\n");
				}
				else
				{
					printf("\nERROR AL CARGAR LOS ARCHIVOS.\n");
				}
				break;
			case 2:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_agregarJugador(listaJugadores);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 3:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_editarJugador(listaJugadores);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}


				break;
			case 4:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					if(!controller_removerJugador(listaJugadores,listaSelecciones))
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
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_menuListados(listaJugadores, listaSelecciones);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 6:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_menuConvocar(listaJugadores, listaSelecciones);
					flagGuardaArchivos=0;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 7:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_menuOrdenarListar(listaJugadores, listaSelecciones);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 8:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_listaConfeConvocados(listaJugadores, listaSelecciones);
					flagArchivoBin=1;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 9:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0 && flagArchivoBin==1)
				{
					controller_cargarJugadoresDesdeBinario("jugadoresFiltrados.bin", listaFiltrada);
					controller_listarJugadoresCompleto(listaFiltrada, listaSelecciones);
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 10:
				if((ll_isEmpty(listaJugadores))==0 && (ll_isEmpty(listaSelecciones))==0)
				{
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
					flagGuardaArchivos=1;
				}
				else
				{
					printf("\t\t\nPOR FAVOR CARGAR PRIMERO LOS ARCHIVOS\n\n");
				}

				break;
			case 11:
				controller_confirmarSalir(listaJugadores, listaSelecciones, flagGuardaArchivos);
				break;

			}

		}while(opcion!=11);

		ll_deleteLinkedList(listaFiltrada);



		ll_deleteLinkedList(listaJugadores);
		ll_deleteLinkedList(listaSelecciones);

	}


	return 0;
}

