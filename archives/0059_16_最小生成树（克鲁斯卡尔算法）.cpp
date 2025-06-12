// 试实现克鲁斯卡尔最小生成树算法。

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

// Sample Output
// 0->5
// 2->3
// 1->6
// 1->2
// 3->4
// 4->5 

// Prepend Code Start
#include <stdio.h>
#define MVNum 10 
#define MaxInt 32767 

typedef struct{ 
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum; 
}AMGraph;

struct Evode{
    char Head;
    char Tail;
    int lowcost;
}Edge[(MVNum * (MVNum - 1)) / 2];

int Vexset[MVNum];
void CreateUDN(AMGraph &G);//实现细节隐藏
void Kruskal(AMGraph G);
int main(){
    AMGraph G;
    CreateUDN(G);
    Kruskal(G);
    return 0;
}
// Prepend Code End

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool cmp(Evode &a, Evode &b) {
  return a.lowcost > b.lowcost; // NOTE: 使用 greater 定义小顶堆
}

int find(int i) {
  while (Vexset[i] != i)
    i = Vexset[i];
  return i;
}

int locate(AMGraph G, char v) {
  for (int i = 0; i < G.vexnum; i++) {
    if (G.vexs[i] == v)
      return i;
  }
  return -1;
}

void Kruskal(AMGraph G) {
  int k = 0;
  for (int i = 0; i < G.vexnum; i++) {
    for (int j = i + 1; j < G.vexnum; j++) { // NOTE: 无向图，遍历一半就行
      if (G.arcs[i][j] < MaxInt) {           // NOTE: 这里没边的话是最大值，不是 0
        Edge[k].Head = G.vexs[i];
        Edge[k].Tail = G.vexs[j];
        Edge[k].lowcost = G.arcs[i][j];
        k++;
      }
    }
  }

  priority_queue<Evode, vector<Evode>, function<decltype(cmp)>> pq(
      cmp, vector<Evode>(Edge, Edge + k));

  // HACK: 其实可以直接排序，但是我想练习一下使用自定义比较函数的 STL 优先队列
  // sort(Edge, Edge + len, cmp);

  // 初始化并查集
  for (int i = 0; i < G.vexnum; i++)
    Vexset[i] = i;

  int cnt = 0;
  while (!pq.empty() && cnt < G.vexnum - 1) {
    Evode top = pq.top();
    pq.pop();

    int r1 = find(locate(G, top.Head));
    int r2 = find(locate(G, top.Tail));

    if (r1 != r2) {
      cout << top.Head << "->" << top.Tail << endl;
      Vexset[r1] = r2;
      cnt++;
    }
  }
}
