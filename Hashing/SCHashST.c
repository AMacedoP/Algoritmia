#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SCHashST.h"

void SCHashST_Init(TSCHashST *H, int max) {
    H->M = max;
    H->N = 0;
    H->table = malloc(max*sizeof(TListaST));
    if (H->table){
        int i;
        for (i = 0; i < H->M; i++)
            ListaST_Init(&(H->table[i]));
    }
}

int SCHashST_Hash(TKey k, int M) {
    int i, valor = 0;
    for (i = 0; i < strlen(k); i++){
        valor +=  k[i] - 'A' + 1;
    }
    return valor % M;
}

void SCHashST_Insert(TSCHashST *H, TKey k, TValue v) {
    int index = SCHashST_Hash(k, H->M);
    ListaST_Insert(&(H->table[index]), k, v);
    (H->N)++;
}

void SCHashST_Delete(TSCHashST *H, TKey k) {
    int index = SCHashST_Hash(k, H->M);
    ListaST_Delete( &(H->table[index]), k);
    (H->N)--;
}

TValue SCHashST_Search(TSCHashST *H, TKey k) {
    int index = SCHashST_Hash(k, H->M);
    return ListaST_Search(&(H->table[index]), k);
}

void SCHashST_Print(TSCHashST *H) {
    int i;
    for (i = 0; i < H->M; i++){
        printf("%d: ", i);
        ListaST_Print(&(H->table[i]));
        printf("\n");
    }
}