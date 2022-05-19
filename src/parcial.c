/*
 ============================================================================
 Name        : parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_miBiblioteca.h"
#include "arrayCensista.h"
#include "arrayDireccion.h"
#include "arrayFechaNacimiento.h"
#include "arrayZona.h"
#include "informes.h"
#define LEN_CENSISTAS 2000
#define LEN_ZONAS 2000
#define LEN_DIRECCIONES 2000
#define LEN_FECHANACIMIENTO 2000

int main(void) {
	setbuf(stdout, NULL);
	Censista censistas[LEN_CENSISTAS];
	FechaNacimiento fechasNac[LEN_FECHANACIMIENTO];
	Zona zonas[LEN_ZONAS];
	Direccion direcciones [LEN_DIRECCIONES];
	int opcionMenu;
	int opcionSubMenu;
	int auxId = 0;
	char auxNombre[51];
	char auxApellido[51];
	int auxEdad = 0;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxCallePrin[56];
	int auxAltura;
	char auxPrimerEntreC[56];
	char auxSegundaEntreC[56];
	char auxCalleUno[56];
	char auxCalleDos[56];
	char auxCalleTres[56];
	char auxCalleCuatro[56];
	int auxLocalidad;
	int auxEstadoZona = 1;
	int auxEstadoCensista = 3;
	int idModificacion;
	int indice;
	int informesOpcion;


	if (iniciarCensista(censistas, LEN_CENSISTAS) == 0 && iniciarDireccion(direcciones, LEN_DIRECCIONES) == 0 &&
			iniciarFechaNac(fechasNac, LEN_FECHANACIMIENTO) == 0 && iniciarZona(zonas, LEN_ZONAS) == 0) {
		do{
			if(utn_getNumero (&opcionMenu,
					"\n*****************************Menu Principal*****************************\n\n"
												"1. Cargar Censista \n"
												"2. Modificacion de Censista \n"
												"3. Baja de Censista \n"
												"4. Cargar Zona \n"
												"5. Asignar Zona a censar \n"
												"6. Carga de datos \n"
												"7. Mostrar Censistas \n"
												"8. Mostrar Zonas \n"
												"9. Carga Forzada Censista: \n"
												"10. Carga Forzada Zonas: \n"
												"11. Informes: \n"
												"12. Salir. \n"
												"\nElija una opcion: ",

										"\n Error, opcion invalida", 1, 11, 2) == 0){
				switch(opcionMenu){
				case 1:
					if (getCensista(auxNombre, auxApellido, &auxEdad) == 0 && getFechaNacimiento(&auxDia, &auxMes, &auxAnio) == 0 &&
							getDireccion(auxCallePrin, &auxAltura, auxPrimerEntreC, auxSegundaEntreC) == 0) {
						auxId = incrementarId();

						printf("%d %s %s %d %d %d %d %s %d %s %s", auxId, auxNombre, auxApellido, auxEdad, auxDia, auxMes,
								auxAnio, auxCallePrin, auxAltura, auxPrimerEntreC, auxSegundaEntreC);


						if (!addFechaNacimiento(fechasNac, LEN_FECHANACIMIENTO, auxDia, auxMes, auxAnio) &&
								!addDireccion(direcciones, LEN_DIRECCIONES, auxCallePrin, auxAltura, auxPrimerEntreC, auxSegundaEntreC) &&
								!addCensista(censistas, LEN_CENSISTAS, auxId, auxNombre, auxApellido, auxEdad, auxDia, auxMes, auxAnio, auxCallePrin, auxAltura, auxPrimerEntreC, auxSegundaEntreC, auxEstadoCensista)) {
							printf("Datos guardados correctamente.");
						} else {
							printf("Los datos no han sido guardados. Reintente por favor.");
						}
					} else {
						printf("No se obtuvieron correctamente los datos.");
					}
					break;

				case 2:
					if (!hayCensista(censistas, LEN_CENSISTAS)) {
						if (!utn_getNumero(&idModificacion, "Ingrese el id del censista a modificar: ", "Error, id inexistente.", 1000, 9999, 2)) {
							indice = encontrarCensistaPorId(censistas, LEN_CENSISTAS, idModificacion);
							if (indice != -1) {
								imprimirEncabezado();
								imprimirCensista(censistas[indice]);
							do{
								if(utn_getNumero (&opcionSubMenu,
										"\n****Modificacion de censista****\n\n"
											"1. Nombre \n"
											"2. Apellido \n"
											"3. Fecha de nacimiento \n"
											"4. Edad \n"
											"5. Direccion \n"
											"6. Salir. \n"
											"\nElija una opcion: ",

											"\n Error, opcion invalida", 1, 6, 2) == 0){
									switch(opcionSubMenu){
										case 1:
											if (!modificarNombre(censistas, indice)){
												printf("Nombre modificado exitosamente.");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente. \n");
											}
											break;
										case 2:
											if (!modificarApellido(censistas, indice)){
												printf("Apellido modificado exitosamente.");
											} else {
												printf("No se ha podido efectuar el cambio. Reintente. \n");
											}
											break;
										case 3:
											modificarDatosFecha(fechasNac, indice);
											break;
										case 4:
											if (!utn_getNumero(&auxEdad, "Ingrese la edad: ", "Edad incorrecta, reingrese.", 18, 65, 2)) {
												censistas[indice].edad = auxEdad;
											}
											break;

										case 5:
											modificarDatosDireccion(direcciones, indice);
											break;
										case 6:
											break;
									}
								}
							} while (opcionSubMenu !=6);
							} else {
								printf("Id inexistente.\n");
							}
						} else {
							printf("El id ingresado no es correcto. Reintente por favor.\n");
						}
					} else {
						printf("Error. Primero debe ingresar un censista para poder modificar sus datos.\n");
					}
					break;

				case 3:
					if (!hayCensista(censistas, LEN_CENSISTAS)) {
						imprimirCensistas(censistas, LEN_CENSISTAS);
						if(!utn_getNumero(&auxId, "\n Ingrese el Id del censista: \n", "Error. Reingrese Id", 1000, 9999, 2)){
							eliminarCensista(censistas, LEN_CENSISTAS, auxId);
						}
					} else {
						printf("Error. Primero debe ingresar un censista para poder modificar sus datos.\n");
					}
					break;

				case 4:
					if (!hayCensista(censistas, LEN_CENSISTAS)) {
						if (!getZona(auxCalleUno, auxCalleDos, auxCalleTres, auxCalleCuatro, auxLocalidad)) {
							auxId = incrementarId();
							if (!addZona(zonas, LEN_ZONAS, auxId, auxCalleUno, auxCalleDos, auxCalleTres, auxCalleCuatro, auxLocalidad, auxEstadoZona)) {
								printf("Datos cargados correctamente. \n");
							}
						}
					} else {
						printf("Error. Primero debe ingresar un censista para poder cargar una zona. \n");
					}
					break;

				case 5:
					if (!hayCensista(censistas, LEN_CENSISTAS)) {
						asignarCensistaEnZona(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);

					} else {
						printf("Error. Primero debe ingresar un censista para poder asignarle una zona.\n");
					}
					break;

				case 6:
					if (!hayCensista(censistas, LEN_CENSISTAS) && !hayZonaCargada(zonas, LEN_ZONAS)) {
						if (!utn_getNumero(&idModificacion, "Ingrese el id de la zona a finalizar: ", "Error, id inexistente.", 1000, 9999, 2)) {
							addDatosCensadosZona(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, idModificacion);
						}
					} else {
						printf("Error. Primero debe ingresar un censista y una zona para poder cargar sus datos.\n");
					}
					break;

				case 7:
					if (!hayCensista(censistas, LEN_CENSISTAS)) {
						void imprimirEncabezado();
						imprimirCensistas(censistas, LEN_CENSISTAS);
					} else {
						printf("Error. Primero debe ingresar un censista y una zona para poder cargar sus datos.\n");
					}

					break;

				case 8:
					imprimirZonasTotal (zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
					break;

				case 9:
					cargaForzadaCensista(censistas, LEN_CENSISTAS, fechasNac, LEN_FECHANACIMIENTO,
							direcciones, LEN_DIRECCIONES);
					break;

				case 10:
					cargaForzadaZona(zonas, LEN_ZONAS);
					break;

				case 11:
					do {
						if(utn_getNumero (&informesOpcion,
											"\n*****************************Menu Principal*****************************\n\n"
																		"1. primer informe \n"
																		"2. segundo infotrme \n"
																		"3. tercer informe \n"
																		"4. Salir. \n"
																		"\nElija una opcion: ",

																"\n Error, opcion invalida", 1, 3, 2) == 0){
										switch(informesOpcion){
										case 1:
											cantidadCensistasActivoPendiente (censistas, LEN_CENSISTAS, zonas, LEN_ZONAS );
											break;
										case 2:
											mostrarCensistasAvellaneda (censistas, LEN_CENSISTAS, zonas, LEN_ZONAS );
											break;
										case 3:
											cantidadLocalidadMasAusentes (zonas, LEN_ZONAS);
											break;
										}
						}

					} while (informesOpcion != 4);
					break;

				case 12:
					printf("talueguito. \n");
					break;
				}
			}

		} while (opcionMenu !=12);
	}



	return EXIT_SUCCESS;
}
