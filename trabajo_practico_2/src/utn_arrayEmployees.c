/*
 * utn_incomeStruct.c
 *
 *  Created on: 2 oct. 2019
 *      Author: alumno
 */
#include "utn_arrayEmployees.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_inputs.h"

#define SECURITY "Esta seguro de querer modificar el"
int utn_initEmployees(Employee pArray[],int limite)
{
int i;
	for(i=0;i<limite;i++)
	{
	pArray[i].sector=0;
	pArray[i].isEmpty=0;
	}
	return 0;
}
int utn_findFreeEmployee(Employee pArray[], int limite,int* posicion)
{
int retorno=-1;
int i;
	if(pArray!=NULL && limite>0 && posicion!=NULL)
	{
		for(i=0;i<limite;i++)
		{if(pArray[i].isEmpty==0)
		{
			*posicion=i;
			retorno=0;
			break;
		}



		}
	}
return retorno;
}
int utn_findEmployeeById(Employee pArray[], int limite,int* posicion,int legajo)
{
int retorno=-1;
int i;
	for(i=0;i<limite;i++)
	{
		if(pArray!=NULL && limite>0	&&	posicion!=NULL &&	legajo>=0)
		{
			if(pArray[i].id==legajo)
			{
				*posicion=i;
				retorno=0;
				return retorno;
				break;
			}

		}
	}
	printf("No se ha encontrado el número de legajo ingresado\n");
return retorno;
}
int utn_addEmployee(Employee pArray[],int limite,int contador,int stringLimit)
{
char names[stringLimit];
int posicion;
int retorno=-1;
float salario;
int sector;
int empty[4]={0,0,0,0};
int seleccion;
int end=0;
int errorDatos=1;

 if(pArray!=NULL&&limite>0&&contador>=0)
 {
	 if(utn_findFreeEmployee(pArray,limite,&posicion)==-1)
	 {
		 printf("\n No hay lugares vacios");
	 }
	 else
	 {	while(end==0)
	 	 {	 printf("Pantalla de ingreso de datos:\n");
		 	 printf("[1] Nombre\n");
		 	 printf("[2] Apellido\n");
		 	 printf("[3] Salario\n");
		 	 printf("[4] Sector\n");
		 	 printf("[5] Volver\n");
		 	 __fpurge(stdin);
		 	 scanf("%d",&seleccion);
		 	 switch(seleccion)
		 	 {
		 	 case 1:	utn_getString(names,"Ingrese el nombre: ","Error debe ingresar caracteres alfabéticos",stringLimit,stringLimit);
		 	 	 	 	strncpy(pArray[posicion].name,names,51);
		 	 	 	 	empty[0]=1;
	 					break;
		 	 case 2:	utn_getString(names,"Ingrese el apellido: ","Error debe ingresar caracteres alfabéticos",stringLimit,stringLimit);
		 	 	 	 	strncpy(pArray[posicion].lastName,names,51);
		 	 	 	 	empty[1]=1;
	 					break;
		 	 case 3:	utn_getFloat(&salario,"Ingrese el salario: ","Error debe ingresar un número válido",1,1000000,5);
		 	 	 	 	pArray[posicion].salary=salario;
		 	 	 	 	empty[2]=1;
	 					break;
		 	 case 4:	utn_getInt(&sector,"Ingrese el código de sector ","Error debe ingresar un código válido",1,10,5);
		 	 	 	 	pArray[posicion].sector=sector;
		 	 	 	 	empty[3]=1;
	 					break;
		 	 default:	utn_comprobe(empty,4,&errorDatos);
		 		 	 	if(errorDatos==1)
	 					{
	 					printf("Falta ingresar datos.");
	 					}
	 					else
	 					{
	 					pArray[posicion].isEmpty=1;
	 					pArray[posicion].id=contador;
	 					retorno=0;
	 					return retorno;
	 					}
		 	 }
 		 }
	 }
 }

return retorno;
}
int utn_modifyEmployee(Employee pArray[],int limite,int stringLimit)
{
	int retorno = -1;
	int volver;
	int seleccion;
	int posicion;
	int legajo;
	int end = 0;
	int definitiveModification = 0;
	char newNames[stringLimit];
	float newSalary;
	int newSector;
	while (end == 0)
	{
		printf("[1] Ingresar legajo a modificar\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d", &volver);
		switch (volver)
		{
			case 2:	return 0;
					break;
			default:printf("Ingrese el numero de legajo del empleado que desea modificar: ");
					__fpurge(stdin);
					scanf("%d", &legajo);
					if (utn_findEmployeeById(pArray, limite, &posicion, legajo) == 0)
					{
						printf("Que desea modificar a %s %s:\n", pArray[posicion].name,pArray[posicion].lastName);
						printf("[1] Nombre\n");
						printf("[2] Apellido\n");
						printf("[3] Salario\n");
						printf("[4] Sector\n");
						printf("[5] Volver\n");
						__fpurge(stdin);
						scanf("%d", &seleccion);
						switch (seleccion)
						{
							case 1:	utn_getString(newNames, "Ingrese nuevo nombre: ","Error debe ingresar caracteres alfabéticos", stringLimit,stringLimit);
									while (definitiveModification == 0)
									{
										printf("%s nombre de %s a %s?\n", SECURITY,pArray[posicion].name, newNames);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	strncpy(pArray[posicion].name, newNames, stringLimit);
													end=1;
													break;
											case 2:	break;
										}
									}
									break;
							case 2:	utn_getString(newNames, "Ingrese nuevo apellido: ","Error debe ingresar caracteres alfabéticos", stringLimit, stringLimit);
									while (definitiveModification == 0)
									{
										printf("%s apellido de %s a %s?\n", SECURITY,pArray[posicion].lastName, newNames);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	strncpy(pArray[posicion].lastName, newNames,stringLimit);
													end=1;
													break;
											case 2:	break;
										}
									}
									break;
							case 3:	utn_getFloat(&newSalary, "Ingrese nuevo salario: ","Error debe ingresar un número válido.", 1, 1000000,5);
									while (definitiveModification == 0)
									{
										printf("%s salario de %.2f a %.2f?\n", SECURITY,pArray[posicion].salary, newSalary);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	pArray[posicion].salary = newSalary;
													end=1;
													break;
											case 2:	break;
										}
									}
									break;
							case 4:	utn_getInt(&newSector, "Ingrese nuevo código de sector: ","Debe ingresar un código de sector válido", 1, 10,5);
									while (definitiveModification == 0)
									{
										printf("%s sector de %d a %d?\n", SECURITY,pArray[posicion].sector, newSector);
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	pArray[posicion].sector = newSector;
													end=1;
													break;
											case 2:	break;
										}
									}
							default:break;
						}
					}
					break;
			}

		}

	retorno = 0;
	return retorno;

}
int utn_removeEmployee(Employee pArray[],int limite)
{
int end=0;
int legajo;
int volver;
int delete=0;
int seleccion;
int definitiveModification=0;
int posicion;
while (end == 0)
	{
		printf("[1] Ingresar legajo a eliminar\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d", &volver);
		switch (volver)
		{
			case 2:	return 0;
					break;
			default:printf("Ingrese el numero de legajo del empleado que desea eliminar: ");
					__fpurge(stdin);
					scanf("%d", &legajo);
					if (utn_findEmployeeById(pArray, limite, &posicion, legajo) == 0)
					{
						printf("Desea eliminar a %s %s\n",pArray[posicion].name,pArray[posicion].lastName);
						printf("[1] Si\n[2] No\n");
						__fpurge(stdin);
						scanf("%d", &seleccion);
						switch (seleccion)
						{
							case 1:	while (definitiveModification == 0)
									{
										printf("Confirme su decision\n");
										printf("[1] Si\n[2] No\n");
										__fpurge(stdin);
										scanf("%d", &definitiveModification);
										switch (definitiveModification)
										{
											case 1:	pArray[posicion].isEmpty = delete;

													end=1;
													break;
											case 2:	break;
										}
									}
						}
					}
		}
	}

return 0;
}
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
							case 1: utn_sortEmployees(pArray,limite,choice);
									break;
							case 2: utn_sortEmployees(pArray,limite,choice);
									break;
							default:end=1;
									break;
							}
				}
		return 0;
}
int utn_sortEmployees(Employee pArray[],int limite,int choice)
{
int flagPasada=-1;
int i;
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
utn_printEmployees(pArray,limite);
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
int utn_printEmployees(Employee pArray[],int limite)
{
	float sumSalaryes=0;
	float promSalaryes=0;
	int cantEmployees=0;
	int cantHighSalaryes=0;
	int j;
	printf("Legajo\tApellido Nombre\tSalario\tSector\n");
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

	printf("\nSalarios:\nTotal	Promedio	Cantidad de empleados que superan promedio\n");
	for(j=0;j<limite;j++)
	{
		if(pArray[j].isEmpty==1)
		{
			cantEmployees++;
			sumSalaryes=sumSalaryes+pArray[j].salary;
		}
	}
	promSalaryes=sumSalaryes/(float)cantEmployees;
	for(j=0;j<limite;j++)
	{
		if(pArray[j].salary>promSalaryes)
		{
			cantHighSalaryes++;
		}
	}
	printf("%.2f	%.2f	%20d\n",sumSalaryes,promSalaryes,cantHighSalaryes);
	return 0;
}

