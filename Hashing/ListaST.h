/* 
 * File:   ListaST.h
 * Author: Ferando Alva Manchego
 *
 */

#ifndef LISTAST_H
#define	LISTAST_H

typedef char* TKey;
typedef int TValue;

typedef struct nodo{
    TKey key;
    TValue value;
    struct nodo *sig;
}TNodo;

typedef struct lista{
    TNodo *inicio;
    TNodo *fin;
    int numElem;
}TListaST;


/* Crea una lista vacía */
void ListaST_Init(TListaST *);
/* Libera la memoria ocupada por todos los elmentos de la lista */
void ListaST_Final(TListaST *);
/* Inserta un nuevo elemento en la lista */
void ListaST_Insert(TListaST *, TKey, TValue);
/* Buscar un elemento está en la lista */
TValue ListaST_Search(TListaST *, TKey);
/* Verifica si la lista está vacía */
int ListaST_IsEmpty(TListaST *);
/* Elimina un elemento de la lista */
void ListaST_Delete(TListaST *, TKey);
/* Obtiene el número de elementos de la lista*/
int ListaST_Size(TListaST *);
/* Imprime los elementos de la lista */
void ListaST_Print(TListaST *);

#endif	/* LISTAST_H */

