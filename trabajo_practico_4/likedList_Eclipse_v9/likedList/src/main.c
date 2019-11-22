/*
 utest example : Unit test examples.
 Copyright (C) <2018>  <Mauricio Davila>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Extras.h"

#define ARCHIVOTEXTO "data.csv"
#define ARCHIVOBINARIO "dataBin.dat"

int main(void) {
	/*startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort*/
	FILE *pArchivoTxt = ARCHIVOTEXTO;
		FILE *pArchivoBin;
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
				if (controller_loadFromBinary(ARCHIVOBINARIO, listaEmpleados)
						== 0) {
				}
				break;
			case 3:
				if (listaEmpleados != NULL) {
					controller_addEmployee(listaEmpleados);
					controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
					controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);

				}
				break;
			case 4:
				if (listaEmpleados != NULL) {
					controller_editEmployee(listaEmpleados);
					controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
					controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
				}
				break;
			case 5:
				if (listaEmpleados != NULL) {
					controller_removeEmployee(listaEmpleados);
					controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
					controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
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
					controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
					printf("\nSe guardo el Archivo en modo texto correctamente\n");

				}
				break;
			case 9:
				if (listaEmpleados != NULL) {
					controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
					printf(
							"\nSe guardo el Archivo en modo binario correctamente\n");

				}
				break;

			default:
				return 0;
			}
		} while (option != 10);
		return 0;
}

