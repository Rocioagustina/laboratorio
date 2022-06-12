#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#define TRUE 1
#define FALSE 0
#define TAM_BUFFER 1024

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPassenger;
	int retorno;
	int flagEncabezado;
	char bufferId [TAM_BUFFER];
	char bufferName [TAM_BUFFER];
	char bufferLastName [TAM_BUFFER];
	char bufferPrice [TAM_BUFFER];
	char bufferFlyCode [TAM_BUFFER];
	char bufferTypePassenger [TAM_BUFFER];
	char bufferStatusFlight [TAM_BUFFER];

	pPassenger = NULL;
	retorno = FALSE;

	if(pFile != NULL)
	{
		while(!feof(pFile))
		{
			if(flagEncabezado == TRUE)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastName, bufferPrice, bufferFlyCode,
						bufferTypePassenger, bufferStatusFlight);

				flagEncabezado = FALSE;
			}

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferLastName, bufferPrice, bufferFlyCode,
									bufferTypePassenger, bufferStatusFlight);

			pPassenger = Passenger_newParametrosStr(bufferId, bufferName, bufferLastName, bufferPrice, bufferFlyCode, bufferTypePassenger, bufferStatusFlight);

			if(pPassenger != NULL)
			{
				 ll_add(pArrayListPassenger, pPassenger);
				 retorno = TRUE;
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pPassenger;
	int retorno;
	int bufferId = 0;
	char bufferName [TAM_BUFFER];
	char bufferLastName [TAM_BUFFER];
	int bufferPrice = 0;
	char bufferFlyCode [TAM_BUFFER];
	int bufferTypePassenger = 0;
	char bufferStatusFlight [TAM_BUFFER];

	retorno = FALSE;

	  if(pFile!=NULL)
	    {
	        while(!feof(pFile))
	        {
	        	pPassenger = Passenger_new();
	            fread(pPassenger,sizeof(Passenger),1,pFile);
	            Passenger_getId(pPassenger, bufferId);
	            Passenger_getNombre(pPassenger, bufferName);
	            Passenger_getApellido(pPassenger, bufferLastName);
	            Passenger_getCodigoVuelo(pPassenger, bufferFlyCode);
	            Passenger_getTipoPasajero(pPassenger, bufferTypePassenger);
	            Passenger_getPrecio(pPassenger, bufferPrice);
	            Passenger_getEstadoVuelo(pPassenger, bufferStatusFlight);
	            if( bufferId >= 0 && strlen(bufferName) > 0 && strlen(bufferLastName) > 0 && strlen(bufferFlyCode) > 0 && bufferTypePassenger > 0 &&
	            	bufferPrice > 0 && strlen(bufferStatusFlight) > 0)
	            {
	                ll_add(pArrayListPassenger, pPassenger);
	                retorno = TRUE;
	            }
	        }
	    }

    return retorno;
}
