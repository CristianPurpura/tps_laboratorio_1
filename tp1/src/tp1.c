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
	float porcentajeAsia;
	float porcentajeAfrica;
	float porcentajeNorte;
	float porcentajeSudamerica;
	float porcentajeEuropa=0;
	float porcentajeOceania;
	int numeroCamiseta;
	int control;
	int opcionMenuPrincipal;
	int opcionMenuMantenimiento;
	int mantenimiento=0;
	int cantidadJugadores = 0;
	float mantenimientoIncrementado;
	int controlCalculos;
	float incremento=0;

	do
	{
		printf("\t\tMENU PRINCIPAL\n\n");
		printf("1. Ingreso de los constos de mantenimiento.\n");
		printf("Costo de Hospedaje -> %d\n",acumuladorHospedaje);
		printf("Costo de Comida -> %d\n",acumuladorComida);
		printf("Costo de Transporte -> %d\n\n",acumuladorTransporte);
		printf("2. Carga de jugadores.\n");
		printf("Arqueros -> %d\n",contadorArqueros);
		printf("Defensores -> %d\n",contadorDefensores);
		printf("Mediocampistas -> %d\n",contadorMediocampistas);
		printf("Delanteros -> %d\n\n",contadorDelanteros);
		printf("3. Realizar todos los calculos.\n\n");
		printf("4. Mostrar los resultados.\n\n");
		printf("5. Salir.\n\n");
		printf("Elija una opcion :");
		scanf("%d",&opcionMenuPrincipal);

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
					control = cargaGastoHospedaje(&acumuladorHospedaje);
					while(control!=0)
					{
						printf("Error por favor cargar los datos nuevamente.\n");
						control = cargaGastoHospedaje(&acumuladorHospedaje);
					}
					break;
				case 2:
					fflush(stdin);
					control = cargaGastoComida(&acumuladorComida);
					while(control!=0)
					{
						printf("Error por favor cargar los datos nuevamente.\n");
						control = cargaGastoComida(&acumuladorComida);
					}
					break;
				case 3:
					fflush(stdin);
					control = cargaGastoTransporte(&acumuladorTransporte);
					while(control!=0)
					{
						printf("Error por favor cargar los datos nuevamente.\n");
						control = cargaGastoTransporte(&acumuladorTransporte);
					}
					break;

				}
				mantenimiento = acumuladorComida+acumuladorHospedaje+acumuladorTransporte;

			}while(opcionMenuMantenimiento!=4);
			break;
		case 2:
			if(cantidadJugadores<=22)
			{
				fflush(stdin);
				control = cargaNumeroCamiseta(&numeroCamiseta);
				while(control!=0)
				{
					printf("Error por favor cargar los datos nuevamente.\n");
					control = cargaNumeroCamiseta(&numeroCamiseta);
				}

				fflush(stdin);
				control = cargaPosicion(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros);
				while(control!=0)
				{
					printf("Error por favor cargar los datos nuevamente.\n");
					control = cargaPosicion(&contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros);
				}

				fflush(stdin);
				control = cargaConfederacion(&contadorAsia, &contadorAfrica, &contadorNorte, &contadorSudamerica, &contadorEuropa, &contadorOceania);
				while(control!=0)
				{
					printf("Error por favor cargar los datos nuevamente.\n");
					control = cargaConfederacion(&contadorAsia, &contadorAfrica, &contadorNorte, &contadorSudamerica, &contadorEuropa, &contadorOceania);
				}
				cantidadJugadores++;
			}




			break;
		case 3:

			controlCalculos = calculos(&contadorAsia, &contadorAfrica, &contadorNorte, &contadorSudamerica, &contadorEuropa, &contadorOceania, &cantidadJugadores, &porcentajeAsia, &porcentajeAfrica, &porcentajeNorte, &porcentajeSudamerica, &porcentajeEuropa, &porcentajeOceania, &mantenimiento, &mantenimientoIncrementado, &incremento);

			if(controlCalculos != 0)
			{
				printf("\n\nError no hay suficientes datos cargados.\n\n ");
				break;
			}

			break;
		case 4:
			if(controlCalculos!= 0)
			{
				printf("\n\nError no se realizaron los calculos aun.\n\n ");
				break;
			}
			else
			{
				printf("\t\tInformar todos los resultados\n\n");
				printf("Porcentaje AFC es  %.2f\n", porcentajeAsia);
				printf("Porcentaje CAF es  %.2f\n", porcentajeAfrica);
				printf("Porcentaje CONCACAF es  %.2f\n", porcentajeNorte);
				printf("Porcentaje CONMEBOL es  %.2f\n", porcentajeSudamerica);
				printf("Porcentaje UEFA es  %.2f\n", porcentajeEuropa);
				printf("Porcentaje OFC es  %.2f\n", porcentajeOceania);
				if(incremento>0)
				{
					printf("El consto de mantenimiento era de %d y recibio un aumento de %.2f, su nuevo valos es de: %.2f \n",mantenimiento,incremento,mantenimientoIncrementado);
				}
				else
				{
					printf("El conto de mantenimiento es de : %d\n", mantenimiento);
				}
			}



		break;




		}

	}while(opcionMenuPrincipal!=5);




	return EXIT_SUCCESS;
}
