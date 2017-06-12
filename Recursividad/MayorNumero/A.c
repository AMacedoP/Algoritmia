#include <stdio.h>
#define max(a, b) ((a) > (b))? a:b
#define MAX 10 

int recurArr(int a[], int n){
	if(n == 1) return a[n-1];
	return max(a[n-1], recurArr(a, n-1));
}

int main(){
	int n = 4;
	int a[] = {1, 4, 6, 2};
	int q = recurArr(a, n);
	printf("%d\n", q);
	return 0;
}