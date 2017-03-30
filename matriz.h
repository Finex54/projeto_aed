
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




#endif
