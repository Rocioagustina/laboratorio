/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define TAM_NOMBRE 50
#define TAM_CODIGO 30
#define TAM_INT 20
#define TAM_ESTADO_VUELO 30

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[30];
	char estadoVuelo [30];
	int isEmpty;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo, char* estadoVuelo);
Passenger* Passenger_newParametrosStr(char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);

int Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this, int id);
int Passenger_getId(Passenger* this, int id);

int Passenger_setNombre(Passenger* this, char nombre [TAM_NOMBRE]);
int Passenger_getNombre(Passenger* this, char nombre [TAM_NOMBRE]);

int Passenger_setApellido(Passenger* this, char apellido [TAM_NOMBRE]);
int Passenger_getApellido(Passenger* this, char apellido [TAM_NOMBRE]);

int Passenger_setCodigoVuelo(Passenger* this, char codigoVuelo [TAM_CODIGO]);
int Passenger_getCodigoVuelo(Passenger* this, char codigoVuelo [TAM_CODIGO]);

int Passenger_setTipoPasajero(Passenger* this, char tipoPasajero [TAM_INT]);
int Passenger_getTipoPasajero(Passenger* this, int tipoPasajero);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this, float precio);

int Passenger_setEstadoVuelo(Passenger* this, char estadoVuelo [TAM_ESTADO_VUELO]);
int Passenger_getEstadoVuelo(Passenger* this, char estadoVuelo [TAM_ESTADO_VUELO]);

void initPassengers(Passenger *listPassenger, int tamanioDelArray);

int findPassengerById(Passenger *listPassenger, int tamanioDelArray, int id);

void printPassengers(Passenger listPassenger [2000]);

void mostrarUnPasajero(Passenger pasajero);

void removePassenger(Passenger *pasajero);

void addPassengers(Passenger *isEmpty, Passenger pasajeroCargado);

void HardcodePasajero (Passenger listPassenger [2000]);

void sortPassengers(Passenger *listPassenger, int tamanioDelArray);

void sortPassengersByCode(Passenger *listPassenger, int tamanioDelArray);

void swapPassenger(Passenger *pasajeroA, Passenger *pasajeroB);





#endif /* PASSENGER_H_ */
