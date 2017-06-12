#include <stdio.h>
#include <limits.h>
#define MAX 25

int main(){
	int t, h, r, T[MAX], H[MAX], R[MAX];
	int TR[MAX][MAX], HT[MAX][MAX], RH[MAX][MAX];

	while(scanf("%d %d %d", &t, &h, &r) == 3){
		for(int i = 0; i < t; i++){
			scanf("%d", &T[i]);
			for(int j = 0; j < r; j++){
				scanf("%d", &TR[i][j]);
			}			
		}

		for(int i = 0; i < r; i++){
			scanf("%d", &R[i]);
			for(int j = 0; j < h; j++){
				scanf("%d", &RH[i][j]);
			}			
		}

		for(int i = 0; i < h; i++){
			scanf("%d", &H[i]);
			for(int j = 0; j < t; j++){
				scanf("%d", &HT[i][j]);
			}			
		}

		int min = INT_MAX, tM, rM, hM;

		for(int i = 0; i < t; i++){
			for(int j = 0; j < h; j++){
				for(int k = 0; k < r; k++){
					if(TR[i][k] == 0 && RH[k][j] == 0 && HT[j][i] == 0){
						int suma = T[i] + H[j] + R[k];
						if(suma < min){
							min = suma;
							tM = i;
							hM = j;
							rM = k;
						}
					}
				}
			}
		}

		if(min != INT_MAX) printf("%d %d %d : %d\n", tM, rM, hM, min);
		else printf("No te cases!\n");
	}

	return 0;
}
