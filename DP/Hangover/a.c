#include <stdio.h>

double cards[10000];

void llenarTabla(){
	double a = 0;
	int i = 2;
	while(a < 5.20){
		a = cards[i-1] + 1.0/(i+1);
		cards[i] = a;
		i++;
	}
}

int hallarCards(double n){
	double now = cards[1];
	int i = 1;
	while(now < n){
		i++;
		now = cards[i];
	}

	return i;
}

int main(){
	cards[1] = 0.5;
	llenarTabla();
	double n;
	scanf("%lf", &n);
	while(n != 0.0){
		int numCards = hallarCards(n);
		printf("%d card(s)\n", numCards);
		scanf("%lf", &n);
	}
	return 0;
}
