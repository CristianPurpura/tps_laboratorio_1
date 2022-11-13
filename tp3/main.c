#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);


	LinkedList* listaJugadores = ll_newLinkedList();
	LinkedList* listaSelecciones = ll_newLinkedList();



	controller_menuPrincipal(listaJugadores, listaSelecciones);




    return 0;
}

