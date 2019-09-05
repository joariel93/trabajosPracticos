#include <stdio.h>
#include <stdlib.h>
#include "utn_operaciones.h"

#define NUMBERS 2
#define RESULT 6
int main (void){
float number[NUMBERS];
float result[RESULT];
int choice;
char seguir1;
char seguir2;

do
{
utn_pideDosNumeros(&number[0],&number[1]);
utn_sumar(number[0],number[1],&result[0]);
utn_restar(number[0],number[1],&result[1]);
utn_multiplicar(number[0],number[1],&result[2]);
if(number[1]!=0)
{
	utn_dividir(number[0],number[1],&result[3]);
}
utn_factorizar2Numeros(number[0],number[1],&result[4],&result[5]);

	do
	{
		printf("Los números ingresados han sido: %.2f y %.2f\n",number[0],number[1]);
		printf("Que operación desea realizar?\n[1]Sumar\n[2]Restar\n[3]Multiplicar\n[4]Dividir\n[5]Factorizar\n");
		__fpurge(stdin);
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	printf("La suma de los números es: %.2f\n",result[0]);
					break;
			case 2:	printf("La resta del primero con el segundo es: %.2f\n",result[1]);
					break;
			case 3:	printf("La mulitplicacion de ambos números es: %.2f\n",result[2]);
					break;
			case 4:	if(number[1]==0)
					{
					printf("No es posible dividir por cero.\n");
					break;
					}
					else
					{
					printf("La división del primer numero por el segundo es: %.2f\n",result[3]);
					break;
					}
			case 5:	printf("El factorial del primer número es: %.2f y del segundo es: %.2f\n",result[4],result[5]);
					break;
			default:printf("Opción invalida.");
					break;
		}
		printf("Desea realizar otra operacion con los mismos numeros? s/n");
		__fpurge(stdin);
		scanf("%c",&seguir1);
	}while(seguir1!='n');
	printf("Desea realizar otra operacion con otros numeros? s/n");
	__fpurge(stdin);
	scanf("%c",&seguir2);
}while(seguir2!='n');
return 0;
}
