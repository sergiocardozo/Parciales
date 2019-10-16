/*
 * controller.h
 *
 *  Created on: 16 oct. 2019
 *      Author: sergio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int listarClientesPendiente(eClientes list[], int len, ePedidos list2[], int len2);

int listar_pendientes(eClientes list[], int size, ePedidos list2[], int size2);

int pedido_ImprimirArrayProcesado(eClientes list[], int len, ePedidos list2[], int len2);



#endif /* CONTROLLER_H_ */
