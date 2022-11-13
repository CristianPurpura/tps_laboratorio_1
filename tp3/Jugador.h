#include "LinkedList.h"
#include <string.h>

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_imprimirUnJugador(Jugador* unJugador);
int jug_imprimirArrayJugadores(LinkedList* pArrayListJugador);

int jug_ElegirPosicion(char* posicion);
int jug_nuevoId(char* patch);
int jug_ultimoId(LinkedList* pArrayListJugador);


int jug_criterioNacionalidad(void* jugador1,void* jugador2);
int jug_criterioNombre(void* jugador1,void* jugador2);
int jug_criterioEdad(void* jugador1,void* jugador2);
int jug_ordenarNacionalidad(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int jug_ordenarNombre(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int jug_ordenarEdad(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int jug_imprimirUnJugCompleto(Jugador* unJugador,char* seleccion);
int jug_imprimirArrayJugCompleto(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones);
int jug_imprimirArrayJugCoconvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones);
int jug_imprimirArrayJugSinCoconvocados(LinkedList* pArrayListJugador);

int jug_listaConvocadosConfe(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones,LinkedList* listaFiltrada);




#endif // jug_H_INCLUDED
