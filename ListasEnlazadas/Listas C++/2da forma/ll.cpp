#include <iostream>
#include <stdlib.h>
#include "ll.h"

using namespace std;

void Node::giveValues(int e){
	this -> value = e;
	this -> sig = NULL;
}

int Node::getValue(){
	return this -> value;
}

LL::LL(){
	this -> ini = NULL;
	this -> fin = NULL;
	this -> size = 0;
}

int LL::getSize(){
	return this -> size;
}

void LL::imprimir(){
	Node *ptr = this -> ini;
	while(ptr != NULL){
		cout << ptr -> getValue() << endl;
		ptr = ptr -> sig;
	}
}

void LL::insertarValor(int e){
	Node *node = (Node *)malloc(sizeof(Node));
	node -> giveValues(e);
	
	if(this -> getSize() == 0){
		this -> ini = node;
		this -> fin = node;
	}
	else{
		this -> fin -> sig = node;
		this -> fin = node;
	}
	(this -> size)++;
}