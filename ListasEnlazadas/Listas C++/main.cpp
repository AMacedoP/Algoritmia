#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
	public:
		Node *sig;
		int value;
		void set_value(int);
};

void Node::set_value(int x){
	value = x;
	sig = NULL;
}

class LL{
	Node *ini;
	Node *fin;
	int size;
	
	public:
		LL(){
			ini = NULL;
			fin = NULL;
			size = 0;		
		};
		
		void insertarNodo(int);
		void imprimir();
		int getSize();
		int estaVacio();
		void eliminarNodo(int);
		int estaElemento(int);
};

void LL::insertarNodo(int x){
	Node *nodo;
	nodo = (Node *)malloc(sizeof(Node));
	nodo -> set_value(x);
	
	if(size == 0){
		ini = nodo;
		fin = nodo;
	}
	else{
		fin -> sig = nodo;
		fin = nodo;
	}
	size++;
}

void LL::imprimir(){
	Node *itr = ini;
	while(itr != NULL){
		cout << itr -> value << endl;
		itr = itr -> sig;
	}
}

int LL::getSize(){
	return size;
}

int LL::estaVacio(){
	return size == 0;
}

void LL::eliminarNodo(int e){
	Node *ant = NULL;
	Node *act = ini;
	
	while(act != NULL){
		if(act -> value == e) break;
		ant = act;
		act = act -> sig;
	}
	
	if(act != NULL){
		if(act == ini) ini = act -> sig;
		else{
			ant -> sig = act -> sig;
			if(fin == act) fin = ant;
		}
		free(act);
		size--;
	}
	else cout << "El valor "<< e << " no se encuentra en la lista" << endl;
}

int LL::estaElemento(int e){
	Node *ptr = ini;
	while(ptr != NULL){
		if(ptr -> value == e) return 1;
		ptr = ptr -> sig;
	}
	return 0;
}

int main(){
	LL a;
	a.insertarNodo(3);
	a.insertarNodo(4);
	a.insertarNodo(5);
	a.insertarNodo(6);
	cout << a.estaElemento(4) << endl;
	a.eliminarNodo(6);
	a.eliminarNodo(3);
	a.imprimir();
	cout << "El tamaño es: " << a.getSize() << endl;
	a.eliminarNodo(4);
	a.eliminarNodo(5);
	a.imprimir();
	cout << a.estaElemento(2) << endl;
	cout << "El tamaño es: " << a.getSize() << endl;
	if(a.estaVacio()) cout << "Vacio" << endl;
	else cout << "No vacio" << endl;
	return 0;
}