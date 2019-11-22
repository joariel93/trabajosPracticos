#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/LinkedList.h"
#include "../../src/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->sueldo > ((Employee*)pEmployeeB)->sueldo)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->sueldo < ((Employee*)pEmployeeB)->sueldo)
    {
        return -1;
    }
    return 0;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->nombre,p->sueldo);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->nombre,name);
        pEmployee->sueldo = salary;
        returnAux = pEmployee;
    }

    return returnAux;

}

