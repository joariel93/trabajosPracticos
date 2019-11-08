#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Extras.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {

	FILE *pArchivo;
	int retorno = 0;

	if ((pArchivo = fopen(path, "r")) == NULL) {
		printf("El archivo no puede ser abierto");
		retorno = -1;
	} else {

		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
	}
	//UNA VEZ LEIDO LLAMAR A LA FUNCION NEW_EMPLOYEE PARA QUE GUARDE UNA POSICION EN LA STRUCT DE EMPLOYEE

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	FILE *pArchivo;
	int retorno = -1;
	if ((pArchivo = fopen(path, "rb")) == NULL) {
		printf("El archivo no puede ser abierto");
		return retorno;
	}
	parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
	retorno = 0;
	fclose(pArchivo);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	char bufId[10];
	char bufNombre[128];
	char bufHorasTrabajadas[10];
	char bufSueldo[10];
	int option;
	int flag = 0;
	Employee *pAux;

	do {
		utn_buscarUltimoId(pArrayListEmployee, bufId);
		utn_menuEmpleado("Creacion de Empleado, su numero de ID sera:", bufId);
		__fpurge(stdin);
		scanf("%d", &option);
		switch (option) {

		case 1:
			utn_getStringChar(bufNombre, "Ingrese el nombre ",
					"Error debe ingresar caracteres alfabéticos", 128, 128);
			break;
		case 2:
			utn_getInt(bufHorasTrabajadas,
					"Ingrese la cantidad de horas trabajadas ",
					"Error solo debe ingresar números", 0, 744, 10);
			break;
		case 3:
			utn_getInt(bufSueldo, "Ingrese el sueldo ",
					"Error solo debe ingresar números", 0, 1000000, 10);
			break;
		default:
			break;
		}
	} while (!(option > 3 || option < 1));
	pAux = employee_newParametros(bufId, bufNombre, bufHorasTrabajadas,
			bufSueldo);
	if (pAux != NULL) {
		ll_add(pArrayListEmployee, pAux);
	}
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int retorno = -1;
	int i;
	int ID;
	int option;
	int posID = NULL;
	char idChange[10];
	char bufName[128];
	int newHoras, newSueldo;

	controller_ListEmployee(pArrayListEmployee);
	printf("Ingrese el ID del empleado que desea modificar ");
	__fpurge(stdin);
	scanf("%d", &ID);
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		aux = ll_get(pArrayListEmployee, i);
		if (aux->id == ID) {
			posID = i;
			break;
		}

	}
	if (posID == NULL) {
		printf("El ID ingresado no corresponde a un empleado");

	} else {
		do {
			sprintf(idChange, "%d", ID);
			utn_menuEmpleado("Que desea modificar al ID: ", idChange);
			__fpurge(stdin);
			scanf("%d", &option);
			switch (option) {
			case 1:
				utn_getStringChar(bufName, "Ingrese el nuevo nombre ",
						"Error debe ingresar caracteres alfabeticos", 128, 128);
				employee_setNombre(aux, bufName);
				break;
			case 2:
				utn_getInt(bufName, "Ingrese la nueva cantidad de horas ",
						"Error debe ingresar una carga horaria valida", 0, 720,
						5);
				newHoras = atoi(bufName);
				employee_setHorasTrabajadas(aux, newHoras);
				break;
			case 3:
				utn_getInt(bufName, "Ingrese nuevo sueldo ",
						"Error debe ingresar un valor valido", 0, 1000000, 5);
				newSueldo = atoi(bufName);
				employee_setSueldo(aux, newSueldo);
				break;
			default:
				break;
			}

		} while (!(option > 3 || option < 1));
		ll_set(pArrayListEmployee, posID, aux);
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int ID;
	int i;
	int posID = NULL;
	int confirm = NULL;
	char name[128];

	controller_ListEmployee(pArrayListEmployee);
	printf("Ingrese el ID del empleado que desea eliminar ");
	__fpurge(stdin);
	scanf("%d", &ID);
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		aux = ll_get(pArrayListEmployee, i);
		if (aux->id == ID) {
			posID = i;
			break;
		}

	}
	if (posID == NULL) {
		printf("El ID ingresado no corresponde a un empleado\n");
	} else {
		employee_getNombre(aux, name);
		printf("Desea eliminar a %s?\n[1] Si\n[2]No\n", name);
		scanf("%d", &confirm);
		if (confirm == 1) {
			ll_remove(pArrayListEmployee, posID);
		}

	}

	return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int i;
	int id, horas, sueldo;
	char nombre[50];
	printf("Id\tNombre\tHoras Trabajadas\tSueldo\n");
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {

		aux = ll_get(pArrayListEmployee, i);

		utn_usarGets(&id, nombre, &horas, &sueldo, aux);
		printf("%d\t%s\t%d\t%d\n", id, nombre, horas, sueldo);
	}
	return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 0;
	int opcion, opcion2;

	if (pArrayListEmployee == NULL) {
		retorno = -1;
	} else {
		do {
			utn_menuSort();
			__fpurge(stdin);
			scanf("%d", &opcion);
			switch (opcion) {
			case 1:do{
				utn_menuSort2();
				__fpurge(stdin);
				scanf("%d", &opcion2);
				switch (opcion2) {
				case 1:
					ll_sort(pArrayListEmployee, funCritID, 1);
					break;
				case 2:
					ll_sort(pArrayListEmployee, funCritID, 0);
					break;
				default: return 0;
				}}while(opcion2<1||opcion2>2);

				break;
			case 2:do{
				utn_menuSort2();
				__fpurge(stdin);
				scanf("%d", &opcion2);
				switch (opcion2) {
				case 1:
					ll_sort(pArrayListEmployee, funCritName, 1);
					break;
				case 2:
					ll_sort(pArrayListEmployee, funCritName, 0);
					break;
				default: return 0;
				}}while(opcion2<1||opcion2>2);

				break;
			case 3:do{
				utn_menuSort2();
				__fpurge(stdin);
				scanf("%d", &opcion2);
				switch (opcion2) {
				case 1:
					ll_sort(pArrayListEmployee, funCritHoras, 1);
					break;
				case 2:
					ll_sort(pArrayListEmployee, funCritHoras, 0);
					break;
				default: return 0;
				}}while(opcion2<1||opcion2>2);

				break;
			case 4:do{
				utn_menuSort2();
				__fpurge(stdin);
				scanf("%d", &opcion2);
				switch (opcion2) {
				case 1:
					ll_sort(pArrayListEmployee, funCritSueldo, 1);
					break;
				case 2:
					ll_sort(pArrayListEmployee, funCritSueldo, 0);
					break;
				default: return 0;
				}}while(opcion2<1||opcion2>2);

				break;
			default:
				return 0;
			}
		} while (opcion < 1 || opcion > 4);

	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	Employee *aux;
	int id, horas, sueldo;
	char nombre[50];
	int retorno = -1;
	int i;
	pFile = fopen(path, "w");
	fprintf(pFile, "ID,Nombre,horasTrabajadas,Sueldo\n");
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		aux = (Employee*) ll_get(pArrayListEmployee, i);
		utn_usarGets(&id, nombre, &horas, &sueldo, aux);
		fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
		retorno = 0;
	}

	fclose(pFile);

	return retorno;
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	Employee *aux;
	int retorno = -1;
	int i;
	int contador = 0;

	if (path != NULL && pArrayListEmployee != NULL) {
		if ((pFile = fopen(path, "w+b")) == NULL) {
			printf("El archivo no puede ser abierto");
			retorno = -1;
		} else {
			for (i = 0; i < ll_len(pArrayListEmployee); i++) {
				aux = ll_get(pArrayListEmployee, i);
				contador = fwrite(aux, sizeof(Employee), 1, pFile);
			}
			retorno = 0;
			fclose(pFile);

		}
	}

	return 1;
}
