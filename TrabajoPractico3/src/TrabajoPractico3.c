#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}
*/


int main()
{
int option = 0;
LinkedList* listaEmpleados = ll_newLinkedList();
    //Employee** lista = (Employee**) malloc(sizeof(Employee*));
    //Employee** pAuxEmpleado;
int cont = 0;
char resp='s';
char bufId;
char bufNombre[128];
char bufHorasTrabajadas;
char bufSueldo;

controller_loadFromText("data.csv",listaEmpleados);


do{
	utn_menu();
	__fpurge(stdin);
	scanf("%d",option);
	switch(option)
    {
    	case 1:	if(controller_loadFromText("data.csv",listaEmpleados)==0)
        		{

           		}
           		break;
    	case 2:	if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
    	        {
    	        }
    	        break;
    	case 3:	if(listaEmpleados!=NULL)
    	        {
    				controller_addEmployee(listaEmpleados);
    				cont++;
    	        }
    	        break;
    }
}while(option != 10);
return 0;
}
