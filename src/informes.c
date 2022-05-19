/*
 * informes.c
 *
 *  Created on: 18 may. 2022
 *      Author: barba
 */
#include "informes.h"
#ifndef INFORMES_C_
#define INFORMES_C_

/*9. Informes:
a. Informar cantidad de censistas en estado Activo con zona Pendiente.
b. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield
ordenados alfabéticamente por apellido y nombre.
c. Informar nombre de localidad con más casas ausentes.
d. Informar el censista cuya zona fue la más censada (total censados presencial y virtual)
e. Informar el promedio de censos por censista/zona.*/


// a. Informar cantidad de censistas en estado Activo con zona Pendiente.

int cantidadCensistasActivoPendiente (Censista* censistas, int lenCensistas, Zona* zonas, int lenZonas ) {
	int retorno = -1;
	int auxCantCensistas = 0;
	int auxIndiceCensista;
		if (censistas != NULL && lenCensistas > 0 && zonas!= NULL && lenZonas > 0) {
			for (int i = 0; i < lenZonas; i++) {
				if (zonas[i].estadoZona == 1 && zonas[i].idCensista > 0) {
					auxIndiceCensista = encontrarCensistaPorId(censistas, lenCensistas, zonas[i].idCensista);
					if (censistas[auxIndiceCensista].estadoCensista == 1) {
						auxCantCensistas++;
					}
				}
			}
			printf("La cantidad de censistas activos con zona pendiente es de: %d", auxCantCensistas);
			retorno = 0;
		}


	return retorno;
}

//b. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield
//ordenados alfabéticamente por apellido y nombre.



int ordenarCensistasPorApellidoyNombre (Censista* censistas, int len)
{
	int retorno = -1;
	int i;
	Censista aux;
	int isOrder;

	if (censistas != NULL && len > 0) {
			do {
				isOrder = 1;
				len--;
					for (i = 0; i < len; i++) {
						if (stricmp(censistas[i].apellido, censistas[i + 1].apellido) < 0) {
							aux = censistas[i];
							censistas[i] = censistas[i + 1];
							censistas[i + 1] = aux;
							isOrder = 0;
						} else if (stricmp(censistas[i].apellido, censistas[i + 1].apellido) == 0
								&& censistas[i].nombre < censistas[i + 1].nombre) {
							aux = censistas[i];
							censistas[i] = censistas[i + 1];
							censistas[i + 1] = aux;
							isOrder = 0;
						}
					}
			} while (isOrder == 0);


			retorno = 0;
	}
	return retorno;
}

int mostrarCensistasAvellaneda (Censista* censistas, int lenCensistas, Zona* zonas, int lenZonas ) {
	int retorno = -1;
	int auxIndiceCensista;

	ordenarCensistasPorApellidoyNombre (censistas, lenCensistas);

	for (int i = 0; i < lenZonas; i++) {
		if (zonas[i].localidad == 3) {
			auxIndiceCensista = encontrarCensistaPorId(censistas, lenCensistas, zonas[i].idCensista);
			imprimirCensista(censistas[auxIndiceCensista]);
		}
		retorno = 0;
	}

	return retorno;
}

//c. Informar nombre de localidad con más casas ausentes.

int cantidadLocalidadMasAusentes (Zona* zonas, int lenZonas ) {
	int retorno = -1;
	int auxQuilmes = 0;
	int auxBernal = 0;
	int auxAvellaneda = 0;
	int auxSarandi = 0;
	if (zonas!= NULL && lenZonas > 0) {
		for (int i = 0; i < lenZonas; i++) {
			if (zonas[i].localidad == 1 && zonas[i].censadosAusentes > 0) {
				auxQuilmes = auxQuilmes + zonas[i].censadosAusentes;
			}
			if (zonas[i].localidad == 2 && zonas[i].censadosAusentes > 0) {
				auxBernal = auxBernal + zonas[i].censadosAusentes;
			}
			if (zonas[i].localidad == 3 && zonas[i].censadosAusentes > 0) {
				auxAvellaneda = auxAvellaneda + zonas[i].censadosAusentes;
			}
			if (zonas[i].localidad == 3 && zonas[i].censadosAusentes > 0) {
				auxSarandi = auxSarandi + zonas[i].censadosAusentes;
			}
		}
		comparacionesLocalidades(&auxQuilmes, &auxBernal, &auxAvellaneda, &auxSarandi);
		retorno = 0;
	}


	return retorno;
}

int comparacionesLocalidades(int* auxQuilmes, int* auxBernal, int* auxAvellaneda, int* auxSarandi) {
	int retorno = -1;
	if (auxQuilmes > auxBernal && auxQuilmes > auxAvellaneda && auxQuilmes > auxSarandi) {
		printf("La localidad con mayor cantidad de ausentes es Quilmes \n");
		retorno = 0;
	}
	if (auxBernal > auxQuilmes && auxBernal > auxAvellaneda && auxBernal > auxSarandi) {
		printf("La localidad con mayor cantidad de ausentes es Bernal \n");
		retorno = 0;
	}
	if (auxAvellaneda > auxBernal && auxAvellaneda > auxQuilmes && auxAvellaneda > auxSarandi) {
		printf("La localidad con mayor cantidad de ausentes es Avellaneda \n");
		retorno = 0;
	}
	if (auxSarandi > auxBernal && auxSarandi > auxAvellaneda && auxSarandi > auxQuilmes) {
		printf("La localidad con mayor cantidad de ausentes es Sarandi \n");
		retorno = 0;
	} else {
		printf("No se pudo evaluar la localidad con mayor cant de ausentes. \n");
	}
	return retorno;
}

#endif /* INFORMES_C_ */
