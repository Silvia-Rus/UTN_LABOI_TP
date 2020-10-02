/*
 * arrayEmployees.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Silvia Rus Mata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <limits.h>
#include "utn.h"
#include "arrayEmployees.h"
#include "calc.h"
#define INTENTOS 3
#define LEN_NOMBRE 30

static int nuevoId(void);

/*
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee* list, int len)
{
	int retorno=-1;
	if (list != NULL && len > 0)
	{
			for (int i = 0; i <len; i++)
			{
				list[i].id = -1;
				list[i].isEmpty = TRUE;
			}
			retorno = 0;
	}
	return retorno;
}
/*
* \brief genera identificadores únicos autoincrementales.
* \return el identificador único autoincremental generado.
*/
static int nuevoId(void)
{
	static int id = 0;
	id = id + 1;
	return id;
}
/*
* \brief busca una posición en la memoria que tenga isEmpty en TRUE.
* \param puntero al array de empleadoss.
* \param longitud del array de empleados.
* \param puntero con la posición en la memoria que tiene isEmpty en TRUE.
* \return el identificador único autoincremental generado.
*/
int indiceVacio(Employee *list, int len, int *pIndiceLibre)
{
	int retorno = -1;

	if (list != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty ==TRUE)
			{
				*pIndiceLibre = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
* \brief comprueba que hay por lo menos un elemento cargado en el array.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return 1 si el array está vacío (todos sus elementos tienen iseEmpty en FALSE) y 0 si no lo está.
 */
int isEmpty(Employee *list, int len)
{
	int retorno = 1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
* \brief find an Employee by Id and returns the index position in array.
* \param puntero a la lista de empleados.
* \param longitud del array.
* \param id a buscar.
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee* list,int len, int id)
{
	int retorno = -1;

	if(list!=NULL && len > 0 && id > 0)
	{
		for(int i=0; i<len;i++)
		{
			if(list[i].id==id)
			{
				retorno=i;
			}
		}
	}
	return retorno;
}
/*
* \brief imprime una tabla de empleados.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*/
int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\n\nLISTADO:\n\n"
				"Apellido   "
				"Nombre     "
				"Id   "
				"Sector    "
				"Sueldo\n");

		for(int i=0;i< len ;i++)
		{
			if(list[i].isEmpty == 0)
			{

				printf(
						"%-11s"
						"%-11s"
						"%-5d"
						"%-9d "
						"%-6f\n",
						list[i].lastName,
						list[i].name,
						list[i].id,
						list[i].sector,
						list[i].salary);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Function to sort the list of employees by ascendent or descendent.
 * \param Employee *list: Pointer the an Employee array
 * \param int len: Length of the array
 * \param int order: Number we receive to determine if the list is going to sort ascendent or descendent
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int sortEmployees(Employee *list, int len, int order)
{
	int retorno = -1;
		Employee auxSwap;
		int flagSwap;
		if(list != NULL && len > 0 && (order == 1 || order == 0))
		{
			do
			{
				flagSwap = 0;
				for(int i=0; i<len-1; i++)
				{
					if( (order == 1 && ( (strncmp(list[i].lastName, list[i+1].lastName, LEN_NOMBRE) > 0) ||
						(strncmp(list[i].lastName, list[i+1].lastName, LEN_NOMBRE) == 0 && list[i].sector > list[i+1].sector)))||
						(order == 0 && ( (strncmp(list[i].lastName, list[i+1].lastName, LEN_NOMBRE) < 0) ||
						(strncmp(list[i].lastName, list[i+1].lastName, LEN_NOMBRE) == 0 && list[i].sector < list[i+1].sector))))
					{
						auxSwap = list[i];
						list[i] = list[i+1];
						list[i+1] = auxSwap;
						flagSwap = 1;
						retorno = 0;
					}
				}
			}while(flagSwap);
		}
		return retorno;;
}
/*
 * \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployees(Employee list[],
				int len,
				int id,
				char name[],
				char lastName[],
				float salary,
				int sector,
				int index)
{
	int retorno = -1;

	if (list != NULL &&
		len>0 &&
		name!=NULL &&
		lastName!=NULL &&
		salary > 0 &&
		sector > 0)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}
/*
* \brief pide los datos para introducir un nuevo empleado. Les asigna un ID único.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int emp_addEmployees(Employee *list, int len)
{
	int retorno = -1;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int index;

	if (!indiceVacio(list, len, &index) &&
		!utn_getLetrasYEspacios(name,
								sizeof(name),
								"\nNombre: ",
								"\nError. El nombre solo puede contener letras y espacios.\n",
								INTENTOS) &&
		!utn_getLetrasYEspacios(lastName,
								sizeof(lastName),
								"\nApellido: ",
								"\nError. El apellido solo puede contener letras y espacios.\n",
								INTENTOS) &&
		!utn_getNumero(&sector,
						"\nSector (1, 2 ó 3): ",
						"\nError. Ingrese 1, 2 ó 3",
						1, 3, INTENTOS) &&
		!utn_getNumeroFloat(&salary,
							"\nSalario: ",
							"\nError. Ingrese solo cifras.\n",
							0, LONG_MAX, INTENTOS))
	{
		id = nuevoId();
		addEmployees(list, len, id, name, lastName, salary, sector, index);
		printf("Carga exitosa.\n\n");
		retorno = 0;
	}else{printf("\nHubo un error en la carga. ");}
	return retorno;
}
/*
* \brief busca el id de un empleado y lo modifica.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int emp_modifyData(Employee *list, int len)
{
	int retorno = -1;
	int index;
	int id;
	int fieldToModify;
	int modifyFlag;

	if(list!=NULL && len >0 && isEmpty(list, len)==0)
	{
		if(!utn_getNumero(&id,
						"\nID del empleado: ",
						"\nError. El ID debe ser númerico.: ",
						0, INT_MAX,  INTENTOS))
		{
			(index=findEmployeeById(list, len, id));
			if(index!=-1)
			{
				Employee bufferEmployee = list[index];
				modifyFlag = FALSE;
				do{
					if(!utn_getNumero(&fieldToModify,
									"\nMENÚ MODIFICACIÓN.\n"
									"Elija el dato que quiera modificar: \n"
									"1-Nombre: \n2-Apellido: \n3-Salario: \n"
									"4-Sector: \n5-Volver a menú principal. ", "\n"
									"Ingrese una opcion valida: ",
									1, 5, INTENTOS))
					{
						switch(fieldToModify)
						{
						case 1:
							if(!utn_getLetrasYEspacios(bufferEmployee.name,
														LEN_NOMBRE,
														"\nIngrese el nuevo nombre del empleado: ",
														"\nERROR.Ingrese un nombre válido: ",
														INTENTOS))
							{
								printf("Nombre actualizado a %s.\n", bufferEmployee.name);
								modifyFlag = TRUE;
								retorno=0;
							}
							break;
						case 2:
							if(!utn_getLetrasYEspacios( bufferEmployee.lastName,
														LEN_NOMBRE,
														"\nIngrese el nuevo apellido del empleado: ",
														"\nERROR. Ingrese un apellido válido: ",
														INTENTOS))
							{
									printf("Apellido actualizado a %s.\n", bufferEmployee.lastName);
									modifyFlag = TRUE;
									retorno=0;
							}
							break;
						case 3:
							if(!utn_getNumeroFloat(&bufferEmployee.salary,
													"\nIngrese el nuevo salario del empleado: ",
													"\nERROR.Ingrese un valor válido: ",
													0, INT_MAX, INTENTOS))
							{
								printf("Salario actualizado a %f.\n", bufferEmployee.salary);
								modifyFlag = TRUE;
								retorno=0;
							}
							break;
						case 4:
							if(!utn_getNumero( &bufferEmployee.sector,
											"\nIngrese el nuevo sector del empleado: (1, 2 ó 3)",
											"\nERROR.Ingrese un valor válido.",
											1, 3, INTENTOS))
							{
								printf("Sector actualizado a %d. \n", bufferEmployee.sector);
								modifyFlag = TRUE;
								retorno=0;
							}
							break;
						}
					}
					if(modifyFlag==TRUE)
					{
						addEmployees(list, len, id, bufferEmployee.name, bufferEmployee.lastName, bufferEmployee.salary, bufferEmployee.sector, index);
					}
				}while(fieldToModify!=5);
			}else{printf("\nEl ID introducido no existe. Intente de nuevo.\n ");}
		}else{printf("\nError.");}
	retorno=0;
	}else{printf("\nError.\n");}
return retorno;
}
/*
* \brief pide los datos para introducir un nuevo empleado. Les asigna un ID único.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int emp_removeEmployee(Employee *list, int len)
{
	int id;
	int index;
	int retorno = -1;
	if (list != NULL && len > 0 && isEmpty(list, len)==0)
	{
		do{
			if (!utn_getNumero(&id,
								"\nIngrese el id del empleado que desea eliminar: ",
								"\nERROR. Introduzca una cifra.\n",
								0, INT_MAX, INTENTOS))
				{
					index=findEmployeeById(list, len, id);
					if(index!=-1)
					{
						list[index].isEmpty=TRUE;
						retorno=0;
						printf("%s %s ha sido dado de baja exitosamente.\n", list[index].name, list[index].lastName);
					}
					else
					{
						printf("ID inválido");
					}
				}
			}while(retorno==-1);
	}else{printf("Error.\n");}
	return retorno;
}
/*
* \brief genera el informe con la suma total de los salarios, el promedio de los salarios,
* 		el promedio de las personas que cobran por encima de la media y saca una tabla ordenada por apellido.
* \param puntero al array de empleados.
* \param longitud del array de empleados.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int emp_informe(Employee *list, int len)
{
	int retorno=-1;
	float sumaSalarios;
	float promedioSalarios;
	int empleadosSalarioArribaMedia;

	if(list !=NULL && len>0 && isEmpty(list, len)==0)
	{
		if(
			(!sortEmployees(list, len, 1)) &&
			(!calc_sumaArray(list, len,&sumaSalarios)) &&
			(!calc_promedioArray(list, len, &promedioSalarios)) &&
			(!calc_cantidadEncimaMedia(list, len, &empleadosSalarioArribaMedia)) &&
			(!printEmployees(list, len)))
		{
			printf("\nCIFRAS:\n\n");
			printf("-> Se pagan un total de $%f en salarios.\n\n", sumaSalarios);
			printf("-> Se paga en promedio $%f por persona.\n\n", promedioSalarios);
			printf("-> Hay %d persona/s cobrando por encima de la media.\n\n", empleadosSalarioArribaMedia);
			retorno=0;
		}
		else
		{
			printf("ERROR.\n\n");
		}
	}else{printf("\nError.\n");}
	return retorno;
}





