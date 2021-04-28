/*
 * contrataciones.c
 *
 *  Created on: 22 abr. 2021
 *      Author: Sordello
 */
#include "contrataciones.h"
#include "pantallas.h"
#include "utn.h"
int idContrataciones()
{
    static int id = 100;
    id++;
    return id;
}
int initContrataciones(sContratacion* arrayContrataciones, int limite)
{
	int retorno=-1;
	int i;
	if(arrayContrataciones != NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			arrayContrataciones[i].isEmpty = LIBRE;
		}
	}
	return retorno;
}
int buscarContratacionLibre(sContratacion* arrayContrataciones, int limite, int* indice)
{
		int retorno=-1;
		int i;
		int index;
		if(arrayContrataciones != NULL && limite>0 && indice != NULL)
		{
			retorno=0;
			for(i=0;i<limite;i++)
			{
				if(arrayContrataciones[i].isEmpty == LIBRE)
				{
					index = i;
					break;
				}
			}
			*indice = index;
		}
		return retorno;
}
int altaContratacion(sContratacion* arrayContrataciones, int limite,sPantalla* arrayPantallas,int limitePantallas)
{
	int retorno=-1;
	int lugarLibre;
	int index;
	char nombreArchivo[50];
	if(arrayContrataciones != NULL && limite>0)
	{
		retorno=0;
		buscarContratacionLibre(arrayContrataciones, limite, &lugarLibre);
		if(lugarLibre>=0)
		{
			mostrarPantallas(arrayPantallas, limitePantallas);
			if(buscarPantallaPorId(arrayPantallas, limite, &index)==0)
			{
			getSString(nombreArchivo, 50, "Ingrese nombre del archivo: ");
			strcpy(arrayContrataciones[lugarLibre].nombreArchivo, nombreArchivo);
			arrayContrataciones[lugarLibre].nombreArchivo[strlen(arrayContrataciones[lugarLibre].nombreArchivo)-1]='\0';

			utn_getNumero(&arrayContrataciones[lugarLibre].cantDias, "Ingrese cantidad de dias: ", "Error en la cantidad de dias", 0, 15, 2);
			utn_getNumero(&arrayContrataciones[lugarLibre].cuitCliente, "Ingrese cuit de cliente: ", "Error en el cuit", 0, 200000000, 2);


			arrayContrataciones[lugarLibre].idContratacion = idContrataciones();
			arrayContrataciones[lugarLibre].idPantalla = index;

			arrayContrataciones[lugarLibre].isEmpty=CONTRATADO;
			}
		}
		/*mostrarPantallas(arrayPantallas, limitePantallas);
		buscarPantallaPorIdContratacion(arrayPantallas, limitePantallas, &index,arrayContrataciones,limite);
		if(buscarContratacionLibre(arrayContrataciones,limite,&lugarLibre)==0)
		{

		}
	}
	*/
	}
	return retorno;
}
void mostrarContratacion(sContratacion* arrayContrataciones, int limite)
{
	if(arrayContrataciones != NULL && limite>0)
	{
		printf("NOMBRE DEL ARCHIVO     IDCONTRATACION      CANTIDAD DE DIAS   CUIT DEL CLIENTE           ID DE LA PANTALLA\n");
		for(int i=0;i<limite;i++)
		{
			if(arrayContrataciones[i].isEmpty == CONTRATADO)
			{
				printf("%s %22d %23d %24d %24d\n",arrayContrataciones[i].nombreArchivo,arrayContrataciones[i].idContratacion,arrayContrataciones[i].cantDias,arrayContrataciones[i].cuitCliente, arrayContrataciones[i].idPantalla);
			}
		}
	}
}
int buscarPantallaPorIdContratacion(sContratacion* arrayContrataciones, int limiteContrataciones, int* index)
{
	int retorno=-1;
	int indice;
	int id;
	if(arrayContrataciones != NULL && limiteContrataciones >0)
	{
		retorno=0;
		utn_getNumero(&id, "Ingrese id de la contratacion: ", "ID invalido", 0, 5, 2);
		for(int i=0;i<limiteContrataciones;i++)
			{
			if(arrayContrataciones[i].idContratacion == id)
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
int buscarContratacionPorCuit(sContratacion* arrayContrataciones, int limite, int* indiceCuit)
{
	int retorno=-1;
	int indice;
	int cuitt;
	if(arrayContrataciones != NULL && limite>0 && indiceCuit != NULL)
	{
		utn_getNumero(&cuitt, "Ingrese cuit del cliente: ", "Cuit invalido", 0, 2000000000, 2);
				for(int i=0;i<limite;i++)
				{
					if(arrayContrataciones[i].cuitCliente==cuitt)
					{
						indice = i;
						//printf("\nINDICEEEE %d\n", indice);
						break;
					}
				}
		*indiceCuit = indice;
		retorno=0;
	}

	return retorno;
}
int modificarContratacion(sContratacion* arrayContrataciones, int limite,sPantalla* arrayPantallas, int limitePantallas)
{
	int retorno=-1;
	int indiceModificar;
	int auxCuit;
	//int indicePantalla;
			if(arrayPantallas != NULL && limite>0 && arrayContrataciones != NULL && limitePantallas>0)
			{
				if(utn_getNumero(&auxCuit, "Ingrese cuit del cliente: ", "CUIT invalido", 0, 20000, 2)==0)
				{
					if(imprimirPantallasContratadasPorCuit(arrayContrataciones, limite, arrayPantallas, limitePantallas, auxCuit)==0)
					{
						if(buscarPantallaPorIdContratacion(arrayContrataciones, limite, &indiceModificar)==0)
							{
									utn_getNumero(&arrayContrataciones[indiceModificar].cantDias, "Ingrese nueva cantidad de dias: ", "Error nueva cantidad de dias", 0, 20, 2);
							}
					}
				}
				retorno=0;
			}
		return retorno;
}
int bajaContratacion(sContratacion* arrayContrataciones, int limite, sPantalla* arrayPantallas, int limitePantallas)
{
	int retorno=-1;
	int indiceBaja;
	if(arrayPantallas != NULL && limite>0 && arrayContrataciones != NULL && limitePantallas>0)
	{
		if(buscarContratacionPorCuit(arrayContrataciones,limite,&indiceBaja)==0)
		{
			mostrarPantallas(arrayPantallas,limitePantallas);
			if(buscarPantallaPorId(arrayPantallas,limitePantallas,&indiceBaja)==0)
			{
				arrayContrataciones[indiceBaja].isEmpty=LIBRE;
			}
		}
	}
	return retorno;
}
int imprimirPantallasContratadasPorCuit(sContratacion* arrayContrataciones, int limite, sPantalla* arrayPantallas, int limitePantallas,int cuitContratacion)
{
	int retorno=-1;
	int indiceArrayPantalla;
	int auxIdPantallas;
	if(arrayContrataciones != NULL && limite>0 && arrayPantallas != NULL && limitePantallas>0 && cuitContratacion>0)
	{
		printf("ID        NOMBRE DEL ARCHIVO             CUIT              DIAS                 ID PANTALLA");
		for(int i=0;i<limite;i++)
		{
			if(arrayContrataciones[i].isEmpty==CONTRATADO && arrayContrataciones[i].cuitCliente == cuitContratacion)
			{
				auxIdPantallas = arrayContrataciones[i].idPantalla;
				buscarPantallaPorId(arrayPantallas, limitePantallas, &indiceArrayPantalla);
				printf("%d %15s %24d %18d %18d\n",arrayContrataciones[i].idContratacion,arrayContrataciones[i].nombreArchivo,arrayContrataciones[i].cuitCliente,arrayContrataciones[i].cantDias,arrayContrataciones[i].idPantalla);
				printf("%s %15s %8s %15.2f",arrayPantallas[indiceArrayPantalla].direccion,arrayPantallas[indiceArrayPantalla].nombre,arrayPantallas[indiceArrayPantalla].tipoPantalla,arrayPantallas[indiceArrayPantalla].precio);

			}
		}
	}

	return retorno;
}
