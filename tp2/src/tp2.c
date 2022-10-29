/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include "utn.h"
#include "confederaciones.h"
#include "informes.h"


#define TAM 15
#define CONF 6

int main(void) {
	setbuf(stdout,NULL);

	eJugador jugadores[TAM]={{1,"Leo Messi","Delantero",10,103,50000000,1,1},
			{2,"Beo Messi","Delantero",5,100,5000000,5,1},
			{3,"Aeo Messi","Delantero",2,100,4000000,2,1},
			{4,"Leo Messaaaaai","Delantero",12,102,8000000,12,1},
			{5,"Ceo Messi","Delantero",4,102,70040000,7,1},
			{6,"Aeo Messi","Delantero",3,104,5000000,3,1},
			{7,"Aeo Messi","Delantero",9,101,500012000,9,1},
			{8,"Leo Messi","Delantero",1,101,2000000,10,1},
			{9,"Aeo Messi","Delantero",8,105,30040000,8,1},
			{10,"Leo Messi","Delantero",14,103,5000000,4,1},};
	eConfederaciones confederaciones[CONF] = {{100,"CONMEBOL","SUDAMERICA",1916,1},
												{101,"UEFA","EUROPA",1954,1},
												{102,"AFC","ASIA",1954,1},
												{103,"CAF","AFRICA",1957,1},
												{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961,1},
												{105,"OFC","OCEANIA",1966,1}};
	int idJugador;
	int opcion;
	int confirmacion;
//	int opcInformes;


	idJugador=10;
	InicializarJugadores(jugadores, TAM);
//	ListadoAlfaConfeJugador(jugadores, confederaciones, TAM, CONF);
//	MotrarJugadoresCompleto(jugadores, confederaciones, TAM, CONF);

	do
	{
		utn_getNumero(&opcion, "\t\tSISTEMA DE JUGADORES DE LA AFA\n\n1- ALTA DE JUGADOR: \n2- BAJA DE JUGADOR: \n3- MODIFICACION DE JUGADOR: \n4- INFORMES:\n5- SALIR:\n \nSELECCIONAR LA OPCION DESEADA: ", "ERROR Opciones entre 1-5\n", 1, 5, 10);


		switch(opcion)
		{
		case 1:
			idJugador++;
			AltaJugador(jugadores, confederaciones, TAM, idJugador,CONF);

			break;
		case 2:
			if(idJugador==0)
			{
				printf("ERROR No se ingreso ningun jugador\n");
				break;
			}
			BajaJugador(jugadores, TAM);
			break;


			break;
		case 3:
			if(idJugador==0)
			{
				printf("ERROR No se ingreso ningun jugador\n");
				break;
			}
			ModificarJugador(jugadores, confederaciones, TAM,CONF);
			break;
		case 4:
			if(idJugador==0)
			{
				printf("ERROR No se ingreso ningun jugador\n");
				break;
			}
			MenuInformes(jugadores, confederaciones, TAM, CONF);

			break;
		case 5:
			utn_getNumero(&confirmacion, "ESTA SEGURO QUE DESEA SALIR.\n1-SI.\n2-NO\nSelecciones la opcion deseada: ", "ERROR \n1-SI.\n2-NO\n ", 1, 2, 10);
			if(confirmacion == 1)
			{
				opcion=6;

				printf("\n\n\t\tGRACIAS POR USAR SISTEMA DE JUGADORES DE LA AFA ");

				system("PAUSE");
			}

			break;

		}
	}while(opcion !=6);



//











	/*MostrarConfederaciones(confederaciones);


	printf("  ========================================================================================\n");
	printf(" | ID   |        NOMBRE       |            REGION                  |     ANIO DE CREACION |  \n  ");
	printf("----------------------------------------------------------------------------------------\n");
	for(int i=0;i<CONF;i++)
	{
		printf(" |  %-4d|      %-15s| %-35s|%15d       |\n",confederaciones[i].id,confederaciones[i].nombre,confederaciones[i].region,confederaciones[i].aniosCreacion);
	}
	printf("  ========================================================================================\n");  */


	return EXIT_SUCCESS;
}
