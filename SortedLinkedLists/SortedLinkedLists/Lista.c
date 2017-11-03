#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* Crea una lista vacía */
void Lista_init(TLista *L) {
    L->inicio = NULL; //(*L).inicio = NULL;
    L->fin = NULL; //  (*L).fin = NULL;
    L->numElem = 0;
}

/* Verifica si la lista está vacía */
int Lista_estaVacia(TLista *L) {
    return L->numElem == 0;
}

/* Libera la memoria ocupada por todos los elmentos de la lista */
void Lista_finalizar(TLista *L) {
    TNodo *ptrRec;
    ptrRec = L->inicio;
    while (ptrRec) {
        L->inicio = L->inicio->sig;
        free(ptrRec);
        ptrRec = L->inicio;
    }
    L->fin = NULL;
    L->numElem = 0;
}

/* Inserta un nuevo elemento en la lista */
void Lista_insertar(TLista *L, TElemento nuevoElem) {
    TNodo *ptrNuevo;
    ptrNuevo = malloc(sizeof (TNodo));

    if (ptrNuevo != NULL) {
        // Crear el nuevo nodo
        ptrNuevo->elem = nuevoElem;
        ptrNuevo->sig = NULL;
        // Insertar el nuevo nodo al final de la lista
        if (!Lista_estaVacia(L)) {
            L->fin->sig = ptrNuevo;
        } else {
            L->inicio = ptrNuevo;
        }
        L->fin = ptrNuevo;
        (L->numElem)++;
    }
}

/* Elimina un elemento de la lista */
void Lista_eliminar(TLista *L, TElemento e) {
    TNodo *ptrRec, *ptrAnt;

    // if (Lista_estaVacia(L)) return;

    ptrRec = L->inicio;
    ptrAnt = NULL;
    // Buscar el elemento en la lista
    while (ptrRec != NULL && ptrRec->elem != e) {
        ptrAnt = ptrRec;
        ptrRec = ptrRec->sig;
    }

    if (ptrRec != NULL) {// Encontró el elemento a eliminar
        if (ptrAnt == NULL) {// Es el primer elemento de la lista
            L->inicio = L->inicio->sig;
        }
        if (ptrRec == L->fin) { // Es el último elemento de la lista
            L->fin = ptrAnt;
            if (L->fin != NULL) L->fin->sig = NULL;
        } else if (ptrAnt != NULL) {
            ptrAnt->sig = ptrRec->sig;
        }
        free(ptrRec);
        (L->numElem)--;
    }
}

/* Obtiene el número de elementos de la lista*/
int Lista_tamanho(TLista *L) {
    return L->numElem;
}

/* Verifica si un elemento está en la lista */
int Lista_estaEnLista(TLista *L, TElemento e) {
    TNodo *ptrRec = L->inicio;
    while (ptrRec != NULL) {
        if (ptrRec->elem == e) return 1;
        ptrRec = ptrRec->sig;
    }
    return 0;
}

/* Imprime los elementos de la lista */
void Lista_imprimir(TLista *L) {
    TNodo *ptrRec = L->inicio;
    while (ptrRec != NULL) {
        printf("%d ", ptrRec->elem);
        ptrRec = ptrRec->sig;
    }
}
    
/* Inserta un elemento en una lista ordenada */
void Lista_insertarEnOrden(TLista *L, TElemento nuevoElem) {
    TNodo *ptrNuevo;
    ptrNuevo = malloc(sizeof (TNodo));

    if (ptrNuevo) {
        ptrNuevo->elem = nuevoElem;
        ptrNuevo->sig = NULL;

        TNodo* ptrRec, *ptrAnt;
        ptrAnt = NULL;
        ptrRec = L->inicio;
        // Buscar la posición en la cual debo insertar
        while (ptrRec && ptrRec->elem < nuevoElem) {
            ptrAnt = ptrRec;
            ptrRec = ptrRec->sig;
        }
        if (ptrAnt == NULL)
            L->inicio = ptrNuevo;
        else {
            ptrAnt->sig = ptrNuevo;
            if (ptrAnt == L->fin) L->fin = ptrNuevo;
        }
        ptrNuevo->sig = ptrRec;
        (L->numElem)++;
    }
}   

