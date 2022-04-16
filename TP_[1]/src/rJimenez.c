/*
 * RJimenez.c
 *
 *  Created on: 5 abr. 2022
 *      Author: rocio
 */


#include "rJimenez.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 256

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

int validarFloat (char resultado [256])
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

