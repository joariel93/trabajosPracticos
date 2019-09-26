/*
 * utn_incomeStruct.c
 *
 *  Created on: 25 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_incomeStruct.h"
#include "utn_inputs.h"
#include "utn_operacionesStruct.h"
int utn_initEmployee(Employee pArray[],int limite)
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
int utn_findEmployee(Employee pArray[], int limite,int* posicion,int legajo)
{
int retorno=-1;
int i;
	for(i=0;i<limite;i++)
	{
		if(pArray!=NULL && limite>0	&&	posicion!=NULL &&	legajo>0)
		{
			if(pArray[i].legajo==legajo)
			{
				*posicion=i;
				retorno=0;
				break;
			}

		}
	}
	printf("No se ha encontrado el número de legajo ingresado\n");
return retorno;
}
int utn_addEmployee(Employee pArray[],int limite)
{
int contadorID=0;
int posicion;
int retorno=-1;
float salario;
int legajo;
int sector;
int empty[5]={0,0,0,0,0};
int seleccion;
int end=0;
int errorDatos=1;

 if(pArray!=NULL&&limite>0&&contadorID>0)
 {
	 if(utn_findFreeEmployee(pArray,limite,&posicion)==-1)
	 {
		 printf("\n No hay lugares vacios");
	 }
	 else
	 {	while(end==0)
	 	 {	 printf("Pantalla de ingreso de datos:\n");
		 	 printf("[1] N° de legajo\n");
		 	 printf("[2] Nombre\n");
		 	 printf("[3] Apellido\n");
		 	 printf("[4] Salario\n");
		 	 printf("[5] Sector\n");
		 	 printf("[6] Volver\n");
		 	 __fpurge(stdin);
		 	 scanf("%d",&seleccion);
		 	 switch(seleccion)
		 	 {
		 	 case 1:	utn_getInt(&legajo,"Ingrese el numero de legajo\n","Error el numero de legajo ingresado ya está usado o no es válido",0,10000,5);
		 	 	 	 	pArray[posicion].legajo=legajo;
		 	 	 	 	pArray[posicion].id=contadorID;
		 	 	 	 	empty[0]=1;
	 	 	 	 		break;
		 	 case 2:	utn_getString(pArray[posicion].name,"Ingrese el nombre: ",51,51);
		 	 	 	 	pArray[posicion].id=contadorID;
	 					empty[1]=1;
	 					break;
		 	 case 3:	utn_getString(pArray[posicion].lastName,"Ingrese el apellido: ",51,51);
		 	 	 	 	pArray[posicion].id=contadorID;
		 	 	 	 	empty[2]=1;
	 					break;
		 	 case 4:	pArray[posicion].salary=utn_getFloat(&salario,"Ingrese el salario: ","Error debe ingresar un número válido",1,1000000,5);
		 	 	 	 	pArray[posicion].id=contadorID;
		 	 	 	 	empty[3]=1;
	 					break;
		 	 case 5:	pArray[posicion].sector=utn_getInt(&sector,"Ingrese el código de sector ","Error debe ingresar un código válido",1,10,5);
		 	 	 	 	pArray[posicion].id=contadorID;
		 	 	 	 	empty[4]=1;
	 					break;
		 	 default:	utn_comprobe(empty,5,&errorDatos);
		 		 	 	if(errorDatos==1)
	 					{
	 					printf("Falta ingresar datos∖n");
	 					}
	 					else
	 					{
	 					contadorID++;
	 					retorno=0;
	 					return retorno;
	 					}
		 	 }
 		 }
	 }
 }

return retorno;
}
int utn_modifyEmployee(Employee pArray[],int limite)
{
int retorno=-1;
int volver;
int seleccion;
int posicion;
int legajo;
int end=0;

int sinIngresos=0;
float newSalary;
int newSector;
int i;
while(end==0)
	{
		printf("[1] Ingresar legajo a modificar\n");
		printf("[2] Volver\n");
		__fpurge(stdin);
		scanf("%d",&volver);
		switch(volver)
			{
				case 2: break;
				default:printf("Ingrese el numero de legajo del empleado que desea ingresar: ");
						__fpurge(stdin);
						scanf("%d",&legajo);
						if(utn_findEmployee(pArray,limite,&posicion,legajo)==0)
						{
							printf("Que desea modificar a %s %s:\n",pArray[posicion].name,pArray[posicion].lastName);
							printf("[1] Nombre\n");
							printf("[2] Apellido\n");
							printf("[3] Salario\n");
							printf("[4] Sector\n");
							printf("[5] Volver\n");
							__fpurge(stdin);
							scanf("%d",&seleccion);
							switch(seleccion)
							{
							case 1:		utn_getString(pArray[posicion].name,"Ingrese nuevo nombre: ",51,51);
										break;
							case 2:		utn_getString(pArray[posicion].lastName,"Ingrese nuevo apellido: ",51,51);
										break;
							case 3:		utn_getFloat(&newSalary,"Ingrese nuevo salario: ","Error debe ingresar un número válido.",1,1000000,5);
										pArray[posicion].salary=newSalary;
										break;
							case 4:		utn_getInt(&newSector,"Ingrese nuevo código de sector: ","Debe ingresar un código de sector válido",1,10,5);
										pArray[posicion].sector=newSector;
										break;
							default:	break;
							}
						}
				}

			retorno=0;
			return retorno;

	}

return 0;
}
int utn_deleteEmployee(Employee pArray[],int limite)
{
int end=0;
int sinIngresos=0;
int i;
while(end==0)
{

}

return 0;
}


