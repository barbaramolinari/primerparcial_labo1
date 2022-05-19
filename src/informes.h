/*
 * informes.h
 *
 *  Created on: 18 may. 2022
 *      Author: barba
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn_miBiblioteca.h"
#include "arrayFechaNacimiento.h"
#include "arrayDireccion.h"
#include "arrayCensista.h"
#include "arrayZona.h"
#ifndef INFORMES_H_
#define INFORMES_H_

int cantidadCensistasActivoPendiente (Censista* censistas, int lenCensistas, Zona* zonas, int lenZonas );

int ordenarCensistasPorApellidoyNombre (Censista* censistas, int len);

int mostrarCensistasAvellaneda (Censista* censistas, int lenCensistas, Zona* zonas, int lenZonas );

int cantidadLocalidadMasAusentes (Zona* zonas, int lenZonas );

int comparacionesLocalidades(int* auxQuilmes, int* auxBernal, int* auxAvellaneda, int* auxSarandi);

#endif /* INFORMES_H_ */
