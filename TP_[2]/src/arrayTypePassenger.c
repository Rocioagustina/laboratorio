/*
 * arrayTypePassenger.c
 *
 *  Created on: 9 may. 2022
 *      Author: rocio
 */
#include "arrayTypePassenger.h"



void inicializarTipoDePasajero(TypePassenger listTypePassenger [3])
{
	listTypePassenger[0].id = 1;
	listTypePassenger[0].descripcion = "Clase Economica";

	listTypePassenger[1].id = 2;
	listTypePassenger[1].descripcion = "Clase Bussiness";

	listTypePassenger[2].id = 3;
	listTypePassenger[2].descripcion = "Primera Clase";
}

void mostrarTipoDePasajero(TypePassenger listTypePassenger [3])
{
	int i;

	printf("Los tipos de pasajero son: \n\n");


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listTypePassenger[i].id);
		printf("%s \n\n", listTypePassenger[i].descripcion);
	}
}
