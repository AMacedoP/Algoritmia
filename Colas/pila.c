#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pila.h"

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

TElemento pila_postfija(char *s){
	int len = strlen(s);
	TPila P;
	pila_crear(&P);
	
	for(int i = 0; i < len; i++){
		if(isdigit(s[i]))
			pila_apilar(&P, s[i] - '0');
		else{
			int num2 = pila_desapilar(&P);
			int num1 = pila_desapilar(&P);
			int res;
			switch(s[i]){
				case '+':
					res = num1 + num2;
					break;
				case '-':
					res = num1 - num2;
					break;
				case '*':
					res = num1 * num2;
					break;
				case '/':
					res = num1 / num2;
					break;
			}
			pila_apilar(&P, res);
		}
	}
	return pila_desapilar(&P);
}

int pila_parenthesis(char *s){
	if(s[0] == ']' || s[0] == ')') return 0;
	
	TPila P;
	pila_crear(&P);
	int len = strlen(s);
	
	for(int i = 0; i < len; i++){
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