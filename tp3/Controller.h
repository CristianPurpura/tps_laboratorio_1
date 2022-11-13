





int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSelecciones);

int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_listarJugadoresCompleto(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_listarJugadoresSinConvocados(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_guardarSeleccionesModoBinario(char* path , LinkedList* pArrayListSeleccion);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_listarSelecConLugar(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

int controller_listaConfeConvocados(LinkedList* pArrayListJugador , LinkedList* pArrayListSeleccion);


int controller_confirmarSalir(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,int flag);
void controller_menuOrdenarListar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
void controller_menuListados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
void controller_menuConvocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
void controller_menuPrincipal(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);




