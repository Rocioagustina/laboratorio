/*
 * arrayPassenger.c
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"

#define DATOS_PASAJEROS "Los datos de los pasajeros son:\n"

void initPassengers(Passenger *listPassenger, int tamanioDelArray)
{
	int i;

	for(i = 0; i < tamanioDelArray; i++)
	{
		listPassenger[i].isEmpty = 1;
	}
}

void addPassengers(Passenger *isEmpty, Passenger pasajeroCargado)
{
	*isEmpty = pasajeroCargado;
}

int findPassengerById(Passenger *listPassenger, int tamanioDelArray, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < tamanioDelArray; i++)
	{
		if(listPassenger[i].id == id && listPassenger[i].isEmpty == 0)
		{
			retorno = i;
			break;
		}
	}


	return retorno;
}

void removePassenger(Passenger *pasajero)
{
	pasajero->isEmpty = 1;
}
/*
sortPassengers()
{

}
*/
void mostrarUnPasajero(Passenger pasajero)
{

	printf("%d\n", pasajero.id);
	printf("%s\n", pasajero.name);
	printf("%s\n", pasajero.lastName);
	printf("%f\n", pasajero.price);
	printf("%s\n", pasajero.flyCode);
	printf("%d\n", pasajero.typePassenger);
	printf("%d\n\n", pasajero.statusFlight);

}

void printPassengers(Passenger listPassenger [2000])
{
	int i;

	printf(DATOS_PASAJEROS);

	for(i = 0; i < 2000; i++)
	{
		if(listPassenger[i].isEmpty == 0)
		{
			mostrarUnPasajero(listPassenger[i]);
		}


	}

}

/*void sortPassengersByCode()
{


}
*/
