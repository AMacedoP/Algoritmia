#include <stdio.h>
#include <string.h>

int verifPalin(char cad[], int i, int j){
	if (j <= i) return 1;
	if (cad[i] == cad[j]) return verifPalin(cad, i+1, j-1);
	else return 0;
}

int main(){
	char c[] = "level";
	int i = 0, j = strlen(c);
	int ans = verifPalin(c, i, j-1);
	printf("%d\n", ans);
	return 0;
}