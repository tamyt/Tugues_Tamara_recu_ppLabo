#ifndef VENTA_H_
#define VENTA_H_

//#include <stdio_ext.h> no va en eclipse
//#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "articulo.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
	int idVenta;
	int clienteId;
	int articuloId;
	int cantidad;
	float precioTotal;
	eFecha fecha;
	int isEmpty;
}eVenta;

int inicializarVentas(eVenta array[], int cant);
int buscarLibreVenta(eVenta array[], int cant);

int alta_Venta(eVenta array[], int cant, int* id, eCliente arrayC[], int cantC, eArticulo arrayA[], int cantA, eRubro arrayR[], int cantR);
int altaForzadaVenta(eVenta array[], int cant, int* id, int clienteId, int articuloId, int cantidad, float precioTotal, int dia, int mes, int anio);

int listarVenta(eVenta unaVenta);
int listarVentas(eVenta array[], int cant);

#endif /* VENTA_H_ */
