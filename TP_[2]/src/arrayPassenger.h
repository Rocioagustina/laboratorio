/*
 * arrayPassenger.h
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


struct
{
 int id;
 char name[51];
 char lastName[51];
 float price;
 char flyCode[10];
 int typePassenger;
 int statusFlight;
 int isEmpty;
}typedef Passenger;

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

#endif /* ARRAYPASSENGER_H_ */
