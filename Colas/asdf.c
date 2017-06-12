#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int TElemento;

typedef struct nodo{
	TElemento info;
	struct nodo *sig;
} TNodo;

typedef struct pila{
	TNodo *top;
} TPila;

void pila_crear(TPila *P){
	P -> top = NULL;
}

int pila_vacia(TPila *P){
	return (P -> top == NULL);
}

void pila_apilar(TPila *P, TElemento e){
	TNodo *new = malloc(sizeof(TNodo));
	if(new){
		new -> info = e;
		new -> sig = P -> top;
		P -> top = new;
	}
}

TElemento pila_desapilar(TPila *P){
	if(!pila_vacia(P)){
		TNodo *act = P -> top;
		TElemento info = act -> info;
		P -> top = act -> sig;
		free(act);
		return info;
	}
	else return -1;
}

void pila_finalizar(TPila *P){
	while(!pila_vacia(P))
		pila_desapilar(P);
}

TElemento pila_tope(TPila *P){
	if(!pila_vacia(P))
		return P -> top -> info;
	return -1;
}

int pila_parenthesis(char *s){
	if(s[0] == ']' || s[0] == ')') return 0;
	if(strlen(s) == 0) return 1;
	
	TPila P;
	pila_crear(&P);
	int len = strlen(s);
	
	int i;
	for(i = 0; i < len; i++){
		switch(s[i]){
			case ']':
				if(pila_tope(&P) == '[') pila_desapilar(&P);
				else return 0;
				break;
			case ')':
				if(pila_tope(&P) == '(') pila_desapilar(&P);
				else return 0;
				break;
			default:
				pila_apilar(&P, s[i]);
				break;
		}
	}
	
	return pila_vacia(&P);
}

int main(){
	int tc;
	scanf("%d", &tc);
	int i;
	char *a;
	fg;
	for(i = 0; i < tc; i++){
		char *s;
		fgets(s, sizeof s, stdin);
		int ans = pila_parenthesis(s);
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}