/*
 * pantallas.h
 *
 *  Created on: 22 abr. 2021
 *      Author: Sordello
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_
#define PANTALLAS 5
#define PANTALLAVACIA 1
#define PANTALLAOCUPADA 0
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char direccion[50];
	int idPantalla;
	char tipoPantalla[50];
	char nombre[50];
	float precio;
	int isEmpty;
}sPantalla;

int initPantallas(sPantalla* arrayPantallas, int limite);
int altaPantalla(sPantalla* arrayPantallas, int limite);
int modificarPantalla(sPantalla* arrayPantallas, int limite);
int buscarPantallaPorId(sPantalla* arrayPantallas, int limite, int* index);
int bajaPantalla(sPantalla* arrayPantallas, int limite);
int buscarPantallaLibre(sPantalla* arrayPantallas, int limite, int* indice);
int idPantallas();
void mostrarPantallas(sPantalla* arrayPantalla, int limite);

#endif /* PANTALLAS_H_ */
