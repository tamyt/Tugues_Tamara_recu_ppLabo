#ifndef RUBRO_H_
#define RUBRO_H_

//#include <stdio_ext.h>// no va en eclipse
//#include <string.h>
#include "utn.h"
#define SIZE 30

typedef struct
{
	int idRubro;
	char descripcion[SIZE];
	int isEmpty;
}eRubro;

int validaIdRubro(int id, eRubro array[],int cant);
int buscaIndDescrPorId(eRubro array[], int cant,int id);

void listarRubro(eRubro unRubro);
int listarRubros(eRubro array[],int cant);

#endif /* RUBRO_H_ */
