#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Extras.h"


#define ARCHIVOTEXTO "data.csv"
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

int main() {
	FILE* pArchivoTxt=ARCHIVOTEXTO;
	FILE* pArchivoBin;
	int option;
	LinkedList *listaEmpleados = ll_newLinkedList();
	//Employee** lista = (Employee**) malloc(sizeof(Employee*));
	//Employee** pAuxEmpleado;
	int cont = 0;
	int flagArchivoBinario;
	char resp = 's';
	char bufId[10];

	do {
		utn_menuPrincipal();
		__fpurge(stdin);
		scanf("%d", &option);
		switch (option) {
		case 1:
			if (controller_loadFromText(ARCHIVOTEXTO, listaEmpleados) == 0) {
				printf("Archivo abierto como texto\n");
			}
			break;
		case 2:
			if (controller_loadFromBinary("data2.bin", listaEmpleados) == 0) {
			}
			break;
		case 3:
			if (listaEmpleados != NULL) {
				controller_addEmployee(listaEmpleados);
				utn_guardarArchivoTXT(ARCHIVOTEXTO,listaEmpleados);

			}
			break;
		case 4:
			if (listaEmpleados != NULL) {
				utn_buscarUltimoId(listaEmpleados,bufId);

			}
			break;
		case 5:
			if (listaEmpleados != NULL) {
				controller_addEmployee(listaEmpleados);

			}
			break;
		case 6:
			if (listaEmpleados != NULL) {
				controller_ListEmployee(listaEmpleados);

			}
			break;
		case 7:
			if (listaEmpleados != NULL) {
				controller_sortEmployee(listaEmpleados);

			}
			break;
		case 8:
			if (listaEmpleados != NULL) {
				controller_addEmployee(listaEmpleados);

			}
			break;
		case 9:
			if (listaEmpleados != NULL) {
				controller_addEmployee(listaEmpleados);

			}
			break;

		default:
			return 0;
		}
	} while (option != 10);
	return 0;
}
