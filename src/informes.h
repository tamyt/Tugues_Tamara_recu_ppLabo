#ifndef INFORMES_H_
#define INFORMES_H_

//#include <stdio_ext.h> no va en eclipse
//#include <string.h>
#include "utn.h"
#include "articulo.h"
#include "rubro.h"
#include "venta.h"
#include "cliente.h"

int listarArticulosConRubro(eArticulo array[], int cant, eRubro arrayR[], int cantR, int rubroId);

int listarVentasConCliente(eVenta array[], int cant, int clienteId);

int sumaVentasConArt(eVenta array[], int cant, int articuloId);
int sumaVentasConCliente(eVenta array[], int cant, int clienteId);

int muestraInformes(eArticulo array[], int cant, eRubro arrayR[], int cantR, eCliente arrayC[], int cantC, eVenta arrayV[], int cantV);

#endif /* INFORMES_H_ */
