/*
 ============================================================================
 Name        : tps_laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedirDatos.h"
#include "calcular.h"

int main(void) {

	setbuf(stdout,NULL);


	int acumuladorHospedaje=0;
	int acumuladorComida=0;
	int acumuladorTransporte=0;
	int contadorArqueros=0;
	int contadorDefensores=0;
	int contadorMediocampistas=0;
	int contadorDelanteros=0;
	int contadorAsia=0;
	int contadorAfrica=0;
	int contadorNorte=0;
	int contadorSudamerica=0;
	int contadorEuropa=0;
	int contadorOceania=0;
	float promedioAsia;
	float promedioAfrica;
	float promedioNorte;
	float promedioSudamerica;
	float promedioEuropa;
	float promedioOceania;
	int numeroCamiseta;
	int control;
	int opcionMenuPrincipal;
	int opcionMenuMantenimiento;
	int mantenimiento=0;
	int cantidadJugadores = 0;
	float mantenimientoIncrementado;
	int controlCalculos;
	float incremento=0;
	int controlHospedaje;
	int controlComida;
	int controlTransporte;
	int controlMenuPrincipal;

	do
	{
		printf("\t\tMENU PRINCIPAL\n\n");
		printf("1. Ingreso de los constos de mantenimiento.\n");
		printf("\n\tCosto de Hospedaje -> $ %d\n",acumuladorHospedaje);
		printf("\tCosto de Comida -> $ %d\n",acumuladorComida);
		printf("\tCosto de Transporte -> $ %d\n\n",acumuladorTransporte);
		printf("2. Carga de jugadores.\n");
		printf("\n\tArqueros -> %d\n",contadorArqueros);
		printf("\tDefensores -> %d\n",contadorDefensores);
		printf("\tMediocampistas -> %d\n",contadorMediocampistas);
		printf("\tDelanteros -> %d\n\n",contadorDelanteros);
		printf("3. Realizar todos los calculos.\n\n");
		printf("4. Mostrar los resultados.\n\n");
		printf("5. Salir.\n\n");
		controlMenuPrincipal = utn_getNumero(&opcionMenuPrincipal, "Elija una opcion :", "\nERROR opciones entre 1-5\n", 1, 5, 5);
		while(controlMenuPrincipal==-1)
		{
			controlMenuPrincipal = utn_getNumero(&opcionMenuPrincipal, "Elija una opcion :", "\n ERROR opciones entre 1-5", 1, 5, 5);
		}

		switch(opcionMenuPrincipal)
		{
		case 1:
			do
			{
				printf("\t\tMENU CARGA GASTOS DE MANTENIMIENTO\n\n");
				printf("1. Costo Hospedaje.\n");
				printf("2. Costo de Comida.\n");
				printf("3 .Costo de Transporte.\n");
				printf("4. Salir.\n");
				printf("Elija una opcion : ");
				scanf("%d",&opcionMenuMantenimiento);


				switch(opcionMenuMantenimiento)
				{
				case 1:
					fflush(stdin);
					controlHospedaje = cargaGastoHospedaje(&acumuladorHospedaje);
					while(controlHospedaje!=0)
					{
						printf("\n\tERROR por favor cargar los datos nuevamente.\n");
						controlHospedaje = cargaGastoHospedaje(&acumuladorHospedaje);
					}
					break;
				case 2:
					fflush(stdin);
					controlComida = cargaGastoComida(&acumuladorComida);
					while(controlComida!=0)
					{
						printf("\n\tERROR por favor cargar los datos nuevamente.\n");
						controlComida = cargaGastoComida(&acumuladorComida);
					}
					break;
				case 3:
					fflush(stdin);
					controlTransporte = cargaGastoTransporte(&acumuladorTransporte);
					while(controlTransporte!=0)
					{
						printf("\n\tERRORr por favor cargar los datos nuevamente.\n");
						controlTransporte = cargaGastoTransporte(&acumuladorTransporte);
					}
					break;
				case 4:
					if(controlHospedaje ==0 && controlComida==0 && controlTransporte==0 )
					{
						break;
					}
					if(controlHospedaje!=0)
					{
						printf("\nFalta ingresar el gasto de Hospedaje. \n");
						opcionMenuMantenimiento = 0;
					}
					if(controlComida!=0)
					{
						printf("\nFalta ingresar el gasto de Comida. \n");
						opcionMenuMantenimiento = 0;
					}
					if(controlTransporte!=0)
					{
						printf("\nFalta ingresar el gasto de Transporte. \n");
						opcionMenuMantenimiento = 0;
					}
					break;

				}
				mantenimiento = acumuladorComida+acumuladorHospedaje+acumuladorTransporte;
				if(controlHospedaje ==0 && controlComida==0 && controlTransporte==0 )
				{
					controlHospedaje=1;
					controlComida=1;
					controlTransporte=1;
					break;
				}


			}while(opcionMenuMantenimiento!=4);
			break;
		case 2:
			if(cantidadJugadores<22)
			{
				fflush(stdin);
				control = cargaNumeroCamiseta(&numeroCamiseta);
				while(control!=0)
				{
					printf("\n\tERROR por favor cargar los datos nuevamente.\n");
					control = cargaNumeroCamiseta(&numeroCamiseta);
				}

				fflush(stdin);
				control = cargaPosicion(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros);
				while(control!=0)
				{
					printf("\n\tERROR por favor cargar los datos nuevamente.\n");
					control = cargaPosicion(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros);
				}

				fflush(stdin);
				control = cargaConfederacion(&contadorAsia, &contadorAfrica, &contadorNorte, &contadorSudamerica, &contadorEuropa, &contadorOceania);
				while(control!=0)
				{
					printf("\n\tERROR por favor cargar los datos nuevamente.\n");
					control = cargaConfederacion(&contadorAsia, &contadorAfrica, &contadorNorte, &contadorSudamerica, &contadorEuropa, &contadorOceania);
				}
				cantidadJugadores++;
			}
			else
			{
				printf("\nYa se cargaron todos los jugadores posibles. \n\n");
			}




			break;
		case 3:

			controlCalculos = calculos(contadorAsia, contadorAfrica, contadorNorte, contadorSudamerica, contadorEuropa, contadorOceania, cantidadJugadores, &promedioAsia, &promedioAfrica, &promedioNorte, &promedioSudamerica, &promedioEuropa, &promedioOceania, mantenimiento, &mantenimientoIncrementado, &incremento);

			if(controlCalculos != 0)
			{
				printf("\n\n\tERROR no hay suficientes datos cargados.\n\n ");
				break;
			}

			break;
		case 4:
			if(controlCalculos!= 0)
			{
				printf("\n\n\tERROR no se realizaron los calculos aun.\n\n ");
				break;
			}
			else
			{
				printf("\t\tInformar todos los resultados\n\n");
				printf("Promedio AFC(Asia) es  %.2f\n", promedioAsia);
				printf("Promedio CAF(Africa) es  %.2f\n", promedioAfrica);
				printf("Promedio CONCACAF(Norte) es  %.2f\n", promedioNorte);
				printf("Promedio CONMEBOL(Sudamerica) es  %.2f\n", promedioSudamerica);
				printf("Promedio UEFA(Europa) es  %.2f\n", promedioEuropa);
				printf("Promedio OFC(Oceania) es  %.2f\n", promedioOceania);
				if(incremento>0)
				{
					printf("\nEl consto de mantenimiento era de %d y recibio un aumento de %.2f, su nuevo valos es de: %.2f \n",mantenimiento,incremento,mantenimientoIncrementado);
				}
				else
				{
					printf("\nEl costo de mantenimiento es de : %d\n", mantenimiento);
				}
			}



			break;




		}

	}while(opcionMenuPrincipal!=5);




	return EXIT_SUCCESS;
}
