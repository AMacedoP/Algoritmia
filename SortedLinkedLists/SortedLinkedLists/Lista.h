/* 
 * File:   Lista.h
 * Author: feralvam
 *
 */

#ifndef LISTA_H
#define	LISTA_H

typedef int TElemento;

typedef struct nodo{
    TElemento elem;
    struct nodo *sig;
}TNodo;

typedef struct lista{
    TNodo *inicio;
    TNodo *fin;
    int numElem;
}TLista;

/* Crea una lista vacía */
void Lista_init(TLista *);
/* Libera la memoria ocupada por todos los elmentos de la lista */
void Lista_finalizar(TLista *);
/* Inserta un nuevo elemento en la lista */
void Lista_insertar(TLista *, TElemento);
/* Verifica si la lista está vacía */
int Lista_estaVacia(TLista *);
/* Elimina un elemento de la lista */
void Lista_eliminar(TLista *, TElemento);
/* Obtiene el número de elementos de la lista*/
int Lista_tamanho(TLista *);
/* Verifica si un elemento está en la lista */
int Lista_estaEnLista(TLista *, TElemento);
/* Imprime los elementos de la lista */
void Lista_imprimir(TLista *);
/* Inserta un elemento en la lista ordenada*/
void Lista_insertarEnOrden(TLista *, TElemento);


#endif	/* LISTA_H */

