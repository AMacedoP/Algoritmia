typedef int TElemento;

typedef struct nodo{
	TElemento info;
	struct nodo *izq;
	struct nodo *der;
} TNodo;

typedef struct ABB{
	TNodo *raiz;
} TABB;

void abb_iniciar(TABB *);
void abb_insertar(TABB *, TElemento);
void abb_imprimir(TABB *, int);
int abb_contar(TABB *);
int esABB(TABB *);