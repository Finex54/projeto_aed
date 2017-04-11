#include "graph.h"
#include "matriz.h"

struct graph {
	int V;
	int E;
	int **adj;
};

struct edge {
	int v;
	 int w;
	 int cor;
};


int **MATRIXinit(int V1, int V2, int value)
{
	int i,j;
	int **MATRIX;

	MATRIX = (int**) malloc (V1*sizeof(int*));
		for(i=0; i<V2; i++)
			MATRIX[i]= (int*) malloc (V2*sizeof(int));
		for(i=0; i<V1; i++)
			for(j=0; j<V2; j++)
				MATRIX[i][j]=value;

	return MATRIX;

}

	void PrintMATRIX(Graph *G)
	{
		for(int i = 0; i < G-> V; i++)
			for(int j = 0; j < G->V; j++)
				printf("%d = adj[%d][%d]\n",G->adj[i][j], i, j);
	}


	Graph *GRAPHinit(int V)
	{
		Graph *G = (Graph*) malloc(sizeof(struct graph));    
		G->V = V; G->E = 0;
		G->adj = MATRIXinit(V, V, 0);
		return G;
	}

	Graph *PreencheMatrizAdjacencias(Graph *G,matriz *mA, int v)
	{
  	int colunas = GetMatrixColunas(mA)-1;

 	 for(int i = 0; i<v; i++)
  	{
    	for(int linhas = 1; linhas<= GetMatrixLinhas(mA); linhas++){
    	if(i == 0 || i == colunas*linhas+1) G->adj[i][1]=1;
    	if(i == colunas*linhas) G->adj[i][i-1]=1;
    	else{
     	 G->adj[i][i-1]=1;
      	G->adj[i][i+1]=1;
    }
  	}
    for(int j = 0; j < i+1; j+colunas+1){
      G->adj[i][j]=1;
  	}
  	}
	}

	void GRAPHinsertE(Graph *G, Edge *e){
		int v = e->v, w = e->w;
		if (G->adj[v][w] == 0) G->E++;
		G->adj[v][w] = 1;
		G->adj[w][v] = 1;
	}
	void GRAPHremoveE(Graph *G, Edge *e)
	{
		int v = e->v, w = e->w;
		if (G->adj[v][w] == 1) G->E--;
		G->adj[v][w] = 0;
		G->adj[w][v] = 0;
	}

/**********************************************************
*
* EDGE: OBTÉM UM VÉRTICE
*		 v é a linha da matriz de adjacências, w é a coluna da matriz de adj.
*
*********************************************************/

	Edge *EDGE(int v, int w)
	{
		Edge *e;
		e->v = v;
		e->w = w;

		return e;
	}

/**********************************************
*
*GRAPHsearch: ADT para procura
*             Inicializa pre a -1 e cnt a 0, chama função search
*
**********************************************/

	void GRAPHsearch(Graph *G)
	{
	  int v;
	  cnt = 0;
	  for (v = 0; v < G->V; v++)
	    pre[v] = -1;
	  for (v = 0; v < G->V; v++)
	    if (pre[v] == -1)
	      search(G, EDGE(v, v));
	}

	void dfsR(Graph *G, Edge *e)
	{
	  int t, w = e->w;
	  pre[w] = cnt++;
	  for (t = 0; t < G->V; t++)
	    if (G->adj[w][t] != 0)
	    if (pre[t] == -1)
	      dfsR(G, EDGE(w, t));
	}

