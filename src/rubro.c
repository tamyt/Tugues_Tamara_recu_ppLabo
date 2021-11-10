#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubro.h"

/**
 * \brief Valida que el id pasado exista en el array de rubros
 * \param id, id pasado para comparar con los id del array de rubros
 * \param array Array de rubros
 * \param cant Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int validaIdRubro(int id, eRubro array[],int cant){
    int retorno = -1;
    for(int i = 0;i<cant;i++){
        if(array[i].idRubro == id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Devuelve la posicion de la estructura donde el id coincida
 * \param array Array de rubros
 * \param cant Limite del array de rubros
 * \param id, id pasado para comparar con los id del array de rubros
 * \return Retorna i (EXITO) y -1 (ERROR)
 *
 */
int buscaIndDescrPorId(eRubro array[], int cant, int id){
    int retorno = -1;
    for(int i = 0;i < cant;i++){
        if(array[i].idRubro == id){
           retorno = i;
        }
    }
    return retorno;
}

/**
 * \brief lista 1 rubro
 * \param unRubro una estructura de tipo eRubro
 * \return void
 *
 */
void listarRubro(eRubro unRubro){
    if(unRubro.isEmpty != 1){
       fflush(stdin);//__fpurge(stdin);
        printf("%8d- \t\t%8s - \t\t%6d-\n",unRubro.idRubro,
	     unRubro.descripcion, unRubro.isEmpty);
    }
}

/**
 * \brief Lista Rubros
 * \param array Array de Rubros
 * \param cant Limite del array de Rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarRubros(eRubro array[],int cant){
    int retorno = -1;
    if(array != NULL && cant > 0){
       printf("\n\t\t\tRubros\n\n");
       printf("\tId\t\tDescripcion\t\t\t\tisEmpty\n");
       printf("------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
          fflush(stdin);//__fpurge(stdin);
           listarRubro(array[i]);
           retorno = 0;
        }
    }
    return retorno;
}
