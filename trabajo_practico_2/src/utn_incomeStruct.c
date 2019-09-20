/*
 * utn_bib.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <string.h>
#include "utn_incomeStruct.h"
#include "utn_inputs.h"
int utn_initEmployee(Employee pArray[],int limite)
{
int i;
	for(i=0;i<limite;i++)
	{
	pArray[i].isEmpty=0;
	}
	return 0;
}
int utn_findFreeEmployee(Employee pArray[]*aArray, int limite,int* posicion)
{
int retorno=-1;
int i;
	if(pArray!=NULL && limite>0&&posicion!=NULL)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].status==0)
			{

			retorno=i;
			}
		}
	}
return retorno;
}
int utn_findEmployee(Employee pArray[], int limite,int* posicion)
{
int retorno=-1;
int i;
	for(i=0;i<limite;i++)
	{
		if(pArray!=NULL && limite>0&&posicion!=NULL)
		{

			retorno=0;
		}
	}
return retorno;
}
int utn_addEmployee(Employee pArray[],int limite)
{
int contadorID=0;
int posicion;
int retorno=-1;
float salario;
int sector;

 if(pArray!=NULL&&limite>0&&contadorID!=NULL)
 {
	 if(utn_findFreeEmployee(pArray,limite,&posicion)==-1)
	 {
		 printf("\n No hay lugares vacios");
	 }
	 else
	 {
	 	pArray[posicion].id=contadorID;
	 	utn_getString(pArray[posicion].name,"Ingrese el nombre: ",51,51);
	 	utn_getString(pArray[posicion].lastName,"Ingrese el apellido: ",51,51);
	 	pArray[posicion].salary=utn_getFloat(&salario,"Ingrese el salario: ","Error debe ingresar un número válido",0,1000000,5);
	 	pArray[posicion].sector=utn_getInt(&sector,"Ingrese el código de sector ","Error debe ingresar un código válido",1,15,5);
	 	pArray[posicion].isEmpty=1;
	 	contadorID++;
 		retorno=0;
	 }
 }

return retorno;
}
int utn_modifyEmployee(Employee pArray[])
{

return 0;
}
int utn_deleteEmployee(Employee pArray[])
{

return 0;
}

