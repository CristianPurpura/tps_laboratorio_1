/*
 * informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Cris
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "confederaciones.h"
#include "jugadores.h"

/// @fn void RegionMasJugadores(eJugador[], eConfederaciones[], int, int)
/// @brief buscca la region que tenga mas jugadores y la imprime con su lista de jugadores en el caso de haber mas de
/// 		una region con la misma cantidad de jugadores loa visa
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void RegionMasJugadores(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void PorcentajeJugadorConfe(eJugador[], eConfederaciones[], int, int)
/// @brief imprime los porcentajes de jugadores por confederacion
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void PorcentajeJugadorConfe(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void ConfeMasAnios(eJugador[], eConfederaciones[], int, int)
/// @brief imprime la confederacion con mas años decontrato en el caso de haber mas de una con la misma cantidad lo avisa
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ConfeMasAnios(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void TotalPromedioSalario(eJugador[], eConfederaciones[], int, int)
/// @brief imprime el total de los sueldos el promedio y cantidad de jugadores que superan ese promedio
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void TotalPromedioSalario(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void ListadoConfeJugador(eJugador[], eConfederaciones[], int, int)
/// @brief   imprime de cada confederacion un listado de todos sus jugadores activos
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ListadoConfeJugador(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void ListadoAlfaConfeJugador(eJugador[], eConfederaciones[], int, int)
/// @brief ordena e imprime un listado ordenado alfaveticamente por confederaciones en el caso de repetirce ordena por nombre
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void ListadoAlfaConfeJugador(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);
/// @fn void MenuInformes(eJugador[], eConfederaciones[], int, int)
/// @brief imprime un menu de informes a seleccionar por el usuario
///
/// @param jugadores lista de jugadores
/// @param lista  lista de confederaciones
/// @param sizeJug tamaño de lista de jugadores
/// @param sizeConfe tamaño de lista de confederaciones
void MenuInformes(eJugador jugadores[],eConfederaciones lista[],int sizeJug,int sizeConfe);




#endif /* INFORMES_H_ */
