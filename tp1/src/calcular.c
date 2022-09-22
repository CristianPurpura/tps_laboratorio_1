/*
 * calcular.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Cris
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int calculos(int* contador1, int* contador2, int* contador3, int* contador4, int* contador5, int* contador6, int* contador7,float* promedioUno, float* promedioDos,float* promedioTres,float* promedioCuatro,float* promedioCinco,float* promedioSeis, int* mantenimiento, float* mantenimientoIncrementado, float* incremento)
{
	int retorno = 1;

	*incremento= 0;
	if(*mantenimiento != 0 && *contador7 != 0)
	{
		*promedioUno = (float) *contador1  / *contador7;
		*promedioDos = (float) *contador2  / *contador7;
		*promedioTres = (float) *contador3  / *contador7;
		*promedioCuatro = (float) *contador4  / *contador7;
		*promedioCinco = (float) *contador5  / *contador7;
		*promedioSeis = (float) *contador6  / *contador7;

		if(*promedioCinco > *promedioUno && *promedioCinco>*promedioDos && *promedioCinco>*promedioTres && *promedioCinco>*promedioCuatro && *promedioCinco>*promedioSeis)
		{
			*incremento= *mantenimiento * 0.35;
			*mantenimientoIncrementado = *mantenimiento + *incremento;
		}

		printf("\n\n\n LOS CALCULOS SE REALIZARON EXITOSAMENTE\n\n\n");

		retorno = 0;

	}


	return retorno;
}
