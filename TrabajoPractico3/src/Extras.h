/*
 * Extras.h
 *
 *  Created on: 6 nov. 2019
 *      Author: alumno
 */

#ifndef EXTRAS_H_
#define EXTRAS_H_

void utn_menuPrincipal();
int utn_getInt(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int utn_getStringChar (char *pResultado,char *pMensaje,char *pMensajeError,int maximo,int limite);
int utn_getStringInt (char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int limite);


#endif /* EXTRAS_H_ */
