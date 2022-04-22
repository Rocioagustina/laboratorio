/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayPassenger.h"

#define MENSAJE_OPCION_UNO "1. ALTA \n"
#define PEDIR_NOMBRE_USUARIO "Ingrese su nombre: \n"
#define PEDIR_APELLIDO_USUARIO "Ingrese su apellido: \n"
#define PEDIR_PRECIO_DEL_VUELO "Ingrese el precio del vuelo: \n"
#define PEDIR_CODIGO_DEL_VUELO "Ingrese el codigo del vuelo: \n"
#define PEDIR_TIPO_DE_PASAJERO "Ingrese que tipo de pasajero es: \n"
#define PEDIR_ESTADO_DEL_VUELO "Ingrese el estado del vuelo: \n"
#define MENSAJE_OPCION_DOS "2. MODIFICACION \n"
#define MENSAJE_OPCION_TRES "3. BAJA \n"
#define MENSAJE_OPCION_CUATRO "4. INFORMAR \n\n"
#define MENSAJE_INFORMAR_UNO "1. Listado de los pasajeros ordenados alfabéticamente por apellido y tipo de pasajero \n"
#define MENSAJE_INFORMAR_DOS "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio \n"
#define MENSAJE_INFORMAR_TRES "3. Listado de los pasajeros por código de vuelo y estados de vuelos ‘ACTIVO’ \n\n"
#define MENSAJE_OPCION_CINCO "5. SALIR"


int main(void) {

	setbuf(stdout, NULL);
	int opcion;

	do
	{
		printf(MENSAJE_OPCION_UNO);
		printf(MENSAJE_OPCION_DOS);
		printf(MENSAJE_OPCION_TRES);
		printf(MENSAJE_OPCION_CUATRO);
		printf(MENSAJE_INFORMAR_UNO);
		printf(MENSAJE_INFORMAR_DOS);
		printf(MENSAJE_INFORMAR_TRES);
		printf(MENSAJE_OPCION_CINCO);
		scanf("%d", &opcion);


		switch(opcion)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}while(opcion != 5);




	return EXIT_SUCCESS;
}
