/*
 * 	Employee.h
 *
 *      Author: Silvia Rus Mata
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "getData.h"


/*
 * \brief construye un espacio de memoria para alojar un nuevo cliente.
 * \return devuelve un puntero a dicho espacio si lo encontró o NULL si no.
 */

//hacer un espacio en la memoria para meter a un cliente
//antes buscábamos el primer índice libre pero ahora la memoria es dinámica

Employee* employee_new()//ESTE OK
{
	//malloc quiere la cantidad de bytes del área de memoria que va a devolver.
	//devuelve la dirección de memoria donde empieza lo reservado.
	//en ese espacio debe caber un empleado.

	Employee* p;
	p=(Employee*)malloc(sizeof(Employee));

	if(p!=NULL)
	{
		//ya encontramos el espacio de la memoria en la que va a estar el empleado
		//para que no arranque vacío
		p->id=0;
		p->nombre[0]='\n';
		p->horasTrabajadas=0;
		p->sueldo=0;
		//devuelve la dirección de memoria que reservó malloc.
		return p;
	}
	else{return NULL;}
}
/*
* \brief compara todos los id encontrados en el CSV y devuelve el valor más alto.
* \param el listado en el que se va a buscar.
* \return el id más alto encontrado en el CSV..
*/
int idMasAltoCsv(LinkedList* this)
{
	int retorno=-1;
	//la longitud de la LinkedList
	int len = ll_len(this);
	Employee* auxEmployee;
	int id;
	int idMasAltoCsv;
	if(this!=NULL)
	{
		//recorremos LinkedList
		for(int i=0;i<len;i++)
		{
			//puntero al empleado recuperado desde LinkedList
			auxEmployee = ll_get(this, i);
			//tomamos el id de ese empleado que hay en ese puntero que hay en ese lugar de LinkedList
			employee_getId(auxEmployee, &id);
			//hace la comparación, guarda el más alto y devuelve el siguiente
			if(i==0 || id>idMasAltoCsv)
			{
				idMasAltoCsv = id;
				retorno = idMasAltoCsv;
			}
		}
	}
	return retorno;

}
/*int cli_nuevoId(void)
{
	LinkedList* this;
	static int id = idMasAltoCsv(*this);
	id = id + 1;
	return id;
}*/

/*
* \brief genera identificadores únicos autoincrementales.
* \return el identificador único autoincremental generado.
*/
int employee_nuevoId(void)
{
	static int id = 0;
	id = id + 1;
	return id;
}
/*
 * \brief constructor que inicializa los parámetros que puedo recibir.
 * \param puntero al id generado de manera autoincremental.
 * \param puntero al nombre introducido para el empleado.
 * \param puntero al número de horas trabajadas introducidas para el empleado.
 * \return ¿?¿
 */
Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* punteroEmpleado=0;
	//aquí creamos el espacio de memoria
	punteroEmpleado = employee_new();
	//Aquí lo que devolvemos por puntero
	if(punteroEmpleado !=NULL)
	{
		//Ahí guarda los valores que pasan por paramétros.

		employee_setIdChar(punteroEmpleado, idStr);
		employee_setNombre(punteroEmpleado, nombreStr);
		employee_setHorasTrabajadasChar(punteroEmpleado, horasTrabajadasStr);
		employee_setSueldoChar(punteroEmpleado, sueldoStr);
	}
	return punteroEmpleado;
}

/*
 * \brief constructor que inicializa los parámetros que puedo recibir.
 * \param puntero al id generado de manera autoincremental.
 * \param puntero al nombre introducido para el empleado.
 * \param puntero al número de horas trabajadas introducidas para el empleado.
 * \return ¿?¿
 */
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr)//ESTE OK
{
	Employee* punteroEmpleado=0;
	//aquí creamos el espacio de memoria
	punteroEmpleado = employee_new();
	//Aquí lo que devolvemos por puntero
	if(punteroEmpleado !=NULL)
	{
		//Ahí guarda los valores que pasan por paramétros.
		punteroEmpleado->id = idStr;
		strncpy(punteroEmpleado->nombre,nombreStr,128);
		punteroEmpleado->horasTrabajadas = horasTrabajadasStr;
		punteroEmpleado->sueldo = sueldoStr;
	}
	return punteroEmpleado;
}

/*
 * \brief encuentra la posición en memoria de un empleado del cual tenemos un id que entra por parámetro.
 * \param array en el que vamos a buscar el espacio de emoria.
 * \param id a buscar..
 * \return el lugar en la memoria.
 */
