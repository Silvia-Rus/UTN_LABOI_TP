#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "getData.h"
#include "parser.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_EmployeeFromText(pFile, pArrayListEmployee))
		{
			printf("\nArchivo cargado con éxito.");
			retorno=0;
		}
		else
		{
			printf("\nEl archivo no existe");
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	retorno = 0;
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char auxNombre[NOMBRE_LEN];
	int auxHorasTrabajadas;
	int auxSueldo;
	int auxId;
	Employee* auxEmployee;
	if(pArrayListEmployee!=NULL)
	{
		if(	!utn_getLetrasYEspacios(auxNombre, NOMBRE_LEN, "\nNombre: ","\nERROR. Ingrese solo nombres y espacios", INTENTOS) &&
			!utn_getNumeroInt(&auxHorasTrabajadas, "\nHoras trabajadas: ", "\nERROR. Ingrese un número entero", 0, INT_MAX, INTENTOS) &&
			!utn_getNumeroInt(&auxSueldo, "\nSueldo: ", "\nERROR. Ingrese un número entero", 0, INT_MAX, INTENTOS))
		{
			auxId = employee_nuevoId();
			auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			ll_add(pArrayListEmployee, auxEmployee);
			printf("\nId asignado: %d", auxId);
			retorno=0;
		}
	}
	return retorno;
}

/*
 * \brief Modifica los datos de un empleado del cual se pide su ID.
 * \param el array de punteros a los empleados.
 * \return 0 si todo salió ok (incluye id erróneo). -1 si no,
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int index;
	int opcion;
	char auxNombre[NOMBRE_LEN];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* auxEmployee;
	if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)<1)
	{
		printf("\nNo hay empleados grabados en la base de datos."
				"\nVuelta al menú principal...");
	}
	else
	{
		if(!utn_getNumeroInt(&id,
						"Id del empleado que quiere modificar: ",
						"ERROR. Ingrese un número entero",
						0,
						INT_MAX,
						INTENTOS))
		{
			index = employee_findById(pArrayListEmployee, id);
			if(index<0)
			{
				printf("\nNo existe ningún empleado con ese id.");
				printf("\nVuelta al menú principal...");
			}
			else
			{
				auxEmployee = ll_get(pArrayListEmployee, index);
				if(!employee_getNombre(auxEmployee, auxNombre))
				{
					printf("\nNombre del empleado a modificar %s", auxNombre);
				}
				do{
					if(!utn_getNumeroInt(&opcion,
										"\nMENÚ MODIFICACIÓN"
										"\nDato a modificar"
										"\n1-Nombre"
										"\n2-Horas trabajadas"
										"\n3-Sueldo"
										"\n4-Volver atras\n",
										"ERROR. Ingrese una opción válida",
										1,
										4,
										INTENTOS))
					{
						switch(opcion)
						{
							case 1:
								if(!utn_getLetrasYEspacios(auxNombre,
														NOMBRE_LEN,
														"Ingrese el nuevo nombre: ",
														"\nERROR. Ingrese únicamente letras y espacios",
														INTENTOS) &&
									!employee_setNombre(auxEmployee, auxNombre))
								{
									ll_set(pArrayListEmployee, index, auxEmployee);
									printf("\nNombre modificado con éxito.");
									retorno=0;
								}
							break;
							case 2:
								if(!utn_getNumeroInt(&auxHorasTrabajadas,
													"\nHoras trabajadas: ",
													"\nERROR.Ingrese un número entero.",
													1,
													INT_MAX,
													INTENTOS) &&
									!employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas))
								{
									ll_set(pArrayListEmployee, index, auxEmployee);
									printf("\nHoras trabajadas modificadas con éxito.");
									retorno=0;
								}
							break;
							case 3:
								if(!utn_getNumeroInt(&auxSueldo,
										"\nNuevo Sueldo: ",
										"\nERROR.Ingrese un número entero.",
										1,
										INT_MAX,
										INTENTOS) &&
									!employee_setSueldo(auxEmployee, auxSueldo))
								{
									ll_set(pArrayListEmployee, index, auxEmployee);
									printf("\nSueldo modificado con éxito.");
									retorno=0;
								}
							break;
						}
					}
				}while(opcion!=4);
				}
			}
		}
	return retorno;
}

/*
 * \brief Da de baja a un empleado del cual se pide un ID.
 * \param el array de punteros a los empleados.
 * \return 0 si todo salió ok (incluye id erróneo). -1 si no,
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
		int id;
		int index;
		int opcion;
		char auxNombre[NOMBRE_LEN];
		Employee* auxEmployee;
		if(pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)<1)
		{
			printf("\nNo hay empleados grabados en la base de datos."
							"\nVuelta al menú principal...");
		}
		else
		{
			if(!utn_getNumeroInt(&id,
								"\nId del empleado que quiere borrar: ",
								"\nERROR. Debe ser un número entero. ",
								0,
								INT_MAX,
								INTENTOS))
			{
				index = employee_findById(pArrayListEmployee, id);
				if(index<0)
				{
					printf("\nNo existe ningún empleado con ese id.");
					printf("\nVuelta al menú principal...");
				}
				else
				{
					auxEmployee = ll_get(pArrayListEmployee, index);
					if(!employee_getNombre(auxEmployee, auxNombre))
					{
						printf("\nNombre del empleado a borrar: %s", auxNombre);
					}
					if(!utn_getNumeroInt(&opcion,
										"\n¿Está seguro de que quiere borrar al empleado?"
										"\n1-Borrar"
										"\n2-Volver el menú principal",
										"\nERROR. Ingrese 1 para borrar o 2 para volver al menú principal",
										1,
										2,
										INTENTOS))
					{
						switch(opcion)
						{
							case 1:
								ll_remove(pArrayListEmployee, index);
								printf("Empleado borrado con éxito");
								retorno=0;
								break;
							case 2:
								printf("Volviendo al menú principal...");
						}
					}
				}
			}
			else
			{
				printf("\nAgotó el número de intentos.");
			}
		}
		 return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* auxEmployee;
	char auxNombre[NOMBRE_LEN];
	int auxId;
	int auxHorasTrabajadas;
	int auxSueldo;
	int len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL)
	{
		printf("\nID    "
				"Nombre    "
				"Horas trab. "
				"Sueldo ");
		for(int i=0; i<len;i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			if(	!employee_getNombre(auxEmployee, auxNombre) &&
				!employee_getId(auxEmployee, &auxId) &&
				!employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) &&
				!employee_getSueldo(auxEmployee, &auxSueldo))
			{
				printf("\n%-6d"
						"%-10s"
						"%-12d"
						"%-7d\n",
						auxId,
						auxNombre,
						auxHorasTrabajadas,
						auxSueldo);
				retorno=0;
			}
		}
	}
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	retorno = 0;
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	retorno = 0;
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	retorno = 0;
	return retorno;
}

