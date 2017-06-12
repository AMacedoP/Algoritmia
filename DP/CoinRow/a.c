#include <stdio.h>
#define max(a, b) ((a) > (b))? (a) : (b)

int coins[100];
int MAX[100];

int findMaxSel(int nCoins){
	if(nCoins == 0) return MAX[0];
	if(nCoins == 1) return MAX[1] = max(coins[0], coins[1]);
	return MAX[nCoins] = max(coins[nCoins] + findMaxSel(nCoins-2), findMaxSel(nCoins-1));
}

int main(){
	int nCoins;
	scanf("%d", &nCoins);
	for(int i = 0; i < nCoins; i++){
		scanf("%d", &coins[i]);
	}
	
	MAX[0] = coins[0];
	int maxSel = findMaxSel(nCoins);

	printf("%d\n", maxSel);
	return 0;
}
