/*
 * arrayZona.h
 *
 *  Created on: 16 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#include "arrayCensista.h"
#ifndef ARRAYZONA_H_
#define ARRAYZONA_H_


static const char LOCALIDAD_ZONA[5][51] = {" ","Quilmes", "Bernal", "Avellaneda", "Sarandi"};
static const char ESTADO_ZONA[3][51] = {" ","Pendiente", "Finalizado"};


struct {
	int idZona;
	char calleUno[51];
	char calleDos[51];
	char calleTres[51];
	char calleCuatro[51];
	int localidad;
	int idCensista;
	int estadoZona;
	int censadosInSitu;
	int censadosVirtual;
	int censadosAusentes;
	int isEmpty;
	} typedef Zona;

int iniciarZona(Zona* list, int len);

int buscarIndexZonaPorIsEmpty(Zona* zonas, int len);

int addZona(Zona* zonas, int len, int id, char calleUno[],char
calleDos[], char calleTres[], char calleCuatro[], int localidad, int estadoZona);

int getZona(char calleUno[], char calleDos[], char calleTres[],
			char calleCuatro[], int localidad);

int encontrarZonaPorId(Zona* zonas, int len,int id);

int imprimirZonasParaCensista(Zona* zonas, int len);

void imprimirEncabezadoZonaParaAsignarCensista();

void imprimirZonaParaAsignarCensista(Zona zona);

int asignarCensistaEnZona(Zona* zonas, int lenZonas, Censista* censistas, int lenCensista);

int getDatosCensadosZona(int* auxCensadosInSitu, int* auxCensadosVirtual, int* auxCensadosAusentes);

void imprimirZonaParaMostrarCensistaAsignado(Zona zona, Censista* censistas, int len);

void imprimirZonasTotal (Zona* zonas, int lenZonas, Censista* censistas, int lenCensistas);

#endif /* ARRAYZONA_H_ */
