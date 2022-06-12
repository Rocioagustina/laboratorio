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

#define ECONOMICA "EconomyClass"
#define EJECUTIVA "ExecutiveClass"
#define PRIMERA "FirstClass"
#define TAM_TIPO_PASAJERO 3
#define TIPOS_PASAJEROS "Los tipos de pasajero son: \n\n"



void inicializarTipoDePasajero(TypePassenger listTypePassenger [TAM_TIPO_PASAJERO])
{
	listTypePassenger[0].id = 1;
	strcpy(listTypePassenger[0].descripcion, ECONOMICA);

	listTypePassenger[1].id = 2;
	strcpy(listTypePassenger[1].descripcion, EJECUTIVA);

	listTypePassenger[2].id = 3;
	strcpy(listTypePassenger[2].descripcion, PRIMERA);
}

void mostrarTipoDePasajero(TypePassenger listTypePassenger [TAM_TIPO_PASAJERO])
{
	int i;

	printf(TIPOS_PASAJEROS);


	for(i = 0; i < 3; i++)
	{
		printf("%d\n", listTypePassenger[i].id);
		printf("%s \n\n", listTypePassenger[i].descripcion);
	}
}

int cambiarTipoDePasajeroCharAEntero (char tipoPasajero [TAM_TIPO_PASAJERO])
{
	int retorno;

	if(strcmp(tipoPasajero, "FirstClass") == 0)
	{
		retorno = 3;
	}
	else
	{
		if (strcmp(tipoPasajero, "ExecutiveClass") == 0)
		{
			retorno = 2;
		}
		else
		{
			retorno = 1;
		}
	}

	return retorno;
}


void cambiarTipoDePasajeroEnteroAChar (int tipoPasajero, char* resultado)
{
	switch(tipoPasajero)
	{
	case 1:
		strcpy(resultado,"FirstClass");
		break;
	case 2:
		strcpy(resultado,"ExecutiveClass");
		break;
	case 3:
		strcpy(resultado,"EconomyClass");
		break;
	}
}
