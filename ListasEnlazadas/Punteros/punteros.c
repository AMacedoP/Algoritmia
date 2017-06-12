#include <stdio.h>
#include <stdlib.h>

int main(){
	int *vector;
	int tam;
	printf("Ingresar el size de la lista: ");
	scanf("%d", &tam);
	vector = malloc(sizeof(int)*tam); // Reservamos memoria
	for(int i = 0; i < tam; i++)
		vector[i] = i;
	for(int i = 0; i < tam; i++)
		printf("%d\n", vector[i]);
	return 0;
}
