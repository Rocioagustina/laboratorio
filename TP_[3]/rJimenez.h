/*
 * rJimenez.h
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */

#ifndef RJIMENEZ_H_
#define RJIMENEZ_H_
#include "Passenger.h"
#include "arrayTypePassenger.h"
#define TAM_STR 256
#define TAM_NOMBRE 50
#define TAM_INT 20



int pedirFloat (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], float *pResultado);

int validarFloat (char resultado [TAM_STR]);

int pedirNombre (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoNombre);

int validarNombre (char nombreSinValidar [TAM_NOMBRE]);

int pedirCodigo (char mensaje [TAM_STR], char *pResultadoCodigo);

int pedirInt(char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], int *pResultadoInt, int minimo, int maximo);

int validarInt(char pResultadoInt [TAM_INT]);

int pedirTipoDePasajero(TypePassenger listTypePassenger [3], char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR],
					int *pResultadoInt, int minimo, int maximo);

int buscarLibre(Passenger *listPassenger, int tamanioDelArray);

int darAltaAlPasajero(Passenger *listPassenger, int tamanioDelArray, char mensajeNombre [TAM_STR], char mensajeErrorNombre [TAM_STR],
					char mensajeExitoNombre [TAM_STR], char mensajeErrorArray [TAM_STR], char mensajeApellido [TAM_STR], char mensajeErrorApellido [TAM_STR],
					char mensajeExitoApellido [TAM_STR], char mensajePrecio [TAM_STR], char mensajeErrorPrecio [TAM_STR], char mensajeExitoPrecio [TAM_STR],
					char mensajeCodigo [TAM_STR], char mensajeTipoDePasajero [TAM_STR], char mensajeErrorTipoDePasajero [TAM_STR],
					char mensajeExitoTipoDePasajero [TAM_STR], TypePassenger *listTypePassenger, char mensajeCargaCompleta [TAM_STR], int id, int minimo,
					int maximo);

int darBajaAlPasajero (Passenger *listPassenger, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR],
					char mensajeExitoId [TAM_STR], char mensajeErrorBaja [TAM_STR], char mensajeExitoBaja [TAM_STR], char mensajeErrorIdNoEncontrado [TAM_STR]);


int modificarAlPasajero(Passenger *listPassenger, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR],
					char mensajeExitoId [TAM_STR], char mensajeOpcion [TAM_STR], char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],
					char mensajeExitoModificar [TAM_STR], char mensajeModificarNombre [TAM_STR], char mensajeErrorModificarNombre [TAM_STR],
					char mensajeExitoModificarNombre [TAM_STR], char mensajeModificarApellido [TAM_STR], char mensajeErrorModificarApellido [TAM_STR],
					char mensajeExitoModificarApellido [TAM_STR], char mensajeModificarPrecio[TAM_STR], char mensajeErrorModificarPrecio [TAM_STR],
					char mensajeExitoModificarPrecio [TAM_STR], char mensajeModificarTipoDePasajero [TAM_STR], char mensajeErrorModificarTipoDePasajero [TAM_STR],
					char mensajeExitoModificarTipoDePasajero [TAM_STR], char mensajeModificarCodigoDeVuelo [TAM_STR],
					char mensajeErrorModificarCodigoDeVuelo [TAM_STR],char mensajeExitoModificarCodigoDeVuelo [TAM_STR]);

int modificarNombre (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],	char mensajeExitoModificar [TAM_STR], Passenger *pasajero);

int modificarApellido (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero);

int modificarPrecio (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero);

int modificarTipoDePasajero(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero,
		int minimo, int maximo);

int modificarCodigo(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero);


#endif /* RJIMENEZ_H_ */
