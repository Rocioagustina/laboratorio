/*
 * arrayStatusFlight.c
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStatusFlight.h"

#define PUNTUAL "En horario"
#define ATRASADO "Atrasado"
#define CANCELADO "Cancelado"
#define ESTADOS_VUELOS "Los estados de vuelos son: \n\n"


void inicializarEstadoDelVuelo(StatusFlight listStatusFlight [3])
{
	listStatusFlight[0].id = 1;
	strcpy(listStatusFlight[0].estado, PUNTUAL);

	listStatusFlight[1].id = 2;
	strcpy(listStatusFlight[1].estado, ATRASADO);

	listStatusFlight[2].id = 3;
	strcpy(listStatusFlight[2].estado, CANCELADO);
}


void mostrarEstadoDelVuelo(StatusFlight listStatusFlight [3])
{
	int i;

	printf(ESTADOS_VUELOS);


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listStatusFlight[i].id);
		printf("%s \n\n", listStatusFlight[i].estado);
	}
}
