#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int cargaGastoHospedaje(int* acumulador)
{

	int control=1;
	int gasto;
	control = utn_getNumero(&gasto, "\nIngrese el gasto de hospedaje :", "\nError el gasto no puede ser menor a 0 :", 0, 10000, 2);

	if(control==0)
	{
		acumulador+= gasto;
		control=0;
	}





	return control;
}

