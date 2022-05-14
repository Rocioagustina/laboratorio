/*
 * arrayPassenger.c
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void sortPassengers(Passenger *listPassenger, int tamanioDelArray)
{
   int bandera;
	do
	{
		bandera = 0;
		for (int i = 0; i < tamanioDelArray - 1; i++)
		{
			if(strcmp(listPassenger[i].lastName, listPassenger[i+1].lastName))
			{
				swapPassenger(&listPassenger[i], &listPassenger[i+1]);
				bandera = 1;
			} else if (strcmp(listPassenger[i].lastName, listPassenger[i+1].lastName) == 1 && listPassenger[i].typePassenger > listPassenger[i+1].typePassenger)
			{
				swapPassenger(&listPassenger[i], &listPassenger[i+1]);
				bandera = 1;
			}
		}
	}while (bandera);
}


void swapPassenger(Passenger *pasajeroA, Passenger *pasajeroB)
{
	Passenger buffer;
    buffer = *pasajeroA;
    *pasajeroA = *pasajeroB;
    *pasajeroB = buffer;
}


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



void HardcodePasajero (Passenger listPassenger [2000])
{
	listPassenger[0].id = 1;
	listPassenger[0].statusFlight = 1;
	listPassenger[0].typePassenger = 1;
	listPassenger[0].price = 123.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Tomas");
	strcpy(listPassenger[0].lastName, "Olivieri");
	strcpy(listPassenger[0].flyCode, "AABBCC");


	listPassenger[0].id = 2;
	listPassenger[0].statusFlight = 1;
	listPassenger[0].typePassenger = 2;
	listPassenger[0].price = 4580.70;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Rocio");
	strcpy(listPassenger[0].lastName, "Jimenez");
	strcpy(listPassenger[0].flyCode, "AABBCC");


	listPassenger[0].id = 3;
	listPassenger[0].statusFlight = 2;
	listPassenger[0].typePassenger = 1;
	listPassenger[0].price = 11123.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Elsa");
	strcpy(listPassenger[0].lastName, "Cañu");
	strcpy(listPassenger[0].flyCode, "BBCCAA");


	listPassenger[0].id = 4;
	listPassenger[0].statusFlight = 2;
	listPassenger[0].typePassenger = 2;
	listPassenger[0].price = 12345.00;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Pablo");
	strcpy(listPassenger[0].lastName, "Olivieri");
	strcpy(listPassenger[0].flyCode, "CCAABB");


	listPassenger[0].id = 5;
	listPassenger[0].statusFlight = 3;
	listPassenger[0].typePassenger = 1;
	listPassenger[0].price = 11223.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Lucas");
	strcpy(listPassenger[0].lastName, "Olivieri");
	strcpy(listPassenger[0].flyCode, "CCAABB");


	listPassenger[0].id = 6;
	listPassenger[0].statusFlight = 3;
	listPassenger[0].typePassenger = 2;
	listPassenger[0].price = 14423.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Sebastian");
	strcpy(listPassenger[0].lastName, "Olivieri");
	strcpy(listPassenger[0].flyCode, "BBAACC");


	listPassenger[0].id = 7;
	listPassenger[0].statusFlight = 3;
	listPassenger[0].typePassenger = 3;
	listPassenger[0].price = 125673.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Gustavo");
	strcpy(listPassenger[0].lastName, "Olivieri");
	strcpy(listPassenger[0].flyCode, "BBAACC");


	listPassenger[0].id = 8;
	listPassenger[0].statusFlight = 1;
	listPassenger[0].typePassenger = 1;
	listPassenger[0].price = 120973.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Hugo");
	strcpy(listPassenger[0].lastName, "Jimenez");
	strcpy(listPassenger[0].flyCode, "AACCBB");


	listPassenger[0].id = 9;
	listPassenger[0].statusFlight = 1;
	listPassenger[0].typePassenger = 2;
	listPassenger[0].price = 120971.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Belen");
	strcpy(listPassenger[0].lastName, "Jimenez");
	strcpy(listPassenger[0].flyCode, "CCBBAA");


	listPassenger[0].id = 10;
	listPassenger[0].statusFlight = 1;
	listPassenger[0].typePassenger = 3;
	listPassenger[0].price = 220973.50;
	listPassenger[0].isEmpty = 0;
	strcpy(listPassenger[0].name, "Maria");
	strcpy(listPassenger[0].lastName, "Picosta");
	strcpy(listPassenger[0].flyCode, "BBCCAA");
}
