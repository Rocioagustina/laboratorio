#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
#define MENSAJE_OPCION_UNO "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
#define MENSAJE_OPCION_DOS "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
#define MENSAJE_OPCION_TRES "3. Alta de pasajero\n"
#define MENSAJE_OPCION_CUATRO "4. Modificar datos de pasajero\n"
#define MENSAJE_OPCION_CINCO "5. Baja de pasajero\n"
#define MENSAJE_OPCION_SEIS "6. Listar pasajeros\n"
#define MENSAJE_OPCION_SIETE "7. Ordenar pasajeros\n"
#define MENSAJE_OPCION_OCHO "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
#define MENSAJE_OPCION_NUEVE "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
#define MENSAJE_OPCION_DIEZ "10. Salir\n"


int main()
{
	setbuf(stdout, NULL);
    int option;

    option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

    	printf(MENSAJE_OPCION_UNO);
		printf(MENSAJE_OPCION_DOS);
		printf(MENSAJE_OPCION_TRES);
		printf(MENSAJE_OPCION_CUATRO);
		printf(MENSAJE_OPCION_CINCO);
		printf(MENSAJE_OPCION_SEIS);
		printf(MENSAJE_OPCION_SIETE);
		printf(MENSAJE_OPCION_OCHO);
		printf(MENSAJE_OPCION_NUEVE);
		printf(MENSAJE_OPCION_DIEZ);

		scanf("%d", &option);

        switch(option)
        {
            case 1:
                controller_loadFromText("C:\\Users\\rocio\\tp_laboratorio_1\\TP_[3]\\dataSetPruebas.csv", listaPasajeros);
                break;
           case 2:controller_loadFromBinary("C:\\Users\\rocio\\tp_laboratorio_1\\TP_[3]\\data.csv", listaPasajeros);
           	   break;
        }
    }while(option != 10);
    return 0;
}

