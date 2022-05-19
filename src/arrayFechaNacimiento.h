/*
 * arrayFechaNacimiento.h
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#ifndef ARRAYFECHANACIMIENTO_H_
#define ARRAYFECHANACIMIENTO_H_


struct {
	int dia;
	int mes;
	int anio;
	int isEmpty;
	} typedef FechaNacimiento;

int iniciarFechaNac(FechaNacimiento* list, int len);

int getFechaNacimiento(int* dia, int* mes, int* anio);

int addFechaNacimiento(FechaNacimiento* fechasNac, int len, int dia, int mes, int anio);

int buscarIndexFechaNacPorIsEmpty(FechaNacimiento* fechasNac, int len);

int modificarDatosFecha(FechaNacimiento* fechasNac, int indice);

#endif /* ARRAYFECHANACIMIENTO_H_ */
