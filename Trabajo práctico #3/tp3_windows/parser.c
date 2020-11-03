#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "getData.h"

#define AUX_LEN 4096

/* \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param la ruta del archivo que queremos parsear
 * \param el array de punteros a dónde vamos a almacenar los datos.
 * \return 0 si todo ok, -1 si hay errores.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retornar=-1;
	char auxId[AUX_LEN];
	char auxNombre[AUX_LEN];
	char auxHorasTrabajadas[AUX_LEN];
	char auxSueldo[AUX_LEN];
	int r;
	Employee* auxEmployee;
	int flagEncabezado = 0;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
			if (flagEncabezado == 0)
			{
				flagEncabezado = 1;
			}
			else
			{
				if(r==4)
				{
					auxEmployee = employee_newParametrosChar(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					ll_add(pArrayListEmployee, auxEmployee);
					retornar=0;
				}
			}
		}while(feof(pFile)==0);
		fclose(pFile);
	}
	return retornar;
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
