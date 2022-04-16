/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include "calculos.h"
#include "rJimenez.h"

#define MENSAJE_OPCION_UNO "1. Ingresar kilometros (Km = x) \n\n"
#define MENSAJE_KILOMETROS_INGRESADOS "1. Ingresar kilometros (Km = %.2f)\n\n"
#define MENSAJE_OPCION_DOS "2. Ingresar precios de vuelos (Aerolineas = y, Latam = z)\n\n"
#define MENSAJE_AEROLINEAS_INGRESADO "2. Ingresar precios de vuelos (Aerolineas = %.2f, Latam = z)\n\n"
#define MENSAJE_LATAM_INGRESADO "2. Ingresar precios de vuelos (Aerolieas = y, Latam = %.2f)\n\n"
#define MENSAJE_AMBOS_INGRESADOS "2. Ingresar precios de vuelos (Aerolieas = %.2f , Latam = %.2f)\n\n"
#define MENSAJE_OPCION_TRES "3. Calcular todos los costos \n\n"
#define MENSAJE_OPCION_CUATRO "4. Informar resultados \n\n"
#define MENSAJE_OPCION_CINCO "5. Carga forzada de datos \n\n"
#define MENSAJE_OPCION_SEIS "6. Salir\n\n"
#define ESPACIADOR "\n\n"
#define SOLICITAR_OPCION "Ingresar una opcion: "
#define INGRESE_KILOMETROS "Ingresar el numero de kilometros"
#define INGRESE_KILOMETROS_ERROR "El numero ingresado es incorrecto"
#define INGRESE_KILOMETROS_EXITOSO "El numero ingresado es correcto"
#define OPCION_AEROLINEAS "1. Ingresar precio de vuelo por Aerolineas Argentinas\n\n"
#define OPCION_LATAM "2. Ingresar precio de vuelo por Latam\n\n"
#define OPCION_MENU_PRINCIPAL "3. Volver al menu principal\n\n"
#define INGRESE_PRECIO_AEROLINEAS "Ingresar el precio del vuelo por Aerolineas Argentinas"
#define INGRESO_PRECIO_AEROLINEAS_ERROR "El numero ingresado es incorrecto"
#define INGRESO_PRECIO_AEROLINEAS_EXITOSO "El precio ingresado es correcto"
#define INGRESE_PRECIO_LATAM "Ingresar el precio del vuelo por Latam"
#define INGRESO_PRECIO_LATAM_ERROR "El numero ingresado es incorrecto"
#define INGRESO_PRECIO_LATAM_EXITOSO "El precio ingresado es correcto"
#define DESCUENTO_DEBITO 0.90
#define AUMENTO_CREDITO 1.25
#define PRECIO_DEL_BITCOIN 4606954.55
#define FIN_DEL_PROCESO "Programa cerrado con exito"
#define INFORMAR_DEBITO "Precio con tarjeta de debito: $ %.2f\n"
#define INFORMAR_CREDITO "Precio con tarjeta de crédito: $ %.2f\n"
#define INFORMAR_BITCOIN "Precio pagando con bitcoin: %f BTC\n"
#define INFORMAR_PRECIO_POR_KILOMETRO "Mostrar precio unitario: $ %.2f\n\n"
#define DIFERENCIA_DE_PRECIO "La diferencia de precio es: $ %.2f\n\n"
#define PRECIO_SIN_DESCUENTO_AEROLINEAS "Precio Aerolineas Argentinas: $ %.2f\n"
#define PRECIO_SIN_DESCUENTO_LATAM "Precio Aerolineas Latam: $ %.2f\n"
#define CARGA_FORZADA_KILOMETROS "Km: %d\n"
#define KILOMETROS 7090
#define CARGA_FORZADA_AEROLINEAS "Aerolineas Argentinas: $ %d\n"
#define AEROLINEAS_ARGENTINAS 162965
#define CARGA_FORZADA_LATAM "Latam: $ %d\n\n"
#define LATAM 159339
#define INGRESAR_OPCION "Ingrese su opcion: \n\n"
#define CALCULOS_CORRECTOS "Los calculos fueron realizados correctamente"
#define CALCULOS_INCORRECTOS "Error, falta informacion para realizar los calculos, revise los datos ingresados"
#define CALCULOS_MOSTRADOS "Los calculos fueron mostrados correctamente"
#define CALCULOS_NO_MOSTRADOS "Los calculos no fueron realizados, por lo tanto, no pudieron ser mostrados"
#define VUELO_AEROLINEAS_EN_CERO "- Precio vuelo Aerolineas:\n\n"
#define VUELO_LATAM_EN_CERO "- Precio vuelo Latam:\n\n"
#define VUELO_AEROLINEAS "- Precio vuelo Aerolineas: %.2f\n"
#define VUELO_LATAM "- Precio vuelo Latam: %.2f\n\n"
#define TARJETA_DE_DEBITO "a) Tarjeta de débito (10 por ciento)\n"//Eclipse no me deja utilizar el simbolo %
#define TARJETA_DE_CREDITO "b) Tarjeta de crédito (25 por ciento)\n" //Eclipse no me deja utilizar el simbolo %
#define BITCOIN "c. Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
#define PRECIO_POR_KILOMETRO "d) Mostrar precio por km (precio unitario)\n"
#define DIFERENCIA_DE_PRECIO_INGRESADA "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n"
#define PRECIO_TARJETA_DEBITO_AEROLINEAS "Aerolineas: \n\na) Precio con tarjeta de débito: r \n"
#define PRECIO_TARJETA_CREDITO_AEROLINEAS "b) Precio con tarjeta de crédito: r \n"
#define PRECIO_CON_BITCOIN_AEROLINEAS "c) Precio pagando con bitcoin : r \n"
#define PRECIO_TARJETA_DEBITO_LATAM "Latam: \n\na) Precio con tarjeta de débito: r \n"
#define PRECIO_TARJETA_CREDITO_LATAM "b) Precio con tarjeta de crédito: r \n"
#define	PRECIO_UNITARIO_KM_AEROLINEAS "d) Precio unitario: r \n\n"
#define PRECIO_CON_BITCOIN_LATAM "c) Precio pagando con bitcoin: r \n"
#define PRECIO_UNITARIO_KM_LATAM "d) Precio unitario: r \n\n"
#define DIFERENCIA_DE_PRECIO_ENTRE_AEROLINEAS "La diferencia de precio es: r \n\n"
#define PRECIO_TARJETA_DEBITO_AEROLINEAS_INGRESADO "Aerolineas: \n\na) Precio con tarjeta de débito: %.2f \n"
#define PRECIO_TARJETA_CREDITO_AEROLINEAS_INGRESADO "b) Precio con tarjeta de crédito: %.2f \n"
#define PRECIO_CON_BITCOIN_AEROLINEAS_INGRESADO "c) Precio pagando con bitcoin : %f \n"
#define PRECIO_TARJETA_DEBITO_LATAM_INGRESADO "Latam: \n\na) Precio con tarjeta de débito: %.2f \n"
#define PRECIO_TARJETA_CREDITO_LATAM_INGRESADO "b) Precio con tarjeta de crédito: %.2f \n"
#define	PRECIO_UNITARIO_KM_AEROLINEAS_INGRESADO "d) Precio unitario: %.2f \n\n"
#define PRECIO_CON_BITCOIN_LATAM_INGRESADO "c) Precio pagando con bitcoin: %f \n"
#define PRECIO_UNITARIO_KM_LATAM_INGRESADO "d) Precio unitario: %.2f \n\n"
#define DIFERENCIA_DE_PRECIO_ENTRE_AEROLINEAS_INGRESADA "La diferencia de precio es: %.2f \n\n"




