/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000

int main()
{
	int opcion;
	char menuPrincipalMensaje[] ="\n1-MENU DE OPCIONES\
            \n\n1-ALTAS CLIENTES\
            \n2-MODIFICAR DATOS DE CLIENTE\
            \n3-BAJA DE CLIENTE\
            \n4-CREAR PEDIDO DE RECOLECCION\
	 	 	\n5 PROCESAR RESIDUOS \
			\n6 IMPRIMIR CLIENTES\
			\n7 IMPRIMIR PEDIDOS CLIENTES\
			\n8 IMPRIMIR PEDIDOS PROCESADOS\
		    \n9-SALIR\n\n\
			\nIngrese opcion:";
	eClientes arrayClientes[QTY_CLIENTES];
	initClientes(arrayClientes,QTY_CLIENTES);


	do
	{
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);

		__fpurge(stdin);

		switch(opcion)
		{
		case 1:
			printf("\n ALTAS\n");
			controllerGetClientes(arrayClientes,QTY_CLIENTES);
			break;
		case 2:
			printf("\nMODIFICAR\n");
			printClientes(arrayClientes,QTY_CLIENTES);
			if(existClientes(arrayClientes,QTY_CLIENTES)==0)
			{
				modificarClientes(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un cliente vuelva a la opcion 1 \n");
			}
			break;
		case 3:
			printf("\nBAJAS\n");
			printClientes(arrayClientes,QTY_CLIENTES);
			if(existClientes(arrayClientes,QTY_CLIENTES)==0)
			{
				getDeleteClientes(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un Cliente vuelva a la opcion 1 \n");
			}
			break;
		case 4:
				printClientes(arrayClientes,QTY_CLIENTES);

			break;
		case 9:
			break;
		default:
			printf("\nError. Ingresa una opcion de 1 a 9");

		}
	}while(opcion != 9);

	return 0;
}
