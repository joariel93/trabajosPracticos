/*
 * utn_bibcalculations.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

#include "utn_incomeStruct.h"
int utn_alphabetically(Employee pArray[]);
int utn_salaries(Employee pArray[]);
int utn_reportEmployee(Employee pArray[])
{int end=0;
int choice;
	while(end==0)
		{
			printf("Que desea hacer? \n");
			printf("[1] Ordenar alfabéticamente \n");
			printf("[2] Ordenar por salario \n");
			printf("[3] Volver \n");
			__fpurge(stdin);
			scanf("%d",&choice);
			switch(choice)
					{
					case 1: utn_alphabetically(pArray);
							break;
					case 2: utn_salaries(pArray);
							break;
					default:end=1;
							break;
					}
		}
return 0;
}
int utn_alphabetically(Employee pArray[])
{

	return 0;
}
int utn_salaries(Employee pArray[])
{

	return 0;
}
