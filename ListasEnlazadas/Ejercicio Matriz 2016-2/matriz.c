#include <stdio.h>
#include <stdlib.h>

/* Declaracion de lista */
typedef struct nodoL{
	int val;
	struct nodoL *sig;
} TNodoL;


typedef struct lista{
	TNodoL *ini;
	TNodoL *fin;
} TLista;

/* Funciones de lista */
void crearLista(TLista *L){
	L -> ini = NULL;
	L -> fin = NULL;
}

int listaVacia(TLista *L){
	return L -> ini == NULL;
}

void insertarEnLista(TLista *L, int e){
	TNodoL *nodo = malloc(sizeof(TNodoL));
	if(nodo){
		nodo -> val = e;
		nodo -> sig = NULL;
		if(listaVacia(L))
			L -> ini = L -> fin = nodo;
		else{
			L -> fin -> sig = nodo;
			L -> fin = nodo;			
		}
	}
}

void imprimirLista(TLista *L){
	TNodoL *nodo = L -> ini;
	while(nodo != NULL){
		printf("%d ", nodo -> val);
		nodo = nodo -> sig;
	}
	printf("\n");
}

/* Declaracion de matriz */
typedef struct nodoM{
	int val;
	struct nodoM *der;
	struct nodoM *abajo;	
} TNodoM;

typedef struct matriz{
	TNodoM *ini;
	TNodoM *lastCol;
	TNodoM *lastRow;
} TMatriz;

/* Funciones de matriz */
void crearMatriz(TMatriz *M){
	M -> ini = NULL;
	M -> lastCol = NULL;
	M -> lastRow = NULL;
}

void addColumn(TMatriz *M, TLista *L){
	TNodoL *nodoL = L -> ini;
	TNodoM *lastColAnt = M -> lastCol;
	if(lastColAnt) M -> lastCol = M -> lastCol -> der;
	TNodoM *lastColNew;
	
	while(nodoL != NULL){
		TNodoM *nuevo = malloc(sizeof(TNodoM));
		nuevo -> val = nodoL -> val;
		nuevo -> der = NULL;
		nuevo -> abajo = NULL;
		if(M -> ini == M -> lastCol){
			if(M -> ini == NULL)
				M -> ini = M -> lastCol = M -> lastRow = nuevo;
			else{
				M -> lastRow -> abajo = nuevo;
				M -> lastRow = nuevo;
			}
		}
		else{
			if(M -> lastCol == NULL){
				M -> lastCol = nuevo;
				lastColNew = M -> lastCol;
			}
			else{
				lastColNew -> abajo = nuevo;
				lastColNew = nuevo;
			}
			lastColAnt -> der = nuevo;
			lastColAnt = lastColAnt -> abajo;
		}
		nodoL = nodoL -> sig;
	}
}

void addRow(TMatriz *M, TLista *L){
	TNodoL *nodoL = L -> ini;
	TNodoM *lastRowAnt = M -> lastRow;
	if(lastRowAnt) M -> lastRow = M -> lastRow -> abajo;
	TNodoM *lastRowNew;
	
	while(nodoL != NULL){
		TNodoM *nuevo = malloc(sizeof(TNodoM));
		nuevo -> val = nodoL -> val;
		nuevo -> der = NULL;
		nuevo -> abajo = NULL;
		if(M -> ini == M -> lastRow){
			if(M -> ini == NULL)
				M -> ini = M -> lastRow = M -> lastCol = nuevo;
			else{
				M -> lastCol -> der = nuevo;
				M -> lastCol = nuevo;
			}
		}
		else{
			if(M -> lastRow == NULL){
				M -> lastRow = nuevo;
				lastRowNew = M -> lastRow;
			}
			else{
				lastRowNew -> der = nuevo;
				lastRowNew = nuevo;
			}
			lastRowAnt -> abajo = nuevo;
			lastRowAnt = lastRowAnt -> der;
		}
		nodoL = nodoL -> sig;
	}
}

void deleteColumn(TMatriz *M, int i){
	// Iteras con dos 2 nodos a la posicion indicada y cambias punteros.
	// Si es el inicio o el final hay que cambiar los punteros de la matriz
}

void deleteRow(TMatriz *M, int i){
	// Iteras con dos 2 nodos a la posicion indicada y cambias punteros.
	// Si es el inicio o el final hay que cambiar los punteros de la matriz	
}

void transpose(TMatriz *M, TMatriz *T){
    TNodoM *col = M -> ini;
    TNodoM *fil = M -> ini;
    while(fil != NULL){
		TLista L;
		crearLista(&L);
        while(col != NULL){
            insertarEnLista(&L, col -> val);
            col = col -> der;
        }
        addColumn(T, &L);
        fil = fil -> abajo;
        col = fil;
    }
}

void print(TMatriz *M){
	TNodoM *col = M -> ini;
	TNodoM *fil = M -> ini;
	while(fil != NULL){
		while(col != NULL){
			printf("%d ", col -> val);
			col = col -> der;
		}
		printf("\n");
		fil = fil -> abajo;
		col = fil;
	}
}

int main(){
	TLista L;
	crearLista(&L);
	insertarEnLista(&L, 3);
	insertarEnLista(&L, 2);
	insertarEnLista(&L, 4);
	insertarEnLista(&L, 6);
	
	TLista K;
	crearLista(&K);
	insertarEnLista(&K, 1);
	insertarEnLista(&K, 2);
	
	TLista N;
	crearLista(&N);
	insertarEnLista(&N, 4);
	insertarEnLista(&N, 0);
	insertarEnLista(&N, 1);
	insertarEnLista(&N, 6);
	insertarEnLista(&N, 9);
	
	TMatriz M;
	crearMatriz(&M);
	addColumn(&M, &L);
	addColumn(&M, &L);
	addRow(&M, &K);
	addColumn(&M, &N);
	print(&M);
	printf("\n");
	
	TMatriz T;
	crearMatriz(&T);
	transpose(&M, &T);
	print(&T);
	return 0;
}