#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "matriz.h"
#include "listas.h"



struct _lista {
  matriz* this;
  struct _lista *prox;
};


lista *iniLista(void)
{

  return NULL;
}




/******************************************************************************
 * criaNovoNoLista ()
 *
 * Arguments: nome - Item to save in list node
 * Returns: t_lista  *
 * Side-Effects: none
 *
 * Description: creates and returns a new node that can later be added to the
 *              list
 *
 *****************************************************************************/
lista  *criaNovoNoLista (lista* lm, matriz* this, int *err)
{
  lista *novoNo;

  novoNo = (lista*) malloc(sizeof(lista));
  if(novoNo!=NULL) {

    novoNo->this = this;
    novoNo->prox = lm;
    lm = novoNo;
    *err = 0;
  } else {
    *err = 1;
  }
  return lm;
}