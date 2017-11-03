/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: fernandoalva
 *
 * Created on June 8, 2016, 3:33 PM
 */

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
    Grafo_insertarVertice(&grafo, 6);
    
    Grafo_insertarArista(&grafo, 1, 3);
    Grafo_insertarArista(&grafo, 3, 5);
    Grafo_insertarArista(&grafo, 5, 3);
    Grafo_insertarArista(&grafo, 2, 3);
    Grafo_insertarArista(&grafo, 2, 6);
    Grafo_insertarArista(&grafo, 5, 6);
    Grafo_insertarArista(&grafo, 4, 1);
    Grafo_insertarArista(&grafo, 4, 5);
    
    Grafo_imprimirGrafo(&grafo);
    
    return (EXIT_SUCCESS);
}

