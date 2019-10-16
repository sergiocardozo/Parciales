#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"
#include "pedidos.h"

static int generarIdCliente()
{
	static int idMax=0;
	return idMax++;
}
int cliente_Inicializar(eClientes array[], int size)
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


int cliente_buscarEmpty(eClientes array[], int size, int* posicion)
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


int cliente_buscarID(eClientes array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idClientes==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_alta(eClientes array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {

            array[posicion].idClientes = generarIdCliente();
        	array[posicion].isEmpty=0;
        	utn_getName("\nIngrese nombre de la Empresa: ","\nError",1,50,2,array[posicion].nombreEmpresa);
        	utn_getTexto("\nIngrese Cuit: ","\nError",1,13,2,array[posicion].cuit);
        	utn_getTexto("\nIngrese direccion: ","\nError",1,50,2,array[posicion].direccion);
        	utn_getName("\nIngrese localidad: ","\nError",1,50,2,array[posicion].localidad);


            printf( "\n ID: %d\t Nombre Empresa: %s\t Cuit: %s\t Direccion: %s\t Localidad: %s",
				   array[posicion].idClientes,
				   array[posicion].cuit,
				   array[posicion].nombreEmpresa,
				   array[posicion].direccion,
				   array[posicion].localidad);
            retorno=0;
        }
    }
    return retorno;
}



int cliente_baja(eClientes clieArray[], int sizeClieArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(clieArray!=NULL && sizeClieArray>0)
    {
    	utn_getUnsignedInt("\nID de cliente a dar de baja: ","\nError",1,sizeof(int),1,sizeClieArray,3,&id);
        if(cliente_buscarID(clieArray,sizeClieArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	utn_getChar("\nEsta seguro que desea dar de baja? S/N","\nError",'A','S',2,&opcion);
        	switch(opcion)
        	{
        	  case 'S':
        		  clieArray[posicion].isEmpty=1;
        		  clieArray[posicion].idClientes=0;
        		  strcpy(clieArray[posicion].nombreEmpresa,"");
        		  strcpy(clieArray[posicion].cuit,"");
        		  strcpy(clieArray[posicion].direccion,"");
        		  strcpy(clieArray[posicion].localidad,"");

        		  retorno = 0;
        	      break;
        	  case 'N':
        		  printf("\nBaja cancelada");
        	      break;
        	  default:
        		  printf("\nOpcion no valida");
        	 }

        }

        retorno=0;
    }

   	return retorno;
}


int cliente_modificar(eClientes array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
    	utn_getUnsignedInt("\nID de cliente a modificar: ","\nError",1,sizeof(int),1,sizeArray,2,&id);
        if(cliente_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
            	printf( "\nID: %d\tCuil: %s\tNombre: %s\tDireccion %s\tLocalidad: %s",
            			array[posicion].idClientes,
						array[posicion].cuit,
            			array[posicion].nombreEmpresa,
						array[posicion].direccion,
						array[posicion].localidad);
                utn_getChar("\nModificar: Direccion(A) Localidad(B) S(Salir)","\nError",'A','S',2,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	utn_getName("\nIngrese direccion: ","\nError",1,50,2,array[posicion].direccion);
                    	break;
                    case 'B':
                    	utn_getName("\nIngrese localidad: ","\nError",1,50,2,array[posicion].localidad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}



int clientesExistente(eClientes list[], int len)
{
	int ret = -1;
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            ret = 0;
        }
    }
    return ret;
}

int cliente_listar(eClientes array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	printf( "\n ID: %d"
            	        "\t Cuil: %s"
            			"\t Nombre: %s"
            			"\t Direccion %s"
            			"\t Localidad: %s",
            			array[i].idClientes,
            		    array[i].cuit,
               		    array[i].nombreEmpresa,
						array[i].direccion,
						array[i].localidad);
        }
        retorno=0;
    }
    return retorno;
}



