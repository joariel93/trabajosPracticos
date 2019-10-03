/*
 * utn_operacionesStruct.c
 *
 *  Created on: 2 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "utn_incomeStruct.h"

int utn_reportEmployee(Employee pArray[],int limite)
{
	int end=0;
		int choice;
			while(end==0)
				{
					printf("Como desea ordenar? \n");
					printf("[1] Ascendente\n");
					printf("[2] Descendente\n");
					printf("[3] Volver \n");
					__fpurge(stdin);
					scanf("%d",&choice);
					switch(choice)
							{
							case 1: utn_ascend(pArray,limite);
									break;
							case 2: utn_descend(pArray,limite);
									break;
							default:end=1;
									break;
							}
				}
		return 0;
}

int utn_ascend(Employee pArray[],int limite)
{
int flagChange=-1;
int i;
while(flagChange==-1)
{
	if(pArray[])
}

	return 0;
}
int utn_descend(Employee pArray[],int limite)
{

	return 0;
}
int utn_comprobe(int pArray[],int limite,int *errorDatos)
{
	int i;
	for(i=0;i<limite;i++)
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

