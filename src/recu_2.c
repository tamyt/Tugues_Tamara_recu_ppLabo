#include <stdio.h>
#include "utn.h"
#include "rubro.h"
#include "articulo.h"
#include "cliente.h"
#include "venta.h"
#include "informes.h"

#define QTY 5
#define QTYR 4

int main()
{
    setbuf(stdout,NULL);
    char rta;
    int contIdArt;
    int contIdVenta;
    //int contIdRubro;
    int flag;
    int flag_2;

    contIdArt = 100;
    contIdVenta = 20000;
    //contIdRubro = 1000;
    flag = 0;
    flag_2 = 0;

    eArticulo arrayArticulos[QTY];

    eRubro arrayRubros[QTYR] = {{1000, "CUIDADO DE ROPA",0},
								{1002, "LIMPIEZA Y DESINFECCION",0},
								{1003, "CUIDADO PERSONAL E HIGIENE",0},
								{1004, "CUIDADO DEL AUTOMOTOR",0}};

    eCliente arrayClientes[QTYR]= {{1, "Juan Sosa", 34565689,0},
								{2, "Ana Rubio" ,5009924,0},
								{3, "Pedro Duarte", 1801897,0},
								{4, "Sonia Rios", 1452587,0}};

	eVenta arrayVentas[QTY];

    if(inicializarArticulos(arrayArticulos,QTY)==0 )
	{
		printf("Array articulos inicializado correctamente. \n");
	}
	if(inicializarVentas(arrayVentas, QTY)==0 )
	{
		printf("Array ventas inicializado correctamente. \n");
	}


	do{
	    if(utn_getCaracter(&rta,
    	    "\nA.Alta articulos\nB.Modificar articulos\nC.Baja articulos\nD.Listar articulos\nE.Listar rubros\nF.Listar clientes\nG.Alta venta\nH.Listar ventas\nI.Informes\nJ.Salir\n",
    	    "Opción inválida\n\n",'A','J',2) == 0){
            switch(rta){
                case 'A'://Alta articulos
                    printf("Ud. ha seleccionado la opción A-Alta articulos \n\n");
                   if(altaForzadaArt(arrayArticulos, QTY, &contIdArt, "Lavandina", 10, 200, 1000) == 0 &&
                        altaForzadaArt(arrayArticulos, QTY, &contIdArt, "Detergente", 20, 300, 1002) == 0 &&
                        altaForzadaArt(arrayArticulos, QTY, &contIdArt, "Suavizante", 18, 500, 1003) == 0 &&
                        altaForzadaArt(arrayArticulos, QTY, &contIdArt, "Talco", 17, 107, 1003) == 0 &&
                        altaForzadaArt(arrayArticulos, QTY, &contIdArt, "Aromatizador", 6, 172, 1004) == 0 ){
                    //if(alta_Art(arrayArticulos, QTY, &contIdArt, arrayRubros, QTYR) == 0){
                        printf("\nEl alta se ha realizado con exito\n\n");
                        flag = 1;
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 'B': // Modificacion de Articulo
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción B-Modificación \n\n");
                        if(modificar_Art(arrayArticulos, QTY,arrayRubros,QTYR) != 0){
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de articulo para poder modificarlo\n\n");
                    }
                    break;
                case 'C':// Baja de Articulo
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción C-Baja \n\n");
                        if(baja_Art(arrayArticulos, QTY,arrayRubros,QTYR) != 0){
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de Articulo para poder darlo de baja\n\n");
                    }
                    break;
                case 'D': // Listar Articulos
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción D-Listar Articulos \n\n");
                        /*listarArticulos(arrayArticulos, QTY,arrayRubros,QTYR);
                        printf("\n\n");*/
                        if(listarArticulosOrdenados(arrayArticulos, QTY,arrayRubros,QTYR) == 0){
                        //if(listarArticulos(arrayArticulos, QTY,arrayRubros,QTYR)==0){
                           printf("\nSe ha informado con exito \n\n");
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de Articulo para poder listarlo\n\n");
                    }
                    break;
                case 'E':// Listar rubros
                    printf("Ud. ha seleccionado la opción E-Listar rubros \n\n");
                    if(listarRubros(arrayRubros,QTYR) == 0){
                       printf("\nSe ha informado con exito \n\n");
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 'F':// Listar clientes
                    printf("Ud. ha seleccionado la opción F-Listar clientes \n\n");
                    if(listarClientes(arrayClientes,QTYR) == 0){
                       printf("\nSe ha informado con exito \n\n");
                    }
                    else{
                        printf("\nError\n\n");
                    }
                    break;
                case 'G':// Alta venta
                    if(flag == 1){
                        printf("Ud. ha seleccionado la opción G-Alta venta \n\n");
                        if(altaForzadaVenta(arrayVentas, QTY, &contIdVenta, 1, 100, 100, 20000,1,11,2010) == 0 &&
                            altaForzadaVenta(arrayVentas, QTY, &contIdVenta, 2, 101, 300, 90000,8,10,2011) == 0 &&
                            altaForzadaVenta(arrayVentas, QTY, &contIdVenta, 3, 101, 500, 150000,15,4,2012) == 0 &&
                            altaForzadaVenta(arrayVentas, QTY, &contIdVenta, 4, 102, 107, 51000,21,8,2000) == 0 &&
                            altaForzadaVenta(arrayVentas, QTY, &contIdVenta, 2, 103, 172, 18404,28,6,2006) == 0 ){
                        //if(alta_Venta(arrayVentas, QTY, &contIdArt, arrayClientes, QTYR, arrayArticulos, QTY, arrayRubros, QTYR) == 0){
                            printf("\nEl alta se ha realizado con exito\n\n");
                            flag_2 = 1;
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de Articulo para poder dar de alta una venta\n\n");
                    }
                    break;
                case 'H':// Listar ventas
                    if(flag_2 == 1){
                        printf("Ud. ha seleccionado la opción H-Listar ventas \n\n");
                        if(listarVentas(arrayVentas,QTY) == 0){
                           printf("\nSe ha informado con exito \n\n");
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de venta para poder listarla\n\n");
                    }
                    break;
                case 'I':// Informes
                    if(flag == 1 && flag_2 == 1){
                        printf("Ud. ha seleccionado la opción I-Informes \n\n");
                        if(muestraInformes(arrayArticulos, QTY,arrayRubros,QTYR, arrayClientes, QTYR, arrayVentas,QTY) == 0){
                           printf("\nSe ha informado con exito \n\n");
                        }
                        else{
                            printf("\nError\n\n");
                        }
                    }
                    else{
                         printf("\nError, no se hizo un alta de articulo y/o un alta de venta para poder informar\n\n");
                    }
                    break;
                default:
                    break;
            }
		}
    }
    while(rta < 'J');

    return 0;
}
