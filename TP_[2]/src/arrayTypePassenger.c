/*
 * arrayTypePassenger.c
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTypePassenger.h"

#define ECONOMICA "Clase economica"
#define EJECUTIVA "Clase ejecutiva"
#define PRIMERA "Primera clase"
#define TIPOS_PASAJEROS "Los tipos de pasajero son: \n\n"



void inicializarTipoDePasajero(TypePassenger listTypePassenger [3])
{
	listTypePassenger[0].id = 1;
	strcpy(listTypePassenger[0].descripcion, ECONOMICA);

	listTypePassenger[1].id = 2;
	strcpy(listTypePassenger[1].descripcion, EJECUTIVA);

	listTypePassenger[2].id = 3;
	strcpy(listTypePassenger[2].descripcion, PRIMERA);
}

void mostrarTipoDePasajero(TypePassenger listTypePassenger [3])
{
	int i;

	printf(TIPOS_PASAJEROS);


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listTypePassenger[i].id);
		printf("%s \n\n", listTypePassenger[i].descripcion);
	}
}

