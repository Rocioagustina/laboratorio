/*
 * rJimenez.c
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rJimenez.h"
#include "arrayPassenger.h"

#define TAM_STR 256
#define TAM_NOMBRE 51
#define TAM_INT 20
#define ELECCION_DE_MODIFICACION "¿Que dato desea modificar?\n\n"
#define MODIFICAR_NOMBRE "1. Nombre\n"
#define MODIFICAR_APELLIDO "2. Apellido\n"
#define MODIFICAR_PRECIO "3. Precio\n"
#define MODIFICAR_TIPO_DE_PASAJERO "4. Tipo de pasajero\n"
#define MODIFICAR_CODIGO_DE_VUELO "5. Codigo de vuelo\n"


/// @fn int pedirFloat(char[], char[], char[], float*)
/// @brief Pide y valida un numero flotante.
///
/// @param mensaje Es el mensaje que pide el numero flotante.
/// @param mensajeError El mensaje que indica que se ingreso un numero incorrecto.
/// @param mensajeExito El mensaje que indica que se ingreso un numero correcto
/// @param pResultado El puntero donde se guarda el numero flotante
/// @return  1 si todo sale bien y 0 si hay algun error.

int pedirFloat (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], float *pResultado)
{
	int retorno;
	char floatSinValidar [TAM_STR];

	retorno = 1;

	printf(mensaje);
	scanf("%s", floatSinValidar);

	if(validarFloat(floatSinValidar) == 0)
	{
		printf(mensajeExito);
		*pResultado = atof(floatSinValidar);
		retorno = 0;
	}
	else
	{
		printf(mensajeError);
	}

	return retorno;
}


/// @fn int validarFloat(char[])
/// @brief Valida un numero flotante.
///
/// @param resultado El numero a validar
/// @return 1 si todo sale bien y 0 si hay algun error.

int validarFloat (char resultado [TAM_STR])
{
	int retorno;
	int banderaFlotante;
	int i;

	retorno = 0;
	banderaFlotante = 0;


	for(i=0 ; i<strlen(resultado) ; i++)
	{
		if(resultado [i] < '0' || resultado [i] > '9')
		{
			if (resultado [i] == '.')
			{
				if (banderaFlotante == 1)
				{
					retorno = 1;
					break;
				}
			banderaFlotante = 1;
			}else
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int pedirNombre(char[], char[], char[], char*)
/// @brief Pide una cadena de caracteres
///
/// @param mensaje El mensaje para pedir el nombre
/// @param mensajeError El mensaje que devuelve si se ingreso mal el nombre
/// @param mensajeExito El mensaje que devuelve si se ingreso bien el nombre
/// @param pResultadoNombre El puntero donde se guarda el nombre
/// @return 0 si sale todo bien y 1 si hay algun error

int pedirNombre (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoNombre)
{
	int retorno;
	char nombreSinValidar[TAM_NOMBRE];

	retorno = 1;

	printf(mensaje);
	scanf("%s", nombreSinValidar);

	if(validarNombre(nombreSinValidar) == 0)
	{
		retorno = 0;
		strcpy(pResultadoNombre, nombreSinValidar);
		printf(mensajeExito);
	}
	else
	{
		printf(mensajeError);
	}

	return retorno;
}

/// @fn int validarNombre(char[])
/// @brief Valida una cadena de caracteres
///
/// @param nombreSinValidar El nombre a validar
/// @return 0 si sale todo bien y 1 si hay algun error

int validarNombre (char nombreSinValidar [TAM_NOMBRE])
{
	int retorno;
	int i;

	retorno = 0;

	for(i = 0; i < strlen (nombreSinValidar); i++)
	{
		if((nombreSinValidar [i] < 'a' || nombreSinValidar [i] > 'z') && (nombreSinValidar [i] < 'A' || nombreSinValidar [i] > 'Z'))
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}


/// @fn int pedirCodigo(char[], char[], char[], char*)
/// @brief Pide el codigo del vuelo
///
/// @param mensaje El mensaje para pedir el codigo
/// @param pResultadoCodigo El puntero donde se guarda el codigo
/// @return 0

int pedirCodigo (char mensaje [TAM_STR], char *pResultadoCodigo)
{
	int retorno;

	retorno = 0;

	printf(mensaje);
	scanf("%s", pResultadoCodigo);

	return retorno;
}


/// @fn int pedirInt(char[], int*)
/// @brief Pide un numero entero
///
/// @param mensaje Es el mensaje que pide un numero entero
/// @param pResultadoInt El puntero donde se guarda el entero
/// @return 0 si sale todo bien y 1 si hay algun error

int pedirInt(char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], int *pResultadoInt, int minimo, int maximo)
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	int numeroNoValidado;

	retorno = 0;

	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (validarInt(numeroSinValidar) == 0)
	{
		numeroNoValidado = atoi(numeroSinValidar);

		if(numeroNoValidado < maximo && numeroNoValidado > minimo)
		{
			*pResultadoInt = numeroNoValidado;
			printf(mensajeExito);
		}
		else
		{
			retorno = 1;
			printf(mensajeError);
		}
	} else
	{
		retorno = 1;
		printf(mensajeError);
	}

	return retorno;
}

/// @fn int validarInt(char[])
/// @brief Valida que el numero sea un entero
///
/// @param pResultadoInt Es el puntero donde se guarda el entero validado
/// @return 0 si sale todo bien y 1 si hay algun error

int validarInt(char pResultadoInt [TAM_INT])
{
	int retorno;
	int i;

	retorno = 0;

	for(i=0 ; i<strlen(pResultadoInt) ; i++)
	{
		if(pResultadoInt [i] < '0' || pResultadoInt [i] > '9')
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

/// @fn int pedirTipoDePasajero(TypePassenger[], char[], char[], char[], int*)
/// @brief Pide el tipo de pasajero
///
/// @param listTypePassenger
/// @param mensaje Es el mensaje que pide el tipo de pasajero
/// @param mensajeError Es el mensaje que indica que hay un error en lo que se ingreso
/// @param mensajeExito Es el mensaje que indica que lo que se ingreso esta bien
/// @param pResultadoInt Es el puntero donde se guarda el tipo de pasajero
/// @return 0 si esta todo bien y 1 si hay algun error

int pedirTipoDePasajero(TypePassenger listTypePassenger [3], char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR],
					int *pResultadoInt, int minimo, int maximo)
{
	int retorno;

	retorno = 0;

	mostrarTipoDePasajero(listTypePassenger);

	if(pedirInt(mensaje, mensajeError, mensajeExito, pResultadoInt, minimo, maximo) == 1)
	{
		retorno = 1;
	}
	return retorno;
}


/// @fn int pedirEstadoDeVuelo(StatusFlight[], char[], char[], char[], int*)
/// @brief Pide el estado del vuelo
///
/// @param listStatusFlight
/// @param mensaje Es Es el mensaje que pide el estado del vuelo
/// @param mensajeError Es el mensaje que indica que hay un error en lo que se ingreso
/// @param mensajeExito Es el mensaje que indica que lo que se ingreso esta bien
/// @param pResultadoInt Es el puntero donde se guarda el estado del vuelo
/// @return 0 si esta todo bien y 1 si hay algun error

int pedirEstadoDeVuelo(StatusFlight listStatusFlight [3], char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR],
					int *pResultadoInt, int minimo, int maximo)
{
	int retorno;

	retorno = 0;

	mostrarEstadoDelVuelo(listStatusFlight);

	if(pedirInt(mensaje, mensajeError, mensajeExito, pResultadoInt, minimo, maximo) == 1)
	{
		retorno = 1;
	}
	return retorno;
}

/// @fn int buscarLibre(Passenger*, int)
/// @brief Busca un lugar libre en el array para posicionar el id
///
/// @param listPassenger
/// @param tamanioDelArray
/// @return -1 si no hay mas lugar y un numero si encontro un lugar

int buscarLibre(Passenger *listPassenger, int tamanioDelArray)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < tamanioDelArray; i++)
	{
		if(listPassenger[i].isEmpty != 0)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}



/// @fn int darAltaAlPasajero(Passenger*, int)
/// @brief
///
/// @param listPassenger
/// @param tamanioDelArray
/// @return

int darAltaAlPasajero(Passenger *listPassenger, int tamanioDelArray, char mensajeNombre [TAM_STR], char mensajeErrorNombre [TAM_STR],
					char mensajeExitoNombre [TAM_STR], char mensajeErrorArray [TAM_STR], char mensajeApellido [TAM_STR], char mensajeErrorApellido [TAM_STR],
					char mensajeExitoApellido [TAM_STR], char mensajePrecio [TAM_STR], char mensajeErrorPrecio [TAM_STR], char mensajeExitoPrecio [TAM_STR],
					char mensajeCodigo [TAM_STR], char mensajeTipoDePasajero [TAM_STR], char mensajeErrorTipoDePasajero [TAM_STR],
					char mensajeExitoTipoDePasajero [TAM_STR], char mensajeEstadoDeVuelo [TAM_STR], char mensajeErrorEstadoDeVuelo [TAM_STR],
					char mensajeExitoEstadoDeVuelo [TAM_STR], TypePassenger *listTypePassenger, StatusFlight *listStatusFlight,
					char mensajeCargaCompleta [TAM_STR], int id, int minimo, int maximo)
{
	int retorno;
	Passenger aux;
	int indice;

	retorno = -1;


	indice = buscarLibre(listPassenger, tamanioDelArray);

	if(indice != -1)
	{
		if(pedirNombre(mensajeNombre, mensajeErrorNombre, mensajeExitoNombre, aux.name) == 0)
		{
			if(pedirNombre(mensajeApellido, mensajeErrorApellido, mensajeExitoApellido, aux.lastName) == 0)
			{
				if(pedirFloat(mensajePrecio, mensajeErrorPrecio, mensajeExitoPrecio, &aux.price) == 0)
				{
					if(pedirCodigo(mensajeCodigo, aux.flyCode) == 0)
					{
						if(pedirTipoDePasajero(listTypePassenger, mensajeTipoDePasajero, mensajeErrorTipoDePasajero, mensajeExitoTipoDePasajero,
								&aux.typePassenger, minimo, maximo) == 0)
						{
							if(pedirEstadoDeVuelo(listStatusFlight, mensajeEstadoDeVuelo, mensajeErrorEstadoDeVuelo, mensajeExitoEstadoDeVuelo,
								&aux.statusFlight, minimo, maximo) == 0)
							{
								printf(mensajeCargaCompleta);
								aux.id = id;
								aux.isEmpty = 0;
								addPassengers(&listPassenger[indice], aux);
								retorno = 0;

							}
						}
					}
				}
			}
		}
	}
	else
	{
		printf(mensajeErrorArray);
	}


	return retorno;
}

int darBajaAlPasajero (Passenger *listPassenger, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR],
					char mensajeExitoId [TAM_STR], char mensajeErrorBaja [TAM_STR], char mensajeExitoBaja [TAM_STR],
					char mensajeErrorIdNoEncontrado [TAM_STR])
{
	int retorno;
	int idBorrar;
	int indice;


	retorno = 1;

	 printPassengers(listPassenger);

	 if(pedirInt(mensajeId, mensajeErrorId, mensajeExitoId, &idBorrar, 0, tamanioDelArray) == 0)
	 {
		 indice = findPassengerById(listPassenger, tamanioDelArray, idBorrar);
		 if(indice != -1)
		 {
			 removePassenger(&listPassenger[indice]);
			 printf(mensajeExitoBaja);
			 retorno = 0;
		 } else
		 {
			 printf(mensajeErrorIdNoEncontrado);
		 }
	 }
	 else
	 {
		 printf(mensajeErrorBaja);
	 }

	return retorno;
}


int modificarAlPasajero(Passenger *listPassenger, int tamanioDelArray, char mensajeId [TAM_STR], char mensajeErrorId [TAM_STR],
					char mensajeExitoId [TAM_STR], char mensajeOpcion [TAM_STR], char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],
					char mensajeExitoModificar [TAM_STR], char mensajeModificarNombre [TAM_STR], char mensajeErrorModificarNombre [TAM_STR],
					char mensajeExitoModificarNombre [TAM_STR], char mensajeModificarApellido [TAM_STR], char mensajeErrorModificarApellido [TAM_STR],
					char mensajeExitoModificarApellido [TAM_STR], char mensajeModificarPrecio[TAM_STR], char mensajeErrorModificarPrecio [TAM_STR],
					char mensajeExitoModificarPrecio [TAM_STR], char mensajeModificarTipoDePasajero [TAM_STR], char mensajeErrorModificarTipoDePasajero [TAM_STR],
					char mensajeExitoModificarTipoDePasajero [TAM_STR], char mensajeModificarCodigoDeVuelo [TAM_STR],
					char mensajeErrorModificarCodigoDeVuelo [TAM_STR],char mensajeExitoModificarCodigoDeVuelo [TAM_STR])
{
	int retorno;
	int idBorrar;
	int indice;
	int opcion;

	retorno = 1;

	printPassengers(listPassenger);

	if(pedirInt(mensajeId, mensajeErrorId, mensajeExitoId, &idBorrar, 0, tamanioDelArray) == 0)
	{
		 indice = findPassengerById(listPassenger, tamanioDelArray, idBorrar);
		 if(indice != -1)
		 {

			 printf(ELECCION_DE_MODIFICACION);
			 printf(MODIFICAR_NOMBRE);
			 printf(MODIFICAR_APELLIDO);
			 printf(MODIFICAR_PRECIO);
			 printf(MODIFICAR_TIPO_DE_PASAJERO);
			 printf(MODIFICAR_CODIGO_DE_VUELO);
			 printf(mensajeOpcion);
			 pedirInt(mensajeModificar, "Error en la modificacion", "Opcion ingresada correctamente", &opcion, 0,6);

			 switch(opcion)
			 {
			 case 1: if(modificarNombre (mensajeModificarNombre, mensajeErrorModificarNombre, mensajeExitoModificarNombre, &listPassenger[indice]) != -1)
					 {
						retorno = 0;
					 }
					break;


			 case 2: if(modificarApellido(mensajeModificarApellido, mensajeErrorModificarApellido, mensajeExitoModificarApellido, &listPassenger[indice])
					 != -1)
					 {
						 retorno = 0;
					 }
			 	 	break;

			 case 3: if(modificarPrecio(mensajeModificarPrecio, mensajeErrorModificarPrecio, mensajeExitoModificarPrecio, &listPassenger[indice]) != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;

			 case 4: if(modificarTipoDePasajero(mensajeModificarTipoDePasajero, mensajeErrorModificarTipoDePasajero, mensajeExitoModificarTipoDePasajero,
					 &listPassenger[indice], 0, 4) != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;

			 case 5:if(modificarCodigo(mensajeModificarCodigoDeVuelo, mensajeErrorModificarCodigoDeVuelo, mensajeExitoModificarCodigoDeVuelo,
					 &listPassenger[indice]) != -1)
			 	 	 {
				 	 	 retorno = 0;
			 	 	 }
				 break;
			 }
		 }
	}


	return retorno;
}


int modificarNombre (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR],	char mensajeExitoModificar [TAM_STR], Passenger *pasajero)
{
	int retorno;
	char nombreModificado[51];

	retorno = -1;


	retorno = pedirNombre(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, nombreModificado);
	if (retorno != -1)
	{
		strcpy(pasajero->name, nombreModificado);
	}

	return retorno;
}


int modificarApellido (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero)
{
	int retorno;
	char apellidoModificado[51];

	retorno = -1;

	retorno = pedirNombre(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar , apellidoModificado);
	if(retorno != -1)
	{
		strcpy(pasajero->lastName, apellidoModificado);
	}

	return retorno;
}


int modificarPrecio (char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero)
{
	int retorno;
	float precioModificado;

	retorno = -1;

	retorno = pedirFloat(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &precioModificado);
	if(retorno != -1)
	{
		pasajero->price = precioModificado;
	}

	return retorno;
}


int modificarTipoDePasajero(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero,
					int minimo, int maximo)
{
	int retorno;
	int tipoDePasajeroModificado;

	retorno = -1;

	retorno = pedirInt(mensajeModificar, mensajeErrorModificar, mensajeExitoModificar, &tipoDePasajeroModificado, 0, 4);
	if(retorno != -1)
	{
		pasajero->typePassenger = tipoDePasajeroModificado;
	}

	return retorno;
}


int modificarCodigo(char mensajeModificar [TAM_STR], char mensajeErrorModificar [TAM_STR], char mensajeExitoModificar [TAM_STR], Passenger *pasajero)
{
	int retorno;
	char codigoModificado [51];

	retorno = -1;

	retorno = pedirCodigo(mensajeModificar, codigoModificado);
	if(retorno != -1)
	{
		strcpy(pasajero->flyCode, codigoModificado);
	}

	return retorno;
}


void totalPromedioPasajero (Passenger *listPassenger, int tamanioDelArray)
{
	int contador;
	float promedio;
	float acumulador;
	int i;


	contador = 0;
	acumulador = 0;

	for (i = 0; i < tamanioDelArray; i++)
	{
		if (listPassenger[i].isEmpty == 0)
		{
			acumulador = listPassenger[i].price;
			contador++;
		}
	}
	promedio = acumulador / contador;

	printf ("El total de precios acumulados es: %f\n", acumulador);
	printf ("El promedio de todos los precios es: %f\n", promedio);
	printf ("Los pasajeros que superan el promedio del precio son: \n");

	for (i = 0; i < tamanioDelArray; i++)
	{
		if (listPassenger[i].price > promedio && listPassenger[i].isEmpty == 0)
		{
			mostrarUnPasajero(listPassenger[i]);
		}
	}
}


void mostrarOrdenadoPorApelidoTipo(Passenger *listPassenger, int tamanioDelArray)
{
	Passenger *aux;

	aux = listPassenger;

	sortPassengers(aux, tamanioDelArray);

	printPassengers(aux);
}


void ordenadoCodigoActivo(Passenger *listPassenger, int tamanioDelArray)
{
	int i;
	Passenger *aux;
	aux = listPassenger;

	sortPassengersByCode(aux, tamanioDelArray);
	printf("Los empleados ordenados por codigo con estado activo son: \n");

	for (i = 0; i < tamanioDelArray; i++)
	{
		if (aux[i].isEmpty == 0 && aux[i].statusFlight == 1)
		{
			mostrarUnPasajero(aux[i]);
		}
	}
}
