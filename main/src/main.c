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
#include "controller.h"

#define QTY_CLIENTES 100
#define QTY_PEDIDOS 1000

int main()
{
	int contadorClientes;
	int contadorPedidos;
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
	ePedidos arrayPedidos[QTY_PEDIDOS];
	cliente_Inicializar(arrayClientes,QTY_CLIENTES);
	pedidos_Inicializar(arrayPedidos,QTY_PEDIDOS);


	do
	{
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);

		__fpurge(stdin);

		switch(opcion)
		{
		case 1:
			printf("\n ALTAS\n");
			cliente_alta(arrayClientes,QTY_CLIENTES,&contadorClientes);
			break;
		case 2:
			printf("\nMODIFICAR\n");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			if(clientesExistente(arrayClientes,QTY_CLIENTES)==0)
			{
				cliente_modificar(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un cliente vuelva a la opcion 1 \n");
			}
			break;
		case 3:
			printf("\nBAJAS\n");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			if( clientesExistente(arrayClientes,QTY_CLIENTES)==0)
			{
				cliente_baja(arrayClientes,QTY_CLIENTES);
			}
			else
			{
				printf("Debe dar de alta un Cliente vuelva a la opcion 1 \n");
			}
			break;
		case 4:
			printf("\nCREAR PEDIDO DE RECOLECCION");
			cliente_listar(arrayClientes,QTY_CLIENTES);
			pedidos_alta(arrayPedidos,QTY_PEDIDOS,&contadorPedidos);
			break;
		case 5:
			printf("PROCESAR RESIDUOS");
			pedidos_listar(arrayPedidos,QTY_PEDIDOS);
			pedidos_procesar(arrayPedidos,QTY_PEDIDOS);
			break;
		case 6:
			listarClientesPendiente(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 7:
			listar_pendientes(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 8:
			pedido_ImprimirArrayProcesado(arrayClientes,QTY_CLIENTES,arrayPedidos,QTY_PEDIDOS);
			break;
		case 9:
			break;
		default:
			printf("\nError. Ingresa una opcion de 1 a 9");

		}
	}while(opcion != 9);

	return 0;
}
