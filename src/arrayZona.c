/*
 * arrayZona.c
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayZona.h"
#ifndef ARRAYZONA_C_
#define ARRAYZONA_C_

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int iniciarZona(Zona* list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for(int i = 0; i < len ; i++){
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * @brief
 *
 * @param calleUno
 * @param calleDos
 * @param calleTres
 * @param calleCuatro
 * @param localidad
 * @return
 */
int getZona(char calleUno[], char calleDos[], char calleTres[],
		char calleCuatro[], int localidad)
{
	int retorno = -1;

		if (utn_getDescripcion(calleUno, 51,"Ingrese la primer calle: ", "Calle mal ingresada. Reintente.\n", 2)== 0) {
			if (utn_getDescripcion(calleDos, 51,"Ingrese la segunda calle: ", "Calle mal ingresada. Reintente.\n", 2) == 0) {
				if (utn_getDescripcion(calleTres, 51,"Ingrese la tercer calle: ", "Calle mal ingresada. Reintente.\n", 2) == 0) {
					if(utn_getDescripcion(calleCuatro, 51,"Ingrese la cuarta calle: ", "Calle mal ingresada. Reintente.\n", 2) ==0) {
						if (utn_getNumero(&localidad, "Ingrese la localidad de la vivienda (1-Quilmes, 2-Bernal, 3-Avellaneda, 4-Sarandi): ",
								"Altura incorrecta, reingrese.", 1, 4, 2) == 0) {
							retorno = 0;
						}

					}

				}
			}
		}
	return retorno;
}

/**
 * @brief
 *
 * @param zonas
 * @param len
 * @return
 */
