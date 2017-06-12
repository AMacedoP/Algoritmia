#ifndef LISTA_H
#define LISTA_H

typedef int TElemento;

typedef struct nodo{
	TElemento value;
	struct nodo *sig;
}TNodo;

typedef struct list{
	TNodo *ini;
	TNodo *fin;
	int numElems;
}TLista;

void crearLista(TLista *);
void imprimirLista(TLista *);
int esListaVacia(TLista *);
int sizeLista(TLista *);
void insertarElemento(TLista *, TElemento);
void eliminarElemento(TLista *, TElemento);
int estaElemento(TLista *, TElemento);
void insertarElementoInicio(TLista *, TElemento);

#endif
