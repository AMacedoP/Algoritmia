/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

void Grafo_init(TGrafo *grafo){
    grafo->numVertices = 0;
    grafo->inicio = NULL;
    grafo->fin = NULL;
}

int Grafo_existeVertice(TGrafo *grafo, TElemento elem){
    TVertice *ptrRec = grafo->inicio;
    while(ptrRec){
        if (ptrRec->info == elem) return 1;
        ptrRec = ptrRec->sig;
    }
    return 0;
}

void Grafo_insertarVertice(TGrafo *grafo, TElemento elem){
    if (!Grafo_existeVertice(grafo, elem)){
        TVertice *ptrNuevoVert = malloc(sizeof(TVertice));
        if (ptrNuevoVert){
            ptrNuevoVert->info = elem;
            Lista_Crear(&ptrNuevoVert->lstAdyacentes);
            ptrNuevoVert->sig = grafo->inicio;

            grafo->inicio= ptrNuevoVert;
            if (grafo->numVertices == 0)
                grafo->fin = ptrNuevoVert;
            grafo->numVertices++;
        }
    }
}

void Grafo_insertarArista(TGrafo *grafo, TElemento elem1, TElemento elem2){
    if (Grafo_existeVertice(grafo, elem1) && Grafo_existeVertice(grafo, elem2)){ 
        TVertice *ptrRec = grafo->inicio;
        while(ptrRec){
            if (ptrRec->info ==  elem1){
                if (!Lista_EstaEnLista(ptrRec->lstAdyacentes, elem2))
                    Lista_Insertar(&ptrRec->lstAdyacentes, elem2);
                break;
            }
            ptrRec = ptrRec->sig;
        }
    }
}

void Grafo_eliminarVertice(TGrafo *grafo, TElemento elem){
    
}

void Grafo_eliminarArista(TGrafo *grafo, TElemento elem1, TElemento elem2){
    
}

void Grafo_imprimirGrafo(TGrafo *grafo){
    TVertice *ptrRec = grafo->inicio;
    while (ptrRec){
        printf("%d: ", ptrRec->info);
        Lista_Imprimir(ptrRec->lstAdyacentes);
        ptrRec = ptrRec->sig;
    }
}

void Grafo_finalizar(TGrafo *grafo){
    
}