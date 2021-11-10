#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

/**
 * \brief Valida que el id pasado exista en el array de Clientes
 * \param id, id pasado para comparar con los id del array de Clientes
 * \param array Array de Clientes
 * \param cant Limite del array de Clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int validaIdCliente(int id, eCliente array[], int cant){
    int retorno = -1;
    for(int i = 0;i<cant;i++){
        if(array[i].idCliente == id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief lista 1 Cliente
 * \param unCliente una estructura de tipo eCliente
 * \return void
 *
 */
void listarCliente(eCliente unCliente){
    if(unCliente.isEmpty != 1){
       fflush(stdin);//__fpurge(stdin);
        printf("%8d- \t\t%8s - \t\t%8d- \t\t%8d\n",unCliente.idCliente,
	     unCliente.nombre, unCliente.telefono, unCliente.isEmpty);
    }
}

/**
 * \brief Lista Clientes
 * \param array Array de Clientes
 * \param cant Limite del array de Clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarClientes(eCliente array[],int cant){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\t\tClientes\n\n");
       printf("\tId\t\tNombre\t\t\tTelefono\t\tisEmpty\n");
       printf("-------------------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
          fflush(stdin);//__fpurge(stdin);
           listarCliente(array[i]);
           retorno = 0;
        }
    }
    return retorno;
}
