#include <stdio.h>
#define N 50

void print(int v[N], int nM){
	for(int i = 0; i <= nM; i++) printf("%d\t", v[i]);
	printf("\n");
}

int esValido(int m[N][N], int v[N], int nV, int nodo){
	for(int i = 0; i < nV; i++)
		if(v[i] == nodo) return 0; // Si ya esta en el vector es invalido

	if(m[v[nV-1]][nodo] == 1) return 1;
	return 0;
}

int hamil(int m[N][N], int v[N], int nM, int nV){
	if(nV == nM){ // Caso base
		if(m[v[nV-1]][v[0]] == 1){
			v[nV] = v[0];
			return 1;
		}
		else return 0;
	}

	for(int nodo = 0; nodo < nM;nodo++){
		if(esValido(m, v, nV, nodo)){
			v[nV] = nodo;
			nV++;
			if(hamil(m, v, nM, nV)) return 1;
			nV--; // Deshaciendo la operacion anterior
			v[nV] = -1;
		}		
	}
	return 0;
}

int main(){
	int m[N][N] = {{0,1,0,1}, {0,0,1,0}, {0,0,0,1}, {1,0,1,0}};
	int n = 4;
	int v[N] = {-1, -1, -1, -1};
	for(int i = 0; i < n; i++){ // Probar todos los posibles
		v[0] = i;
		if(hamil(m, v, n, 1)){
			print(v, n);
			break;
		}		
	}
	return 0;	
}
