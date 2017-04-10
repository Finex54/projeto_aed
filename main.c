#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "matriz.h"
#include "listas.h"
#include "graph.h"


/******************************************************************************
 *  PrintList ()
 *
 * Arguments:  lm - pointer to the list
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: print the list of matrices. 
 *****************************************************************************/
void PrintList(lista *lm){

  lista *aux;
  matriz *mA;

  printf("--> Printing items saved in memory...\n");

  aux = lm;
  while( aux!= NULL ){
    mA = (matriz *) getItemLista(aux);
    PrintMatrix( mA );
    aux = getProxElementoLista(aux);
  }

  printf( "...[DONE]\n" );

  return;

}





/******************************************************************************
 * Usage ()
 *
 * Arguments: nomeProg - name of executable
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: message function when arguments are missing
 *
 *****************************************************************************/
void Usage(char *nomeProg)
{
  printf("Usage: %s [filename]\n",
      nomeProg);

  exit(1);

}

/*****************************************************************************
*verifica_extensao()
*
*Argumentos: Nome do ficheiro de entrada
*Retorna 0 se a extensão do ficheiro estiver correta e retorna 1 caso contrário
*
*****************************************************************************/

int verifica_extensao(char* filename)
{
	int size = strlen (filename);
	return ( filename[size-1]=='z' && filename[size-2]=='u' && filename[size-3]=='p' && filename[size-4]=='.') ? 0:1;
}


/******************************************************************************
*
*EscreveFileSaida()
*
*Não retorna nada
*Cria o ficheiro .moves
*
******************************************************************************/

/*ALTERAR ENTRADAS PARA RECEBER A LISTA E A MATRIZ A ESCREVER MAIS A PONTUAÇÃO*/

void EscreveFileSaida(char *nomeEntrada)
{

  char ext[6] = "moves";
  char nomeSaida[100];
  int i=0;
  FILE *fpOut;
  
  for(i=0; i<(strlen(nomeEntrada)-3); i++)
    nomeSaida[i] = nomeEntrada[i];

  nomeSaida[i] = '\0';

  strcat(nomeSaida, ext);

  printf("\n\n %s \n\n", nomeSaida);  /*APENAS PARA TESTE*/

  fpOut=fopen(nomeSaida, "w");

  fclose(fpOut);

}


int ContaClusterVar1(matriz* mA, int linhaCluster, int colunaCluster, int contagem)
{
  int valor = GetMatrixElement(mA, linhaCluster, colunaCluster);
  printf("\n\n%d %d %d\n\n", valor, GetMatrixLinhas(mA), linhaCluster);

  if (valor==-1 || linhaCluster>GetMatrixLinhas(mA) || colunaCluster >GetMatrixColunas(mA) || linhaCluster <0 || colunaCluster <0)
    return -1;

}




void VarianteUm(matriz* mA)
{
  int lcluster =  GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA);
  int ccluster = GetMatrixColunaCluster(mA) - 1;
  int value = GetMatrixElement(mA, lcluster, ccluster);
  int contagem=1;

  /*ContaClusterVar1(mA, lcluster, ccluster, &contagem);*/
  contagem=ContaClusterVar1(mA, lcluster, ccluster, contagem);

  printf("\n\nContagem = %d\n\n", contagem);


}


void VarianteDois(matriz* mA)
{
  int lcluster = GetMatrixLinhas(mA) - GetMatrixLinhaCluster(mA);
  int ccluster = GetMatrixColunaCluster(mA) - 1;
  int value = GetMatrixElement(mA, lcluster, ccluster);





}


/**********************************************
*
*CALCULA: FAZ VARIANTE 1 OU VARIANTE 2
*
*
**********************************************/


void Calcula(lista *lm)
{

lista *aux=NULL;

for(aux=lm; aux!=NULL; aux=getProxElementoLista(aux))
{
  int vertices=0;
  Graph *grafo;
  int variante = GetVariante(getItemLista(aux));
  if(variante == 1 || variante == 2){

    /*Calcular o número de vértices da matriz*/
    for(int i = 0; i<GetMatrixLinhas(getItemLista(aux)); i++)
      for(int j=0; j< GetMatrixColunas(getItemLista(aux)); j++)
        /*if( GetMatrixElement(getItemLista(aux), i, j)!= -1 )*/vertices++;
   grafo = GRAPHinit(vertices);
   //printf("numero de vertices: %d\n", vertices);

  /* 
  if (variante==1)
    VarianteUm(getItemLista(aux));

  if(variante==2)
    VarianteDois(getItemLista(aux));*/
}
  else printf("Erro ao selecionar a variante\n");
}
}


int main(int argc, char *argv[])
{
	char *nomeficheiro;
  	FILE *fp_entrada;
  	lista *lista_matrizes;

  	/*
  		CASO A EXECUÇÃO DO FICHEIRO NÃO SEJA REALIZADA
  		CORRETAMENTE
  	*/
  	if( argc < 2 )
    	Usage( argv[0] );

	nomeficheiro = argv[1];

	if(verifica_extensao(nomeficheiro)!=0)
	{
		printf("Extensão do ficheiro errada\n");
		exit(2);
	}

  	fp_entrada = fopen( nomeficheiro, "r" );

  	/*
  	VERIFICA SE NÃO HÁ ERROS NA ABERTURA DO FICHEIRO
  	*/
  	if( fp_entrada == NULL ){
    printf( "Open error of the input file\n" );
    exit(2);
  }

  lista_matrizes = saveMatrices( fp_entrada );

  /*APENAS PARA TESTE*/
    PrintList( lista_matrizes);



    Calcula(lista_matrizes);

    EscreveFileSaida(nomeficheiro);

  	/*Liberta a memória da lista*/
    libertaLista( lista_matrizes, FreeItem );


  	/*Fecha o ficheiro*/
  	fclose(fp_entrada);

    exit(0);
}