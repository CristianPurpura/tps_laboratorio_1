#include "LinkedList.h"
#include <string.h>

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);


int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int selec_imprimirUnaSeleccion(Seleccion* unaSeleccion);
int selec_imprimirArraySelecciones(LinkedList* pArrayListSelecciones);
int selec_imprimirArraySelecConLugar(LinkedList* pArrayListSelecciones);

int selec_AgregarConvocados(LinkedList* pArrayListSelecciones,int idSelec);
int selec_SacarConvocados(LinkedList* pArrayListSelecciones,int idSelec);

int selec_criterioConfederacion(void* seleccion1,void* seleccion2);
int selec_ordenarConfederacion(LinkedList* pArrayListSelecciones);





#endif // selec_H_INCLUDED
