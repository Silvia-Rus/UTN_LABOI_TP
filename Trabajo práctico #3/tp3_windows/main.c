/*
 ============================================================================
 Name        : TP3.c
 Author      : Silvia Rus Mata
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "getData.h"

#define LEN_ARRAY_PUNTEROS 1000

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
	int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("---¡¡Bienvenido al sistema de carga de empleados!!----\n\n");


   do{
		if(!utn_getNumeroInt(&option,
							"\n\nMENÚ PRINCIPAL:\n"
							"Ingrese un número del 1 al 10:\n"
							"1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							"2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
							"3-Dar de alta de empleado.\n"
							"4-Modificar datos de empleado.\n"
							"5-Dar de baja de empleado.\n"
							"6-Listar empleados.\n"
							"7-Ordenar empleado.\n"
							"8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
							"9-Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
							"10-Salir\n",
							"\n\nERROR\n\n\n",
							1,
							10,
							INTENTOS))
		{
			switch(option)
			{
				case 1://Cargar los datos de los empleados desde el archivo data.csv (modo texto).
					if(!controller_loadFromText("data.csv",listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
					break;
				case 2://Cargar los datos de los empleados desde el archivo data.csv (modo binario)
					/* if(!controller_loadFromBinary("data.csv",listaEmpleados))
						{
							printf("\nHubo un problema al cargar los datos desde el archivo csv.");
						}*/
					printf("opción 2");
					break;
				case 3://Alta de empleado
					if(!controller_addEmployee(listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
					break;
				case 4://Modificar datos de empleado
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("\n");
					}
					break;
				case 5://Baja de empleado
					if(!controller_removeEmployee(listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
					break;
				case 6://Listar empleados
					if(!controller_ListEmployee(listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
						break;
				case 7://Ordenar empleados
					/*if(!controller_ListEmployee(listaEmpleados))
					{
						printf("\nHubo un problema al ordenar los empleados.");
					}*/
					printf("opción 7");
					break;
				case 8://Guardar los datos de los empleados en el archivo data.csv (modo texto).
					/*if(!controller_saveAsText("data.csv",listaEmpleados))
					{
						printf("\nHubo un problema al guardar los datos desde el archivo csv.");
					}*/
					printf("opción 8");
					break;
				case 9://Guardar los datos de los empleados en el archivo data.csv (modo binario).
					/*if(!controller_saveAsBinary("data.csv",listaEmpleados))
					{
						printf("\nHubo un problema al guardar los datos desde el archivo csv.");
					}*/
					printf("opción 9");
					break;
			}
		}
		else
		{
			printf("Agotó el número de intentos.");
			break;
		}
	}while(option != 10);

    printf("¡Hasta la próxima!");
    return EXIT_SUCCESS;
}

