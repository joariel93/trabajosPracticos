/*
 * utn_inputs.h
 *
 *  Created on: 19 sep. 2019
 *      Author: alumno
 */

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int utn_getFloat(float* pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int utn_getString (char *pResultado,char *pMensaje,int maximo,int limite);


#endif /* UTN_INPUTS_H_ */
