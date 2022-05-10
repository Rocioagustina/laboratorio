/*
 * rJimenez.c
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */


#include <stdio.h>
#include <stdlib.h>
#include "rJimenez.h"

#define TAM_STR 256
#define TAM_NOMBRE 51
#define TAM_INT 20

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

	retorno = 0;

	printf(mensaje);
	scanf("%s", floatSinValidar);

	if(validarFloat(floatSinValidar) == 0)
	{
		printf(mensajeExito);
		*pResultado = atof(floatSinValidar);
		retorno = 1;
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
		strncopy(pResultadoNombre, nombreSinValidar);
	}


	return retorno;
}

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

int pedirCodigo (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoCodigo)
{
	int retorno;

	retorno = 0;

	printf(mensaje);
	scanf("%s", pResultadoCodigo);

	return retorno;
}

int PedirInt(char mensaje [TAM_STR], int *pResultadoInt)
{
	int retorno;
	char numeroSinValidar [TAM_INT];
	retorno = 0;

	printf(mensaje);
	scanf("%s", numeroSinValidar);

	if (ValidarInt(numeroSinValidar) == 0)
	{
		*pResultadoInt = atoi(numeroSinValidar);

	} else
	{
		retorno = 1;
	}

	return retorno;
}


int ValidarInt(char pResultadoInt [TAM_INT])
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


