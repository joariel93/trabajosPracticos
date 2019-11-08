#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Employee.h"

Employee* employee_new() {
	Employee *emp = (Employee*) malloc(sizeof(Employee));

	if (emp != NULL) {
		emp->id = 0;
		strcpy(emp->nombre, " ");
		emp->horasTrabajadas = 0;
		emp->sueldo = 0;

	}
	return emp;
}
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldo) {
	int auxId, auxHorasTrabajadas, auxSueldo;
	char auxNombre[30];
	Employee *emp = (Employee*) malloc(sizeof(Employee));

	if (emp != NULL) {
		auxId = atoi(idStr);
		strcpy(auxNombre, nombreStr);
		auxHorasTrabajadas = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldo);
		employee_setId(emp, auxId);
		employee_setNombre(emp, auxNombre);
		employee_setHorasTrabajadas(emp, auxHorasTrabajadas);
		employee_setSueldo(emp, auxSueldo);
	}

	return emp;
}
int employee_setId(Employee *this, int id) {
	int retorno = -1;
	if (this != NULL && id >= 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee *this, int *id) {
	int retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int employee_getNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;

	if (this != NULL && horasTrabajadas >= 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno = -1;
	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;

	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}
int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno = -1;
	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}
int funCritID(void *argumento1, void *argumento2) {
	Employee *arg1 = (Employee*) argumento1;
	Employee *arg2 = (Employee*) argumento2;
	int id1, id2;
	int retorno;

	employee_getId(arg1, &id1);
	employee_getId(arg2, &id2);

	if (id1 < id2) {
		retorno = -1;
	} else if (id1 > id2) {
		retorno = 1;

	} else {
		retorno = 0;
	}
	return retorno;
}
int funCritName(void *argumento1, void *argumento2) {
	Employee *arg1 = (Employee*) argumento1;
	Employee *arg2 = (Employee*) argumento2;
	char name1[128];
	char name2[128];
	int retorno;
	employee_getNombre(arg1, name1);
	employee_getNombre(arg2, name2);

retorno=strcmp(name1, name2);
	return retorno;
}
int funCritHoras(void *argumento1, void *argumento2) {
	Employee *arg1 = (Employee*) argumento1;
	Employee *arg2 = (Employee*) argumento2;
	int horas1, horas2;
	int retorno;

	employee_getHorasTrabajadas(arg1, &horas1);
	employee_getHorasTrabajadas(arg2, &horas2);

	if (horas1 < horas2) {
		retorno = -1;
	} else if (horas1 > horas2) {
		retorno = 1;

	} else {
		retorno = 0;
	}
	return retorno;
}
int funCritSueldo(void *argumento1, void *argumento2) {
	Employee *arg1 = (Employee*) argumento1;
	Employee *arg2 = (Employee*) argumento2;
	int sueldo1, sueldo2;
	int retorno;

	employee_getSueldo(arg1, &sueldo1);
	employee_getSueldo(arg2, &sueldo2);

	if (sueldo1 < sueldo2) {
		retorno = -1;
	} else if (sueldo1 > sueldo2) {
		retorno = 1;

	} else {
		retorno = 0;
	}
	return retorno;
}
