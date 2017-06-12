#include <stdio.h>
#include "pila.h"

int main(){
	TPila P;
	pila_crear(&P);
	pila_apilar(&P, 4);
	pila_apilar(&P, 1);
	pila_apilar(&P, 8);
	
	while(!pila_vacia(&P)){
		printf("Desapiló: %d\n", pila_desapilar(&P));
	}
	
	// Notacion postfija
	printf("\n");
	char *s = "34+78*-";
	printf("%d\n", pila_postfija(s));
	printf("\n");
	
	// Parenthesis balance
	char *par = "()[]()[(([]()[]))](())()";
	printf("%d\n", pila_parenthesis(par));
	return 0;
}