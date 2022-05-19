/*
 * arrayFechaNacimiento.c
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayFechaNacimiento.h"
#ifndef ARRAYFECHANACIMIENTO_C_
#define ARRAYFECHANACIMIENTO_C_

/**
 * @brief
 *
 * @param list
 * @param len
 * @return
 */
int iniciarFechaNac(FechaNacimiento* list, int len) {
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
 * @param dia
 * @param mes
 * @param anio
 * @return
 */
int getFechaNacimiento(int* dia, int* mes, int* anio)
{
	int retorno = -1;

		if (utn_getNumero(dia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 31, 2) == 0) {
			if (utn_getNumero(mes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2) == 0) {
				if (utn_getNumero(anio, "Ingrese el anio de nacimiento: \n", "Anio invalido. Reingrese por favor.", 1957, 2004, 2) == 0) {
					if (dia >= 30 && mes == 2) {
						printf("El mes de febrero no puede tener mas de 29 dias. Reingrese los datos por favor.");
						utn_getNumero(dia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 29, 2);
						utn_getNumero(mes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2);
					}
					if (dia > 30 && (mes == 4 || mes == 5 || mes == 9 || mes == 11) ) {
						printf("El mes seleccionado no puede tener mas de 30 dias. Reingrese los datos por favor.");
						utn_getNumero(dia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 30, 2);
						utn_getNumero(mes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2);
					}
					if (dia < 30 && (mes == 1 || mes == 3 || mes == 6 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) {
						printf("El mes seleccionado no puede tener menos de 30 dias. Reingrese los datos por favor.");
						utn_getNumero(dia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 31, 2);
						utn_getNumero(mes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2);
					}
					retorno = 0;
				}
			}
		}
	return retorno;
}



/**
 * @brief
 *
 * @param fechasNac
 * @param len
 * @param dia
 * @param mes
 * @param anio
 * @return
 */
int addFechaNacimiento(FechaNacimiento* fechasNac, int len, int dia, int mes, int anio)
{
	int retorno = -1;
	int posicionLibre;
	if (fechasNac != NULL && len > 0) {
		posicionLibre = buscarIndexFechaNacPorIsEmpty(fechasNac, len);
		if (posicionLibre != -1) {
			fechasNac[posicionLibre].dia = dia;
			fechasNac[posicionLibre].mes = mes;
			fechasNac[posicionLibre].anio = anio;
			fechasNac[posicionLibre].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief
 *
 * @param fechasNac
 * @param len
 * @return
 */
int buscarIndexFechaNacPorIsEmpty(FechaNacimiento* fechasNac, int len)
{
	int retorno = -1;

		if(fechasNac != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(fechasNac[i].isEmpty == 1)
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
 * @param fechasNac
 * @param indice
 * @return
 */
int modificarDatosFecha(FechaNacimiento* fechasNac, int indice)
{
	int retorno = -1;
	int auxDia;
	int auxMes;
	int auxAnio;
	int opcionMenuFecha;
	char seguirSubMenu = 's';

	do {
		if(utn_getNumero (&opcionMenuFecha,
				"\n****Elija el campo a modificar: ****\n\n"
					"1. Dia \n"
					"2. Mes \n"
					"3. Anio \n"
					"4. Salir. \n"
					"\nElija una opcion: ",

					"\n Error, opcion invalida", 1, 4, 2) == 0){
			switch(opcionMenuFecha){
				case 1:
					if (!utn_getNumero(&auxDia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 31, 2)){
						if (auxDia >= 30 && fechasNac[indice].mes == 2){
							printf("El mes de febrero no puede tener mas de 29 dias. Reingrese los datos por favor.");
							if (!utn_getNumero(&auxDia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 29, 2)) {
								fechasNac[indice].dia = auxDia;
							}

						} else if (auxDia > 30 && (fechasNac[indice].mes == 4 || fechasNac[indice].mes == 5 || fechasNac[indice].mes == 9 ||
								fechasNac[indice].mes == 11)){
							printf("El mes seleccionado no puede tener mas de 30 dias. Reingrese los datos por favor.");
							if (!utn_getNumero(&auxDia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 30, 2)) {
								fechasNac[indice].dia = auxDia;
							}

						} else if (auxDia < 30 && (fechasNac[indice].mes == 1 || fechasNac[indice].mes == 3 || fechasNac[indice].mes == 6 ||
								fechasNac[indice].mes == 7 || fechasNac[indice].mes == 8 || fechasNac[indice].mes == 10 || fechasNac[indice].mes == 12)) {
							printf("El mes seleccionado no puede tener menos de 30 dias. Reingrese los datos por favor.");
							if(!utn_getNumero(&auxDia, "Ingrese el dia de nacimiento: \n", "Dia inexistente. Reingrese por favor.", 1, 31, 2)) {
								fechasNac[indice].dia = auxDia;
							}
						} else {
							fechasNac[indice].dia = auxDia;
							}

							retorno = 0;
						}
					break;
				case 2:
					if (!utn_getNumero(&auxMes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 31, 2)){
						if (fechasNac[indice].dia >= 30 && auxMes == 2 ){
							printf("El mes de febrero no puede tener mas de 29 dias. Reingrese los datos por favor.");
							if(!utn_getNumero(&auxMes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2)) {
								fechasNac[indice].mes = auxMes;
							}


						} else if (fechasNac[indice].dia > 30 && (auxMes == 4 || auxMes == 5 || auxMes == 9 || auxMes == 11)){
							printf("El mes seleccionado no puede tener mas de 30 dias. Reingrese los datos por favor.");
							 if(!utn_getNumero(&auxMes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2)) {
								 fechasNac[indice].mes = auxMes;
							 }

						} else if (fechasNac[indice].dia < 30 && (auxMes == 1 || auxMes == 3 || auxMes == 6 ||
								auxMes == 7 || auxMes == 8 || auxMes == 10 || auxMes == 12)) {
							printf("El mes seleccionado no puede tener menos de 30 dias. Reingrese los datos por favor.");
							if(!utn_getNumero(&auxMes, "Ingrese el mes de nacimiento: \n", "Mes inexistente. Reingrese por favor.", 1, 12, 2)){
								fechasNac[indice].mes = auxMes;
							}

						} else {
							fechasNac[indice].mes = auxMes;
						}

						retorno = 0;
					}
					break;
				case 3:
					if (!utn_getNumero(&auxAnio, "Ingrese el anio de nacimiento: \n", "Anio invalido. Reingrese por favor.", 1957, 2004, 2)){
						fechasNac[indice].anio = auxAnio;
						retorno = 0;
						}
					break;
				case 4:
					break;
			}
			printf("Desea seguir modificando? Ingrese s / n: \n");
			fflush(stdin);
			scanf("%c", &seguirSubMenu);
		}

	} while (opcionMenuFecha !=4);


	return retorno;
}





#endif /* ARRAYFECHANACIMIENTO_C_ */
