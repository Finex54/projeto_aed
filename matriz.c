#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"
#include "listas.h"

struct _matriz {
  int **values;
  int linhas, colunas;
  int variante, linha_cluster, coluna_cluster;
};





/******************************************************************************
 * *NewMatrix(int size)
 *
 * Arguments: size - size of the square matrix (size x size)
 * Returns: (matrix *) pointer to actual word (string)
 * Side-Effects: none
 *
 * Description: returns the new matrix 
 *****************************************************************************/
matriz *NewMatrix(int linhas, int colunas, int variante, int coluna_cluster, int linha_cluster)
{

  int pI, pJ;
  pI = pJ = 0;

  /* allocate space for the matrix */
  matriz *Mat = (matriz*) malloc (sizeof(matriz));/* Write your code here */
  Mat->values = (int **) malloc(linhas*sizeof(int*));/* Write your code here */
  for ( pI = 0; pI < linhas; pI++ )
    Mat->values[pI] = (int*) malloc (colunas*sizeof(int));/* Write your code here */
 
  /* initiate matrix */
  for ( pI =0; pI < linhas; pI++ )
    for ( pJ =0; pJ < colunas; pJ++ )
      Mat->values[pI][pJ] = 0.0;

  Mat->linhas = linhas;
  Mat->colunas = colunas;
  Mat->variante = variante;
  Mat->coluna_cluster = coluna_cluster;
  Mat->linha_cluster = linha_cluster;

  return Mat;

}


/******************************************************************************
 * SetMatrixElement(t_matrix *mA, int pI, int pJ, float value)
 *
 * Arguments: mA    - (t_matrix *) the matrix
 *            pI    - (int) row of the element
 *            pJ    - (int) column if the element
 *            value - (float) value to include int the matrix 
 * Returns: (void) nothing 
 * Side-Effects: none
 *
 * Description: function to include an element (value) in the matrix (mA),
 *              in position (pI, pJ)
 *****************************************************************************/
void SetMatrixElement(matriz *mA, int pI, int pJ, float value)
{

  mA->values[pI][pJ] = value;

  return;

}





/******************************************************************************
 *  saveMatrices ()
 *
 * Arguments:  fm - pointer to the file with the matrices
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: save the matrices in fm, into mA. 
 *****************************************************************************/
lista *saveMatrices( FILE *fm )
{

  lista *lm;
  matriz *newMatrix;
  
  int m_linhas = 0, m_colunas=0, variante=0, linha=0, coluna=0;
  int pJ, pI, err;
  int NumberMatrices = 0;
  float newEntry = 0.0;

  printf("--> Loading matrices...");

  lm = iniLista();


  while( 1 ){ 

    /* scan the size of the matrix NumberMatrices */
    if( fscanf( fm, "%d %d %d %d %d", &m_linhas, &m_colunas, &variante, &linha, &coluna ) != 5 )
      break;

    /* verify if size is correct */
    /*if( m_size < 2 || m_size > 9 )
      {
            printf("FileData is corrupted.\n");
            exit(1);
      }*/


    /* create a new matrix */
    newMatrix = NewMatrix( m_linhas, m_colunas, variante, linha, coluna );

    /* save the matrix */
    for( pI = 0 ; pI < m_linhas ; pI++ ){
      for( pJ = 0 ; pJ < m_colunas ; pJ++ ){
        if( fscanf( fm, "%f", &newEntry ) != 1 )
          {
            printf("FileData is corrupted.\n");
            exit(1);
          }


        SetMatrixElement(newMatrix, pI, pJ, newEntry);
      }
    }
 
    NumberMatrices++;
    lm = criaNovoNoLista (lm, newMatrix, &err);


  }

  printf( "[DONE]\n" );
  return lm;

}




/******************************************************************************
 * PrintMatrix(t_matrix *mA)
 *
 * Arguments: mA - (t_matrix *) the matrix
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: print the matrix pointed by mA
 *****************************************************************************/
void PrintMatrix(matriz *mA)
{
 
  int pI, pJ;

  printf( "Matrix:\n" );
  printf("Variante: %d, Cluster: (%d, %d)\n", mA->variante, mA->linha_cluster, mA->coluna_cluster);
  for( pI = 0; pI < mA->linhas ; pI++ ){
    for( pJ = 0; pJ < mA->colunas ; pJ++ )
      printf( "%d ", GetMatrixElement( mA, pI, pJ ) );
    printf( "\n" );
  }

  return;

}

/******************************************************************************
 * GetMatrixElement(Matrix *mA, int pI, int pJ)
 *
 * Arguments: mA - (matrix *) the matrix
 *            pI - (int) row of the element
 *            pJ - (int) column if the element
 * Returns: (float) the value of the matrix that is in (pI, pJ)
 * Side-Effects: none
 *
 * Description: returns an element in the matrix (mA) in position (pI,pJ)
 *****************************************************************************/
int GetMatrixElement(matriz *mA, int pI, int pJ)
{

  return mA->values[pI][pJ];

}


int GetMatrixLinhas(matriz *mA)
{

  return mA->linhas;

}


int GetMatrixLinhaCluster(matriz *mA)
{

  return mA->linha_cluster;

}



int GetMatrixColunas(matriz *mA)
{

  return mA->colunas;

}

int GetMatrixColunaCluster(matriz *mA)
{

  return mA->coluna_cluster;

}

int** GetMatrix(matriz *mA)
{

  return mA->values;

}

/******************************************************************************
 * FreeMatrix(t_matrix *mA)
 *
 * Arguments: mA - (t_matrix *) the matrix
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: free all the memory associated with the matrix mA
 *****************************************************************************/
void FreeMatrix(matriz *mA)
{
  int pI;
  /* Complete the code here */
  for ( pI = 0; pI < mA->linhas; pI++ )
    free(mA->values[pI]);

  free(mA->values);
  free(mA);


  return;

}

/******************************************************************************
 * FreeItem ()
 *
 * Arguments: p - pointer to Item
 * Returns: (void)
 * Side-Effects: calls function to free word structure
 *
 * Description: interfaces generic list item to specific matrix structure
 *
 *****************************************************************************/
void FreeItem( matriz* this)
{

  FreeMatrix( (matriz *)this);

  return;
}