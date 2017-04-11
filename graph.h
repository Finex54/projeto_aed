#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdlib.h>
#include "matriz.h"

#define maxV 100
#define dfsR search

static int cnt, pre[maxV];

typedef struct edge Edge;
typedef struct graph Graph;


int **MATRIXinit(int V1, int V2, int value);
void PrintMATRIX(Graph *G);
Graph *GRAPHinit(int);
Graph *PreencheMatrizAdjacencias(Graph *G, matriz *mA);
void GRAPHinsertE(Graph *G, Edge*);
void GRAPHremoveE(Graph *G, Edge*);
Edge *EDGE(int v, int w);
void GRAPHsearch(Graph *G);
void dfsR(Graph *G, Edge *e);


#endif