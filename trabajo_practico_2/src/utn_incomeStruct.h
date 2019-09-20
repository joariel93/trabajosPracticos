/*
 * utn_bib.h
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */

#ifndef SRC_UTN_BIBINCOME_H_
#define SRC_UTN_BIBINCOME_H_
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
int utn_findEmployee(Employee pArray[], int limite,int* posicion);
int utn_addEmployee(Employee pArray[],int limite);
int utn_modifyEmployee(Employee pArray[]);
int utn_deleteEmployee(Employee pArray[]);
int utn_reportEmployee(Employee pArray[]);


#endif /* SRC_UTN_BIBINCOME_H_ */
