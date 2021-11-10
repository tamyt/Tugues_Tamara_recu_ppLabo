#ifndef CLIENTE_H_
#define CLIENTE_H_

//#include <stdio_ext.h> no va en eclipse
//#include <string.h>
#include "utn.h"
#define NOM 25

typedef struct
{
	int idCliente;
	char nombre[NOM];
	int telefono;
	int isEmpty;
}eCliente;

int validaIdCliente(int id, eCliente array[], int cant);
void listarCliente(eCliente unCliente);
int listarClientes(eCliente array[],int cant);

#endif /* CLIENTE_H_ */
