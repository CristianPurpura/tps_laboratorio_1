/*
 * calcular.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Cris
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int calculos(int* contador1, int* contador2, int* contador3, int* contador4, int* contador5, int* contador6, int* contador7,float* porcentaje1, float* porcentaje2,float* porcentaje3,float* porcentaje4,float* porcentaje5,float* porcentaje6, int* mantenimiento, float* mantenimientoIncrementado, float* incremento)
{
	int retorno = 1;
	if(*mantenimiento != 0 && *contador7 != 0)
	{
		*porcentaje1 = (float) *contador1 *100 / *contador7;
		*porcentaje2 = (float) *contador2 *100 / *contador7;
		*porcentaje3 = (float) *contador3 *100 / *contador7;
		*porcentaje4 = (float) *contador4 *100 / *contador7;
		*porcentaje5 = (float) *contador5 *100 / *contador7;
		*porcentaje6 = (float) *contador6 *100 / *contador7;

		if(*porcentaje5>51)
		{
			*incremento= *mantenimiento * 0.35;
			*mantenimientoIncrementado = *mantenimiento + *incremento;
		}

		printf("\n\n LOS CALCULOS SE REALIZARON EXITOSAMENTE\n\n");

		retorno = 0;

	}


	return retorno;
}
