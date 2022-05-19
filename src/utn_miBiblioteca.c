/*
 * funciones.c
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */
#include "utn_miBiblioteca.h"
#ifndef UTN_MIBIBLIOTECA_C_
#define UTN_MIBIBLIOTECA_C_


static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);


/**
 * @brief incrementa el id automáticamente
 *
 * @return devuelve el id
 */
int incrementarId()
{
    static int id = 1000;
    id++;
    return id;
}


/**
 * \brief Lee en stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde de copia de cadena obtenida
 * \param longitud Define tamaño de cadena
 * \return Retorna 0 si obtiene la cadena
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se guardara el resultado de la funcion
 * \return Retorna 0 si obtiene numero entero o -1 si fallo la operacion.
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica que la cadena ingresada sea numerica
 * \param cadena Cadena de caracteres para analizar
 * \param limite longitud de la cadena
 * \return Retorna 1 si la cadena es numerica, 0  si no lo es y -1 en caso de error al ejecutar.
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Pide un numero al usuario, lo verifica y devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se guardara el resultado de la funcion
 * \param mensaje Mensaje a mostrar
 * \param mensajeError Mensaje de error a mostrar
 * \param minimo Numero minimo tolerado
 * \param maximo Numero maximo tolerado
 * \param reintentos cantidad de reintentos permitidos
 * \return Retorna 0 si se obtuvo el numero  correctamente y -1 en caso de error
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica que la cadena ingresada sea flotante
 * \param pResultado Puntero al espacio de memoria donde guardara el resultado de la funcion
 * \return Retorna 0 si se obtuvo el numero flotante y -1 en caso de que no lo sea.
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica que la cadena ingresada sea flotante
 * \param cadena Cadena de caracteres a analizar por la funcion
 * \return Retorna 1 si la cadena es flotante y 0 en caso de que no lo sea
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, lo verifica y devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se guardara el resultado de la funcion
 * \param mensaje Mensaje a mostrar
 * \param mensajeError Mensaje de error a mostrar
 * \param minimo Numero minimo tolerado
 * \param maximo Numero maximo tolerado
 * \param reintentos cantidad de reintentos permitidos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no se pudo obtener
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}




/**
 * \brief Obtiene un string validado para utilizar como nombre
 * \param pResultado Puntero al espacio de memoria donde se guardara el resultado de la funcion
 * \param longitud longitud del array
 * \return Retorna 0  si se obtiene el nombre correctamente y -1 en caso de error
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica que la cadena ingresada sea valida como nombre
 * \param cadena Cadena de caracteres a ser analizada
 * \param longitud longitud del array
 * \return Retorna 1  si la cadena es valida y 0 en caso de que no lo sea
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, lo verifica y devuelve su resultado
 * \param pResultado Puntero al espacio de memoria donde se guardara el resultado de la función
 * \param longitud longitud del array resultante
 * \param mensaje Mensaje a mostrar
 * \param mensajeError Mensaje de error a mostrar
 * \param reintentos Cantidad de reintentos permitidos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 en caso de error.
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se guardará el resultado de la funcion
 * \param longitud longitud del array
 * \return Retorna 0 si se obtiene una descripcion que cumpla con los parámetros y -1 en caso de que no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica que la cadena sea valida en los parametros que solicita descripcion
 * \param cadena Cadena de caracteres a ser analizada
 * \param longitud de la cadena
 * \return Retorna 1 si la cadena es valida y 0 en caso de que no lo sea
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, la verifica y devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se guardará el resultado de la funcion
 * \param longitud Longitud del array resultado
 * \param mensaje Mensaje a mostrar
 * \param mensajeError Mensaje de error a mostrar
 * \param reintentos Cantidad de reintentos permitidos
 * \return Retorna 0 si se obtuvo la descripcion necesaria y -1 en caso de error.
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


#endif /* UTN_MIBIBLIOTECA_C_ */
