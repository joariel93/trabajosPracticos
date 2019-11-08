/*
 * Extras.c
 *
 *  Created on: 6 nov. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

void utn_menuPrincipal() {
	printf("Bienvenido que desea hacer?\n");
	printf(
			"[1] Cargar los datos de los empleados desde el archivo data1.csv (modo texto)\n");
	printf(
			"[2] Cargar los datos de los empleados desde el archivo data2.csv (modo binario)\n");
	printf("[3] Alta de empleado\n");
	printf("[4] Modificar datos de empleado\n");
	printf("[5] Baja de empleado\n");
	printf("[6] Listar empleados\n");
	printf("[7] Ordenar empleados\n");
	printf(
			"[8] Guardar los datos de los empleados en el archivo data1.csv (modo texto)\n");
	printf(
			"[9] Guardar los datos de los empleados en el archivo data2.bin (modo binario)\n");
	printf("[10] Salir\n");

}
int utn_menuEmpleado(char *pMensaje, char *id) {
	printf("%s %s\n", pMensaje, id);
	printf("[1] Nombre\n");
	printf("[2] Horas Trabajadas\n");
	printf("[3] Sueldo\n");
	printf("[4] Salir\n");
	return 0;
}
void utn_menuSort() {
	printf("[1] Ordenar por ID\n");
	printf("[2] Ordenar por Nombre\n");
	printf("[3] Ordenar por horas trabajdas\n");
	printf("[4] Ordenar por sueldo\n");
	printf("[5] Volver\n");

}
void utn_menuSort2() {
	printf("[1] Ascendente\n");
	printf("[2] Descendente\n");
	printf("[3] Volver\n");
}
void utn_buscarUltimoId(LinkedList *pArrayListEmployee, char bufId[]) {
	Employee *aux;
	int i;
	int id;

	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		aux = ll_get(pArrayListEmployee, i);
	}

	id = i + 1;
	sprintf(bufId, "%d", id);
}
int utn_getInt(char *pResultado[], char *pMensaje, char *pMensajeError,
		int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int number;
	do {
		printf("%s", pMensaje);
		__fpurge(stdin);
		if (scanf("%d", &number) == 1 && number >= minimo && number <= maximo) {
			sprintf(pResultado, "%d", number);
			retorno = 0;
			break;
		}
		reintentos--;
		printf("%s, le quedan %d intentos.\n", pMensajeError, reintentos);

	} while (reintentos >= 0);
	return retorno;
}
int utn_getStringChar(char *pResultado, char *pMensaje, char *pMensajeError,
		int maximo, int limite) {
	int flagError = -1;
	int i;
	int retorno = -1;
	char text[limite];
	if (pResultado != NULL && pMensaje != NULL && 0 < maximo) {
		while (flagError == -1) {
			flagError = 0;
			printf("%s", pMensaje);
			__fpurge(stdin);
			fgets(text, sizeof(text), stdin);
			text[strlen(text) - 1] = '\0';
			if (strlen(text) <= maximo) {
				strncpy(pResultado, text, maximo + 1);
				retorno = 0;
			}
			for (i = 0; i < strlen(text) - 1; i++) {
				if (!((text[i] >= 'A' && text[i] <= 'Z')
						|| (text[i] >= 'a' && text[i] <= 'z'))) {
					printf("%s\n", pMensajeError);
					flagError = -1;
					break;
				}
			}
		}

	}
	return retorno;
}
int utn_usarGets(int *id, char nombre[], int *horas, int *sueldo, Employee *aux) {
	int retorno = 0;
	employee_getId(aux, id);
	employee_getNombre(aux, nombre);
	employee_getHorasTrabajadas(aux, horas);
	employee_getSueldo(aux, sueldo);
	return retorno;
}
