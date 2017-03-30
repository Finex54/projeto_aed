
#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"

/* type definition for structure to hold word */
typedef struct _matriz matriz;



lista *saveMatrices( FILE *fm );
matriz *NewMatrix(int linhas, int colunas);
void SetMatrixElement(matriz *mA, int pI, int pJ, float value);
lista  *criaNovoNoLista (lista* lm, matriz* this, int *err);
matriz* getItemLista (lista *m);
void PrintMatrix(matriz *mA);
float GetMatrixElement(matriz *mA, int pI, int pJ);
void FreeMatrix(matriz *mA);
void FreeItem( matriz* this);
void libertaLista(lista *lm, void freeItem(matriz*));



#endif
