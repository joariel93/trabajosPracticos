/*
 * trabajoPractico2.c
 *
 *  Created on: 18 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_incomeStruct.h"
#include "utn_operacionesStruct.h"

#define LIMITE 1000
int main (void){
	Employee datos[LIMITE];
	int opcion;
	int end=0;

	while(end==0)
	{
		printf("Que desea hacer? \n");
		printf("[1] Altas \n");
		printf("[2] Modificaciones \n");
		printf("[3] Bajas \n");
		printf("[4] Informes \n");
		printf("[5] Salir \n");
		__fpurge(stdin);
		scanf("%d",&opcion);
		utn_initEmployee(datos,LIMITE);
		switch(opcion)
		{
		case 1: utn_addEmployee(datos,1000);
				break;
		case 2: utn_modifyEmployee(datos);
				break;
		case 3: utn_deleteEmployee(datos);
				break;
		case 4: utn_reportEmployee(datos);
				break;
		default: end=1;
				break;
		}

	}
	return 0;
}

