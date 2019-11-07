#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Extras.h"

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
	int retorno = 0;
	int cantidadLeida, longitudTexto;
	char texto[50];

	if ((pArchivo = fopen(path, "r+b")) == NULL) {
		printf("El archivo no puede ser abierto");
		retorno = -1;
	}
	while (!feof(pArchivo)) {
		cantidadLeida = fread(texto, sizeof(char), longitudTexto, pArchivo);
		printf("El texto leido es: %s", texto);
	}

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
	Employee *pAux;

	utn_buscarUltimoId(pArrayListEmployee, bufId);
	utn_getStringChar(bufNombre, "Ingrese el nombre",
			"Error debe ingresar caracteres alfabéticos", 128, 128);
	utn_getInt(bufHorasTrabajadas, "Ingrese la cantidad de horas trabajadas",
			"Error solo debe ingresar números", 0, 744, 10);
	utn_getInt(bufSueldo, "Ingrese el sueldo",
			"Error solo debe ingresar números", 0, 1000000, 10);

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
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
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

			if (employee_getId(aux, &id) == 0) {
				printf("%d\t", id);
			} else {
				printf("error\n");
			}
			if (employee_getNombre(aux, nombre) == 0) {
				printf("%s\t", nombre);
			} else {
				printf("error\n");
			}
			if (employee_getHorasTrabajadas(aux, &horas) == 0) {
				printf("%d\t", horas);
			} else {
				printf("error\n");
			}
			if (employee_getSueldo(aux, &sueldo) == 0) {
				printf("%d\n", sueldo);
			} else {
				printf("error\n");
			}
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

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
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
	return 1;
}
