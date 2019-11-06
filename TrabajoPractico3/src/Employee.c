#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Employee.h"


Employee* employee_new(){
Employee* emp = (Employee*)malloc( sizeof(Employee));

if(emp != NULL){
	emp->id=0;
	strcpy(emp->nombre," ");
	emp->horasTrabajadas=0;
	emp->sueldo=0;

}
return emp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
int auxId,auxHorasTrabajadas,auxSueldo;
char auxNombre[30];
	Employee* emp = (Employee*)malloc( sizeof(Employee));

	if(emp != NULL){
	    auxId=atoi(idStr);
	    strcpy(auxNombre, nombreStr);
	    auxHorasTrabajadas=atoi(horasTrabajadasStr);
	    auxSueldo=atoi(sueldo);
	    employee_setId(emp,auxId);
	    employee_setNombre(emp,auxNombre);
	    employee_setHorasTrabajadas(emp,auxHorasTrabajadas);
	    employee_setSueldo(emp,auxSueldo);
	}


	return emp;
}
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL&&id>=0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
	id=this->id;
	retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas>=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		retorno=0;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL)
	{
		sueldo=this->sueldo;
		retorno=0;
	}

	return retorno;
}


