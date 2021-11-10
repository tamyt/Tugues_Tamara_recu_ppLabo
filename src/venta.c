#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "venta.h"

/**
 * \brief Inicializa el array
 * \param array Array de ventas a ser inicializado
 * \param cant Limite del array de ventas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarVentas(eVenta array[], int cant){
     int retorno = -1;
     if(array != NULL && cant > 0){
         for(int i = 0;i < cant;i++){
             array[i].isEmpty = 1;
         }
         retorno = 0;
     }
     return retorno;
}

/**
 * \brief Busca la primera posicion libre del array
 * \param array Array de Ventas donde se busca la posicion libre
 * \param cant Limite del array de Ventas
 * \return Retorna posicion (EXITO) y -1 (ERROR)
 *
 */
int buscarLibreVenta(eVenta array[], int cant){
    int posicion;
    posicion = -1;
    if(array != NULL && cant > 0){
        for(int i = 0;i < cant;i++){
            if(array[i].isEmpty == 1){
              posicion = i;
              break;
            }
        }
    }
    return posicion;
 }

/**
 * \brief Da de alta una Venta
 * \param array Array de Ventas donde se guarda la Venta dado de alta
 * \param cant Limite del array de Ventas
 * \param id puntero autoincrementable, id del Venta siendo dado de alta
 * \param arrayC Array de clientes usado para listar clientes y validar el id de cliente
 * \param cantC Limite del array de clientes
 * \param arrayA Array de articulos usado para listar articulos y validar el id de articulo
 * \param cantA Limite del array de articulos
 * \param arrayR Array de rubros usado para listar articulos
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Venta(eVenta array[], int cant, int* id, eCliente arrayC[], int cantC, eArticulo arrayA[], int cantA, eRubro arrayR[], int cantR){
    int respuesta = -1;
    int indice;
	eVenta bufferVenta;
    indice = buscarLibreVenta(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL
	&& arrayC != NULL && cantC > 0 && arrayA != NULL && cantA > 0 && arrayR != NULL && cantR > 0)
	{
	    if(listarClientes(arrayC, cantC) == 0 &&
	        utn_getNumero(&bufferVenta.clienteId,"Ingrese el id del cliente\n","\nERROR\n", 1,10,2) == 0 &&
            validaIdCliente(bufferVenta.clienteId, arrayC, cantC) == 0 &&
            listarArticulos(arrayA, cantA, arrayR, cantR) == 0 &&
	        utn_getNumero(&bufferVenta.articuloId,"Ingrese el id del articulo\n","\nERROR\n", 100,110,2) == 0 &&
            validaIdArt(bufferVenta.articuloId, arrayA, cantA) == 0 &&
			utn_getNumero(&bufferVenta.cantidad,"Ingrese la cantidad\n","\nERROR\n",1,1000,2) == 0 &&
			utn_getNumeroFlotante(&bufferVenta.precioTotal,"Ingrese el precio total\n","\nERROR\n",100,200000,2) == 0 &&
            utn_getNumero(&bufferVenta.fecha.dia,"Ingrese el dia\n","\nERROR\n",1,31,2) == 0 &&
            utn_getNumero(&bufferVenta.fecha.mes,"Ingrese el mes\n","\nERROR\n",1,12,2) == 0 &&
            utn_getNumero(&bufferVenta.fecha.anio,"Ingrese el anio\n","\nERROR\n",1900,2021,2) == 0 )
		{
			respuesta = 0;
			bufferVenta.idVenta = *id;
			bufferVenta.isEmpty = 0;
			array[indice] = bufferVenta;
			(*id)++;
		}

	}
	return respuesta;
}


/**
 * \brief Da de alta forzada una venta
 * \param array Array de Ventas donde se guarda la Venta dada de alta
 * \param cant Limite del array de Ventas
 * \param id puntero autoincrementable, id de la Venta siendo dado de alta
 * \param clienteId valor a ser guardado en el campo del mismo nombre en bufferVenta
 * \param articuloId valor a ser guardado en el campo del mismo nombre en bufferVenta
 * \param cantidad valor a ser guardado en el campo del mismo nombre en bufferVenta
 * \param precioTotal valor a ser guardado en el campo del mismo nombre en bufferVenta
 * \param dia valor a ser guardado en el campo fecha.dia en bufferVenta
 * \param mes valor a ser guardado en el campo fecha.mes en bufferVenta
 * \param anio valor a ser guardado en el campo fecha.anio en bufferVenta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzadaVenta(eVenta array[], int cant, int* id, int clienteId, int articuloId, int cantidad, float precioTotal, int dia, int mes, int anio){
    int retorno = -1;
    int indice;
	eVenta bufferVenta;

    indice = buscarLibreVenta(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && clienteId > 0 && articuloId > 0
	&& cantidad >0 && precioTotal >0 && dia > 0 && dia < 32 && mes > 0 && mes < 13 && anio > 1900 && anio < 2022)
	{
			bufferVenta.idVenta = *id;
			bufferVenta.clienteId = clienteId;
			bufferVenta.articuloId = articuloId;
			bufferVenta.cantidad = cantidad;
			bufferVenta.precioTotal = precioTotal;
			bufferVenta.fecha.dia = dia;
			bufferVenta.fecha.mes = mes;
			bufferVenta.fecha.anio = anio;
		    bufferVenta.isEmpty = 0;

			array[indice] = bufferVenta;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}

/**
 * \brief lista 1 Venta
 * \param unaVenta una estructura de tipo eVenta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarVenta(eVenta unaVenta){
    if(unaVenta.isEmpty != 1){
       fflush(stdin);//__fpurge(stdin);
        printf("%8d- %10d-\t%15d - \t%8d - \t%8.2f-\t%8d/%d/%d - \t%6d\n",unaVenta.idVenta,
    	    unaVenta.clienteId, unaVenta.articuloId, unaVenta.cantidad,
    	    unaVenta.precioTotal, unaVenta.fecha.dia, unaVenta.fecha.mes, unaVenta.fecha.anio, unaVenta.isEmpty);
    }
    return 0;
}

/**
 * \brief Lista Ventas
 * \param array Array de Ventas
 * \param cant Limite del array de Ventas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarVentas(eVenta array[], int cant){// lista desordenado
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\t\t\t\tVentas \n\n");
       printf("IdVenta\t\tClienteId\tArticuloId\tCantidad\tPrecio total\t\tFecha\t\tisEmpty\n");
       printf("-----------------------------------------------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
           listarVenta(array[i]);
           retorno = 0;
       }

    }
    return retorno;
}
