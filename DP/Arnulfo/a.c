#include <stdio.h>

int n, m;
int mat[50][50];

int coinRow(int c){
	if(c == 0) return 		
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);

	int ans = hallarMax();
	return 0;
}
