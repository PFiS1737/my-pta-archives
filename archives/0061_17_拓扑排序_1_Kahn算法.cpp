// Write a program to find the topological order in a digraph.
// 编写一个程序来查找有向图中的拓扑顺序。
//
// The topological order is supposed to be stored in TopOrder[] where TopOrder[i] is the i-th vertex in the resulting sequence.
// 拓扑顺序应该存储在 TopOrder[] 中，其中 TopOrder[i] 是结果序列中的 i 个顶点。
// The topological sort cannot be successful if there is a cycle in the graph -- in that case TopSort must return false; otherwise return true.
// 如果图中存在环路，则拓扑排序无法成功——在这种情况下， TopSort 必须返回 false ；否则返回 true 。
//
// Notice that the topological order might not be unique, but the judge's input guarantees the uniqueness of the result.
// 请注意，拓扑顺序可能不是唯一的，但评委的输入保证了结果的唯一性。

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

Vertex st[MaxVertexNum];
int in[MaxVertexNum] = {0};

bool TopSort(LGraph Graph, Vertex TopOrder[]) {
  int N = Graph->Nv;

  for (int v = 0; v < N; v++) {
    PtrToAdjVNode p = Graph->G[v].FirstEdge;
    while (p) {
      in[p->AdjV]++;
      p = p->Next;
    }
  }

  int top = -1;
  for (int v = 0; v < N; v++) {
    if (!in[v]) {
      st[++top] = v;
    }
  }

  int i = 0;
  while (top >= 0) {
    Vertex v = st[top--];
    TopOrder[i++] = v;

    PtrToAdjVNode p = Graph->G[v].FirstEdge;
    while (p) {
      Vertex w = p->AdjV;
      if (--in[w] == 0) {
        st[++top] = w;
      }
      p = p->Next;
    }
  }

  return i == N;
}
