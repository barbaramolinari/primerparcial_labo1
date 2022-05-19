/*
 * funciones.h
 *
 *  Created on: 24 abr. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifndef UTN_MIBIBLIOTECA_H_
#define UTN_MIBIBLIOTECA_H_
#define TRUE 1
#define FALSE 0

int incrementarId();

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* UTN_MIBIBLIOTECA_H_ */
