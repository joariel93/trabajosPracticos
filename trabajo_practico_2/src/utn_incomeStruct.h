/*
 * utn_incomeStruct.h
 *
 *  Created on: 2 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_INCOMESTRUCT_H_
#define UTN_INCOMESTRUCT_H_
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
int utn_initEmployee(Employee pArray[],int limite);
int utn_findFreeEmployee(Employee pArray[],int limite,int* posicion);
int utn_findEmployee(Employee pArray[], int limite,int* posicion,int legajo);
int utn_addEmployee(Employee pArray[],int limite,int contador, int stringLimit);
int utn_modifyEmployee(Employee pArray[],int limite, int stringLimit);
int utn_deleteEmployee(Employee pArray[],int limite);




#endif /* UTN_INCOMESTRUCT_H_ */
