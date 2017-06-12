#include <stdio.h>

#define W 5
#define N 4
#define max(a, b) ((a) > (b)) ? (a) : (b)

int mochila(int w[N], int v[N]){
	int dp[N+1][W+1] = {{}};

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= W; j++){
			if(w[i-1] - j > 0) // Si supera
				dp[i][j] = dp[i-1][j];
			else {
				dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
			}
		}
	}

	return dp[N][W];
}

int main(){
	int w[N] = {2, 1, 3, 2};
	int v[N] = {12, 10, 20, 15};

	int valor = mochila(w, v);

	printf("El valor maximo de la mochila es: %d\n", valor);

	return 0;
}
