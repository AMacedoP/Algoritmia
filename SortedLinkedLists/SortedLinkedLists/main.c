/* 
 * File:   main.c
 * Author: Fernando Alva Manchego
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void demo_insertarEnListaOrdenada(){
    TLista L;

    Lista_init(&L);
    
    Lista_insertarEnOrden(&L, 5);
    Lista_insertarEnOrden(&L, 1);
    Lista_insertarEnOrden(&L, 10);
    Lista_insertarEnOrden(&L, 9);
    Lista_insertarEnOrden(&L, 4);
    Lista_insertarEnOrden(&L, 10);
    
    Lista_imprimir(&L);
}

/*
void demo_unirListasOrdenadas(){
    TLista L1, L2;
    Lista_crear(&L1);
    Lista_crear(&L2);
    
    Lista_insertarEnOrden(&L1, 5);
    Lista_insertarEnOrden(&L1, 10);
    Lista_insertarEnOrden(&L1, 15);
    printf("Lista 1:\n");
    Lista_imprimir(&L1);
    
    Lista_insertarEnOrden(&L2, 2);
    Lista_insertarEnOrden(&L2, 3);
    Lista_insertarEnOrden(&L2, 20);
    printf("Lista 2:\n");
    Lista_imprimir(&L2);
    
    TLista L3 = Lista_mergeListas(&L1, &L2);
    printf("Lista Unión:\n");
    Lista_imprimir(&L3);
}
 */


int main(int argc, char** argv) {
    demo_insertarEnListaOrdenada();
    //demo_unirListasOrdenadas();
    
    return (EXIT_SUCCESS);
}

