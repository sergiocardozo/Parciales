/*
 * pedidos.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "pedidos.h"
#include "utn.h"

static int generarIdPedidos()
{
	static int idMax=0;
	return idMax++;
}


int pedidos_Inicializar(ePedidos array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int pedidos_buscarEmpty(ePedidos array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int pedidos_buscarID(ePedidos array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idPedidos==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int pedidos_alta(ePedidos array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID>0)
    {
        if(pedidos_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	if(utn_getUnsignedInt("\n:Ingrese ID de cliente: ","\nError",1,sizeof(int),1,size,2,&array[posicion].idClientes)==0)
        	{
        		(*contadorID)++;
        		array[posicion].idPedidos = generarIdPedidos();
        		array[posicion].isEmpty=0;
        		array[posicion].estado=PENDIENTE;
        		utn_getFloat("\n:Ingrese cantidad de kilos: ","\nError",1,sizeof(float),1,10000,2,&array[posicion].kilos);

        		printf("\n_ID: %d _Cantidad de kilos: %f _Estado: Pendiente",array[posicion].idPedidos,array[posicion].kilos);
        		retorno=0;
        	}
        	else
        	{
        		printf("Numero de ID incorrecto");
        	}
        }
    }
    return retorno;
}


int pedidos_procesar(ePedidos array[], int size)
{
    int retorno=-1;
    int posicion;
    int id;

    if(array!=NULL && size>0)
    {
    	utn_getUnsignedInt("\nID de pedido: ","\nError",1,sizeof(int),1,size,3,&id);
    	if(pedidos_buscarID(array,size,id,&posicion)==-1)
    	{
    		printf("No existe el ID del pedido");
    	}
    	else
    	{
    		if(array[posicion].estado==0)
    		 {
    			utn_getFloat("\nCantidad de kilos de HDPE ","\nError",1,sizeof(float),1,3000,1,&array[posicion].HDPE);
    			utn_getFloat("\nCantidad de kilos de LPDE ","\nError",1,sizeof(float),1,3000,1,&array[posicion].LPDE);
    			utn_getFloat("\nCantidad de kilos de PP ","\nError",1,sizeof(float),1,3000,1,&array[posicion].PP);
    			utn_getFloat("\nCantidad de kilos de residuos Desechables ","\nError",1,sizeof(float),1,3000,1,&array[posicion].desechables);

    			array[posicion].estado=COMPLETADOS;
    		    printf("\n ID: %d"
    		    		"\tCantidad de kilos: %.2f"
    		    		"\tCantidad de kilosHDPE: %.2f"
    		    		"\tCantidad de kilosLDPE: %.2f"
    		    		"\tCantidad de kilosPP: %.2f"
    		    		"\tCantidad de kilos de residuos desechables: %.2f"
    		    		"\tEstado: Completado",
						array[posicion].idPedidos,
						array[posicion].kilos,
						array[posicion].HDPE,
						array[posicion].LPDE,
						array[posicion].PP,
						array[posicion].desechables);

    		 }

    		else
    		{
    			printf("El pedido ya fue procesado");
    		}
    	}

    }


    return retorno;
}



int pedidos_listar(ePedidos array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
            	printf("\n ID: %d"
            	       "\n Cantidad de kilos: %f",
            	        array[i].idPedidos,
            	        array[i].kilos);
            	if(array[i].estado==0)
            	{
            		printf("\n Estado: Pendiente");
            	}
            	else
            	{
            		printf("\n Estado: Completado");
            	}
            }
        }
        retorno=0;
    }
    return retorno;
}



