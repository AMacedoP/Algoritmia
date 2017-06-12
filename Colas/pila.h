typedef int TElemento;

typedef struct nodo{
	TElemento info;
	struct nodo *sig;
} TNodo;

typedef struct pila{
	TNodo *top;
} TPila;

void pila_crear(TPila *);
void pila_apilar(TPila *, TElemento);
TElemento pila_desapilar(TPila *);
TElemento pila_tope(TPila *);
int pila_vacia(TPila *);
void pila_finalizar(TPila *);
TElemento pila_postfija(char *);
int pila_parenthesis(char *);