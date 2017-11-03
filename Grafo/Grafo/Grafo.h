/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 * Author: fernandoalva
 *
 * Created on June 8, 2016, 3:35 PM
 */

#ifndef GRAFO_H
#define GRAFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Lista.h"
    
    typedef struct vertice{
        TElemento info;
        TLista lstAdyacentes;
        struct vertice *sig;
    }TVertice;
    
    
    typedef struct grafo{
        int numVertices;
        TVertice *inicio;
        TVertice *fin;
    }TGrafo;
   
    
    void Grafo_init(TGrafo *grafo);
    void Grafo_insertarVertice(TGrafo *grafo, TElemento elem);
    void Grafo_insertarArista(TGrafo *grafo, TElemento elem1, TElemento elem2);
    void Grafo_eliminarVertice(TGrafo *grafo, TElemento elem);
    void Grafo_eliminarArista(TGrafo *grafo, TElemento elem1, TElemento elem2);
    void Grafo_imprimirGrafo(TGrafo *grafo);
    void Grafo_finalizar(TGrafo *grafo);
    
#ifdef __cplusplus
}
#endif

#endif /* GRAFO_H */

