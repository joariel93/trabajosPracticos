/*
 * utn_incomeStruct.h
 *
 *  Created on: 2 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_ARRAYEMPLOYEES_H_
#define UTN_ARRAYEMPLOYEES_H_
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
int utn_initEmployees(Employee pArray[],int limite);
int utn_findFreeEmployee(Employee pArray[],int limite,int* posicion);
int utn_findEmployeeById(Employee pArray[], int limite,int* posicion,int legajo);
int utn_addEmployee(Employee pArray[],int limite,int contador, int stringLimit);
int utn_modifyEmployee(Employee pArray[],int limite, int stringLimit);
int utn_removeEmployee(Employee pArray[],int limite);
int utn_reportEmployee(Employee pArray[],int limite);
int utn_sortEmployees(Employee pArray[],int limite,int choice);
int utn_comprobe(int pArray[],int limite,int *errorDatos);
int utn_printEmployees(Employee pArray[],int limite);



#endif /* UTN_ARRAYEMPLOYEES_H_ */