int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	int len = ll_len(pArrayListEmployee);
	int auxId;
	Employee* auxEmp;
	if(pArrayListEmployee!=NULL && id>0)
	{
		for(int i=0;i<len;i++)
		{
			auxEmp = ll_get(pArrayListEmployee, i);
			if(!employee_getId(auxEmp, &auxId) && auxId == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief valida el id introducido y lo copia al array.
 * \param array en el que vamos a copiar el id
 * \param id a introducir.
 * \return 0 si lo copió sin problemas, -1 si hubo un error.
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}
/*
 * \brief valida el id introducido como texto y lo copia al array entero.
 * \param array en el que vamos a copiar el id
 * \param id a introducir.
 * \return 0 si lo copió sin problemas, -1 si hubo un error.
 */
int employee_setIdChar(Employee* this, char* id)
{
	int retorno=-1;
	char auxId[AUX_LEN];
	if(this!=NULL && id!=NULL && esNumericaInt(id, AUX_LEN)==1)
	{
		strncpy(auxId, id, AUX_LEN);
		this->id = atoi(auxId);
		retorno=0;
	}
	return retorno;
}
/*
 * \brief va al array y devuelve por puntero el id.
 * \param array en el que buscamos el id.
 * \param el id que queremos recuperar.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}

/*
 * \brief valida el nombre introducido y lo copia al array.
 * \param array en el que vamos a copiar el nombre
 * \param nombre a introducir.
 * \return 0 si lo copió sin problemas, -1 si hubo un error.
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL                         &&
		nombre !=NULL                       &&
		//valida que son letras y espacios
		esLetrasYEspacios(nombre, NOMBRE_LEN) )
	{
		//copia el nombre que ENTRÓ por parámetro a this->nombre.
		//para acceder a ese campo hay que invocar esta función
		strncpy(this->nombre, nombre, NOMBRE_LEN);
		retorno= 0;
	}
	return retorno;
}
/*
 * \brief va al array y devuelve por puntero el nombre.
 * \param array en el que buscamos el nombre,
 * \param nombre que queremos recuperar.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre !=NULL)
	{
		//vamos y vemos que hay en el array y LO DEVOLVEMOS por parámtero,
		//por eso no validamos, porque ya está validad cuando se introdujo.
		//copia lo que hay en this->nombre a la variable que enviamos.
		strncpy(nombre, this->nombre, NOMBRE_LEN);
		retorno= 0;
	}
	return retorno;
}
/*
 * \brief copia el valor introducido para horas trabajadas.
 * \param array en el que vamos a copiar las horas trabajadas.
 * \param número de horas trabajadas a introducir.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && horasTrabajadas>-1)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
/*
 * \brief copia el valor introducido para horas trabajadas y lo transforma en un entero..
 * \param array en el que vamos a copiar las horas trabajadas.
 * \param número de horas trabajadas a introducir.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setHorasTrabajadasChar(Employee* this, char* horasTrabajadas)
{
	int retorno=-1;
	char auxHorasTrabajadas[AUX_LEN];
	if(this!=NULL && horasTrabajadas>0 && esNumericaInt(horasTrabajadas, AUX_LEN)==1)
	{
		strncpy(auxHorasTrabajadas, horasTrabajadas, AUX_LEN);
		this->horasTrabajadas = atoi(auxHorasTrabajadas);
		retorno=0;
	}
	return retorno;
}
/*
 * \brief devuelve por puntero las horas trabajadas que figuran en el array.
 * \param array en el que vamos a copiar las horas trabajadas.
 * \param número de horas trabajadas a recuperar.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
/*
 * \brief copia el valor introducido para sueldo.
 * \param array en el que vamos a introducir el sueldo.
 * \param sueldo a introducir.
 * \return 0 si lo introdujo sin problemas, -1 si hubo un error.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo>-1)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}
/*
 * \brief copia el valor introducido para el sueldo y lo transforma en un entero..
 * \param array en el que vamos a copiar el sueldo.
 * \param número de horas trabajadas a introducir.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_setSueldoChar(Employee* this, char* sueldo)
{
	int retorno=-1;
	char auxSueldo[AUX_LEN];
	if(this!=NULL && esNumericaInt(sueldo, AUX_LEN)==1)
	{
		strncpy(auxSueldo, sueldo, AUX_LEN);
		this->sueldo = atoi(auxSueldo);
		retorno=0;
	}
	return retorno;
}
/*
 * \brief devuelve por puntero sueldo que figura en el array.
 * \param array en el que vamos a buscar el sueldo.
 * \param sueldo a recuperar.
 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}
