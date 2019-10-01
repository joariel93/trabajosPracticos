/*
 * utn_bibcalculations.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn_bibincome.h"
int utn_reportEmployee(Employee pArray[])
{int end=0;
int choice;
	while(end==0)
		{
			printf("Que desea hacer? \n");
			printf("[1] Altas \n");
			printf("[2] Modificaciones \n");
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

}
int utn_alphabetically(Employee pArray[])
{

}
int utn_salaries(Employee pArray[])
{

}
