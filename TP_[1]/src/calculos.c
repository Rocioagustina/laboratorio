/*
 * Calculos.c
 *
 *  Created on: 5 abr. 2022
 *      Author: rocio
 *

 */

#include "calculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_STR 256

/// @fn int hacerCalculos(float*, float, float*, float, float*, float, float*, float*, float, float, float, float*, float*, float*, float*)
/// @brief Es la funcion que utilizo para realizar los calculos
///
/// @param pPrecioDebitoAerolineas Es el puntero en el cual se va a guardar el precio final de Aerolineas con el descuento por usar debito
/// @param descuentoDebito Es el descuento que se hace sobre el precio total por usar debito
/// @param pPrecioCreditoAerolineas Es el puntero en el cual se va a guardar el precio final de Aerolineas con el aumento por usar credito
/// @param aumentoCredito Es el aumento que se hace sobre el precio total por usar credito
/// @param pPrecioBitcoinAerolineas Es el puntero en el cual se va a guardar el precio final de Aerolineas por usar bitcoin
/// @param valorDelBitcoin Es el valor actual del bitcoin
/// @param pPrecioPorKmAerolineas Es el puntero en el cual se va a guardar el precio por km en Aerolineas
/// @param pPrecioPorKmLatam Es el puntero en el cual se va a guardar el precio por km en Latam
/// @param cantidadDeKilometros Es la cantidad de km que ingreso el usuario
/// @param precioAerolineas Es el precio que ingreso el usuario para Aerolineas
/// @param precioLatam Es el precio que ingreso el usuario para Latam
/// @param pDiferenciaPrecio Es el puntero en el cual se va a guardar la diferencia de precio entre las dos aerolineas
/// @param pPrecioDebitoLatam Es el puntero en el cual se va a guardar el precio final de Latam con el descuento por usar debito
/// @param pPrecioCreditoLatam Es el puntero en el cual se va a guardar el precio final de Latam con el aumento por usar credito
/// @param pPrecioBitcoinLatam Es el puntero en el cual se va a guardar el precio final de Latam por usar bitcoin
/// @return 1 si todo sale bien y 0 si hay algun error.

int hacerCalculos (float *pPrecioDebitoAerolineas, float descuentoDebito, float *pPrecioCreditoAerolineas,
		float aumentoCredito, float *pPrecioBitcoinAerolineas, float valorDelBitcoin, float *pPrecioPorKmAerolineas, float *pPrecioPorKmLatam,
		float cantidadDeKilometros, float precioAerolineas,	float precioLatam, float *pDiferenciaPrecio, float *pPrecioDebitoLatam,
		float *pPrecioCreditoLatam, float *pPrecioBitcoinLatam)
{
	int retorno;
	retorno = 0;

	calcularDescuentoDebito (precioAerolineas, pPrecioDebitoAerolineas, descuentoDebito);
	calcularDescuentoDebito (precioLatam, pPrecioDebitoLatam, descuentoDebito);
	calcularAumentoCredito (precioAerolineas, pPrecioCreditoAerolineas, aumentoCredito);
	calcularAumentoCredito (precioLatam, pPrecioCreditoLatam, aumentoCredito);
	calcularBitcoin (precioAerolineas, pPrecioBitcoinAerolineas, valorDelBitcoin);
	calcularBitcoin (precioLatam, pPrecioBitcoinLatam, valorDelBitcoin);
	mostrarPrecioPorKilometro (precioAerolineas, pPrecioPorKmAerolineas, cantidadDeKilometros);
	mostrarPrecioPorKilometro (precioLatam, pPrecioPorKmLatam, cantidadDeKilometros);
	diferenciaDePrecio (precioAerolineas, pDiferenciaPrecio, precioLatam);

	retorno = 1;

	return retorno;
}

/// @fn void mostrarResultados(char[], char[], char[], char[], char[], float, float, float, float, float, float, float, float, float, float, float, char[], char[])
/// @brief Es la funcion que utilizo para mostrar los resultados de los calculos hechos anteriormente
///
/// @param mensajeDescuentoDebito Es el mensaje en el cual informo cual es el precio final con debito
/// @param mensajeAumentoCredito Es el mensaje en el cual informo cual es el precio final con credito
/// @param mensajeCalcularBitcoin Es el mensaje en el cual informo cual es el precio en bitcoin
/// @param mensajePrecioPorKm Es el mensaje en el cual informo cual es el precio por km
/// @param mensajeDiferenciaDePrecio Es el mensaje en el cual informo la diferencia de precio entre las aerolineas
/// @param resultadoDescuentoDebitoAerolineas Es el resultado del descuento por usar debito en Aerolineas
/// @param resultadoAumentoCreditoAerolineas Es el resultado del aumento por usar credito en Aerolineas
/// @param resultadoCalcularBitcoinAerolineas Es el resultado del precio en bitcoin
/// @param resultadoPrecioPorKmAerolineas Es el resultado del precio por km en Aerolineas
/// @param resultadoDescuentoDebitoLatam Es el resultado del descuento por usar debito en Latam
/// @param resultadoAumentoCreditoLatam Es el resultado del aumento por usar credito en Latam
/// @param resultadoCalcularBitcoinLatam Es el resultado del precio en bitcoin
/// @param resultadoPrecioPorKmLatam Es el resultado del precio por km en Latam
/// @param resultadoDiferenciaDePrecio Es el resultado de la diferencia de precio entre las aerolineas
/// @param precioAerolineas Es el precio de Aerolineas ingresado por el usuario
/// @param precioLatam Es el precio de Latam ingresado por el usuario
/// @param mensajePrecioAerolineas Es el mensaje en el cual informo el precio total de Aerolineas, sin descuentos ni aumentos
/// @param mensajePrecioLatam Es el mensaje en el cual informo el precio total de Latam, sin descuentos ni aumentos
/// @return 1 si todo sale bien y 0 si hay algun error.

