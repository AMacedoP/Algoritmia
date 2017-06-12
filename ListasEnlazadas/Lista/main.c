#include <stdio.h>
#include "lista.h"

int main(){
	TLista L;
	crearLista(&L);
	insertarElemento(&L, 4);
	insertarElemento(&L, 7);
	insertarElemento(&L, 1);
	insertarElemento(&L, 3);
	imprimirLista(&L);

	eliminarElemento(&L, 4);
	eliminarElemento(&L, 2);
	imprimirLista(&L);

	TLista A;
	crearLista(&A);
	eliminarElemento(&A, 4);
	insertarElemento(&A, 4);
	eliminarElemento(&A, 4);
	imprimirLista(&A);
	insertarElemento(&A, 1);
	insertarElementoInicio(&A, 2);
	imprimirLista(&A);
}
