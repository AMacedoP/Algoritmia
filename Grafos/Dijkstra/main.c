#include <stdio.h>
#include <stdlib.h>

#include "Grafo.h"

int main() {
    TGrafo grafo;
    
    Grafo_init(&grafo);
    
    Grafo_insertarVertice(&grafo, 1);
    Grafo_insertarVertice(&grafo, 2);
    Grafo_insertarVertice(&grafo, 3);
    Grafo_insertarVertice(&grafo, 4);
    Grafo_insertarVertice(&grafo, 5);
/*
    Grafo_insertarVertice(&grafo, 6);
*/
    
/*
    Grafo_insertarArista(&grafo, 1, 3);
    Grafo_insertarArista(&grafo, 3, 5);
    Grafo_insertarArista(&grafo, 5, 3);
    Grafo_insertarArista(&grafo, 2, 3);
    Grafo_insertarArista(&grafo, 2, 6);
    Grafo_insertarArista(&grafo, 5, 6);
    Grafo_insertarArista(&grafo, 4, 1);
    Grafo_insertarArista(&grafo, 4, 5);
*/
    
    Grafo_insertarArista(&grafo, 1, 2, 3.0);
    Grafo_insertarArista(&grafo, 2, 1, 3.0);
    
    Grafo_insertarArista(&grafo, 1, 4, 7.0);
    Grafo_insertarArista(&grafo, 4, 1, 7.0);
    
    Grafo_insertarArista(&grafo, 2, 3, 4.0);
    Grafo_insertarArista(&grafo, 3, 2, 4.0);
    
    Grafo_insertarArista(&grafo, 2, 4, 2.0);
    Grafo_insertarArista(&grafo, 4, 2, 2.0);
    
    Grafo_insertarArista(&grafo, 3, 4, 5.0);
    Grafo_insertarArista(&grafo, 4, 3, 5.0);
    
    Grafo_insertarArista(&grafo, 3, 5, 6.0);
    Grafo_insertarArista(&grafo, 5, 3, 6.0);
    
    Grafo_insertarArista(&grafo, 4, 5, 4.0);
    Grafo_insertarArista(&grafo, 5, 4, 4.0);
    
    Grafo_imprimirGrafo(&grafo);
    
    Grafo_imprimirCaminosMasCortos(&grafo, 1);
    
    return 0;
}