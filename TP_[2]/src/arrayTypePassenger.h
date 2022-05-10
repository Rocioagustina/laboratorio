/*
 * arrayTypePassenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */

#ifndef ARRAYTYPEPASSENGER_H_
#define ARRAYTYPEPASSENGER_H_
#define TAM_DESCRIPCION 256


struct
{
 int id;
 char descripcion[TAM_DESCRIPCION];
}typedef TypePassenger;

void inicializarTipoDePasajero (TypePassenger listTypePassenger [3]);

#endif /* ARRAYTYPEPASSENGER_H_ */
