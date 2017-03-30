#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "listas.h"

struct _matriz {
  float **values;
  int linhas, colunas;
};

