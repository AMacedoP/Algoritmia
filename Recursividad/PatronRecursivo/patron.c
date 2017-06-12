/* Se usa recursividad porque se cumple un patron que se reduce
 * a la mitad */

#include <stdio.h>

void patron(int n, int i){ // n es la base e i el desplazamiento
	if(n > 0){
		patron(n/2, i);
		for(int d = 0; d < i; d++) printf(" ");
		for(int d = 0; d < n; d++) printf("*");
		printf("\n");
		patron(n/2, i + n/2);
	}	
}

int main(){
	int n, i, tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d", &n, &i);
		patron(n, i);
	}
	return 0;
}
