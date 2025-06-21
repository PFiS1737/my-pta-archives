// NOTE: 用 priority_queue 实现
//
// 使用 Dijkstra 算法，求起到到各点的最短路径长度

// Sample Input
// 14 14
// ABCDEFGHIJKLMN
// AB 1
// AC 1
// AD 3
// BG 2
// CE 1
// DM 3
// EF 1
// FI 2
// GJ 5
// IL 3
// JL 2
// KL 2
// KN 6
// MN 5

// Sample Output
// dist[A][A]=0
// dist[A][B]=1
// dist[A][C]=1
// dist[A][D]=3
// dist[A][E]=2
// dist[A][F]=3
// dist[A][G]=3
// dist[A][H]=256
// dist[A][I]=5
// dist[A][J]=8
// dist[A][K]=10
// dist[A][L]=8
// dist[A][M]=6
// dist[A][N]=11

// Prepend Code Start
#include <stdio.h>
#define MAX_VERTEX_NUM 14                 //最大顶点数
#define INFINITY 256   //正无穷
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int Vertex;
typedef struct{
  char vexs[MAX_VERTEX_NUM];           //存放顶点的一维数组
  int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //邻接矩阵
  int Nv,Na;          //图的当前顶点数和边数
}MGraph;

int locate(MGraph G,char v)
{
  int i;
  for(i=0;i<G.Nv;i++)
    if(G.vexs[i]==v)
       return i;
   return -1;
}
void CreatMGraph(MGraph &G)
{
    int i,j,k;
    char v1,v2;
    int w;
    scanf("%d%d",&G.Nv,&G.Na);
    getchar();
    for(i=0;i<G.Nv;i++)
         scanf("%c",&G.vexs[i]);
    for(i=0;i<G.Nv;i++)
         for(j=0;j<G.Nv;j++)
            G.arcs[i][j]=INFINITY;
    for(k=0;k<G.Na;k++) {
         getchar();
        scanf("%c%c %d",&v1,&v2,&w);
        i=locate(G,v1);
        j=locate(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=w;
    }
}
void printGraph(MGraph G)//打印图
{
    int i,j;
    for(i=0;i<G.Nv;i++)
    {
       for(j=0;j<G.Nv;j++)
          printf("%4d",G.arcs[i][j]);
       printf("\n");
    }
}

Vertex FindMinDist( MGraph Graph, int dist[], int collected[] );
bool Dijkstra( MGraph Graph, int dist[],  Vertex S );

int main()
    {
        MGraph G;
        int i,j;
        int dist[MAX_VERTEX_NUM];
        CreatMGraph(G);
        i=0;
        Dijkstra(G,dist,i);
        for(j=0;j<G.Nv;j++)
           printf("dist[%c][%c]=%d\n",G.vexs[i],G.vexs[j],dist[j]);
        return 0;
    }
// Prepend Code End

#include <queue>
#include <vector>
using namespace std;

bool Dijkstra(MGraph Graph, int dist[], Vertex S) {
  for (int i = 0; i < Graph.Nv; i++) {
    dist[i] = INFINITY;
  }
  dist[S] = 0;

  auto cmp = [&dist](int a, int b) { return dist[a] > dist[b]; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  pq.push(S);

  int visited[MAX_VERTEX_NUM] = {false};

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();

    if (visited[u])
      continue;
    visited[u] = true;

    for (int v = 0; v < Graph.Nv; v++) {
      if (Graph.arcs[u][v] < INFINITY && dist[u] + Graph.arcs[u][v] < dist[v]) {
        dist[v] = dist[u] + Graph.arcs[u][v];
        pq.push(v);
      }
    }
  }

  return true;
}
