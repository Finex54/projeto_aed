#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "listas.h"

struct _matriz {
  float **values;
  int linhas, colunas;
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
matriz *NewMatrix(int linhas, int colunas)
{

  int pI, pJ;
  pI = pJ = 0;

  /* allocate space for the matrix */
  matriz *Mat = (matriz*) malloc (sizeof(matriz));/* Write your code here */
  Mat->values = (float **) malloc(linhas*sizeof(float*));/* Write your code here */
  for ( pI = 0; pI < linhas; pI++ )
    Mat->values[pI] = (float*) malloc (colunas*sizeof(float));/* Write your code here */
 
  /* initiate matrix */
  for ( pI =0; pI < linhas; pI++ )
    for ( pJ =0; pJ < colunas; pJ++ )
      Mat->values[pI][pJ] = 0.0;

  Mat->linhas = linhas;
  Mat->colunas = colunas;

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
  
  int m_linhas = 0, m_colunas=0, variante=0;;
  int pJ, pI, err;
  int NumberMatrices = 0;
  float newEntry = 0.0;

  printf("--> Loading matrices...");

  lm = iniLista();


  while( 1 ){ 

    /* scan the size of the matrix NumberMatrices */
    if( fscanf( fm, "%d %d %d", &m_linhas, &m_colunas, &variante ) != 3 )
      break;

    /* verify if size is correct */
    /*if( m_size < 2 || m_size > 9 )
      {
            printf("FileData is corrupted.\n");
            exit(1);
      }*/

    /* create a new matrix */
    newMatrix = NewMatrix( m_linhas, m_colunas );

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

