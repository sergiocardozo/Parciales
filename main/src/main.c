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

#define QTY_CLIENTES 10
#define QTY_PEDIDOS 15

int main()
{
	int contadorClientes=0;
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

	eClientes arrayClientes[QTY_CLIENTES];/* = {
			{0,"Fadeca","20358043047","buenos aires 439","Burzaco",0},
			{1,"La Zorra","20255043547","Somellera 489","Adrogue",0},
			{2,"El Rincon","20607543840","Mitre 500","Adrogue",0},
			{3,"Von Bier","30256043542","Pasco 600","Temperley",0},
			{4,"Planeta tacos","20666043547","Acasuso 764","Banfield",0},
			{5,"The Mitre","20255043547","Mitre 1236","Adrogue",0}

	};*/
	ePedidos arrayPedidos[QTY_PEDIDOS];/*={
			{0,0,500,0,0,0,0,0,0},
			{1,0,700,1,300,200,200,0,0},
			{2,0,300,0,0,0,0,0,0},
			{3,1,800,1,100,200,200,300,0},
			{4,2,200,1,100,100,0,0,0},
			{5,2,500,0,0,0,0,0,0},
			{6,2,400,0,0,0,0,0,0},
			{7,2,100,0,0,0,0,0,0},
			{8,3,500,1,100,200,200,0,0},
			{9,4,700,1,100,200,200,200,0},
			{10,5,500,0,0,0,0,0,0},
			{11,5,600,1,100,200,300,0,0}
	};*/

	cliente_Inicializar(arrayClientes,QTY_CLIENTES);
	pedidos_Inicializar(arrayPedidos,QTY_PEDIDOS);


	do
	{
		__fpurge(stdin);
		utn_getUnsignedInt(menuPrincipalMensaje,"\nError",1,sizeof(int),1,8,1,&opcion);



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
