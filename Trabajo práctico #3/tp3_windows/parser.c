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

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

				if(r==4 && esNumericaInt(auxId, sizeof(auxId)))
				{
					auxEmployee = employee_newParametrosChar(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					ll_add(pArrayListEmployee, auxEmployee);
					retornar=0;
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
		int output=-1;
		char auxNombre[NOMBRE_LEN];
		int auxId;
		int auxHorasTrabajadas;
		int auxSueldo;

		Employee* auxEmployee;
		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
			ll_clear(pArrayListEmployee);
			do
			{
				if( fread(&auxId,sizeof(int),1,pFile) &&
					fread(auxNombre, NOMBRE_LEN, 1, pFile)&&
					fread(&auxHorasTrabajadas,sizeof(int), 1, pFile) &&
					fread(&auxSueldo,sizeof(int),1,pFile))
				{
					auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
					ll_add(pArrayListEmployee, auxEmployee);
					output=0;
				}
			}while(feof(pFile)==0);
			fclose(pFile);
		}

		return output;
	}
