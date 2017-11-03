/* 
 * File:   SCHashST.h
 * Author: feralvam
 *
 * Created on October 29, 2014, 5:17 PM
 */

#ifndef SCHASHST_H
#define	SCHASHST_H

#include "ListaST.h"

typedef struct SCHashST{
    int N; // número de pares llave-valor
    int M; // tamaño de la tabla hash
    TListaST* table; // la tabla hash
} TSCHashST;

void SCHashST_Init(TSCHashST *, int);
void SCHashST_Insert(TSCHashST *, TKey, TValue);
void SCHashST_Delete(TSCHashST *, TKey);
TValue SCHashST_Search(TSCHashST *, TKey);
void SCHashST_Print(TSCHashST *);

#endif	/* SCHASHST_H */

