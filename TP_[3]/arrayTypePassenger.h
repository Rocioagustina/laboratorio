/*
 * arrayTypePassenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */

#ifndef ARRAYTYPEPASSENGER_H_
#define ARRAYTYPEPASSENGER_H_
#define TAM_DESCRIPCION 256
#define TAM_TIPO_PASAJERO 3

struct
{
 int id;
 char descripcion[TAM_DESCRIPCION];
}typedef TypePassenger;

void inicializarTipoDePasajero (TypePassenger listTypePassenger [TAM_TIPO_PASAJERO]);

void mostrarTipoDePasajero(TypePassenger listTypePassenger [TAM_TIPO_PASAJERO]);

#endif /* ARRAYTYPEPASSENGER_H_ */
