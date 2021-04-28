/*
 ============================================================================
 Name        : PARCIAL2017.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pantallas.h"
#include "contrataciones.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	/*int numero;
	utn_getNumero(&numero, "INGRES ENUMERO: ", "ERROR", 0, 10, 3);
	printf("EL NUMERO ES : %d", numero);

	*/
	sPantalla arrayPantallas[PANTALLAS];
	sContratacion arrayContratacion[CONTRATACIONES];
	initPantallas(arrayPantallas, PANTALLAS);
	initContrataciones(arrayContratacion, CONTRATACIONES);
	//int numero;
	char opcion;
	do
	{
		utn_getChar(&opcion, "a. Alta Pantalla\nb.Baja pantalla\nc.Modificar Pantalla\nd.Ingresar contratacion\ne.Modificar contratacion\nf.Cancelar contratacion\ng.Listar contrataciones\nh.Listar pantallas\ni.Informar\nj.Salir\nIngrese una opcion: ", "OPCION INVALIDA", 'a', 'z', 2);
		switch(opcion)
		{
		case 'a':
			altaPantalla(arrayPantallas, PANTALLAS);
			break;
		case 'b':
			bajaPantalla(arrayPantallas, PANTALLAS);
			break;
		case 'c':
			modificarPantalla(arrayPantallas, PANTALLAS);
			break;
		case 'd':
			altaContratacion(arrayContratacion, CONTRATACIONES, arrayPantallas,PANTALLAS);
			break;
		case 'e':
			modificarContratacion(arrayContratacion, CONTRATACIONES, arrayPantallas, PANTALLAS);
			break;
		case 'f':
			bajaContratacion(arrayContratacion, CONTRATACIONES, arrayPantallas, PANTALLAS);
			break;
		case 'g':
			mostrarContratacion(arrayContratacion, CONTRATACIONES);
			break;
		case 'h':
			mostrarPantallas(arrayPantallas, PANTALLAS);
			break;
		}
	}while(opcion != 'l');
	return EXIT_SUCCESS;
}
