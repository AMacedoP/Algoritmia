#include <stdio.h>

void D2B(int n){
	if (n == 0) return;
	D2B(n/2);
	printf("%d", n%2);
}

int main(){
	D2B(10);
	printf("\n");
	return 0;
}