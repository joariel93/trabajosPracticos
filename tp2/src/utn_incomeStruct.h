/*
 * utn_incomeStruct.h
 *
 *  Created on: 25 sep. 2019
 *      Author: alumno
 */

#ifndef UTN_INCOMESTRUCT_H_
#define UTN_INCOMESTRUCT_H_

typedef struct
{
	int id;
	int legajo;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
int utn_initEmployee(Employee pArray[],int limite);
int utn_findFreeEmployee(Employee pArray[],int limite,int* posicion);
int utn_findEmployee(Employee pArray[], int limite,int* posicion,int legajo);
int utn_addEmployee(Employee pArray[],int limite);
int utn_modifyEmployee(Employee pArray[],int limite);
int utn_deleteEmployee(Employee pArray[],int limite);
int utn_reportEmployee(Employee pArray[]);




#endif /* UTN_INCOMESTRUCT_H_ */
