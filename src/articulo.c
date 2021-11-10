#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "articulo.h"

/**
 * \brief Valida que el id pasado exista en el array de articulos
 * \param id, id pasado para comparar con los id del array de articulos
 * \param array Array de articulos
 * \param cant Limite del array de articulos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int validaIdArt(int id, eArticulo array[], int cant){
    int retorno = -1;
    for(int i = 0;i<cant;i++){
        if(array[i].idArticulo == id){
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Inicializa el array
 * \param array Array de articulos a ser inicializado
 * \param cant Limite del array de articulos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarArticulos(eArticulo array[], int cant){
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
 * \param array Array de articulos donde se busca la posicion libre
 * \param cant Limite del array de articulos
 * \return Retorna posicion (EXITO) y -1 (ERROR)
 *
 */
int buscarLibre(eArticulo array[], int cant){
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
 * \brief Da de alta un articulo
 * \param array Array de articulos donde se guarda el articulo dado de alta
 * \param cant Limite del array de articulos
 * \param id puntero autoincrementable, id del articulo siendo dado de alta
 * \param arrayR Array de rubros usado para listar rubros y validar el id de rubro
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int alta_Art(eArticulo array[], int cant, int* id, eRubro arrayR[], int cantR){
    int respuesta = -1;
    int indice;
	eArticulo bufferArticulo;
    indice = buscarLibre(array,cant);
	if(array != NULL && cant > 0 && indice < cant && indice >= 0 && id != NULL && arrayR != NULL && cantR > 0)
	{
	    if(utn_getCadena(bufferArticulo.descripcionArt, SIZEART,"\nIngrese el nombre del articulo\n","\nERROR\n",2) == 0 &&
		    utn_getNumeroFlotante(&bufferArticulo.medida,"Ingrese la medida\n","\nERROR\n", 5,300,2) == 0 &&
			utn_getNumeroFlotante(&bufferArticulo.precio,"Ingrese el precio\n","\nERROR\n",100,2000,2) == 0 &&
			listarRubros(arrayR, cantR) == 0 &&
			utn_getNumero(&bufferArticulo.rubroId,"Ingrese el id del rubro\n","\nERROR\n",1000,1010,2) == 0 &&
            validaIdRubro(bufferArticulo.rubroId,arrayR,cantR)== 0)
		{
			respuesta = 0;
			bufferArticulo.idArticulo = *id;
			bufferArticulo.isEmpty = 0;
			array[indice] = bufferArticulo;
			(*id)++;
		}

	}
	return respuesta;
}
/**
 * \brief Da de alta forzada un articulo
 * \param array Array de articulos donde se guarda el articulo dado de alta
 * \param cant Limite del array de articulos
 * \param id puntero autoincrementable, id del articulo siendo dado de alta
 * \param nombre valor a ser guardado en el campo descripcionArt en bufferArticulo
 * \param medida valor a ser guardado en el campo del mismo nombre en bufferArticulo
 * \param precio valor a ser guardado en el campo del mismo nombre en bufferArticulo
 * \param rubroId valor a ser guardado en el campo del mismo nombre en bufferArticulo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaForzadaArt(eArticulo array[], int cant, int* id, char nombre[], float medida, float precio,int rubroId){
    int retorno = -1;
    int indice;
	eArticulo bufferArticulo;

    indice = buscarLibre(array, cant);
	if(array != NULL && cant > 0 && id != NULL  && nombre != NULL && medida > 0 && precio >0 && rubroId >0)
	{
			bufferArticulo.idArticulo = *id;
			strcpy(bufferArticulo.descripcionArt, nombre);
			bufferArticulo.medida = medida;
			bufferArticulo.precio = precio;
			bufferArticulo.rubroId = rubroId;
		    bufferArticulo.isEmpty = 0;

			array[indice] = bufferArticulo;
			(*id)++;
			retorno = 0;
	}
	return retorno;
}

/**
 * \brief ordena el array de estructuras de articulo por rubro y por descripcion
 * \param array Array de Articulos para poder ordenar por descripcion
 * \param cant Limite del array de Articulos
 * \param arrayR Array de rubros usado para poder ordenar tomando el rubro
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int ordenaArticuloPorRubroYDescr(eArticulo array[], int cant, eRubro arrayR[], int cantR){
    int retorno = -1;
    int indiceI;
    int indiceJ;
    eArticulo articuloAux;
    if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0){
        for(int i = 0;i<cant-1;i++){
            for(int j = i + 1;j < cant;j++){
                indiceI = buscaIndDescrPorId(arrayR, cantR, array[i].rubroId);
                indiceJ = buscaIndDescrPorId(arrayR, cantR, array[j].rubroId);
                if(strcmp(arrayR[indiceI].descripcion, arrayR[indiceJ].descripcion) > 0 ||
                (strcmp(arrayR[indiceI].descripcion, arrayR[indiceJ].descripcion) == 0 &&
                strcmp(array[i].descripcionArt, array[j].descripcionArt) > 0)){
                    articuloAux = array[i];
                    array[i] = array[j];
                    array[j] = articuloAux;
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief lista 1 articulo
 * \param unArticulo una estructura de tipo eArticulo
 * \param descr char donde se pasa la descripcion del rubro
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarArticulo(eArticulo unArticulo, char descr[]){
    if(unArticulo.isEmpty != 1){
       fflush(stdin);//__fpurge(stdin);
        printf("%8d- \t\t%8s-\t%8.2f - \t%8.2f - \t%8d - \t\t%8s\n",unArticulo.idArticulo,
    	    unArticulo.descripcionArt, unArticulo.medida, unArticulo.precio,
    	    unArticulo.rubroId, descr);
    }
    return 0;
}

/**
 * \brief Lista Articulos ordenados
 * \param array Array de Articulos
 * \param cant Limite del array de Articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarArticulosOrdenados(eArticulo array[], int cant, eRubro arrayR[], int cantR){
    int retorno = -1;
    int indice;
    if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0){
       if(ordenaArticuloPorRubroYDescr(array,cant, arrayR,cantR) == 0){
            printf("\n\t\t\tArticulos ordenados\n\n");
            printf("IdArticulo\t\tArticulo\t\tMedida\t\tPrecio\t\tId\t\tRubro\n");
            printf("----------------------------------------------------------------------------------------------------------------\n");
            for(int i = 0;i<cant;i++){
                indice = buscaIndDescrPorId(arrayR, cantR, array[i].rubroId);
                listarArticulo(array[i], arrayR[indice].descripcion);
            }
            retorno = 0;
        }
        else{
            printf("Error en listar ordenado");
        }
    }
    return retorno;
}

/**
 * \brief Lista Articulo desordenados, es decir que no llama a la funcion de "ordenaArticuloPorRubroYDescr"
 * \param array Array de Articulos
 * \param cant Limite del array de Articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int listarArticulos(eArticulo array[], int cant, eRubro arrayR[], int cantR){// lista desordenado
    int retorno = -1;
    int indice;
    if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0){
       printf("\n\t\t\tArticulos desordenados\n\n");
       printf("IdArticulo\t\tArticulo\t\tMedida\t\tPrecio\t\tId\t\tRubro\n");
       printf("----------------------------------------------------------------------------------------------------------------\n");
       for(int i = 0;i<cant;i++){
           indice = buscaIndDescrPorId(arrayR, cantR, array[i].rubroId);
           listarArticulo(array[i], arrayR[indice].descripcion);
           retorno = 0;
       }

    }
    return retorno;
}


/**
 * \brief Busca una posicion en el array de estructuras de articulos que coincida con un id ingresado
 * \param array Array de articulos
 * \param cant Limite del array de articulos
 * \param idArt, dato ingresado para buscar la posicion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarPosicionConId(eArticulo array[], int cant, int idArt){
    int posicion;
    posicion = -1;
    if(array != NULL && cant > 0 && idArt > 0){
        for(int i = 0;i < cant;i++){
            if(array[i].idArticulo == idArt){
              posicion = i;
              break;
            }
         }
    }
    return posicion;
}

/**
 * \brief Modifica la medida y/o el precio de un articulo
 * \param array Array de articulos
 * \param cant Limite del array de articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificar_Art(eArticulo array[], int cant, eRubro arrayR[], int cantR){
    int respuesta = -1;
    int rta;
	int bufferId;
	float bufferMedida;
	float bufferPrecio;
	int indice;
	if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0)
	{
	    if(listarArticulos(array, cant, arrayR, cantR) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el id\n","\nERROR\n",100,110,2) == 0){
            indice = buscarPosicionConId(array,cant, bufferId);
            if(indice >= 0){
                do{
                    if(utn_getNumero(&rta, "\n1.Modificar medida\n2.Modificar precio\n3.Salir\n", "Opción inválida\n", 1, 3, 2) == 0){
                        switch(rta){
                            case 1:
                                printf("Ud. ha seleccionado la opción 1.Modificar medida \n\n");
                                if(utn_getNumeroFlotante(&bufferMedida,"\nIngrese la medida\n","\nERROR\n",5,500,2) == 0){
                                    array[indice].medida = bufferMedida;
                                    printf("\nSe ha modificado la medida con exito: \n");
                                    listarArticulos(array, cant, arrayR, cantR);
                                }
                                else{
                                    printf("Error\n");
                                }
                                break;
                            case 2:
                                printf("Ud. ha seleccionado la opción 2.Modificar precio \n\n");
                                if(utn_getNumeroFlotante(&bufferPrecio,"Ingrese el precio\n","Cantidad incorrecta\n",10,1000,2)==0){
                                    array[indice].precio = bufferPrecio;
                                    printf("\nSe ha modificado el precio con exito: \n");
                                    listarArticulos(array, cant, arrayR, cantR);

                                }
                                else{
                                    printf("Error\n");
                                }
                                break;
                            default:
                                printf("Ud. ha seleccionado la opción 3.Salir \n\n");
                                break;
                        }
                        respuesta = 0;
                    }
                }
                while(rta < 3);
            }
            else{
                printf("No se ha encontrado el Id\n");
            }

	    }
    }
	return respuesta;
}

/**
 * \brief Da de baja un articulo
 * \param array Array de Articulos
 * \param cant Limite del array de Articulos
 * \param arrayR Array de rubros
 * \param cantR Limite del array de rubros
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int baja_Art(eArticulo array[], int cant, eRubro arrayR[], int cantR){
    int respuesta = -1;
	int indice;
	int bufferId;
	char decision;
	if(array != NULL && cant > 0 && arrayR != NULL && cantR > 0)
	{
	    if(listarArticulos(array, cant, arrayR, cantR) == 0 &&
            utn_getNumero(&bufferId,"\nIngrese el Id\n","\nERROR\n",100,110,2) == 0){
            indice = buscarPosicionConId(array,cant, bufferId);
            if(indice >= 0){
                if(utn_getCaracter(&decision,"\nSeguro que lo quiere dar de baja?(s/n) \n","\nERROR\n",'n','s',2)==0 &&
                    decision == 's'){
                    array[indice].isEmpty = 1;
                    respuesta = 0;
                   fflush(stdin);//__fpurge(stdin);
                    printf("Se ha dado de baja con exito :");
                    listarArticulos(array, cant, arrayR, cantR);
                }
            }
        }
    }

	return respuesta;
}
