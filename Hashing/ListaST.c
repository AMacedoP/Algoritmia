#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaST.h"

/* Crea una lista vacía */
void ListaST_Init(TListaST *L){
    L->inicio = NULL;
    L->fin = NULL;
    L->numElem = 0;
}

/* Verifica si la lista está vacía */
int ListaST_IsEmpty(TListaST *L){
    return (L->numElem == 0);
}

/* Libera la memoria ocupada por todos los elmentos de la lista */
void ListaST_Final(TListaST *L){
    TNodo *ptr_rec;
    ptr_rec = L->inicio;
    while (ptr_rec != NULL){
        L->inicio = L->inicio->sig;
        free(ptr_rec);
        ptr_rec = L->inicio;
    }
}

/* Inserta un nuevo elemento en la lista */
void ListaST_Insert(TListaST *L, TKey k, TValue v){
    TNodo *ptr_nuevo;
    ptr_nuevo = malloc(sizeof(TNodo));
    
    if (ptr_nuevo!=NULL){
        //Verificar si la llave ya existe en la lista
        TNodo *ptr_rec;
        ptr_rec = L->inicio;
        int encontro = 0;
        while (ptr_rec != NULL && !encontro){
            if (strcmp(ptr_rec->key, k) == 0){
                //Si la llave existe, actualizar el valor
                ptr_rec->value = v;
                encontro = 1;
            }
            ptr_rec = ptr_rec->sig;
        }
        //Si no lo encontró, añadir el nuevo nodo
        if (!encontro){
            //Inicializar los miembros del nuevo nodo
            ptr_nuevo->key = malloc(strlen(k)*sizeof(char));
            strcpy(ptr_nuevo->key, k);
            ptr_nuevo->value = v;
            ptr_nuevo->sig = NULL;
            // Insertar el nuevo nodo al final de la lista
            if (L->inicio == NULL)
                L->inicio = ptr_nuevo;
            else
                L->fin->sig = ptr_nuevo;
            L->fin = ptr_nuevo;
            // Actualizar el tamaño de la lista
            (L->numElem)++;
            }
    }
}

/* Elimina un elemento de la lista */
void ListaST_Delete(TListaST *L, TKey k){
    TNodo *ptr_rec, *ptr_ant;
    int termino = 0;
    ptr_rec = L->inicio;
    while (ptr_rec != NULL && !termino){
        if (ptr_rec->key == k){
            // Verificar si estoy al inicio
            if (ptr_rec == L->inicio)
                L->inicio = L->inicio->sig;
            else
                // Verificar si estoy en el final
                if (ptr_rec == L->fin){
                    L->fin = ptr_ant;
                    L->fin->sig = NULL;
                }else
                    // Si estoy en un nodo intermedio
                    ptr_ant->sig = ptr_rec->sig;
            // Eliminar el nodo
            free(ptr_rec);
            termino = 1;
            // Actualizar el número de elementos
            (L->numElem)--;        
        }else{
            ptr_ant = ptr_rec;
            ptr_rec = ptr_rec->sig;
        }
    }
}

/* Obtiene el número de elementos de la lista*/
int ListaST_Size(TListaST *L){
    return L->numElem;
}

/* Imprime los elementos de la lista */
void ListaST_Print(TListaST *L){
    TNodo *ptr_rec;
    ptr_rec = L->inicio;
    while (ptr_rec!=NULL){
        printf("-> (%s, %d) ", ptr_rec->key, ptr_rec->value);
        ptr_rec = ptr_rec->sig;
    }
}

TValue ListaST_Search(TListaST *L, TKey k){
    TNodo *ptr_rec;
    ptr_rec = L->inicio;
    while (ptr_rec!=NULL){
        if (ptr_rec->key == k)
            return ptr_rec->value;
        ptr_rec = ptr_rec->sig;
    }
    return -1;
}