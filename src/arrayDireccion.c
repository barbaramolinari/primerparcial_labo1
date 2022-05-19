/*
 * arrayDireccion.c
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayDireccion.h"
#ifndef ARRAYDIRECCION_C_
#define ARRAYDIRECCION_C_

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int iniciarDireccion(Direccion* list, int len) {
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
 * @param callePrincipal
 * @param altura
 * @param primerEntreCalle
 * @param segundaEntreCalle
 * @return
 */
int getDireccion(char* callePrincipal, int* altura, char* primerEntreCalle, char* segundaEntreCalle)
{
	int retorno = -1;

		if (utn_getDescripcion(callePrincipal, 51,"Ingrese la calle principal: ", "Calle mal ingresada. Reintente.\n", 2)== 0) {
			if (utn_getNumero(altura, "Ingrese la altura de la vivienda: ", "Altura incorrecta, reingrese.", 0, 27500, 2) == 0) {
				if (utn_getDescripcion(primerEntreCalle, 51,"Ingrese la primer entrecalle: ", "Calle mal ingresada. Reintente.\n", 2) == 0) {
					if(utn_getDescripcion(segundaEntreCalle, 51,"Ingrese la segunda entrecalle: ", "Calle mal ingresada. Reintente.\n", 2) ==0) {
						retorno = 0;
					}

				}
			}
		}
	return retorno;
}

/**
 * @brief
 *
 * @param direcciones
 * @param len
 * @param callePrincipal
 * @param altura
 * @param primerEntreCalle
 * @param segundaEntreCalle
 * @return
 */
int addDireccion(Direccion* direcciones, int len, char callePrincipal[], int altura, char primerEntreCalle[],
		char segundaEntreCalle[])
{
	int retorno = -1;
	int posicionLibre;
	if (direcciones != NULL && len > 0) {
		posicionLibre = buscarIndexDireccionPorIsEmpty(direcciones, len);
		if (posicionLibre != -1) {
			strcpy(direcciones[posicionLibre].callePrincipal, callePrincipal);
			direcciones[posicionLibre].altura = altura;
			strcpy(direcciones[posicionLibre].primerEntreCalle, primerEntreCalle);
			strcpy(direcciones[posicionLibre].segundaEntreCalle, segundaEntreCalle);
			direcciones[posicionLibre].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief
 *
 * @param direcciones
 * @param len
 * @return
 */
int buscarIndexDireccionPorIsEmpty(Direccion* direcciones, int len)
{
	int retorno = -1;

		if(direcciones != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(direcciones[i].isEmpty == 1)
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
 * @param direcciones
 * @param indice
 * @return
 */
int modificarDatosDireccion(Direccion* direcciones, int indice)
{
	int retorno = -1;
	char auxCallePrincipal[51];
	int auxAltura = 0;
	char auxPrimerEntreC[51];
	char auxSegundaEntreC[51];
	int opcionMenuFecha;
	char seguirSubMenu = 's';


	do {
		if(utn_getNumero (&opcionMenuFecha,
				"\n****Elija el campo a modificar: ****\n\n"
					"1. Calle principal \n"
					"2. Altura \n"
					"3. Primer Entre calle \n"
					"4. Segunda Entre calle. \n"
					"5. Salir. \n"
					"\nElija una opcion: ",

					"\n Error, opcion invalida", 1, 6, 2) == 0){
			switch(opcionMenuFecha){
				case 1:
					if (!utn_getNombre(auxCallePrincipal, 51,"Ingrese la calle principal: ", "Calle mal ingresada. Reintente.\n", 2)){
						strcpy(direcciones[indice].callePrincipal , auxCallePrincipal);
						retorno = 0;
					}
					break;

				case 2:
					if (!utn_getNumero(&auxAltura, "Ingrese la altura de la vivienda: ", "Altura incorrecta, reingrese.", 0, 27500, 2)){
						direcciones[indice].altura = auxAltura;
						retorno = 0;
					}

					break;

				case 3:
					if (!utn_getNombre(auxPrimerEntreC, 51,"Ingrese la primer entre calle: ", "Calle mal ingresada. Reintente.\n", 2)){
						strcpy(direcciones[indice].primerEntreCalle , auxPrimerEntreC);
						retorno = 0;
					}
					break;
				case 4:
					if (!utn_getNombre(auxSegundaEntreC, 51,"Ingrese la segunda entre calle: ", "Calle mal ingresada. Reintente.\n", 2)){
						strcpy(direcciones[indice].segundaEntreCalle , auxSegundaEntreC);
						retorno = 0;
					}
					break;
				case 5:
					break;
			}
			printf("Desea seguir modificando? Ingrese s / n: \n");
			fflush(stdin);
			scanf("%c", &seguirSubMenu);
		}

	} while (opcionMenuFecha !=5);

	return retorno;
}


#endif /* ARRAYDIRECCION_C_ */
