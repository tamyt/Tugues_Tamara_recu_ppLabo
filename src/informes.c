#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"

/**
 * \brief Lista Articulos solo con el rubro seleccionado
 * \param array Array de Articulos
 * \param cant Limite del array de Articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \param rubroId campo usado para listar articulos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarArticulosConRubro(eArticulo array[], int cant, eRubro arrayR[], int cantR, int rubroId){
    int retorno = -1;
    int indice;
    if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0 && rubroId > 0){
       printf("\n\t\t\t\tArticulos \n\n");
       printf("IdArticulo\t\tArticulo\t\tMedida\t\tPrecio\t\tId\t\tRubro\n");
       printf("----------------------------------------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
           if(array[i].rubroId == rubroId){
                indice = buscaIndDescrPorId(arrayR, cantR, array[i].rubroId);
                listarArticulo(array[i], arrayR[indice].descripcion);
                retorno = 0;
           }
       }

    }
    return retorno;
}

/**
 * \brief Lista ventas solo con el cliente seleccionado
 * \param array Array de Ventas
 * \param cant Limite del array de ventas
 * \param clienteId campo usado para listar ventas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarVentasConCliente(eVenta array[], int cant, int clienteId){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\t\t\t\tVentas \n\n");
       printf("IdVenta\t\tClienteId\tArticuloId\tCantidad\tPrecio total\t\tFecha\t\tisEmpty\n");
       printf("-----------------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0;i<cant;i++){
           if(array[i].clienteId == clienteId){
               listarVenta(array[i]);
               retorno = 0;
           }
        }

    }
    return retorno;
}

/**
 * \brief Suma el importe de cada venta del articulo elegido
 * \param array Array de Ventas
 * \param cant Limite del array de Ventas
 * \param articuloId campo usado para sumar ventas que tengan ese articuloId
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sumaVentasConArt(eVenta array[], int cant, int articuloId){
    float acum;
    acum = 0;
    if(array != NULL && cant > 0){
        for(int i = 0;i<cant;i++){
           if(array[i].articuloId == articuloId){
               acum = acum + array[i].precioTotal;
           }
        }
    }
    return acum;
}

/**
 * \brief Suma el importe de cada venta del cliente elegido
 * \param array Array de Ventas
 * \param cant Limite del array de Ventas
 * \param clienteId campo usado para sumar ventas que tengan ese clienteId
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int sumaVentasConCliente(eVenta array[], int cant, int clienteId){
    float acum;
    acum = 0;
    if(array != NULL && cant > 0){
        for(int i = 0;i<cant;i++){
           if(array[i].clienteId == clienteId){
               acum = acum + array[i].precioTotal;
           }
        }
    }
    return acum;
}
/**
 * \brief Muestra el informe elegido
 * \param array Array de articulos
 * \param cant Limite del array de articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \param array Array de clientes
 * \param cant Limite del array de clientes
 * \param arrayR Array de ventas
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int muestraInformes(eArticulo array[], int cant, eRubro arrayR[], int cantR, eCliente arrayC[], int cantC, eVenta arrayV[], int cantV){
    int respuesta = -1;
    int rta;
    int bufferRubro;
    int bufferCliente;
    int bufferArt;
    float importeArts;
    float importeClientes;
	if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0 && arrayC != NULL && cantC > 0 && arrayV != NULL && cantV > 0)
	{
        do{
            fflush(stdin);//__fpurge(stdin);
            if(utn_getNumero(&rta,
            "\n1- Mostrar artículos de un rubro seleccionado\n2- Mostrar todas las ventas efectuadas al cliente seleccionado\n3- Informar importe total de las ventas realizadas de un artículo seleccionado\n4- Informar importe total de las ventas realizadas a un cliente seleccionado\n5- Salir\n",
            "Opción inválida\n", 1, 5, 2) == 0){
                switch(rta){
                    case 1:
                        printf("Ud. ha seleccionado la opción 1- Mostrar artículos de un rubro seleccionado \n\n");
                        if(listarRubros(arrayR, cantR) == 0 &&
            			    utn_getNumero(&bufferRubro,"Ingrese el id del rubro\n","\nERROR\n",1000,1010,2) == 0 &&
                            validaIdRubro(bufferRubro,arrayR,cantR)== 0){
                            listarArticulosConRubro(array, cant, arrayR, cantR, bufferRubro);
                        }
                        else{
                            printf("Error\n");
                        }
                        break;
                    case 2:
                        printf("Ud. ha seleccionado la opción 2- Mostrar todas las ventas efectuadas al cliente seleccionado \n\n");
                        if(listarClientes(arrayC, cantC) == 0 &&
            			    utn_getNumero(&bufferCliente,"Ingrese el id del cliente\n","\nERROR\n",1,12,2) == 0 &&
                            validaIdCliente(bufferCliente,arrayC,cantC)== 0){
                            listarVentasConCliente(arrayV, cantV, bufferCliente);
                        }
                        else{
                            printf("Error\n");
                        }
                        break;
                    case 3:
                        printf("Ud. ha seleccionado la opción 3- Informar importe total de las ventas realizadas de un artículo seleccionado \n\n");
                        if(listarArticulos(array, cant, arrayR, cantR) == 0 &&
            			    utn_getNumero(&bufferArt,"Ingrese el id del articulo\n","\nERROR\n",100,110,2) == 0 &&
                            validaIdArt(bufferArt, array, cant)== 0){
                            importeArts = sumaVentasConArt(arrayV, cantV, bufferArt);
                            if(importeArts > 0){
                                printf("El importe total de las ventas de ese articulo es de %.2f\n", importeArts);
                            }
                        }
                        else{
                            printf("Error\n");
                        }
                        break;
                    case 4:
                        printf("Ud. ha seleccionado la opción 4- Informar importe total de las ventas realizadas a un cliente seleccionado \n\n");
                         if(listarClientes(arrayC, cantC) == 0 &&
            			    utn_getNumero(&bufferCliente,"Ingrese el id del cliente\n","\nERROR\n",1,12,2) == 0 &&
                            validaIdCliente(bufferCliente,arrayC,cantC)== 0){
                            importeClientes = sumaVentasConCliente(arrayV, cantV, bufferCliente);
                            if(importeClientes > 0){
                                printf("El importe total de las ventas a ese cliente es de %.2f\n", importeClientes);
                            }
                        }
                        else{
                            printf("Error\n");
                        }
                        break;
                    default:
                        printf("Ud. ha seleccionado la opción 5- Salir \n\n");
                        break;
                }
                respuesta = 0;
            }
        }
        while(rta < 5);
    }
	return respuesta;
}
