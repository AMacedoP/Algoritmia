#include <stdio.h>
#define MAX 100

int bbr(int v[MAX],int key,int ini,int fin){
	
	if(ini<=fin){
		int m=(ini+fin)/2;
		if(v[m]==key) return m;
		if(v[ini]<v[m]){
			if(key>=v[ini]&&key<=v[m]) return bbr(v,key,ini,m);
			else return bbr(v,key,m+1,fin);	
		}else{
			if(key>=v[m]&&key<=v[fin]) return bbr(v,key,m+1,fin);
			else return bbr(v,key,ini,m-1);	
		}
	}
	return -1;
}

int main(){
 	int a[]={6,9,10,1,2,3};
 	int key = 9;
 	int pos = bbr(a,key,0,5);
 	printf("Posición: %d\n",pos);
}
