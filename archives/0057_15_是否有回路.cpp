// 如果有向图用邻接表表示，试设计算法判断图中是否存在回路。
//
// IsAcyclic 判断 graph 是否无环图，如果是则返回 true，否则返回 false。

// Sample Input
// 6 9
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3
// 1 4
// 3 4
// 3 5
// 4 5

// Sample Output
// Yes

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;    /* 顶点编号类型 */
typedef char VertInfo; /* 顶点信息类型 */
typedef struct EdgeNode *Position; /* 指针即结点位置 */
struct EdgeNode {
    Vertex dest;     /* 边的另一端点编号 */
    Position next;   /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *AdjList; /* 邻接表 */
struct HeadNode {
    Position adj;  /* 邻接表头指针 */
    VertInfo data; /* 存储顶点信息 */
};
typedef struct LGraphNode *LGraph; /* 邻接表表示的图 */
struct LGraphNode {
    int n_verts; /* 顶点数 */
    int m_edges; /* 边数 */
    AdjList *ver_list; /* 存储顶点邻接表 */
    bool directed; /* true为有向图，false为无向图 */
};

#define kMaxV 1000
/* 裁判实现，细节略 */
void InitGraph(LGraph graph, int kMaxVertex, bool directed);
bool ExistEdge(LGraph graph, Vertex u, Vertex v);
void InsertEdge(LGraph graph, Vertex u, Vertex v);
LGraph BuildGraph();
/* 裁判实现部分结束 */

bool IsAcyclic( LGraph graph );

int main(void)
{
     LGraph graph;
     
     graph = BuildGraph();
     if (IsAcyclic(graph) == true) {
          printf("Yes\n");
     }
     else {
          printf("No\n");
     }
     
     return 0;
}
// Prepend Code End

int flags[kMaxV] = {0};

bool dfs(LGraph g, Vertex v) {
  flags[v] = 1;

  for (Position p = g->ver_list[v]->adj; p != NULL; p = p->next) {
    if (flags[p->dest] == 1)
      return false;

    if (flags[p->dest] == 0)
      if (!dfs(g, p->dest))
        return false;
  }

  flags[v] = 2;

  return true;
}

bool IsAcyclic(LGraph graph) {
  for (int i = 0; i < graph->n_verts; ++i)
    if (flags[i] == 0)
      if (!dfs(graph, i))
        return false;

  return true;
}
