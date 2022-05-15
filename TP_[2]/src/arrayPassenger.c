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
			if(strcmp(listPassenger[i].lastName, listPassenger[i+1].lastName) > 0 && (listPassenger[i].isEmpty == 0 && listPassenger[i].isEmpty == 0))
			{
				swapPassenger(&listPassenger[i], &listPassenger[i+1]);
				bandera = 1;
			} else if (strcmp(listPassenger[i].lastName, listPassenger[i+1].lastName) == 0 && listPassenger[i].typePassenger > listPassenger[i+1].typePassenger)
			{
				swapPassenger(&listPassenger[i], &listPassenger[i+1]);
				bandera = 1;
			}
		}
	}while (bandera == 0);
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

void sortPassengersByCode(Passenger *listPassenger, int tamanioDelArray)
{
	   int bandera;
		do
		{
			bandera = 0;
			for (int i = 0; i < tamanioDelArray - 1; i++)
			{
				if(strcmp(listPassenger[i].flyCode, listPassenger[i+1].flyCode) > 0 && (listPassenger[i].isEmpty == 0 && listPassenger[i].isEmpty == 0))
				{
					swapPassenger(&listPassenger[i], &listPassenger[i+1]);
					bandera = 1;
				}
			}
		}while (bandera);
}




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


	listPassenger[1].id = 2;
	listPassenger[1].statusFlight = 1;
	listPassenger[1].typePassenger = 2;
	listPassenger[1].price = 4580.70;
	listPassenger[1].isEmpty = 0;
	strcpy(listPassenger[1].name, "Rocio");
	strcpy(listPassenger[1].lastName, "Jimenez");
	strcpy(listPassenger[1].flyCode, "AABBCC");


	listPassenger[2].id = 3;
	listPassenger[2].statusFlight = 2;
	listPassenger[2].typePassenger = 1;
	listPassenger[2].price = 11123.50;
	listPassenger[2].isEmpty = 0;
	strcpy(listPassenger[2].name, "Elsa");
	strcpy(listPassenger[2].lastName, "Cañu");
	strcpy(listPassenger[2].flyCode, "BBCCAA");


	listPassenger[3].id = 4;
	listPassenger[3].statusFlight = 2;
	listPassenger[3].typePassenger = 2;
	listPassenger[3].price = 12345.00;
	listPassenger[3].isEmpty = 0;
	strcpy(listPassenger[3].name, "Pablo");
	strcpy(listPassenger[3].lastName, "Olivieri");
	strcpy(listPassenger[3].flyCode, "CCAABB");


	listPassenger[4].id = 5;
	listPassenger[4].statusFlight = 3;
	listPassenger[4].typePassenger = 1;
	listPassenger[4].price = 11223.50;
	listPassenger[4].isEmpty = 0;
	strcpy(listPassenger[4].name, "Lucas");
	strcpy(listPassenger[4].lastName, "Olivieri");
	strcpy(listPassenger[4].flyCode, "CCAABB");


	listPassenger[5].id = 6;
	listPassenger[5].statusFlight = 3;
	listPassenger[5].typePassenger = 2;
	listPassenger[5].price = 14423.50;
	listPassenger[5].isEmpty = 0;
	strcpy(listPassenger[5].name, "Sebastian");
	strcpy(listPassenger[5].lastName, "Olivieri");
	strcpy(listPassenger[5].flyCode, "BBAACC");


	listPassenger[6].id = 7;
	listPassenger[6].statusFlight = 3;
	listPassenger[6].typePassenger = 3;
	listPassenger[6].price = 125673.50;
	listPassenger[6].isEmpty = 0;
	strcpy(listPassenger[6].name, "Gustavo");
	strcpy(listPassenger[6].lastName, "Olivieri");
	strcpy(listPassenger[6].flyCode, "BBAACC");


	listPassenger[7].id = 8;
	listPassenger[7].statusFlight = 1;
	listPassenger[7].typePassenger = 1;
	listPassenger[7].price = 120973.50;
	listPassenger[7].isEmpty = 0;
	strcpy(listPassenger[7].name, "Hugo");
	strcpy(listPassenger[7].lastName, "Jimenez");
	strcpy(listPassenger[7].flyCode, "AACCBB");


	listPassenger[8].id = 9;
	listPassenger[8].statusFlight = 1;
	listPassenger[8].typePassenger = 2;
	listPassenger[8].price = 120971.50;
	listPassenger[8].isEmpty = 0;
	strcpy(listPassenger[8].name, "Belen");
	strcpy(listPassenger[8].lastName, "Jimenez");
	strcpy(listPassenger[8].flyCode, "CCBBAA");


	listPassenger[9].id = 10;
	listPassenger[9].statusFlight = 1;
	listPassenger[9].typePassenger = 3;
	listPassenger[9].price = 220973.50;
	listPassenger[9].isEmpty = 0;
	strcpy(listPassenger[9].name, "Maria");
	strcpy(listPassenger[9].lastName, "Picosta");
	strcpy(listPassenger[9].flyCode, "BBCCAA");
}
