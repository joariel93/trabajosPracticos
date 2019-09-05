#include <stdio.h>
#include <stdlib.h>
#include "utn_operaciones.h"

int main (void){
float firstNumber;
float secondNumber;
float sumResult;
float subtractionResult;
float multiplicationResult;
float divisionResult;
float factorialResultA;
float factorialResultB;
int choice;

utn_pideDosNumeros(&firstNumber,&secondNumber);
utn_sumar(firstNumber,secondNumber,&sumResult);
utn_restar(firstNumber,secondNumber,&subtractionResult);
utn_multiplicar(firstNumber,secondNumber,&multiplicationResult);
if(secondNumber!=0)
{
	utn_dividir(firstNumber,secondNumber,&divisionResult);
}
utn_factorizar2Numeros(firstNumber,secondNumber,&factorialResultA,&factorialResultB);

printf("Los números ingresados han sido: %.2f y %.2f\n",firstNumber,secondNumber);
printf("Que operación desea realizar?\n[1]Sumar\n[2]Restar\n[3]Multiplicar\n[4]Dividir\n[5]Factorizar");
__fpurge(stdin);
scanf("%d",&choice);	
switch
{
	case 1:	printf("La suma de los números es: %.2f\n",sumResult);
		break;
	case 2:	printf("La resta del primero con el segundo es: %.2f\n",subtractionResult);
		break;
	case 3:	printf("La mulitplicacion de ambos números es: %.2f\n",multiplicationResult);
		break;
	case 4:	if(secondNumber==0)
		{
			printf("No es posible dividir por cero.\n");
			break;
		}
		else
		{
			printf("La división del primer numero por el segundo es: %.2f\n",divisionResult);
			break;
		}
	case 5:	printf("El factorial del primer número es: %.2f y del segundo es: %.2f\n",factorialResultA,factorialResultB);
		break;
	default: break;	
}
return 0;
}
