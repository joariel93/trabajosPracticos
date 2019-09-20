/*
 * utn_inputs.c
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_incomeStruct.h"

int utn_getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int number;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%d",&number)==1 && number >= minimo && number <= maximo)
		{
			*pResultado = number;
			retorno = 0;
			break;
		}
		reintentos--;
		printf("%s, le quedan %d intentos.",pMensajeError,reintentos);

	}while(reintentos >= 0);
	return retorno;
}
int utn_getFloat(float* pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int number;
	do
	{
		printf("%s",pMensaje);
		fflush(stdin);
		if(scanf("%f",&number)==1 && number >= minimo && number <= maximo)
		{
			*pResultado = number;
			retorno = 0;
			break;
		}
		reintentos--;
		printf("%s, le quedan %d intentos.",pMensajeError,reintentos);

	}while(reintentos >= 0);
	return retorno;
}
int utn_getString (char *pResultado,char *pMensaje,int maximo,int limite)
{
	int retorno = -1;
	char text[limite];
	if(	pResultado != NULL && pMensaje	!= NULL &&	0< maximo)
	{
			printf("%s",pMensaje);
			__fpurge(stdin);
			fgets(text,sizeof(text),stdin);
			text[strlen(text)-1] = '\0';
			if(strlen(text) <= maximo)
			{
				strncpy(pResultado,text,maximo+1);
				retorno = 0;
			}


	}
	return retorno;
}


