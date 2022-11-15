
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @fn int esNumerica(char*, int)
/// @brief valida que la cadena sea numerica
///
/// @param cadena cadena de caracteres a validar
/// @param tam tamaño de la cadena
/// @return 1 si es numerico 0 si no lo es

int esNumerica(char* cadena,int tam)
{
	int retorno = 1;
	int i = 0;
	if(cadena != NULL && tam > 0)
	{
		if(cadena[i] == '-' )
		{
			i = 1;
		}
		for(;cadena[i] != '\0';i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9' ){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/// @fn int myGets(char*, int)
/// @brief lee desdde el teclado hasta \n o hasta el limite de la cadena -1
///
/// @param cadena copia la cadena en un puntero
/// @param tam define el tamaño de cadena
/// @return 0  si se obtiene una cadena y -1  si no

int myGets(char* cadena, int tam)
{
	int retorno = -1;
	char buffer[4096];

	if(cadena != NULL && tam > 0)
	{
		fflush(stdin);
		if(fgets(buffer,sizeof(buffer),stdin) != NULL)
		{
			if(buffer[strnlen(buffer,sizeof(buffer))-1] == '\n')
			{
				buffer[strnlen(buffer,sizeof(buffer))-1] = '\0';
			}
			if(strlen(buffer) <= tam)
			{
				strncpy(cadena,buffer,tam);
				retorno = 0;
			}
		}

	}
	return retorno;
}


/// @fn int getInt(int*)
/// @brief pide una cadena por teclado valida que sea numerica y la convierte a entero
///
/// @param pResultado puntero a un entero
/// @return 1 si logra devolver el entero 0 si no

int getInt(int* pResultado)
{
	int retorno = 0;
	char buffer[64];
	if(pResultado != NULL)
	{

		if(!myGets(buffer,sizeof(buffer)) && esNumerica(buffer,sizeof(buffer)))
		{
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief pide un numero entero con rango
///
/// @param pResultado puntero a la variable donde se guarda el valor ingresado
/// @param mensaje mensaje para el usuario pidiendo el ingreso de datos
/// @param mensajeError mensaje que imprime si el rango no es valido
/// @param minimo valor minimo del rango
/// @param maximo valor maximo del rango
/// @param reintentos cantidad de veces que el usuario puede equivocarce
/// @return 0 si no hay error 1 si hay error


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	int control;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			control = getInt(&buffer);
			if(control == 1 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/// @fn int esFlotante(char*, int)
/// @brief valida si la cadena ingresada es flotante
///
/// @param cadena cadena de caracteres a ser validada
/// @param tam tamaño de la cadena
/// @return 1 si la cadena es flotante , 0  si no es numerico o tiene mas de un '.' y -1 en caso de ERROR de parametro

int esFlotante(char* cadena,int tam)
{
	int retorno = -1;
	int i = 0;
	int contadorDePuntos = 0;

	if(cadena != NULL && tam > 0)
	{
		retorno = 1;
		if(cadena[0] != '-')
		{
			i = 1;
		}
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
			if(cadena[i] == '.')
			{
				contadorDePuntos++;
				if(contadorDePuntos > 1){
					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}

/// @fn int getFloat(float*)
/// @brief  verifica si la cadena es nuero flotante y la convierte a flotante
///
/// @param pFloat puntero a variable flotante
/// @return 1 si salio bien 0 si no

int getFloat(float* pFloat)
{
	int retorno = 0;
	char bufferFloat[64];
	if(pFloat != NULL)
	{
		fflush(stdin);

		if(!myGets(bufferFloat,sizeof(bufferFloat)) && esFlotante(bufferFloat,sizeof(bufferFloat)))
		{
			*pFloat = atof(bufferFloat);
			retorno = 1;
		}
	}
	return retorno;
}


/// @fn int utn_getNumeroFloat(float*, char*, char*, float, float, int)
/// @brief pide un numero flotante lo valida y lo devuelve
///
/// @param pResultado puntero a variable donde se guarda el resultado
/// @param mensaje mensaje pidiendo el ingreso
/// @param mensajeError mensaje de rango no valido
/// @param minimo valor minimo
/// @param maximo valor maximo
/// @param reintentos cantidad de reintentos
/// @return 0 si pudo validar 1 si no

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	int control;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			control = getFloat(&bufferFloat);
			if(control && minimo <= bufferFloat && maximo >= bufferFloat)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	return retorno;
}

/// @fn int esSoloLetras(char*, int)
/// @brief revibe una cadena y valida que sean solo letras y espacios
///
/// @param pResultado cadena de caracteres
/// @param limite tamaño de la cadena
/// @return 1 si son letras 0 si no

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScan;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScan = scanf("%c",&bufferChar);
			if(resultadoScan == 1 && bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("\n-REINTENTOS : %d\n",reintentos);
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/// @fn int esSoloLetras(char*, int)
/// @brief recibe una cade y valida que sean letras o espacios
///
/// @param pResultado cadena de caractederes
/// @param limite tamaño de la cadena
/// @return 1 si valida 0 si no lo hace

int esSoloLetras(char* pResultado,int limite)
{
	int respuesta = 1;
	int i;
	if(pResultado != NULL && limite > 0)
	{
		for(i=0; i <= limite && pResultado[i] != '\0';i++)
		{
			if((pResultado[i] < 'a' || pResultado[i] > 'z') &&
			   (pResultado[i] < 'A' || pResultado[i] > 'Z') &&
			   pResultado[i] != ' '  )
			{
				respuesta = 0;
				break;
			}
			if(pResultado[0] == ' ')
			{
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}

/// @fn int getString(char*, int)
/// @brief pide un texo lo valida y lo devuelve
///
/// @param pResultado puntero a variable resultado
/// @param longitud tamaño del array
/// @return 1 si salio bien 0 si hubo error


int getString(char* pResultado,int longitud)
{
	int retorno = 0;
	char buffAux[1000];
	if(pResultado != NULL && longitud > 0)
	{
		fflush(stdin);
		if(!myGets(buffAux,sizeof(buffAux)) && esSoloLetras(buffAux,sizeof(buffAux)))
		{
			strncpy(pResultado,buffAux,longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn int utn_getCadena(char*, int, char*, char*, int)
/// @brief pide al usuario una cadena
///
/// @param pResultado puntero a variable donde se guarda la cadena
/// @param longitud tamaño de la cadena
/// @param mensaje mesaje que se imprime para el usuario
/// @param mensajeError mensaje error mal ingreso de datos
/// @param reintentos  cantidad de reintentos
/// @return 0 si pudo 1 sis alio bien


int utn_getCadena(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = 1;
	char bufferChar[45];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getString(bufferChar,sizeof(bufferChar)) &&
				strlen(bufferChar) < longitud)
			{
				strncpy(pResultado,bufferChar,longitud-1);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getNumeroCorto(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	int control;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			control = getInt(&buffer);
			if(control == 1 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = (short)buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/// @fn int utn_formateadorNombres(char*)
/// @brief pasa todo el nombre a minuscula y le pone mayuscula a la primera letra de cada palabra
///
/// @param pResultado
/// @return
int utn_formateadorNombres(char* pResultado)
{
	int tamCadena;
	int retorno=-1;

	strlwr(pResultado);
	tamCadena=strlen(pResultado);
	pResultado[0]= pResultado[0]-32;
	for(int j =0;j<tamCadena;j++)
	{

	if(pResultado[j]==' ')
	{
	//	printf("entro\n");
		pResultado[j+1]= pResultado[j+1]-32;
	}
	}

	return retorno;
}





