int main()
{
    setbuf(stdout, NULL);

    int opcionUno;
    float numeroDeKilometros;
    int opcionDos;
    float precioAerolineas;
    float precioLatam;
    float precioDebitoAerolineas;
    float precioCreditoAerolineas;
    float precioDebitoLatam;
    float precioCreditoLatam;
    float precioBitcoinAerolineas;
    float precioBitcoinLatam;
    float precioPorKmAerolineas;
    float precioPorKmLatam;
    float diferenciaDePrecio;
    int flagKilometros;
    int flagAerolineas;
    int flagLatam;
    int flagCalculosRealizados;
    int flagCalculosMostrados;

    flagKilometros = 0;
    flagAerolineas = 0;
    flagLatam = 0;
    flagCalculosRealizados = 0;
    flagCalculosMostrados = 0;

    do
    {
    	printf(ESPACIADOR);

    	if(flagKilometros == 0)
    	{
    		printf(MENSAJE_OPCION_UNO);

    	}
    	else
    	{
    		printf(MENSAJE_KILOMETROS_INGRESADOS, numeroDeKilometros);

    	}

    	if(flagAerolineas == 0 && flagLatam == 0)
    	{
    		printf(MENSAJE_OPCION_DOS);
    		printf(VUELO_AEROLINEAS_EN_CERO);
    		printf(VUELO_LATAM_EN_CERO);
    	}
    	else
    	{
    		if(flagAerolineas == 1 && flagLatam == 0)
    		{
    			printf(MENSAJE_AEROLINEAS_INGRESADO, precioAerolineas);
    			printf(VUELO_AEROLINEAS, precioAerolineas);
    			printf(VUELO_LATAM, precioLatam);

    		}
    		else
    		{
    			if(flagAerolineas == 0 && flagLatam ==1)
    			{
    				printf(MENSAJE_LATAM_INGRESADO, precioLatam);
    				printf(VUELO_AEROLINEAS, precioAerolineas);
    				printf(VUELO_LATAM, precioLatam);
    			}
    			else
    			{
    				printf(MENSAJE_AMBOS_INGRESADOS, precioAerolineas, precioLatam);
    				printf(VUELO_AEROLINEAS, precioAerolineas);
					printf(VUELO_LATAM, precioLatam);

    			}
    		}
    	}

    	printf(MENSAJE_OPCION_TRES);
    	if(flagCalculosRealizados == 1 && flagCalculosMostrados == 1)
    	{
    		printf(PRECIO_TARJETA_DEBITO_AEROLINEAS_INGRESADO, precioDebitoAerolineas);
			printf(PRECIO_TARJETA_CREDITO_AEROLINEAS_INGRESADO, precioCreditoAerolineas);
			printf(PRECIO_CON_BITCOIN_AEROLINEAS_INGRESADO, precioBitcoinAerolineas);
			printf(PRECIO_UNITARIO_KM_AEROLINEAS_INGRESADO, precioPorKmAerolineas);
			printf(PRECIO_TARJETA_DEBITO_LATAM_INGRESADO, precioDebitoLatam);
			printf(PRECIO_TARJETA_CREDITO_LATAM_INGRESADO, precioCreditoLatam);
			printf(PRECIO_CON_BITCOIN_LATAM_INGRESADO, precioBitcoinLatam);
			printf(PRECIO_UNITARIO_KM_LATAM_INGRESADO, precioPorKmLatam);
			printf(DIFERENCIA_DE_PRECIO_ENTRE_AEROLINEAS_INGRESADA, diferenciaDePrecio);
    	}
    	else
    	{
        	printf(TARJETA_DE_DEBITO);
        	printf(TARJETA_DE_CREDITO);
        	printf(BITCOIN);
        	printf(PRECIO_POR_KILOMETRO);
        	printf(DIFERENCIA_DE_PRECIO_INGRESADA);
        	printf(MENSAJE_OPCION_CUATRO);
        	printf(PRECIO_TARJETA_DEBITO_AEROLINEAS);
        	printf(PRECIO_TARJETA_CREDITO_AEROLINEAS);
        	printf(PRECIO_CON_BITCOIN_AEROLINEAS);
        	printf(PRECIO_UNITARIO_KM_AEROLINEAS);
        	printf(PRECIO_TARJETA_DEBITO_LATAM);
        	printf(PRECIO_TARJETA_CREDITO_LATAM);
        	printf(PRECIO_CON_BITCOIN_LATAM);
        	printf(PRECIO_UNITARIO_KM_LATAM);
        	printf(DIFERENCIA_DE_PRECIO_ENTRE_AEROLINEAS);
    	}
    	printf(MENSAJE_OPCION_CINCO);
    	printf(MENSAJE_OPCION_SEIS);
    	printf(INGRESAR_OPCION);

    	scanf("%d", &opcionUno);

    	switch (opcionUno)
    	{
    		case 1: flagKilometros = pedirFloat (INGRESE_KILOMETROS, INGRESE_KILOMETROS_ERROR, INGRESE_KILOMETROS_EXITOSO,
    				&numeroDeKilometros);

    			break;
    		case 2: printf(OPCION_AEROLINEAS);
    				printf(OPCION_LATAM);
    				printf(OPCION_MENU_PRINCIPAL);

    				scanf("%d", &opcionDos);

    				switch (opcionDos)
					{
    					case 1: flagAerolineas = pedirFloat (INGRESE_PRECIO_AEROLINEAS, INGRESO_PRECIO_AEROLINEAS_ERROR, INGRESO_PRECIO_AEROLINEAS_EXITOSO,
    						&precioAerolineas);
    						break;
    					case 2: flagLatam = pedirFloat (INGRESE_PRECIO_LATAM, INGRESO_PRECIO_LATAM_ERROR, INGRESO_PRECIO_LATAM_EXITOSO,
        						&precioLatam);
    						break;
    					case 3:
    						break;
					}
    			break;
    		case 3: if(flagAerolineas == 1 && flagLatam == 1 && flagKilometros == 1)
    				{
    				flagCalculosRealizados = hacerCalculos (&precioDebitoAerolineas, DESCUENTO_DEBITO, &precioCreditoAerolineas,
    					AUMENTO_CREDITO, &precioBitcoinAerolineas, PRECIO_DEL_BITCOIN, &precioPorKmAerolineas, &precioPorKmLatam,
						numeroDeKilometros, precioAerolineas, precioLatam, &diferenciaDePrecio, &precioDebitoLatam, &precioCreditoLatam,
						&precioBitcoinLatam);
						printf(CALCULOS_CORRECTOS);
    				}
    				else
    				{
    					printf(CALCULOS_INCORRECTOS);
    				}
    			break;
    		case 4: if(flagCalculosRealizados == 1)
					{
    				flagCalculosMostrados = mostrarResultados (INFORMAR_DEBITO, INFORMAR_CREDITO, INFORMAR_BITCOIN, INFORMAR_PRECIO_POR_KILOMETRO,
					DIFERENCIA_DE_PRECIO, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas,
					precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioPorKmLatam, diferenciaDePrecio, precioAerolineas,
					precioLatam, PRECIO_SIN_DESCUENTO_AEROLINEAS, PRECIO_SIN_DESCUENTO_LATAM);
					printf(CALCULOS_MOSTRADOS);
					}
    				else
    				{
    					printf(CALCULOS_NO_MOSTRADOS);
    				}

    			break;
    		case 5: printf(CARGA_FORZADA_KILOMETROS, KILOMETROS);
    				printf(CARGA_FORZADA_AEROLINEAS, AEROLINEAS_ARGENTINAS);
    				printf(CARGA_FORZADA_LATAM, LATAM);

    				hacerCalculos (&precioDebitoAerolineas, DESCUENTO_DEBITO, &precioCreditoAerolineas, AUMENTO_CREDITO,
									&precioBitcoinAerolineas, PRECIO_DEL_BITCOIN, &precioPorKmAerolineas, &precioPorKmLatam,
									KILOMETROS,	AEROLINEAS_ARGENTINAS, LATAM, &diferenciaDePrecio, &precioDebitoLatam,
									&precioCreditoLatam, &precioBitcoinLatam);
    				flagCalculosRealizados = 1;
    				precioAerolineas = AEROLINEAS_ARGENTINAS;
    				precioLatam = LATAM;
    				mostrarResultados (INFORMAR_DEBITO, INFORMAR_CREDITO, INFORMAR_BITCOIN, INFORMAR_PRECIO_POR_KILOMETRO,
    									DIFERENCIA_DE_PRECIO, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioPorKmAerolineas,
    									precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioPorKmLatam, diferenciaDePrecio, AEROLINEAS_ARGENTINAS,
    									LATAM, PRECIO_SIN_DESCUENTO_AEROLINEAS, PRECIO_SIN_DESCUENTO_LATAM);
    			break;
    		case 6: printf(FIN_DEL_PROCESO);

    	}


    } while(opcionUno != 6);

    system("cls");
    return EXIT_SUCCESS;
}

