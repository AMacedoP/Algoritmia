#include "Lista.h"
    
typedef struct vertice{
    TElemento info;
    TLista lstAdyacentes;
    struct vertice *sig;
} TVertice;


typedef struct grafo{
    int numVertices;
    TVertice *inicio;
    TVertice *fin;
} TGrafo;


void Grafo_init(TGrafo *grafo);
void Grafo_insertarVertice(TGrafo *grafo, TElemento elem);
void Grafo_insertarArista(TGrafo *grafo, TElemento elem1, TElemento elem2, double peso);
void Grafo_eliminarVertice(TGrafo *grafo, TElemento elem);
void Grafo_eliminarArista(TGrafo *grafo, TElemento elem1, TElemento elem2);
void Grafo_imprimirGrafo(TGrafo *grafo);
void Grafo_finalizar(TGrafo *grafo);
void Grafo_imprimirCaminosMasCortos(TGrafo *grafo, TElemento elem);
