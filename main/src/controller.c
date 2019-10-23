/*
 * controller.c
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"


int listarClientesPendiente(eClientes list[], int len, ePedidos list2[], int len2)
{
	int i;
	int auxPos;
	int contadorPendientes = 0;
	int retorno = -1;

	if(list != NULL && len>0)
	{
		__fpurge(stdin);
		printf("\nID: -- Nombre de la Empresa:  -- cuit:  -- Direccion:	--	Localidad:  -- Pendientes: \n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				for(auxPos=0;auxPos<len2;auxPos++)
				{
					if(list[i].idClientes == list2[auxPos].idClientes
							&& list2[auxPos].isEmpty==0
							&& list2[auxPos].estado==0)
					{
						contadorPendientes++;
					}
				}
				list[i].idClientes = list2[i].idClientes;

				printf("\n\n%4d		%-20s		%-10s		%-10s		%-25s		%4d",list[i].idClientes,
																		list[i].nombreEmpresa,
																		list[i].cuit,
																		list[i].direccion,
																		list[i].localidad,
																		contadorPendientes);
				contadorPendientes=0;

			}
		}
		retorno = 0;
	}
	return retorno;
}

int listar_pendientes(eClientes list[], int size, ePedidos list2[], int size2)
{
    int retorno=-1;
    int posicion,i;

    if(list2!=NULL && size2>0)
    {
    	__fpurge(stdin);
    	for(i=0;i<size2;i++)
    	    {
    			if(list2[i].isEmpty==0 && list2[i].estado == 0)
    	          {
    				for(posicion=0;posicion<size;posicion++)
    				{
    					if(list2[i].idClientes == list[posicion].idClientes
    							&& list[posicion].isEmpty == 0)
    					{
    						printf( "\n ID: %d\t Cuit: %s\tDireccion: %s\t Kilos: %.2f\t Estado: Pendiente",
									list2[i].idPedidos,
    								list[posicion].cuit,
 									list[posicion].direccion,
									list2[i].kilos);
    					}
    				}
    	          }
    	    }
    	retorno=0;
    }
    return retorno;
}

int pedido_ImprimirArrayProcesado(eClientes list[], int len, ePedidos list2[], int len2)
{
	int retorno=-1;
	int posicion;
	int i;

	    if(list2!=NULL && len2>0)
	    {
	    	__fpurge(stdin);
	    	for(i=0;i<len2;i++)
	    	    {
	    			if(list2[i].isEmpty==0 && list2[i].estado == 1)
	    	          {
	    				for(posicion=0;posicion<len;posicion++)
	    				{
	    					if(list[i].idClientes == list[posicion].idClientes
	    							&& list[posicion].isEmpty == 0)
	    					{
	    						printf( "\n ID: %d \n Cuit: %s\t Direccion: %s\t Kilos de HDPE: %.2f\t Kilos de LDPE: %.2f\tKilos de PP: %.2f"
										"\tKilos de residuos desechables: %.2f\tEstado: Completado",
										list2[i].idPedidos,
	    								list[posicion].cuit,
	 									list[posicion].direccion,
										list2[i].HDPE,
										list2[i].LPDE,
										list2[i].PP,
										list2[i].desechables);

	    					}
	    				}
	    	          }
	    	    }
	    	retorno=0;
	    }
	    return retorno;
}

void mock_controller()
{

}
