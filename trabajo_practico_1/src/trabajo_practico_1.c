#include <stdio.h>
#include <stdlib.h>
#include "utn_operaciones.h"

#define NUMBERS 2
#define RESULT 6
int main (void){
float number[NUMBERS];
float result[RESULT];
int choice;
int seguir1=0;
int seguir2=0;
int end=0;

printf("Calculadora:\n");
printf("[1] Ingresar primer operando. \n");
printf("[2] Ingresar segundo operando. \n");
printf("[3] Calcular operaciones. \n");
printf("[4] Mostrar resultados. \n");
printf("[5] Salir. \n");
while(end==0)
{
	printf("Que desea hacer? \n");
	__fpurge(stdin);
	scanf ("%d",&choice);
	switch (choice)
	{
		case 1:	utn_pideUnNumero(&number[0]);
				seguir1=1;
				break;
		case 2:	utn_pideUnNumero(&number[1]);
				seguir2=1;
				break;
		case 3:	if(seguir1==0||seguir2==0)
				{
					printf("Debe ingresar 2 operandos\n");
				}
				else
				{	utn_sumar(number[0],number[1],&result[0]);
					utn_restar(number[0],number[1],&result[1]);
					utn_multiplicar(number[0],number[1],&result[2]);
					if(number[1]!=0)
					{
						utn_dividir(number[0],number[1],&result[3]);
					}
					utn_factorizar2Numeros(number[0],number[1],&result[4],&result[5]);
					}
				break;
		case 4: if(seguir1==0||seguir2==0)
				{
					printf("Debe ingresar 2 operandos\n");
				}
				else
				{
					printf("La suma de los números es: %.2f\n",result[0]);
					printf("La resta del primero con el segundo es: %.2f\n",result[1]);
					printf("La mulitplicacion de ambos números es: %.2f\n",result[2]);
					if(number[1]==0)
					{
						printf("No es posible dividir por cero.\n");
					}
					else
					{
						printf("La división del primer numero por el segundo es: %.2f\n",result[3]);

					}
					printf("El factorial del primer número es: %.2f y del segundo es: %.2f\n",result[4],result[5]);
				break;
		default:end=1;
				break;
	}


}
}
	return 0;
}



