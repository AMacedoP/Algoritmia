typedef int TElemento;

typedef struct nodo{
    TElemento elem;
    double peso;
    struct nodo *sig;
}TNodo;

typedef struct lista{
    TNodo *inicio;
    TNodo *fin;
    int numElem;
}TLista;

void Lista_Crear(TLista *);
void Lista_Finalizar(TLista *);
int Lista_EstaVacia(TLista);
void Lista_Insertar(TLista *, TElemento, double);
void Lista_Eliminar(TLista *, TElemento);
int Lista_Tamanho(TLista);
int Lista_EstaEnLista(TLista, TElemento);
void Lista_Imprimir(TLista);
