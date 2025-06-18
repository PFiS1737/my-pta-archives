
// Sample Input
// 5 7
// 1 0
// 4 3
// 2 1
// 2 0
// 3 2
// 4 1
// 4 2

// Sample Output
// 4 3 2 1 0 

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();

    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");

    return 0;
}
// Prepend Code End

int flags[MaxVertexNum] = {0};
int i;

bool dfs(LGraph Graph, Vertex v, Vertex TopOrder[]) {
  flags[v] = 1;

  PtrToAdjVNode p = Graph->G[v].FirstEdge;
  while (p) {
    int v = p->AdjV;
    if (flags[v] == 1) {
      return false;
    }
    if (flags[v] == 0) {
      dfs(Graph, v, TopOrder);
    }
    p = p->Next;
  }

  flags[v] = 2;

  TopOrder[--i] = v;

  return true;
}

bool TopSort(LGraph Graph, Vertex TopOrder[]) {
  i = Graph->Nv;

  for (int v = 0; v < Graph->Nv; v++) {
    if (!flags[v]) {
      if (!dfs(Graph, v, TopOrder)) {
        return false;
      }
    }
  }

  return true;
}
