/*
 * arrayPassenger.h
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#include "arrayFechaNacimiento.h"
#include "arrayDireccion.h"
#ifndef ARRAYCENSISTA_H_
#define ARRAYCENSISTA_H_
#define FORCED_CHARGE 5



struct {
	int idCensista;
	char nombre[51];
	char apellido[51];
	int edad;
	FechaNacimiento fechaNac;
	Direccion direccion;
	int estadoCensista;
	int isEmpty;
	} typedef Censista;

int iniciarCensista(Censista* censistas, int len);

int getCensista(char* nombre, char* apellido, int* edad);

int addCensista(Censista* censistas, int len, int idCensista, char nombre[],
		char apellido[], int edad, int auxDia, int auxMes, int auxAnio, char auxCallePrin[],
		int auxAltura, char auxPrimerEntreC[], char auxSegundaEntreC[], int estadoCensista);

int hayCensista(Censista* censistas, int len);

int encontrarCensistaPorId(Censista* censistas, int len,int id);

void imprimirEncabezado();

void imprimirCensista(Censista censista);

int imprimirCensistas(Censista* censistas, int len);

int buscarIndexCensistaPorIsEmpty(Censista* censistas, int len);

int eliminarCensista(Censista* censistas, int len, int id);

int modificarNombre(Censista* censistas, int indice);

int modificarApellido(Censista* censistas, int indice);


#endif /* ARRAYCENSISTA_H_ */
