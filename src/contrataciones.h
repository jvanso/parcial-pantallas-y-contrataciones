/*
 * contrataciones.h
 *
 *  Created on: 22 abr. 2021
 *      Author: Sordello
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_
#define CONTRATACIONES 5
#define CONTRATADO 0
#define LIBRE 1
#include <stdio.h>
#include <stdlib.h>
#include "pantallas.h"
typedef struct
{
	int idContratacion;
	int isEmpty;
	int cantDias;
	char nombreArchivo[50];
	int cuitCliente;
	int idPantalla;
}sContratacion;


int buscarContratacionLibre(sContratacion* arrayContrataciones, int limite, int* indice);
int initContrataciones(sContratacion* arrayContrataciones, int limite);
int idContrataciones();
int modificarContratacion(sContratacion* arrayContrataciones, int limite,sPantalla* arrayPantallas, int limitePantallas);
int buscarContratacionPorCuit(sContratacion* arrayContrataciones, int limite, int* indiceCuit);
int bajaContratacion(sContratacion* arrayContrataciones, int limite, sPantalla* arrayPantallas, int limitePantallas);
int buscarPantallaPorIdContratacion(sContratacion* arrayContrataciones, int limiteContrataciones, int* index);
int altaContratacion(sContratacion* arrayContrataciones, int limite,sPantalla* arrayPantallas,int limitePantallas);
int imprimirPantallasContratadasPorCuit(sContratacion* arrayContrataciones, int limite, sPantalla* arrayPantallas, int limitePantallas,int cuitContratacion);
void mostrarContratacion(sContratacion* arrayContrataciones, int limite);


#endif /* CONTRATACIONES_H_ */
