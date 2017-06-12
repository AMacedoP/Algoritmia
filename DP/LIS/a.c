#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? a : b

int LIS[50];
int input[50];

int hallarLIS(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(input[i] > input[j]) LIS[i] = LIS[j] + 1;
		}
	}

	int max = 0;
	for(int i = 0; i < n; i++){
		if(max < LIS[i]) max = LIS[i];
	}

	return max;
}

int main(){
	int numbers;
	scanf("%d", &numbers);
	for(int i = 0; i < numbers; i++) scanf("%d", &input[i]);
	for(int i = 0; i < numbers; i++) LIS[i] = 1;
	int ans = hallarLIS(numbers);
	for(int i = 0; i < numbers; i++) printf("%d ", LIS[i]);
	printf("\n");
	printf("El LIS max es: %d\n", ans);
	return 0;
}
