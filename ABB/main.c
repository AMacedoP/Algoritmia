#include <stdio.h>
#include "abb.h"

int main(){
	TABB T;
	abb_iniciar(&T);
	
	abb_insertar(&T, 6);
	abb_insertar(&T, 5);
	abb_insertar(&T, 8);
	abb_insertar(&T, 7);
	
	abb_imprimir(&T, 1);
	printf("\n");
	
	abb_imprimir(&T, 2);
	printf("\n");
	
	abb_imprimir(&T, 3);
	printf("\n");
	
	printf("Numero de nodos: %d\n", abb_contar(&T));

	printf("%d\n", esABB(&T));
	return 0;
}