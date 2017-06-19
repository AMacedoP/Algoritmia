#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>


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

void Grafo_insertarArista(TGrafo *grafo, TElemento elem1, TElemento elem2, double peso){
    if (Grafo_existeVertice(grafo, elem1) && Grafo_existeVertice(grafo, elem2)){ 
        TVertice *ptrRec = grafo->inicio;
        while(ptrRec){
            if (ptrRec->info ==  elem1){
                if (!Lista_EstaEnLista(ptrRec->lstAdyacentes, elem2))
                    Lista_Insertar(&ptrRec->lstAdyacentes, elem2, peso);
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

TLista *ObtenerAdyacentes(TGrafo *grafo, TElemento elem){
    TVertice *ptrRec = grafo->inicio;
    while(ptrRec){
        if (ptrRec->info == elem){
            return &(ptrRec->lstAdyacentes);
        }
        ptrRec = ptrRec->sig;
    }
}

int ObtenerMinimoNoVisitado(TGrafo *grafo,int *arrVisitados, double *arrDistMin){
    int i, indMin; double minDist = DBL_MAX;
    for (i = 0; i < grafo->numVertices; i++){
        if (arrVisitados[i] == 0 && arrDistMin[i] < minDist){
            minDist = arrDistMin[i];
            indMin = i;
        }
    }
    return indMin;
}

void Grafo_imprimirCaminosMasCortos(TGrafo *grafo, TElemento vertInicial){
    int *arrPadres = malloc(grafo->numVertices*sizeof(int));
    int *arrVisitados = malloc(grafo->numVertices*sizeof(int));
    double *arrDistMin = malloc(grafo->numVertices*sizeof(double));
    
    int i;
    for (i = 0; i < grafo->numVertices; i++){
        arrPadres[i] = -1;
        arrVisitados[i] = 0;
        arrDistMin[i] = DBL_MAX;
    }
    // Obtener el índice que le corresponde al elemento
    arrDistMin[vertInicial-1] = 0;
    
    int indMin; TLista *lstAdyacentes;
    for (i=0; i < grafo->numVertices; i++){
        //Encontrar el mínimo de los no visitados
        indMin = ObtenerMinimoNoVisitado(grafo, arrVisitados, arrDistMin); 
        arrVisitados[indMin] = 1;
        lstAdyacentes = ObtenerAdyacentes(grafo, indMin + 1);
        TNodo *ptrNodo = lstAdyacentes->inicio;
        while (ptrNodo){
            if (arrVisitados[ptrNodo->elem - 1] == 0)
                if ( arrDistMin[ptrNodo->elem - 1] > arrDistMin[indMin] + ptrNodo->peso){
                    arrDistMin[ptrNodo->elem - 1] = arrDistMin[indMin] + ptrNodo->peso;
                    arrPadres[ptrNodo->elem - 1] = indMin;
                }
            ptrNodo = ptrNodo->sig;
        }
    }
    // Imprimir las distancias minimas y los padres
    for (i=0; i<grafo->numVertices; i++){
        printf("%d : %lf\n", i + 1, arrDistMin[i]);
    }
    
    free(arrPadres);
    free(arrVisitados);
    free(arrDistMin);
}