class Node{
	int value;
	
	public:
		Node *sig;
		void giveValues(int);
		int getValue();
};

class LL{
	int size;
	
	public:
		Node *ini;
		Node *fin;
		LL();
		int getSize();
		void imprimir();
		void insertarValor(int);
};