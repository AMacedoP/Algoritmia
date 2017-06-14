#include <iostream>
#include "ll.h"

using namespace std;

int main(){
	LL A;
	A.imprimir();
	cout << A.getSize() << endl;
	A.insertarValor(3);
	A.insertarValor(4);
	A.imprimir();
	cout << A.getSize() << endl;
	return 0;
}