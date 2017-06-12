#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void crearLista(TLista *L){
	L -> ini = NULL;
	L -> fin = NULL;
	L -> numElems = 0;
}

void imprimirLista(TLista *L){
	TNodo *ptr = L -> ini;
	while(ptr != NULL){
		printf("%d\t", ptr -> value);
		ptr = ptr -> sig;
	}
	printf("\n");
}

int sizeLista(TLista *L){
	return L -> numElems;
}

int esListaVacia(TLista *L){
	return L -> numElems == 0;
}

void insertarElemento(TLista *L, TElemento e){
	TNodo *nodo = malloc(sizeof(TNodo));
	if(nodo){
		nodo -> value = e;
		nodo -> sig = NULL;

		if(esListaVacia(L)){
			L -> ini = nodo;
			L -> fin = nodo;
		}
		else{
			L -> fin -> sig = nodo;
			L -> fin = nodo;
		}
		(L -> numElems)++;
	}
}

void eliminarElemento(TLista *L, TElemento e){
	if(esListaVacia(L))
		printf("No se puede eliminar, la lista esta vacia\n");	
	else if(sizeLista(L) == 1){
		if(L -> ini -> value == e){
			printf("Eliminando elemento con valor %d\n", e);
			L -> ini = L -> fin = NULL;
			L -> numElems = 0;
		}
		else printf("El elemento no existe\n");
	}
	else{
		TNodo *act = L -> ini;
		TNodo *ant = NULL;

		while(act != NULL){
			if(act -> value == e)
				break;
			ant = act;
			act = act -> sig;
		}

		if(act != NULL){
			printf("Eliminando elemento con valor %d\n", e);
			if(ant == NULL)
				L -> ini = act -> sig;
			else if(act -> sig == NULL){
				L -> fin = NULL;
				ant -> sig = NULL;
			}
			else
				ant -> sig = act -> sig;
			free(act);
			(L -> numElems)--;
		}
		else
			printf("El elemento no existe\n");
	}
}

int estaElemento (TLista *L, TElemento e){
	TNodo *ptr = L -> ini;
	while(ptr != NULL){
		if(ptr -> value == e)
			return 1;
		ptr = ptr -> sig;
	}
	return 0;
}

void insertarElementoInicio(TLista *L, TElemento e){
	TNodo *nodo = malloc(sizeof(TNodo));
	if(nodo){
		nodo -> value = e;
		if(esListaVacia(L))
			L -> fin = nodo;
		else
			nodo -> sig = L -> ini;
		L -> ini = nodo;
		(L -> numElems)++;
	}
}
