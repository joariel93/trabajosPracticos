/*
 * utn.operaciones.h
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */

#ifndef UTN_OPERACIONES_
#define UTN_OPERACIONES_
float utn_pideUnNumero(float *number);
float utn_pideDosNumeros(float *numberOne,float *numberTwo);//Recibo el puntero de dos variables donde escribiré su valor
float utn_sumar(float numberOne,float numberTwo,float *resultSum);//Recibo 2 valores de variables y el puntero del resultado de la suma
float utn_restar(float numberOne,float numberTwo,float *resultSub);//Recibo 2 valores de variables y el puntero del resultado de la resta
float utn_multiplicar(float numberOne,float numberTwo,float *resultMult);//Recibo 2 valores de variables y el puntero del resultado de la multiplicacion
float utn_dividir(float numberOne,float numberTwo,float *resultDiv);//Recibo 2 valores de variables y el puntero del resultado de la división
float utn_factorizar2Numeros(float numberOne,float numberTwo,float *resultFactA,float *resultFactB);//Recibo 2 valores de variables y 2 punteros de los resultados de las factorizaciones

#endif /* UTN_H_ */

