// 试实现普里姆最小生成树算法。
//
// int LocateVex(AMGraph G , char v);
// 返回 v 对应的顶点的下标
//
// int Min(AMGraph G);
// 根据 closedge 找到最小值对应的顶点下标，
// 其中 lowcost 为 0 表示该顶点已经被加入到生成树中，
// 该函数会将其略过

// Sample Input
// 7 9
// 0123456
// 0 1 28
// 0 5 10
// 1 2 16
// 1 6 14
// 2 3 12
// 3 6 18
// 3 4 22
// 4 5 25
// 4 6 24
// 0

// Sample Output
// 0->5
// 5->4
// 4->3
// 3->2
// 2->1
// 1->6

// Prepend Code Start
#include <iostream>
#define MVNum 10
#define MaxInt 32767 
using namespace std;

struct edge{
    char adjvex;
    int lowcost;
}closedge[MVNum];

typedef struct{ 
    char vexs[MVNum];   
    int arcs[MVNum][MVNum]; 
    int vexnum,arcnum;
}AMGraph;
int LocateVex(AMGraph G , char v);//实现细节隐藏
int Min(AMGraph G);//实现细节隐藏
int CreateUDN(AMGraph &G);//实现细节隐藏

void Prim(AMGraph G, char u);

int main(){
    AMGraph G;
    CreateUDN(G);
    char u;
    cin >> u;
    Prim(G , u);
    return 0;
}
// Prepend Code End

void Prim(AMGraph G, char u) {
  int k = LocateVex(G, u);

  for (int i = 0; i < G.vexnum; i++) {
    if (i != k) {
      closedge[i].adjvex = G.vexs[k];
      closedge[i].lowcost = G.arcs[k][i];
    } else {
      closedge[i].lowcost = 0;
    }
  }

  for (int _ = 0; _ < G.vexnum - 1; _++) {
    // 根据 closedge 找到最小值对应的顶点下标，
    // 其中 lowcost 为 0 表示该顶点已经被加入到生成树中，
    // 该函数会将其略过
    int min = Min(G);

    cout << closedge[min].adjvex << "->" << G.vexs[min] << endl;

    closedge[min].lowcost = 0;

    for (int i = 0; i < G.vexnum; i++) {
      if (G.arcs[min][i] < closedge[i].lowcost) {
        closedge[i].lowcost = G.arcs[min][i];
        closedge[i].adjvex = G.vexs[min];
      }
    }
  }
}
