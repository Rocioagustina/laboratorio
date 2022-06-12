/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rJimenez.h"
#include "Passenger.h"
#define TAM_STR 256
#define TAM_NOMBRE 50
#define TAM_ESTADO_VUELO 30
#define TAM_CODIGO 30
#define TAM_INT 20
#define TRUE 1
#define FALSE 0
#define DATOS_PASAJEROS "Los datos de los pasajeros son:\n"



int Passenger_setId(Passenger* this, int id)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		this->id = id;
	}

	return retorno;
}

int Passenger_setIdStr(Passenger* this, char id [TAM_INT])
{
	int retorno;

	retorno = 0;

	if(this != NULL && id != NULL)
	{
		if(validarInt(id) == 0)
		{
			printf("HolaId\n");
			retorno = 1;
			Passenger_setId(this, atoi(id));
		}
	}

	return retorno;
}

int Passenger_getId(Passenger* this, int id)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		id = this->id;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this, char nombre [TAM_NOMBRE])
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		if(validarNombre(nombre) == 0)
		{
			printf("HolaNombre\n");
			retorno = 1;
			strncpy(this->nombre, nombre, TAM_NOMBRE);
		}
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this, char nombre [TAM_NOMBRE])
{
	int retorno;

	retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		retorno = 1;
		strncpy(nombre, this->nombre, TAM_NOMBRE);
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this, char apellido [TAM_NOMBRE])
{
	int retorno;

	retorno = 0;

	if(this != NULL && apellido != NULL)
	{
			printf("HolaApellido\n");
			retorno = 1;
			strncpy(this->apellido, apellido, TAM_NOMBRE);
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this, char apellido [TAM_NOMBRE])
{
	int retorno;

	retorno = 0;

	if(this != NULL && apellido != NULL)
	{
		retorno = 1;
		strncpy(apellido, this->apellido, TAM_NOMBRE);
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char codigoVuelo [TAM_CODIGO])
{
	int retorno;

	retorno = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		printf("HolaCodeVuelo\n");
		retorno = 1;
		strncpy(this->codigoVuelo, codigoVuelo, TAM_CODIGO);
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char codigoVuelo [TAM_CODIGO])
{
	int retorno;

	retorno = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 1;
		strncpy(codigoVuelo, this->codigoVuelo, TAM_CODIGO);
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, char tipoPasajero [TAM_INT])
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		this->tipoPasajero = cambiarTipoDePasajeroCharAEntero (tipoPasajero);
	}

	return retorno;
}

int Passenger_setTipoPasajeroStr(Passenger* this, char tipoPasajero [TAM_INT])
{
	int retorno;

	retorno = 0;

	if(this != NULL && tipoPasajero != NULL)
	{
		if(validarInt(tipoPasajero) == 0 )
		{
			printf("HolaTipoPasajero\n");
			retorno = 1;
			Passenger_setTipoPasajero(this, atoi(tipoPasajero));
		}
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		tipoPasajero = this->tipoPasajero;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		printf("HolaPrecio\n");
		retorno = 1;
		this->precio = precio;
	}

	return retorno;
}

int Passenger_setPrecioStr(Passenger* this, char precio [TAM_STR])
{
	int retorno;

	retorno = 0;

	if(this != NULL && precio != NULL)
	{
		if(validarFloat(precio) == 0)
		{
			retorno = 1;
			Passenger_setPrecio(this, atof(precio));
		}
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this, float precio)
{
	int retorno;

	retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		precio = this->precio;
	}

	return retorno;
}


int Passenger_setEstadoVuelo(Passenger* this, char estadoVuelo [TAM_ESTADO_VUELO])
{
	int retorno;

	retorno = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		if(validarNombre(estadoVuelo) == 0)
		{
			printf("HolaEstadoVuelo\n");
			retorno = 1;
			strncpy(this->estadoVuelo, estadoVuelo, TAM_ESTADO_VUELO);
		}
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this, char estadoVuelo [TAM_ESTADO_VUELO])
{
	int retorno;

	retorno = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 1;
		strncpy(estadoVuelo, this->estadoVuelo, TAM_ESTADO_VUELO);
	}

	return retorno;
}
Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}


Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	Passenger* retorno = NULL;
	Passenger* pasajero = NULL;

    if (id > 0 && nombre != NULL &&  apellido != NULL && tipoPasajero > 0 && codigoVuelo != NULL && precio > 0 && estadoVuelo != NULL)
    {
    	pasajero = Passenger_new();
        if (Passenger_setId(pasajero, id) && Passenger_setNombre(pasajero, nombre) && Passenger_setApellido(pasajero, apellido) &&
        	Passenger_setPrecio(pasajero, precio) && Passenger_setTipoPasajero(pasajero, tipoPasajero) && Passenger_setCodigoVuelo(pasajero, codigoVuelo)
			&& Passenger_setEstadoVuelo(pasajero, estadoVuelo))
        {
            retorno = pasajero;
        } else
        {
        	Passenger_delete(pasajero);
        }
    }

    return retorno;
}

Passenger* Passenger_newParametrosStr(char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
	Passenger* retorno = NULL;
	Passenger* pasajero = NULL;

	if (id != NULL && nombre != NULL &&  apellido != NULL && tipoPasajero != NULL && codigoVuelo != NULL && precio != NULL && estadoVuelo != NULL)
	    {
	    	pasajero = Passenger_new();
	        if (Passenger_setIdStr(pasajero, id) && Passenger_setNombre(pasajero, nombre) && Passenger_setApellido(pasajero, apellido) &&
	        	Passenger_setPrecioStr(pasajero, precio) && Passenger_setTipoPasajeroStr(pasajero, tipoPasajero) && Passenger_setCodigoVuelo(pasajero,
	        	codigoVuelo) && Passenger_setEstadoVuelo(pasajero, estadoVuelo))
	        {
	            retorno = pasajero;
	        } else
	        {
	        	Passenger_delete(pasajero);
	        }
	    }
	return retorno;
}


int Passenger_delete(Passenger* this)
{
	int retorno;

	retorno = FALSE;
	if(this != NULL)
	{
		free((void*)this);
		retorno = TRUE;
	}
	return retorno;
}

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
			if(strcmp(listPassenger[i].apellido, listPassenger[i+1].apellido) > 0 && (listPassenger[i].isEmpty == 0 && listPassenger[i].isEmpty == 0))
			{
				swapPassenger(&listPassenger[i], &listPassenger[i+1]);
				bandera = 1;
			} else if (strcmp(listPassenger[i].apellido, listPassenger[i+1].apellido) == 0 && listPassenger[i].tipoPasajero > listPassenger[i+1].tipoPasajero)
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
	printf("%s\n", pasajero.nombre);
	printf("%s\n", pasajero.apellido);
	printf("%f\n", pasajero.precio);
	printf("%s\n", pasajero.codigoVuelo);
	printf("%d\n", pasajero.tipoPasajero);
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
				if(strcmp(listPassenger[i].codigoVuelo, listPassenger[i+1].codigoVuelo) > 0 && (listPassenger[i].isEmpty == 0 &&
						listPassenger[i].isEmpty == 0))
				{
					swapPassenger(&listPassenger[i], &listPassenger[i+1]);
					bandera = 1;
				}
			}
		}while (bandera);
}

