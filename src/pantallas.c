/*
 * pantallas.c
 *
 *  Created on: 22 abr. 2021
 *      Author: Sordello
 */
#include "pantallas.h"
#include "utn.h"

int initPantallas(sPantalla* arrayPantallas, int limite)
{
	int retorno=-1;
	int i;
	if(arrayPantallas != NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			arrayPantallas[i].isEmpty = PANTALLAVACIA;
		}
	}
	return retorno;
}
int buscarPantallaLibre(sPantalla* arrayPantallas, int limite, int* indice)
{
		int retorno=-1;
		int i;
		int index;
		if(arrayPantallas != NULL && limite>0 && indice != NULL)
		{
			retorno=0;
			for(i=0;i<limite;i++)
			{
				if(arrayPantallas[i].isEmpty == PANTALLAVACIA)
				{
					index = i;
					break;
				}
			}
			*indice = index;
		}
		return retorno;
}
int altaPantalla(sPantalla* arrayPantallas, int limite)
{
	int retorno=-1;
	int lugarLibre;
	char direccion[50];
	char nombre[50];
	char tipoPantalla[50];
	if(arrayPantallas != NULL && limite>0)
	{
		retorno=0;
		if(buscarPantallaLibre(arrayPantallas,limite,&lugarLibre)==0)
		{
			getSString(direccion, 50, "Ingrese direccion: ");
			getSString(nombre, 50, "Ingrese nombre: ");
			getSString(tipoPantalla, 50, "Ingrese tipo de pantalla(LCD o LED): ");
			utn_getNumeroFlotante(&arrayPantallas[lugarLibre].precio, "Ingrese precio: ", "Error precio", 0, 200, 2);
			strcpy(arrayPantallas[lugarLibre].direccion, direccion);
			arrayPantallas[lugarLibre].direccion[strlen(arrayPantallas[lugarLibre].direccion)-1]='\0';

			strcpy(arrayPantallas[lugarLibre].nombre, nombre);
			arrayPantallas[lugarLibre].nombre[strlen(arrayPantallas[lugarLibre].nombre)-1]='\0';

			strcpy(arrayPantallas[lugarLibre].tipoPantalla,tipoPantalla);
			arrayPantallas[lugarLibre].tipoPantalla[strlen(arrayPantallas[lugarLibre].tipoPantalla)-1]='\0';

			arrayPantallas[lugarLibre].isEmpty = PANTALLAOCUPADA;
			arrayPantallas[lugarLibre].idPantalla = idPantallas();

		}
	}
	return retorno;
}

/*
int modificarPantalla(sPantalla* arrayPantallas, int limite)
{
	int retorno=-1;
	int indiceModificar;
	if(arrayPantallas != NULL && limite>0)
	{

	}
}
*/
int bajaPantalla(sPantalla* arrayPantallas, int limite)
{
	int retorno=-1;
	int indiceBaja;
	if(arrayPantallas != NULL && limite>0)
	{
		retorno=0;
		buscarPantallaPorId(arrayPantallas, limite, &indiceBaja);
		arrayPantallas[indiceBaja].isEmpty=PANTALLAVACIA;
	}
	return retorno;
}
void mostrarPantallas(sPantalla* arrayPantalla, int limite)
{
	if(arrayPantalla != NULL && limite>0)
	{
		printf("DIRECCION     ID      TIPO DE PANTALLA    NOMBRE     PRECIO\n");
		for(int i=0;i<limite;i++)
		{
			if(arrayPantalla[i].isEmpty == PANTALLAOCUPADA)
			{
				printf("%s %12d %13s %15s %13.2f\n",arrayPantalla[i].direccion,arrayPantalla[i].idPantalla,arrayPantalla[i].tipoPantalla,arrayPantalla[i].nombre,arrayPantalla[i].precio);
				//printf("%s     %d      %s    %s     %.2f",arrayPantalla[i].direccion,arrayPantalla[i].idPantalla,arrayPantalla[i].tipoPantalla,arrayPantalla[i].nombre,arrayPantalla[i].precio);
			}
		}
	}
}
int buscarPantallaPorId(sPantalla* arrayPantallas, int limite, int* index)
{
	int retorno=-1;
	int indice;
	int id;
	if(arrayPantallas != NULL && limite >0)
	{
		retorno=0;
		utn_getInt(&id, "Ingrese id: ", "ID invalido", 0, 5, 2);
		for(int i=0;i<limite;i++)
		{
			if(arrayPantallas[i].idPantalla==id)
			{
				indice = i;
				//printf("\nINDICEEEE %d\n", indice);
				break;
			}
		}
		*index = indice;
	}
	return retorno;
}
int idPantallas()
{
    static int id = 0;
    id++;
    return id;
}
int modificarPantalla(sPantalla* arrayPantallas, int limite)
{
	int retorno=-1;
	int indiceModificar;
	char nombre[50];
	char direccion[50];
	char tipoPantalla[50];
	char opcion;
		if(arrayPantallas != NULL && limite>0)
		{
			retorno=0;
			buscarPantallaPorId(arrayPantallas, limite, &indiceModificar);
		do
		{
			utn_getChar(&opcion, "a. Direccion\nb. Tipo de pantalla\nc.Nombre\nd.Precio\ne.Salir\nQue desea modificar?", "Opcion invalida", 'a', 'f', 2);
			switch(opcion)
			{
			case 'a':
				getSString(direccion, 50, "Ingrese nueva direccion: ");
				strcpy(arrayPantallas[indiceModificar].direccion, direccion);
				break;
			case 'b':
				getSString(tipoPantalla, 50, "Ingrese nuevo tipo de pantalla: ");
				strcpy(arrayPantallas[indiceModificar].tipoPantalla, tipoPantalla);
				break;
			case 'c':
				getSString(nombre, 50, "Ingrese nuevo nombre de pantalla: ");
				strcpy(arrayPantallas[indiceModificar].nombre, nombre);
				break;
			case 'd':
				utn_getFloat(&arrayPantallas[indiceModificar].precio, "Ingrese nuevo precio: ", "Error nuevo precio", 0, 150.00, 2);
				break;
			}
		}while(opcion != 'e');
		}
	return retorno;
}
