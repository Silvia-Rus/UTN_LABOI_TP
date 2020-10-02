/*
 * arrayEmployees.h
 *
 *  Created on: 29 sept. 2020
 *      Author: Silvia Rus Mata
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TRUE 1
#define FALSE 0

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int indiceVacio(Employee *list, int len, int *pIndiceLibre);
int isEmpty(Employee *list, int len);
int findEmployeeById(Employee* list,int len, int id);
int printEmployees(Employee* list, int len);
int sortEmployees(Employee *list, int len, int order);
int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector, int index);
int emp_addEmployees(Employee *list, int len);
int emp_modifyData(Employee *list, int len);
int emp_removeEmployee(Employee *list, int len);
int emp_informe(Employee *list, int len);



#endif /* ARRAYEMPLOYEES_H_ */
