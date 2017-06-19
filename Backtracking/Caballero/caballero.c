#include <stdio.h>
#define MAX 10

int MOVX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int MOVY[] = {1, 2, 2, 1, -1, -2, -2, -1};

int es_valido(int A[MAX][MAX], int x, int y, int tam){
	int v1 = (A[x][y] == 0);
	int v2 = (x >= 0 && x < tam);
	int v3 = (y >= 0 && y < tam);
	return v1 && v2 && v3;
}

int caballero(int A[MAX][MAX], int x, int y, int n, int movs){
	if(movs == n*n+1) return 1;

	for(int i = 0; i < 8; i++){
		int newX = x + MOVX[i];
		int newY = y + MOVY[i];

		if(es_valido(A, newX, newY, n)){
			A[newX][newY] = movs;
			if(caballero(A, newX, newY, n, movs+1)) return 1;
			A[newX][newY] = 0; // Deshacer el cambio
		}
	}
	
	return 0;
}

void imprimir_tablero(int A[MAX][MAX], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int A[MAX][MAX], n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) A[i][j] = 0;
	}	
	
	A[0][0] = 1;
	int ans = caballero(A, 0, 0, n, 2);

	if(ans) imprimir_tablero(A, n);
	else printf("No se pudo\n");
	return 0;
}