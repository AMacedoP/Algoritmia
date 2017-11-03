#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main() {
    TLista L;
    
    Lista_Crear(&L);
    
    Lista_Insertar(&L, 1);
    Lista_Insertar(&L, 2);
    Lista_Insertar(&L, 3);
    Lista_Insertar(&L, 4);
    Lista_Insertar(&L, 5);
    
    printf("La lista tiene %d elementos\n", Lista_Tamanho(L));
    
    Lista_Imprimir(L);
    
    Lista_Eliminar(&L, 5);
    Lista_Imprimir(L);
    
    Lista_Eliminar(&L, 1);
    Lista_Imprimir(L);
    
    Lista_Eliminar(&L, 3);
    Lista_Imprimir(L);
    
    Lista_Eliminar(&L, 2);
    Lista_Imprimir(L);
    
    Lista_Eliminar(&L, 4);
    Lista_Imprimir(L);
    
    return (EXIT_SUCCESS);
}