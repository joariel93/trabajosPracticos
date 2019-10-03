#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_incomeStruct.h"
#include "utn_operacionesStruct.h"


#define LIMITEARRAY 3
int main (void){
	Employee datos[LIMITEARRAY];
	int contadorID=0;
	int opcion;
	int flag=0;
	int end=0;
	utn_initEmployee(datos,LIMITEARRAY);
	while(end==0)
	{
		printf("Bienvenido, que desea hacer? \n");
		printf("[1] Altas \n");
		printf("[2] Modificaciones \n");
		printf("[3] Bajas \n");
		printf("[4] Informes \n");
		printf("[5] Salir \n");
		__fpurge(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1: utn_addEmployee(datos,LIMITEARRAY,contadorID);
				contadorID++;
				flag=1;
				break;
		case 2: if(flag==1)
				{
				utn_modifyEmployee(datos,LIMITEARRAY);
				}
				else
				{
					printf("No hay empleados ingresados.\n");
				}
				break;
		case 3: if(flag==1)
				{
				utn_deleteEmployee(datos,LIMITEARRAY);
				}
				else
				{
					printf("No hay empleados ingresados.\n");
				}
				break;
		case 4: if(flag==1)
				{
				utn_reportEmployee(datos,LIMITEARRAY);
				}
				else
				{
				printf("No hay empleados ingresados.\n");
				}
				break;
		default: end=1;
				break;
		}

	}
	return 0;
}
