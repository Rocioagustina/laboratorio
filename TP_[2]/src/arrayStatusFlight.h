/*
 * arrayStatusFlight.h
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */

#ifndef ARRAYSTATUSFLIGHT_H_
#define ARRAYSTATUSFLIGHT_H_
#define TAM_ESTADO 256

struct
{
 int id;
 char estado[TAM_ESTADO];
} typedef StatusFlight;

void inicializarEstadoDelVuelo(StatusFlight listStatusFlight [3]);

void mostrarEstadoDelVuelo(StatusFlight listStatusFlight [3]);

#endif /* ARRAYSTATUSFLIGHT_H_ */
