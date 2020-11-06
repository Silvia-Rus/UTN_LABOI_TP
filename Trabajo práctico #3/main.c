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
	int banderaCargaArchivo=0;
	int opcionCarga;

    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("---¡¡Bienvenido al sistema de carga de empleados!!---\n");
    printf("---->Cargue un archivo para comenzar a trabajar.<----");
   do{
		if(!utn_getNumeroInt(&option,
							"\n\nMENÚ PRINCIPAL:\n"
							"Ingrese un número del 1 al 10:\n"
							"1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
							"2-Cargar los datos de los empleados desde el archivo dataBin.csv (modo binario).\n"
							"3-Dar de alta de empleado.\n"
							"4-Modificar datos de empleado.\n"
							"5-Dar de baja de empleado.\n"
							"6-Listar empleados.\n"
							"7-Ordenar empleados alfabéticamente por nombre.\n"
							"8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
							"9-Guardar los datos de los empleados en el archivo dataBin.csv (modo binario).\n"
							"10-Salir\n",
							"\n\nERROR. Ingrese un número del 1 al 10.\n\n\n",
							1,
							10,
							INTENTOS))
		{
			switch(option)
			{
				case 1://Cargar los datos de los empleados desde el archivo data.csv (modo texto).
					if(banderaCargaArchivo==0 && !controller_loadFromText("data.csv",listaEmpleados))
					{
						printf("\nEmpleados cargados correctamente\n");
						banderaCargaArchivo=1;
					}
					else
					{
						if(!utn_getNumeroInt(&opcionCarga,
											"\nYa hay datos cargados, ¿desea reemplazarlos?"
											"\n1 -Sí (se borrara todo lo cargado tanto por lista como manualmente)"
											"\n2 -No (vuelve al menú principal) ",
											"ERROR. Ingrese un número entero",
											1,
											2,
											INTENTOS))
						{
							switch(opcionCarga)
							{
							case 1:
								if(!controller_loadFromText("data.csv",listaEmpleados))
								{
									printf("\nVolviendo al menú principal...");
								}
								break;
							case 2:
								printf("\nVolviendo al menú principal...");
								break;
							}
						}
					}
					break;
				case 2://Cargar los datos de los empleados desde el archivo data.csv (modo binario)
					if(banderaCargaArchivo==0 && !controller_loadFromBinary("dataBin.csv",listaEmpleados))
					{

						printf("\nEmpleados cargados correctamente\n");
						banderaCargaArchivo=1;
					}
					else
					{
						if(!utn_getNumeroInt(&opcionCarga,
											"\nYa hay datos cargados, ¿desea reemplazarlos?"
											"\n1 -Sí (se borrara todo lo cargado tanto por lista como manualmente.)"
											"\n2 -No (Vuelve al menú principal) ",
											"ERROR. Ingrese un número entero",
											1,
											2,
											INTENTOS))
						{
							switch(opcionCarga)
							{
							case 1:
								if(!controller_loadFromBinary("dataBin.csv",listaEmpleados))
								{
									printf("\nVolviendo al menú principal...");
								}
								break;
							case 2:
								printf("\nVolviendo al menú principal...");
								break;
							}
						}
					}
					break;
				case 3://Alta de empleado
					if(banderaCargaArchivo==0)
					{
						printf("\nCargue primero un archivo de datos (opción 1 ó 2).");
					}
					else
					{
						if(!controller_addEmployee(listaEmpleados))
						{
							printf("\nVolviendo al menú principal...");
						}
					}
					break;
				case 4://Modificar datos de empleado
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
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
					if(!controller_sortEmployee(listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
					break;
				case 8://Guardar los datos de los empleados en el archivo data.csv (modo texto).
					if(!controller_saveAsText("data.csv",listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
					break;
				case 9://Guardar los datos de los empleados en el archivo data.csv (modo binario).
					if(!controller_saveAsBinary("databin.csv",listaEmpleados))
					{
						printf("\nVolviendo al menú principal...");
					}
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
    ll_deleteLinkedList(listaEmpleados);
    return EXIT_SUCCESS;
}

