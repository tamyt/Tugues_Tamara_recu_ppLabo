#ifndef ARTICULO_H_
#define ARTICULO_H_

//#include <stdio_ext.h> no va en eclipse
//#include <string.h>
#include "utn.h"
#include "rubro.h"

#define SIZEART 30

typedef struct
{
	int idArticulo;
	char descripcionArt[SIZEART];
	float medida;
	float precio;
	int rubroId;
	int isEmpty;
}eArticulo;

int validaIdArt(int id, eArticulo array[], int cant);

int inicializarArticulos(eArticulo array[], int cant);
int buscarLibre(eArticulo array[], int cant);
int alta_Art(eArticulo array[], int cant, int* id, eRubro arrayR[], int cantR);
int altaForzadaArt(eArticulo array[], int cant, int* id, char nombre[], float medida, float precio,int rubroId);

int ordenaArticuloPorRubroYDescr(eArticulo array[], int cant, eRubro arrayR[], int cantR);

int listarArticulo(eArticulo unArticulo, char descr[]);

int listarArticulosOrdenados(eArticulo array[], int cant, eRubro arrayR[], int cantR);

int listarArticulos(eArticulo array[], int cant, eRubro arrayR[], int cantR);
int buscarPosicionConId(eArticulo array[], int cant, int idArt);
int modificar_Art(eArticulo array[], int cant,eRubro arrayR[], int cantR);
int baja_Art(eArticulo array[], int cant, eRubro arrayR[], int cantR);


#endif /* ARTICULO_H_ */
