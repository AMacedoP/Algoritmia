#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void abb_iniciar(TABB * T){
	T -> raiz = NULL;
}

void abb_insertar_nodo(TNodo *S, TNodo *N){
	if (S -> info < N -> info){
		if(S -> der == NULL)
			S -> der = N;
		else
			abb_insertar_nodo(S -> der, N);
	}
	else if(S -> info > N -> info){
		if(S -> izq == NULL)
			S -> izq = N;
		else
			abb_insertar_nodo(S -> izq, N);
	}
	else return;
}

void abb_insertar(TABB *T, TElemento e){
	TNodo *nuevo = malloc(sizeof(TNodo));
	if(nuevo){
		nuevo -> info = e;
		nuevo -> izq = NULL;
		nuevo -> der = NULL;
		if(T -> raiz == NULL){
			T -> raiz = nuevo;
		}
		else 
			abb_insertar_nodo(T -> raiz, nuevo);
	}		
}

void abb_preorder(TNodo *T){
	if(T != NULL){
		printf("%d ", T -> info);
		abb_preorder(T -> izq);
		abb_preorder(T -> der);
	}
}

void abb_inorder(TNodo *T){
	if(T != NULL){
		abb_inorder(T -> izq);
		printf("%d ", T -> info);
		abb_inorder(T -> der);
	}
}

void abb_postorder(TNodo *T){
	if(T != NULL){
		abb_postorder(T -> izq);
		abb_postorder(T -> der);
		printf("%d ", T -> info);
	}
}

void abb_imprimir(TABB *T, int modo){
	switch(modo){
		case 1: abb_preorder(T -> raiz); break;
		case 2: abb_inorder(T -> raiz); break;
		case 3: abb_postorder(T -> raiz); break;
	}
}

int abb_contarNodos(TNodo *N){
	if(N == NULL) return 0;
	return 1 + abb_contarNodos(N -> izq) + abb_contarNodos(N -> der);
}

int abb_contar(TABB *T){
	return abb_contarNodos(T -> raiz);
}

int cumple(TNodo *N){
	if(N != NULL){
		if(N -> der != NULL){
			if(N -> der -> info < N -> info) return 0;
		}
		if(N -> izq != NULL){
			if(N -> izq -> info > N -> info) return 0;
		}
		return cumple(N -> der) && (N -> izq);
	}
	return 1;
}

int esABB(TABB *T){
	return cumple(T -> raiz);
}