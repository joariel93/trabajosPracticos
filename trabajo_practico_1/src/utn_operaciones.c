/*
 * utn.operaciones.c
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>

float utn_pideUnNumero(float *number)
{
	float number1=*number;


	printf("Ingrese un número: \n");
	__fpurge(stdin);
	scanf ("%f",&number1);

	*number=number1;

	return 0;
}
float utn_pideDosNumeros(float *numberOne,float *numberTwo)
{
	float number1=*numberOne;
	float number2=*numberTwo;

	printf("Ingrese un número: \n");
	__fpurge(stdin);
	scanf ("%f",&number1);

	printf("Ingrese otro número: \n");
	__fpurge(stdin);
	scanf ("%f",&number2);

	*numberOne=number1;
	*numberTwo=number2;
	return 0;
}
float utn_sumar(float numberOne,float numberTwo,float* presultSum)
{
	float result=numberOne+numberTwo;
	*presultSum=result;
	return 0;
}
float utn_restar(float numberOne,float numberTwo,float* presultSub)
{
	float result=numberOne-numberTwo;
	*presultSub=result;
	return 0;
}
float utn_multiplicar(float numberOne,float numberTwo,float* presultMult)
{
	float result=numberOne*numberTwo;
	*presultMult=result;
	return 0;
}
float utn_dividir(float numberOne,float numberTwo,float* presultDiv)
{
	float result=numberOne/numberTwo;
	*presultDiv=result;
	return 0;
}

float utn_factorizar2Numeros(float numberOne,float numberTwo,float* presultFactA,float* presultFactB)
{
	float resultA=1;
	float resultB=1;
	int i;
	int j;
	for(i=numberOne;i>=1;i--)
	{
		resultA=resultA*i;
	}
	for(j=numberTwo;j>=1;j--)
	{
		resultB=resultB*j;
	}

	*presultFactA=resultA;
	*presultFactB=resultB;
	return 0;
}

