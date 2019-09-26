/*
 * utn_operacionesStruct.c
 *
 *  Created on: 25 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
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
int utn_comprobe(int pArray[],int limite,int *errorDatos)
{
	int i;
	for(i=0;i<5;i++)
			 	 	 	 	{
			 		 	 		if(pArray[i]==0)
			 		 	 		{
			 		 	 		*errorDatos=1;
			 		 	 		break;
			 		 	 		}
			 		 	 		else
			 		 	 		{
			 		 	 		*errorDatos=0;
			 		 	 		continue;
			 		 	 		}
			 	 	 	 	}
	return 0;
}

