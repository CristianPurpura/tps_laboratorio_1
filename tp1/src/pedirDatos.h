/*
 * pedirDatos.h
 *
 *  Created on: 17 sep. 2022
 *      Author: Cris
 */

#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_
/// @fn int cargaGastoHospedaje(int*)
/// @brief recibe y devuelve un contador
///
/// @param acumulador
/// @return retorna 0 si se puedo incrementar el contador , 1 si no se puedo incrementar

int cargaGastoHospedaje(int* acumulador);



/// @fn int cargaGastoComida(int*)
/// @brief recibe y devuelve un contador
///
/// @param acumulador
/// @returnretorna 0 si se puedo incrementar el contador , 1 si no se puedo incrementar

int cargaGastoComida(int* acumulador);



/// @fn int cargaGastoTransporte(int*)
/// @brief recibe y devuelve un contador
///
/// @param acumulador
/// @returnretorna 0 si se puedo incrementar el contador , 1 si no se puedo incrementar

int cargaGastoTransporte(int* acumulador);


/// @fn int cargaNumeroCamiseta(int*)
/// @brief carga un numero validad entre 2 rangos a una variable
///
/// @param numeroCamiseta
/// @return retorna 0 si se puedo cargar el dato y 1 si no se puedo

int cargaNumeroCamiseta (int* numeroCamiseta);

/// @fn int cargaPosicion(int*, int*, int*, int*)
/// @brief recibe 4 contadores valida la carga detro de ellos dependiendo de un menu de opciones retorna 4 contadores
///
/// @param contador1
/// @param contador2
/// @param contador3
/// @param contador4
/// @return retorna 0 si se puedo realizar la carga y 1 si no se puedo

int cargaPosicion (int* contador1, int* contador2, int* contador3, int* contador4);

/// @fn int cargaConfederacion(int*, int*, int*, int*, int*, int*)
/// @brief recibe 6 contadores valida la carga detro de ellos dependiendo de un menu de opciones retorna 6 contadores
///
/// @param contador1
/// @param contador2
/// @param contador3
/// @param contador4
/// @param contador5
/// @param contador6
/// @return retorna 0 si se puedo realizar la carga y 1 si no se puedo

int cargaConfederacion (int* contador1, int* contador2, int* contador3, int* contador4, int* contador5, int* contador6);


#endif /* PEDIRDATOS_H_ */