int mostrarResultados (char mensajeDescuentoDebito [TAM_STR], char mensajeAumentoCredito [TAM_STR],
		char mensajeCalcularBitcoin [TAM_STR],	char mensajePrecioPorKm [TAM_STR], char mensajeDiferenciaDePrecio [TAM_STR],
		float resultadoDescuentoDebitoAerolineas, float resultadoAumentoCreditoAerolineas, float resultadoCalcularBitcoinAerolineas,
		float resultadoPrecioPorKmAerolineas, float resultadoDescuentoDebitoLatam, float resultadoAumentoCreditoLatam,
		float resultadoCalcularBitcoinLatam, float resultadoPrecioPorKmLatam, float resultadoDiferenciaDePrecio, float precioAerolineas,
		float precioLatam, char mensajePrecioAerolineas [TAM_STR], char mensajePrecioLatam [TAM_STR])
{

	int retorno;
	retorno = 0;


	printf(mensajePrecioAerolineas, precioAerolineas);
	printf(mensajeDescuentoDebito, resultadoDescuentoDebitoAerolineas);
	printf(mensajeAumentoCredito, resultadoAumentoCreditoAerolineas);
	printf(mensajeCalcularBitcoin, resultadoCalcularBitcoinAerolineas);
	printf(mensajePrecioPorKm, resultadoPrecioPorKmAerolineas);
	printf(mensajePrecioLatam, precioLatam);
	printf(mensajeDescuentoDebito, resultadoDescuentoDebitoLatam);
	printf(mensajeAumentoCredito, resultadoAumentoCreditoLatam);
	printf(mensajeCalcularBitcoin, resultadoCalcularBitcoinLatam);
	printf(mensajePrecioPorKm, resultadoPrecioPorKmLatam);
	printf(mensajeDiferenciaDePrecio, resultadoDiferenciaDePrecio);

	retorno = 1;

	return retorno;

}
/// @fn int calcularDescuentoDebito(float, float*, float)
/// @brief Es la funcion que calcula el descuento por usar debito (10%)
///
/// @param precio Es el precio que ingresa el usuario
/// @param pPrecioDebito Es el puntero en el que guardo el precio con el descuento
/// @param descuentoDebito Es el descuento que se le realiza al total por usar debito
/// @return 1 si todo sale bien y 0 si hay algun error.

int calcularDescuentoDebito(float precio, float *pPrecioDebito, float descuentoDebito)
{
	int retorno;
	retorno = 0;

	*pPrecioDebito = (precio * descuentoDebito);

	retorno = 1;

	return retorno;
}

/// @fn int calcularAumentoCredito(float, float*, float)
/// @brief Es la funcion que calcula el aumento por usar credito (25%)
///
/// @param precio Es el precio que ingresa el usuario
/// @param pPrecioCredito Es el puntero en el que guardo el precio con el aumento
/// @param aumentoCredito Es el aumento que se le realiza al total por usar credito
/// @return 1 si todo sale bien y 0 si hay algun error.

int calcularAumentoCredito (float precio, float *pPrecioCredito, float aumentoCredito)
{
	int retorno;
	retorno = 0;

	*pPrecioCredito = (precio * aumentoCredito);

	retorno = 1;

	return retorno;
}

/// @fn int calcularBitcoin(float, float*, float)
/// @brief Es la funcion que calcula segun el monton ingresado, cuantos bitcoin saldria el pasaje
///
/// @param precio Es el precio ingresado por el usuario
/// @param pPrecioBitcoin Es el puntero en el que guardo el precio en bitcoin
/// @param valorDelBitcoin Es el precio actual del bitcoin
/// @return 1 si todo sale bien y 0 si hay algun error.

int calcularBitcoin (float precio, float *pPrecioBitcoin, float valorDelBitcoin)
{
	int retorno;
	retorno = 0;

	*pPrecioBitcoin = (precio / valorDelBitcoin);

	retorno = 1;

	return retorno;
}

/// @fn int mostrarPrecioPorKilometro(float, float*, float)
/// @brief Es la funcion que calcula el precio por km
///
/// @param precio Es el precio que ingresa el usuario
/// @param pPrecioPorKm Es el puntero en el que guardo el precio por km
/// @param cantidadDeKilometros Es la cantidad de km que ingresa el usuario
/// @return 1 si todo sale bien y 0 si hay algun error.

int mostrarPrecioPorKilometro (float precio, float *pPrecioPorKm, float cantidadDeKilometros)
{
	int retorno;
	retorno = 0;

	*pPrecioPorKm = (precio / cantidadDeKilometros);

	retorno = 1;


	return retorno;
}

/// @fn int diferenciaDePrecio(float, float*, float)
/// @brief Es la funcion que calcula la diferencia de precio entre las dos aerolineas
///
/// @param precioAerolineas Es el precio que ingresa el usuario para Aerolineas
/// @param pDiferenciaPrecio Es el puntero en el que guardo la diferencia de precio entre las aerolineas
/// @param precioLatam Es el precio que ingresa el usuario para Latam
/// @return 1 si todo sale bien y 0 si hay algun error.

int diferenciaDePrecio (float precioAerolineas, float *pDiferenciaPrecio, float precioLatam)
{
	int retorno;
	retorno = 0;

	*pDiferenciaPrecio = fabsf ((precioAerolineas - precioLatam));

	retorno = 1;

	return retorno;
}







