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

int main(void) {

	int gasto=0;
	int acumuladorHospedaje=0;



	acumuladorHospedaje = cargaGastoHospedaje(gasto);

	printf("%d",acumuladorHospedaje);

	return EXIT_SUCCESS;
}
