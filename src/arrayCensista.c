/*
 * arrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayCensista.h"
#ifndef ARRAYCENSISTA_C_
#define ARRAYCENSISTA_C_

static const char ESTADO_CENSISTA[4][51] = {" ", "Activo", "Inactivo", "Liberado",};




/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */

int iniciarCensista(Censista* list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for(int i = 0; i < len ; i++){
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

//---------

/**
 * @brief
 *
 * @param nombre
 * @param apellido
 * @param edad
 * @return
 */
int getCensista(char* nombre, char* apellido, int* edad)
{
	int retorno = -1;

	if (utn_getNombre(nombre, 51,"Ingrese el nombre: ", "Nombre mal ingresado. Reintente.\n", 2)== 0) {
		if (utn_getNombre(apellido, 51,"Ingrese el apellido: ", "Apellido mal ingresado. Reintente.\n", 2) == 0) {
			if (utn_getNumero(edad, "Ingrese la edad: ", "Edad incorrecta, reingrese.", 18, 65, 2) == 0) {
				retorno = 0;
			}

		}
	}
	return retorno;
}



/**
 * @brief
 *
 * @param censistas
 * @param len
 * @param idCensista
 * @param nombre
 * @param apellido
 * @param edad
 * @param auxDia
 * @param auxMes
 * @param auxAnio
 * @param auxCallePrin
 * @param auxAltura
 * @param auxPrimerEntreC
 * @param auxSegundaEntreC
 * @param estadoCensista
 * @return
 */
int addCensista(Censista* censistas, int len, int idCensista, char nombre[],
		char apellido[], int edad, int auxDia, int auxMes, int auxAnio, char auxCallePrin[],
		int auxAltura, char auxPrimerEntreC[], char auxSegundaEntreC[], int estadoCensista)
{
	int retorno = -1;
	int posicionLibre;
	if (censistas != NULL && len > 0) {
		posicionLibre = buscarIndexCensistaPorIsEmpty(censistas, len);
		if (posicionLibre != -1) {
			censistas[posicionLibre].idCensista = idCensista;
			strcpy(censistas[posicionLibre].nombre, nombre);
			strcpy(censistas[posicionLibre].apellido, apellido);
			censistas[posicionLibre].edad = edad;
			censistas[posicionLibre].fechaNac.dia = auxDia;
			censistas[posicionLibre].fechaNac.mes = auxMes;
			censistas[posicionLibre].fechaNac.anio = auxAnio;
			censistas[posicionLibre].estadoCensista = estadoCensista;
			strcpy(censistas[posicionLibre].direccion.callePrincipal, auxCallePrin);
			censistas[posicionLibre].direccion.altura = auxAltura;
			strcpy(censistas[posicionLibre].direccion.primerEntreCalle, auxPrimerEntreC);
			strcpy(censistas[posicionLibre].direccion.segundaEntreCalle, auxSegundaEntreC);
			censistas[posicionLibre].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

//--
/**
 * @brief
 *
 * @param censistas
 * @param len
 * @param id
 * @return
 */
int encontrarCensistaPorId(Censista* censistas, int len,int id) {
	int retorno = -1;
	if (censistas != NULL && len > 0 && id > 0) {
		for (int i =0; i < len; i++) {
			if (censistas[i].idCensista == id && censistas[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



//--
/**
 * @brief
 *
 * @param censistas
 * @param len
 * @return
 */
int imprimirCensistas(Censista* censistas, int len) {
	int retorno = -1;
	if (censistas != NULL && len > 0) {
		imprimirEncabezado();
		for (int i = 0; i < len; i++) {
			if (censistas[i].isEmpty == FALSE) {
				imprimirCensista(censistas[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}


//--
/**
 * @brief
 *
 * @param censistas
 * @param len
 * @return
 */
int buscarIndexCensistaPorIsEmpty(Censista* censistas, int len)
{
	int retorno = -1;

		if(censistas != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(censistas[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

//--

/**
 * @brief
 *
 * @param censistas
 * @param indice
 * @return
 */
int modificarNombre(Censista* censistas, int indice)
{
	int retorno = -1;
	char auxName[51];

	if (!utn_getNombre(auxName, 51, "Ingrese un nombre:", "Nombre incorrecto. Reingrese.", 2)){
		strcpy(censistas[indice].nombre, auxName);

		retorno = 0;
	}

	return retorno;
}


//--
/**
 * @brief
 *
 * @param censistas
 * @param indice
 * @return
 */
int modificarApellido(Censista* censistas, int indice)
{
	int retorno = -1;
	char auxApellido[51];


	if (!utn_getNombre(auxApellido, 51, "Ingrese un apellido:", "Apellido incorrecto. Reingrese.", 2)){
		strcpy(censistas[indice].apellido, auxApellido);

		retorno = 0;
	}


	return retorno;
}

//--
/**
 * @brief
 *
 * @param censistas
 * @param len
 * @param id
 * @return
 */
int eliminarCensista(Censista* censistas, int len, int id) {

	int retorno = -1;
	int indice;
	int flag = 0;

	indice = encontrarCensistaPorId(censistas, len, id);
	if (indice != -1){
		if(censistas[indice].estadoCensista == 1) {
			censistas[indice].estadoCensista = 2;
			printf("El censista fue marcado como Inactivo. \n");
			flag = 1;
		}
		if(censistas[indice].estadoCensista != 1 && flag == 0){
			censistas[indice].isEmpty = 1;
			printf("Censista dado de baja. \n");

		}
		retorno = 0;
	} else {
		printf("Error. No existe censista asociado a ese Id.");
	}
	return retorno;
}





//--
/**
 * @brief
 *
 * @param censista
 */
void imprimirCensista(Censista censista) {

	if(censista.isEmpty == FALSE) {
		printf("|%*d|%*s|%*s|%*d / %*d / %*d|%*d|%*s %*d, entre %*s y %*s|%*s\n",
				-8, censista.idCensista, -13, censista.nombre, -13, censista.apellido, -3, censista.fechaNac.dia, -3, censista.fechaNac.mes,
				-7, censista.fechaNac.anio, -4, censista.edad, -20, censista.direccion.callePrincipal, -8, censista.direccion.altura,
				-20, censista.direccion.primerEntreCalle, -20, censista.direccion.segundaEntreCalle, -12, ESTADO_CENSISTA[censista.estadoCensista]);
	}
}


//--
/**
 * @brief
 *
 */
void imprimirEncabezado(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-8,"Id",-13, "Nombre", -13, "Apellido", -3 -3 -5, "Fecha de Nacimiento",
			-4, "Edad", -20 -8 -20 -32, "Domicilio", -12, "Estado");
}


/**
 * @brief
 *
 * @param censistas
 * @param lenCensistas
 * @param fechasNac
 * @param lenFechasNac
 * @param direcciones
 * @param lenDirecciones
 * @return
 */
int cargaForzadaCensista(Censista* censistas, int lenCensistas, FechaNacimiento* fechasNac, int lenFechasNac, Direccion* direcciones,
							int lenDirecciones){
	int retorno = -1;
	int i;

	Censista censista[FORCED_CHARGE] = {{0, "NEZUKO", "KAMADO",  28, {07, 12, 1993},{"CALLE 382", 2740, "LAPRIDA", "MOSCONI"}, 3, 0},
											{0, "TANJIRO", "KAMADO", 30,{26, 04, 1992}, {"ALSINA", 360, "MITRE", "SARMIENTO"}, 3, 0},
											{0, "KIMETSU", "NOYAIBA", 29, {18, 01, 1993}, {"RIVADAVIA", 2508, "CALCHAQUI", "PERON"}, 3, 0},
											{0, "TENTEN", "UZUI", 29, {07, 03, 1993},{"JUJUY", 420, "YRIGOYEN", "SAN MARTIN"}, 3, 0},
											{0, "MITSURI", "KANROJI", 42, {05, 05, 1980}, {"BOLIVIA", 840, "PERU", "25 DE MAYO"}, 3, 0}};

	if(censistas != NULL){
		imprimirEncabezado();
		for(i = 0; i < FORCED_CHARGE; i++){
			int id = incrementarId();
			if (!addFechaNacimiento(fechasNac, lenFechasNac, censista[i].fechaNac.dia, censista[i].fechaNac.mes, censista[i].fechaNac.anio)) {
				if (!addDireccion(direcciones, lenDirecciones, censista[i].direccion.callePrincipal, censista[i].direccion.altura,
					censista[i].direccion.primerEntreCalle , censista[i].direccion.segundaEntreCalle)) {
					if(!addCensista(censistas, lenCensistas, id, censista[i].nombre, censista[i].apellido, censista[i].edad, censista[i].fechaNac.dia,
						censista[i].fechaNac.mes, censista[i].fechaNac.anio, censista[i].direccion.callePrincipal, censista[i].direccion.altura,
						censista[i].direccion.primerEntreCalle , censista[i].direccion.segundaEntreCalle, censista[i].estadoCensista)) {
						imprimirCensista(censistas[i]);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}




//--
/**
 * @brief
 *
 * @param censistas
 * @param len
 * @return
 */
int hayCensista(Censista* censistas, int len) {
	int retorno = -1;
	if (censistas != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (censistas[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

#endif /* ARRAYCENSISTA_C_ */
