/*
 * utn_operacionesStruct.c
 *
 *  Created on: 2 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

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
							case 1: utn_order(pArray,limite,choice);
									break;
							case 2: utn_order(pArray,limite,choice);
									break;
							default:end=1;
									break;
							}
				}
		return 0;
}

int utn_order(Employee pArray[],int limite,int choice)
{
int flagPasada=-1;
int i,j;
Employee aux;

while(flagPasada==-1)
{
	flagPasada=0;
	for(i=0;i<limite;i++)
	{
		if(pArray[i].isEmpty!=0&&pArray[i+1].isEmpty!=0&&(i+1)<=limite)
		{
			if(choice==1)
			{
				if(strcmp(pArray[i].lastName,pArray[i+1].lastName)==0)
				{
					if(pArray[i].sector>pArray[i+1].sector)
					{
						aux=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=aux;
						flagPasada=-1;
					}

				}else if(strcmp(pArray[i].lastName,pArray[i+1].lastName)>0&&(i+1)<=limite)
				{
					aux=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=aux;
					flagPasada=-1;
				}

			}else
			{
				if(strcmp(pArray[i].lastName,pArray[i+1].lastName)==0&&i+1<=limite)
								{
									if(pArray[i].sector<pArray[i+1].sector)
									{
										aux=pArray[i];
										pArray[i]=pArray[i+1];
										pArray[i+1]=aux;
										flagPasada=-1;
									}

								}else if(strcmp(pArray[i].lastName,pArray[i+1].lastName)<0&&i+1<=limite)
								{
									aux=pArray[i];
									pArray[i]=pArray[i+1];
									pArray[i+1]=aux;
									flagPasada=-1;
								}
			}
		}else if(pArray[i].isEmpty==0&&pArray[i+1].isEmpty!=0&&i+1<=limite)
		{
			aux=pArray[i];
			pArray[i]=pArray[i+1];
			pArray[i+1]=aux;
			flagPasada=-1;
		}else if(pArray[i].isEmpty==0&&pArray[i+1].isEmpty==0&&i+1<=limite)
		{
			continue;
		}
	}
}
printf("Legajo\tApellido\tNombre\tSalario\tSector\n");
for(j=0;j<limite;j++)
{
		if(pArray[j].isEmpty==1)
		{
			printf("%d\t%s\t%s\t%.2f\t%d\n",pArray[j].id,pArray[j].lastName,pArray[j].name,pArray[j].salary,pArray[j].sector);
		}else if(pArray[j].isEmpty==0)
		{
			continue;
		}
}
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

