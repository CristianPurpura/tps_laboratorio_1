#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int cargaGastoHospedaje(int* acumulador)
{

	int control = 1;
	int gasto;
	control = utn_getNumero(&gasto,"Ingrese el gasto de hospedaje :","Error el gasto no puede ser menor a 0 \n", 1, 10000, 1);

	if(control==0)
	{
		*acumulador+= gasto;
		control=0;
	}





	return control;
}

int cargaGastoComida(int* acumulador)
{

	int control = 1;
	int gasto;
	control = utn_getNumero(&gasto,"Ingrese el gasto de comida :","Error el gasto no puede ser menor a 0 \n", 1, 10000, 1);

	if(control==0)
	{
		*acumulador+= gasto;
		control=0;
	}





	return control;
}

int cargaGastoTransporte(int* acumulador)
{

	int control = 1;
	int gasto;
	control = utn_getNumero(&gasto,"Ingrese el gasto de transporte :","Error el gasto no puede ser menor a 0 \n", 1, 10000, 1);

	if(control==0)
	{
		*acumulador+= gasto;
		control=0;
	}





	return control;
}

int cargaNumeroCamiseta (int* numeroCamiseta)
{
	int control = 1;
	int buffer;
	control = utn_getNumero(&buffer,"Ingrese el numero de camiseta :","Error numero entre 1 y 50 \n", 1, 50, 1);

	if(control==0)
	{
		*numeroCamiseta+= buffer;
		control=0;
	}


	return control;
}

int cargaPosicion (int* contador1, int* contador2, int* contador3, int* contador4)
{
	int control = 1;
	int buffer;


	control = utn_getNumero(&buffer, "Ingrese la posicion\n 1(Arqueros)\n 2(Defensores)\n 3(Mediocampistas)\n 4(Delanteros)\n Elija una opcion : ", "Error posicion no valida 1-4\n", 1, 4, 1);

	if(control==0)
	{
		switch(buffer)
		{
		case 1:
			if(*contador1<2)
			{
				*contador1= *contador1 + 1;
			}
			else
			{
				printf("Posicion llena elija otra.\n");
				control = 1;

			}
			break;
		case 2:
			if(*contador2<8)
			{
				*contador2= *contador2 + 1;
			}
			else
			{
				printf("Posicion llena elija otra.\n");
				control = 1;
			}
			break;
		case 3:
			if(*contador3<8)
			{
				*contador3= *contador3 + 1;
			}
			else
			{
				printf("Posicion llena elija otra.\n");
				control = 1;
			}
			break;
		case 4:
			if(*contador4<4)
			{
				*contador4= *contador4 + 1;
			}
			else
			{
				printf("Posicion llena elija otra.\n");
				control = 1;
			}
			break;

		}


	}



	return control;
}

int cargaConfederacion (int* contador1, int* contador2, int* contador3, int* contador4, int* contador5, int* contador6)
{
	int control = 1;
	int buffer;


	control = utn_getNumero(&buffer, "Ingrese la confederacion\n 1(AFC)\n 2(CAF)\n 3(CONCACAF)\n 4(CONMEBOL)\n 5(UEFA)\n 6(OFC)\n Elija una opcion : ", "Error confederacion no valida 1-6\n", 1, 6, 1);

	if(control==0)
	{
		switch(buffer)
		{
		case 1:
			*contador1= *contador1 + 1;

			break;
		case 2:
			*contador2= *contador2 + 1;

			break;
		case 3:
			*contador3= *contador3 + 1;

			break;
		case 4:
			*contador4= *contador4 + 1;

			break;
		case 5:
			*contador5= *contador5 + 1;

			break;
		case 6:
			*contador6= *contador6 + 1;

			break;

		}


	}



	return control;
}

