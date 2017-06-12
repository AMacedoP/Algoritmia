#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int items, expectedW;
int W[50], V[50], dp[50][50];

int knapsack(int id, int w){
	printf("%d %d\n", id, w);
	if(id == items || w == 0) return 0;
	if(dp[id][w] != -1) return dp[id][w];
	
	if(W[id] > w) return dp[id][w] = knapsack(id + 1, w);

	if(W[id] <= w)
		return dp[id][w] = max(knapsack(id + 1, w), V[id] + knapsack(id + 1, w - W[id]));
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &items, &expectedW);
	for(int i = 0; i < items; i++)
		scanf("%d %d", &W[i], &V[i]);
	int ans = knapsack(0, expectedW);

	for(int i = 0; i < expectedW + 2; i++){
		for(int j = 0; j < expectedW + 2; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Knapsack: %d\n", ans);
	return 0;
}
