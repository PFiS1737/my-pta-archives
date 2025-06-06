// 本题要求建立一个无向图，采用邻接矩阵做为存储结构。
//
// 输入信息为：第一行给出图的顶点数n和边数e。第二行给出n个字符，表示n个顶点的数据元素的值。后面是e行，给出每一条边的两个顶点的值(顶点之间无空格)。
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
// 0: 2 3 4
// 1: 3 5
// 2: 0 3 5
// 3: 0 1 2
// 4: 0 5
// 5: 1 2 4 6
// 6: 5

// Prepend Code Start
#include <stdio.h>
#define MVNum 100                 //最大顶点数
typedef struct{
  char vexs[MVNum];           //存放顶点的一维数组
  int arcs[MVNum][MVNum];     //邻接矩阵
  int vexnum,arcnum;          //图的当前顶点数和边数
}MGraph;
void CreatMGraph(MGraph &G);/* 创建图 */
void printGraph(MGraph G);/*输出图 */
int locate(MGraph G,char v)//返回顶点v的下标
{
  int i;
  for(i=0;i<G.vexnum;i++)
    if(G.vexs[i]==v)
       return i;
   return -1;
}

int main()
{
    MGraph G;
    CreatMGraph(G);//创建图G
    printGraph(G);//打印该图
    return 0;
}

void printGraph(MGraph G)//打印图
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
    {
       printf("%c:",G.vexs[i]);
       for(j=0;j<G.vexnum;j++)
          if (G.arcs[i][j])  printf(" %c",G.vexs[j]);
       printf("\n");
    }
}
// Prepend Code End

void CreatMGraph(MGraph &G) {
  int i, j, k;
  char v1, v2;
  scanf("%d%d", &G.vexnum, &G.arcnum);
  getchar();
  for (i = 0; i < G.vexnum; i++)
    scanf("%c", &G.vexs[i]);
  for (i = 0; i < G.vexnum; i++)
    for (j = 0; j < G.vexnum; j++)
      G.arcs[i][j] = 0;
  for (k = 0; k < G.arcnum; k++) {
    getchar();
    scanf("%c%c", &v1, &v2);
    i = locate(G, v1);
    j = locate(G, v2);
    G.arcs[i][j] = 1;
    G.arcs[j][i] = 1;
  }
}
