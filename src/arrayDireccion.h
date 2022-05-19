/*
 * arrayDireccion.h
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#ifndef ARRAYDIRECCION_H_
#define ARRAYDIRECCION_H_


struct {
	char callePrincipal[51];
	int altura;
	char primerEntreCalle[51];
	char segundaEntreCalle[51];
	int isEmpty;
	} typedef Direccion;

int iniciarDireccion(Direccion* list, int len);

int addDireccion(Direccion* direcciones, int len, char callePrincipal[], int altura, char primerEntreCalle[],
			char segundaEntreCalle[]);

int buscarIndexDireccionPorIsEmpty(Direccion* direcciones, int len);

int getDireccion(char* callePrincipal, int* altura, char* primerEntreCalle, char* segundaEntreCalle);

int modificarDatosDireccion(Direccion* direcciones, int indice);


#endif /* ARRAYDIRECCION_H_ */
