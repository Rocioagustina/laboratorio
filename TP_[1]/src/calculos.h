/*
 * Calculos.h
 *
 *  Created on: 5 abr. 2022
 *      Author: rocio
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#define TAM_STR 256


int calcularDescuentoDebito(float precio, float *pPrecioDebito, float descuentoDebito);

int calcularAumentoCredito (float precio, float *pPrecioCredito, float aumentoCredito);

int calcularBitcoin (float precio, float *pPrecioBitcoin, float precioDelBitcoin);

int mostrarPrecioPorKilometro (float precio, float *pPrecioPorKm, float cantidadDeKilometros);

int diferenciaDePrecio (float precioAerolineas, float *pDiferenciaPrecio, float precioLatam);
int hacerCalculos (float *pPrecioDebitoAerolineas, float descuentoDebito, float *pPrecioCreditoAerolineas,
		float aumentoCredito, float *pPrecioBitcoinAerolineas, float valorDelBitcoin, float *pPrecioPorKmAerolineas, float *pPrecioPorKmLatam,
		float cantidadDeKilometros, float precioAerolineas,	float precioLatam, float *pDiferenciaPrecio, float *pPrecioDebitoLatam,
		float *pPrecioCreditoLatam, float *pPrecioBitcoinLatam);

int mostrarResultados (char mensajeDescuentoDebito [TAM_STR], char mensajeAumentoCredito [TAM_STR],
		char mensajeCalcularBitcoin [TAM_STR],	char mensajePrecioPorKm [TAM_STR], char mensajeDiferenciaDePrecio [TAM_STR],
		float resultadoDescuentoDebitoAerolineas, float resultadoAumentoCreditoAerolineas, float resultadoCalcularBitcoinAerolineas,
		float resultadoPrecioPorKmAerolineas, float resultadoDescuentoDebitoLatam, float resultadoAumentoCreditoLatam,
		float resultadoCalcularBitcoinLatam, float resultadoPrecioPorKmLatam, float resultadoDiferenciaDePrecio, float precioAerolineas,
		float precioLatam, char mensajePrecioAerolineas [TAM_STR], char mensajePrecioLatam [TAM_STR]);




#endif /* CALCULOS_H_ */
