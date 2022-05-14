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
#include <string.h>
#include "arrayPassenger.h"
#include "arrayTypePassenger.h"
#include "arrayStatusFlight.h"
#include "rJimenez.h"

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
#define TAMANIO_ARRAY_PASAJEROS 2000
#define MENSAJE_ERROR_NOMBRE "Error en el ingreso del nombre \n"
#define MENSAJE_EXITO_NOMBRE "El nombre ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_ARRAY "No se puede ingresar al pasajero ya que no hay mas espacio \n"
#define MENSAJE_ERROR_APELLIDO "Error en el ingreso del apellido \n"
#define MENSAJE_EXITO_APELLIDO "El apellido ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_PRECIO "Error en el ingreso del precio \n"
#define MENSAJE_EXITO_PRECIO "El precio ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_TIPO_DE_PASAJERO "Error en el ingreso del tipo de pasajero \n"
#define MENSAJE_EXITO_TIPO_DE_PASAJERO "El tipo de pasajero ha sido ingresado exitosamente \n"
#define MENSAJE_ERROR_ESTADO_DEL_VUELO "Error en el ingreso del estado del vuelo \n"
#define MENSAJE_EXITO_ESTADO_DEL_VUELO "El estado del vuelo ha sido ingresado exitosamente \n"
#define ALTA_COMPLETA "El alta del pasajero ha sido completada exitosamente \n"
#define MENSAJE_ID "Ingrese el ID del pasajero: \n"
#define MENSAJE_ERROR_ID "Error en el ingreso del ID \n"
#define MENSAJE_EXITO_ID "El ID fue ingresado correctamente \n"
#define MENSAJE_ERROR_BAJA "Error en la baja, no pudo realizarse \n"
#define MENSAJE_EXITO_BAJA "La baja del pasajero ha sido completada exitosamente \n"
#define MENSAJE_ID_NO_ENCONTRADO "ID no encontrado \n"
#define MENSAJE_PEDIR_OPCION "Ingrese una opcion: \n"
#define MENSAJE_MODIFICAR "Ingrese el dato que desea modificar: \n"
#define MENSAJE_ERROR_MODIFICAR "Error en la baja, no pudo realizarse \n"
#define MENSAJE_EXITO_MODIFICAR "La modificacion ha sido completada exitosamente \n"
#define MENSAJE_MODIFICAR_NOMBRE "Ingrese el nuevo nombre \n"
#define MENSAJE_ERROR_MODIFICAR_NOMBRE "Error en el ingreso del nombre, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_NOMBRE "El nombre ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_APELLIDO "Ingrese el nuevo apellido \n"
#define MENSAJE_ERROR_MODIFICAR_APELLIDO "Error en el ingreso del apellido, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_APELLIDO "El apellido ha sido modificado exitosamente \n"
#define MENSAJE_MODIFICAR_PRECIO "Ingrese el nuevo precio \n"
#define MENSAJE_ERROR_MODIFICAR_PRECIO "Error en el ingreso del precio, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_PRECIO "El precio fue modificado exitosamente \n"
#define MENSAJE_MODIFICAR_TIPO_DE_PASAJERO "Ingrese el nuevo tipo de pasajero \n"
#define MENSAJE_ERROR_MODIFICAR_TIPO_DE_PASAJERO "Error en el ingreso del tipo de pasajero, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_TIPO_DE_PASAJERO "El tipo de pasajero fue modificado exitosamente \n"
#define MENSAJE_MODIFICAR_CODIGO_DE_VUELO "Ingrese el nuevo codigo \n"
#define MENSAJE_ERROR_MODIFICAR_CODIGO_DE_VUELO "Error en el ingreso del codigo, no se pudo modificar \n"
#define MENSAJE_EXITO_MODIFICAR_CODIGO_DE_VUELO "El codigo fue modificado exitosamente \n"
#define FIN_DEL_PROCESO "Programa cerrado con exito"




int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	Passenger arrayPasajeros [TAMANIO_ARRAY_PASAJEROS];
	StatusFlight arrayEstadoDeVuelo [3];
	TypePassenger arrayTipoDePasajero [3];
	int id;

	id= 1;

	initPassengers(arrayPasajeros, TAMANIO_ARRAY_PASAJEROS);
	inicializarTipoDePasajero(arrayTipoDePasajero);
	inicializarEstadoDelVuelo(arrayEstadoDeVuelo);


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
			if(darAltaAlPasajero(arrayPasajeros, TAMANIO_ARRAY_PASAJEROS, PEDIR_NOMBRE_USUARIO, MENSAJE_ERROR_NOMBRE, MENSAJE_EXITO_NOMBRE,
				MENSAJE_ERROR_ARRAY, PEDIR_APELLIDO_USUARIO, MENSAJE_ERROR_APELLIDO, MENSAJE_EXITO_APELLIDO, PEDIR_PRECIO_DEL_VUELO, MENSAJE_ERROR_PRECIO,
				MENSAJE_EXITO_PRECIO, PEDIR_CODIGO_DEL_VUELO, PEDIR_TIPO_DE_PASAJERO, MENSAJE_ERROR_TIPO_DE_PASAJERO, MENSAJE_EXITO_TIPO_DE_PASAJERO,
				PEDIR_ESTADO_DEL_VUELO, MENSAJE_ERROR_ESTADO_DEL_VUELO, MENSAJE_EXITO_ESTADO_DEL_VUELO, arrayTipoDePasajero, arrayEstadoDeVuelo,
				ALTA_COMPLETA, id, 0, 4) == 0)
			{
				id++;
			}

			break;
		case 2: modificarAlPasajero(arrayPasajeros, TAMANIO_ARRAY_PASAJEROS, MENSAJE_ID, MENSAJE_ERROR_ID, MENSAJE_EXITO_ID, MENSAJE_PEDIR_OPCION,
				MENSAJE_MODIFICAR, MENSAJE_ERROR_MODIFICAR, MENSAJE_EXITO_MODIFICAR, MENSAJE_MODIFICAR_NOMBRE, MENSAJE_ERROR_MODIFICAR_NOMBRE,
				MENSAJE_EXITO_MODIFICAR_NOMBRE, MENSAJE_MODIFICAR_APELLIDO, MENSAJE_ERROR_MODIFICAR_APELLIDO, MENSAJE_EXITO_MODIFICAR_APELLIDO,
				MENSAJE_MODIFICAR_PRECIO, MENSAJE_ERROR_MODIFICAR_PRECIO, MENSAJE_EXITO_MODIFICAR_PRECIO, MENSAJE_MODIFICAR_TIPO_DE_PASAJERO,
				MENSAJE_ERROR_MODIFICAR_TIPO_DE_PASAJERO, MENSAJE_EXITO_MODIFICAR_TIPO_DE_PASAJERO, MENSAJE_MODIFICAR_CODIGO_DE_VUELO,
				MENSAJE_ERROR_MODIFICAR_CODIGO_DE_VUELO, MENSAJE_EXITO_MODIFICAR_CODIGO_DE_VUELO);
			break;
		case 3: darBajaAlPasajero(arrayPasajeros, TAMANIO_ARRAY_PASAJEROS, MENSAJE_ID, MENSAJE_ERROR_ID, MENSAJE_EXITO_ID, MENSAJE_ERROR_BAJA,
				MENSAJE_EXITO_BAJA, MENSAJE_ID_NO_ENCONTRADO);
			break;
		case 4:
			break;
		case 5: printf(FIN_DEL_PROCESO);
			break;
		}
	}while(opcion != 5);




	return EXIT_SUCCESS;
}
