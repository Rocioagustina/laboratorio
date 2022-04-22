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

#endif /* ARRAYPASSENGER_H_ */
