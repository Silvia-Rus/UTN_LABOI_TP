/*
 ============================================================================
 Name        : TP2.c
 Author      : Silvia Rus Mata
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#include "calc.h"

#define LEN_LIST 1000
#define LEN_STR 51



int main(void)

{
	setbuf(stdout, NULL);
	int respuesta;
	Employee employeeList[LEN_LIST];

	printf("-------¡¡Bienvenido al ABM!!-------\n\n");
	if(!initEmployees(employeeList, LEN_LIST))
	{
		do{
				if((utn_getNumero(&respuesta,
						"MENÚ PRINCIPAL:\n"
						"Ingrese un número del 1 al 5:\n"
						"1-Para dar de alta a un usuario.\n"
						"2-Para modificar un usuario.\n"
						"3-Para dar de baja a un usuario.\n"
						"4-Para sacar informes.\n"
						"5-Para salir.\n",
						"\n\nERROR\n\n\n", 1, 5, 3)==0))
				{
					switch(respuesta)
					{
						case 1://ALTA
							if(emp_addEmployees(employeeList, LEN_LIST))
							{
								printf("Error en la carga.");
							}
							break;
						case 2://MODIFICACIÓN
							if(emp_modifyData(employeeList, LEN_LIST))
							{
								printf("No hay empleados dados de alta en la base de datos.\n\n");
							}
							break;

						case 3://BAJA
							if(emp_removeEmployee(employeeList, LEN_LIST))
							{
								printf("No hay empleados dados de alta en la base de datos.\n\n");
							}
							break;
						case 4://INFORME
							if(emp_informe(employeeList, LEN_LIST))
							{
								printf("No hay empleados dados de alta en la base de datos.\n\n");
							}
							break;
					}
				}
				else
				{
					printf("Excedió el número de intentos");
					break;
				}
			}while(respuesta!=5);
	}
	printf("¡Hasta la próxima!");
	return EXIT_SUCCESS;
}
