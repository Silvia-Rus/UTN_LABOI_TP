/*
 * 	Employee.h
 *
 *      Author: Silvia Rus Mata
 */
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 128
#define AUX_LEN 4096

typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

int idMasAltoCsv(LinkedList* this);
int employee_nuevoId(void);
int employee_findById(LinkedList* pArrayListEmployee, int id);
Employee* employee_new();
int employee_initArrayPunteros (Employee** listPunteros, int len);
int employee_indiceVacio(Employee** listPunteros, int len);
int employee_printArrayPunteros(Employee** listPunteros, int len);
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr);
Employee* employee_newParametrosChar(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_deleteIndexInArray(Employee** listPunteros, int len, int indice);
int employee_buscarPorIdArray(Employee** listPunteros, int len, int id);

int employee_setId(Employee* this,int id);
int employee_setIdChar(Employee* this, char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasChar(Employee* this, char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoChar(Employee* this, char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
