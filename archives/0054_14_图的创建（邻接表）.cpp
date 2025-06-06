// 本题要求建立一个无向图，采用邻接表做为存储结构。
//
// 输入信息为：第一行给出图的顶点数n和边数e。第二行给出n个字符，表示n个顶点的数据元素的值。后面是e行，给出每一条边的两个顶点的值（顶点之间无空格）。
//
// 输出每个顶点的值以及各顶点的邻接点的值。

// Sample Input
// 7 9
// 0123456
// 02
// 03
// 04
// 13
// 15
// 23
// 25
// 45
// 56

// Sample Output
// 0: 4 3 2
// 1: 5 3
// 2: 5 3 0
// 3: 2 1 0
// 4: 5 0
// 5: 6 4 2 1
// 6: 5

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                                 //最大顶点数
typedef struct ArcNode{                        //表结点
    int adjvex;                                    //邻接点的位置
    struct ArcNode *nextarc;      //指向下一个表结点的指针
  }ArcNode;
typedef struct VNode{
   char data;                                    //顶点信息
   ArcNode *firstarc;         //指向第一个表结点的指针
}VNode, AdjList[MVNum];                 //AdjList表示邻接表类型
typedef struct{
    AdjList vertices;              //头结点数组
    int vexnum, arcnum;     //图的当前顶点数和边数
}ALGraph;
void CreatMGraph(ALGraph &G);/* 创建图 */
void printGraph(ALGraph G);/*输出图 */
int main()
{
    ALGraph G;
    CreatMGraph(G);
    printGraph(G);
    return 0;
}

void printGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    for(i=0;i<G.vexnum;i++)
    {
       printf("%c:",G.vertices[i].data);
       for(p=G.vertices[i].firstarc;p;p=p->nextarc)
           printf(" %c",G.vertices[p->adjvex].data);
       printf("\n");
    }
}

// Prepend Code End

#include <iostream>
using namespace std;

int locate(ALGraph G, char v) {
  for (int i = 0; i < MVNum; i++) {
    if (G.vertices[i].data == v) {
      return i;
    }
  }
  return -1;
}
void CreatMGraph(ALGraph &G) {
  cin >> G.vexnum >> G.arcnum;
  getchar();
  for (int i = 0; i < G.vexnum; i++) {
    VNode n;
    cin >> n.data;
    n.firstarc = 0;
    G.vertices[i] = n;
  }
  for (int _ = 0; _ < G.arcnum; _++) {
    getchar();
    char v1, v2;
    cin >> v1 >> v2;
    int i1 = locate(G, v1);
    int i2 = locate(G, v2);
    ArcNode *n1 = new ArcNode(), *n2 = new ArcNode();
    n1->adjvex = i2;
    n1->nextarc = G.vertices[i1].firstarc;
    G.vertices[i1].firstarc = n1;
    n2->adjvex = i1;
    n2->nextarc = G.vertices[i2].firstarc;
    G.vertices[i2].firstarc = n2;
  }
}
