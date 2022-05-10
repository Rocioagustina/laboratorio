/*
 * rJimenez.h
 *
 *  Created on: 21 abr. 2022
 *      Author: rocio
 */

#ifndef RJIMENEZ_H_
#define RJIMENEZ_H_
#define TAM_STR 256
#define TAM_NOMBRE 51
#define TAM_INT 20


int pedirFloat (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], float *pResultado);

int validarFloat (char resultado [TAM_STR]);

int pedirNombre (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoNombre);

int validarNombre (char nombreSinValidar [TAM_NOMBRE]);

int pedirCodigo (char mensaje [TAM_STR], char mensajeError [TAM_STR], char mensajeExito [TAM_STR], char *pResultadoCodigo);

int PedirInt(char mensaje [TAM_STR], int *pResultadoInt);

int ValidarInt(char pResultadoInt [TAM_INT]);


#endif /* RJIMENEZ_H_ */