int buscarIndexZonaPorIsEmpty(Zona* zonas, int len)
{
	int retorno = -1;

		if(zonas != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(zonas[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

/**
 * @brief
 *
 * @param zonas
 * @param len
 * @param id
 * @param calleUno
 * @param calleDos
 * @param calleTres
 * @param calleCuatro
 * @param localidad
 * @param estadoZona
 * @return
 */
int addZona(Zona* zonas, int len, int id, char calleUno[],char
calleDos[], char calleTres[], char calleCuatro[], int localidad, int estadoZona)
{
	int retorno = -1;
	int posicionLibre;
	if (zonas != NULL && len > 0) {
		posicionLibre = buscarIndexZonaPorIsEmpty(zonas, len);
		if (posicionLibre != -1) {
			zonas[posicionLibre].idZona = id;
			strcpy(zonas[posicionLibre].calleUno, calleUno);
			strcpy(zonas[posicionLibre].calleDos, calleDos);
			strcpy(zonas[posicionLibre].calleTres, calleTres);
			strcpy(zonas[posicionLibre].calleCuatro, calleCuatro);
			zonas[posicionLibre].localidad = localidad;
			zonas[posicionLibre].estadoZona = 1;
			zonas[posicionLibre].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief
 *
 * @param zonas
 * @param len
 * @param id
 * @return
 */
int encontrarZonaPorId(Zona* zonas, int len,int id) {
	int retorno = -1;
	if (zonas != NULL && len > 0 && id > 0) {
		for (int i =0; i < len; i++) {
			if (zonas[i].idZona == id && zonas[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief
 *
 * @param zonas
 * @param lenZonas
 * @param censistas
 * @param lenCensista
 * @return
 */
int asignarCensistaEnZona(Zona* zonas, int lenZonas, Censista* censistas, int lenCensista)
{
	int retorno = -1;
	int auxIdZona;
	int auxIdCensista;
	int auxIndiceZona;
	int auxIndiceCensista;

	imprimirZonasParaCensista(zonas, lenZonas);
	if (!utn_getNumero(&auxIdZona, "Ingrese el Id de zona: ", "Zona inexistente. Reingrese por favor", 1000, 9999, 2)) {
		auxIndiceZona = encontrarZonaPorId(zonas, lenZonas, auxIdZona);

		if (auxIndiceZona != -1 && !utn_getNumero(&auxIdCensista, "Ingrese el Id de Censista: ",
				"Censista inexistente. Reingrese por favor", 1000, 9999, 2)) {
			auxIndiceCensista =	encontrarCensistaPorId(censistas, lenCensista, auxIdCensista);
			if (auxIndiceCensista != -1) {
				if (censistas[auxIndiceCensista].estadoCensista != 1) {
					zonas[auxIndiceZona].idCensista = auxIdCensista;
					censistas[auxIndiceCensista].estadoCensista = 1;
					retorno = 0;
				} else {
					printf("Censista asignado previamente a otra zona. \n");
				}

			} else {
				printf("Id Censista invalido. \n");
			}


		} else {
			printf("Id Zona invalido. \n");
		}


	} else {
		printf("Error. No se pudo asignar la zona seleccionada. \n");
	}

	return retorno;
}

//--
/**
 * @brief
 *
 * @param zonas
 * @param len
 * @return
 */
int imprimirZonasParaCensista(Zona* zonas, int len) {
	int retorno = -1;
	if (zonas != NULL && len > 0) {
		imprimirEncabezadoZonaParaAsignarCensista();
		for (int i = 0; i < len; i++) {
			if (zonas[i].isEmpty == FALSE) {
				imprimirZonaParaAsignarCensista(zonas[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}


/**
 * @brief
 *
 * @param zona
 */
void imprimirZonaParaAsignarCensista(Zona zona) {
	//char ESTADO_ZONA[3][51] = {" ","Pendiente", "Finalizado"};
	//char LOCALIDAD_ZONA[5][51] = {" ","Quilmes", "Bernal", "Avellaneda", "Sarandi"};

	if(zona.isEmpty == FALSE) {
		printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*s\n",
				-8, zona.idZona, -20, zona.calleUno, -20, zona.calleDos, -20, zona.calleTres, -20, zona.calleCuatro,
				-15, LOCALIDAD_ZONA[zona.localidad], -15, ESTADO_ZONA[zona.estadoZona]);
	}
}


//--
/**
 * @brief
 *
 */
void imprimirEncabezadoZonaParaAsignarCensista(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-8,"Id Zona", -20, "Calle Uno", -20, "Calle Dos", -20, "Calle Tres",
			-20, "Calle Cuatro", -15, "Localidad", -15, "Estado Zona");
}

//--
/**
 * @brief
 *
 * @param auxCensadosInSitu
 * @param auxCensadosVirtual
 * @param auxCensadosAusentes
 * @return
 */
int getDatosCensadosZona(int* auxCensadosInSitu, int* auxCensadosVirtual, int* auxCensadosAusentes)
{
	int retorno = -1;

		if (utn_getNumero(auxCensadosInSitu, "Ingrese la cantidad de censados in situ: ", "Cantidad invalida. Reintente", 0, 3000, 2)== 0) {
			if (utn_getNumero(auxCensadosVirtual, "Ingrese la cantidad de censados virtual: ", "Cantidad invalida. Reintente", 0, 3000, 2) == 0) {
				if (utn_getNumero(auxCensadosAusentes, "Ingrese la cantidad de censados Ausentes: ", "Cantidad invalida. Reintente", 0, 3000, 2) == 0) {
					retorno = 0;

				}
			}
		}
	return retorno;
}

//------
/**
 * @brief
 *
 * @param zonas
 * @param lenZonas
 * @param censistas
 * @param lenCensistas
 * @param id
 * @return
 */
int addDatosCensadosZona(Zona* zonas, int lenZonas, Censista* censistas, int lenCensistas, int id)
{
	int retorno = -1;
	int indice;
	int indiceCensista;
	int auxIdCensista;
	int auxCensadosInSitu;
	int auxCensadosVirtual;
	int auxCensadosAusentes;

	if (zonas != NULL && lenZonas > 0) {
		indice = encontrarZonaPorId(zonas, lenZonas, id);
		if (indice != -1) {
			if (!getDatosCensadosZona(&auxCensadosInSitu, &auxCensadosVirtual, &auxCensadosAusentes)) {

				zonas[indice].censadosInSitu = auxCensadosInSitu;
				zonas[indice].censadosVirtual = auxCensadosVirtual;
				zonas[indice].censadosAusentes = auxCensadosAusentes;
				zonas[indice].estadoZona = 2;
				auxIdCensista = zonas[indice].idCensista;
				indiceCensista = encontrarCensistaPorId(censistas, lenCensistas, auxIdCensista);
				if (indiceCensista != -1) {
					censistas[indiceCensista].estadoCensista = 3;
					retorno = 0;
				}

			}
		}
	}
	return retorno;
}

//---
/**
 * @brief
 *
 * @param zonas
 * @param len
 * @return
 */
int hayZonaCargada(Zona* zonas, int len) {
	int retorno = -1;
	if (zonas != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (zonas[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//----
/**
 * @brief
 *
 */
void imprimirEncabezadoZonaParaMostrarCensista(){

	printf("\n|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n\n",-8,"Id Zona", -20, "Calle Uno", -20, "Calle Dos", -20, "Calle Tres",
			-20, "Calle Cuatro", -15, "Localidad", -15, "Estado Zona", -30, "Censista Asignado");
}

/**
 * @brief
 *
 * @param zona
 * @param censistas
 * @param len
 */
void imprimirZonaParaMostrarCensistaAsignado(Zona zona, Censista* censistas, int len) {
	int auxIndiceCensista;

	if(zona.isEmpty == FALSE) {

		printf("|%*d|%*s|%*s|%*s|%*s|%*s|%*s|",
				-8, zona.idZona, -20, zona.calleUno, -20, zona.calleDos, -20, zona.calleTres, -20, zona.calleCuatro,
				-15, LOCALIDAD_ZONA[zona.localidad], -15, ESTADO_ZONA[zona.estadoZona]);

		if (zona.idCensista > 1000) {
			auxIndiceCensista = encontrarCensistaPorId(censistas, len, zona.idCensista);
			if (auxIndiceCensista != -1) {
				printf("%*s|%*s| \n", -13, censistas[auxIndiceCensista].nombre, -13, censistas[auxIndiceCensista].apellido);
			} else {
				printf("no se encontro censista. \n");
			}
		} else {
			printf("%*s| \n", -30, "No hay asignacion.");
		}
	}
}

/**
 * @brief
 *
 * @param zonas
 * @param lenZonas
 * @param censistas
 * @param lenCensistas
 */
void imprimirZonasTotal (Zona* zonas, int lenZonas, Censista* censistas, int lenCensistas) {
	imprimirEncabezadoZonaParaMostrarCensista();
	for (int i = 0; i < lenZonas; i++) {
		if (zonas[i].isEmpty == FALSE) {
			imprimirZonaParaMostrarCensistaAsignado(zonas[i], censistas, lenCensistas);
		}
	}
}

//--
/**
 * @brief
 *
 * @param zonas
 * @param len
 * @return
 */
int cargaForzadaZona(Zona* zonas, int len){
	int retorno = -1;
	int i;


	Zona zona[FORCED_CHARGE] = {{0,"CALCHAQUI","LAPRIDA","PANAMA", "BOLIVIA", 1, 0, 1},
								{0,"TRIUNVIRATO","MISIONES","NICARAGUA", "9 DE JULIO", 2, 0, 1},
								{0,"MITRE","SARMIENTO","RIVADAVIA", "25 DE MAYO", 3, 0, 1},
								{0,"LAMADRID","ALSINA","VIDELA", "BRANDSEN", 4, 0, 1},
								{0,"ZAPIOLA","BROWN","PARANA", "URQUIZA", 1, 0, 1}};


	if(zonas != NULL){
		imprimirEncabezadoZonaParaAsignarCensista();
		for(i = 0; i < FORCED_CHARGE; i++){
			int id = incrementarId();
			if(!addZona(zonas, len, id, zona[i].calleUno, zona[i].calleDos, zona[i].calleTres, zona[i].calleCuatro, zona[i].localidad, zona[i].estadoZona)) {
				zona[i].idZona = id;
				imprimirZonaParaAsignarCensista(zona[i]);
			}
		}
		retorno = 0;
	}
	return retorno;
}


#endif /* ARRAYZONA_C_ */
