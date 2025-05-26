// 函数SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2)是从1到upbound中找出father为0的节点赋给s1,s2,（为了保证答案唯一，请让s1的节点编号小于s2），
// 函数HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)是构造哈夫曼树以及计算哈夫曼编码。保证输入的权重值小于1000。
// 第一行输入一个数n，表示叶子节点的个数，接下去输入n个整数，表示每个节点的权值

// Sample Input
// 4
// 1 2 3 4

// Sample Output
// 1 5 0 0
// 2 5 0 0
// 3 6 0 0
// 4 7 0 0
// 3 6 1 2
// 6 7 3 5
// 10 0 4 6
// 110
// 111
// 10
// 0

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode, *HuffmanTree;
typedef char ** HuffmanCode;

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2);
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n);

int main() {
    HuffmanTree ht;
    HuffmanCode hc;

    int n;
    scanf("%d", &n);
    
    int *w = (int *) malloc (n * sizeof(int));
    for(int i = 0; i < n; ++ i)
        scanf("%d", &w[i]);

    HuffmanCoding(ht, hc, w, n);
    
    for (int i = 1; i <= 2 * n - 1; ++ i) {
        printf("%d %d %d %d\n", 
        ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }

    for (int i = 1; i <= n; ++ i)
        printf("%s\n", hc[i]);

    free(w);
    free(ht);
    for (int i = 1; i <= n; ++ i)
        free(hc[i]);
    
    return 0;
}
// Prepend Code End

void SelectTwoMin(int upbound, HuffmanTree HT, int &s1, int &s2) {
  int min1 = 1001, min2 = 1001;

  s1 = s2 = 0;

  for (int i = 1; i <= upbound; i++) {
    if (!HT[i].parent && HT[i].weight < min1) {
      min2 = min1;
      s2 = s1;
      min1 = HT[i].weight;
      s1 = i;
    } else if (!HT[i].parent && HT[i].weight < min2) {
      min2 = HT[i].weight;
      s2 = i;
    }
  }
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n) {
  int s1 = 0, s2 = 0;

  HT = new HTNode[(2 * n)];
  for (int i = 1; i <= n; ++i) {
    HT[i].weight = w[i - 1];
  }

  for (int i = n + 1; i <= 2 * n - 1; i++) {
    SelectTwoMin(i - 1, HT, s1, s2);

    HT[i].weight = HT[s1].weight + HT[s2].weight;
    HT[i].lchild = s1;
    HT[i].rchild = s2;

    HT[s1].parent = i;
    HT[s2].parent = i;
  }

  HC = new char *[n + 1];

  for (int i = 1; i <= n; i++) {
    int idx = n - 1;

    char code[n];
    code[idx] = '\0';

    int j = i, p = HT[j].parent;
    while (p) {
      code[--idx] = (HT[p].lchild == j) ? '0' : '1';
      j = p;
      p = HT[j].parent;
    }

    HC[i] = new char[n - idx];
    strcpy(HC[i], &code[idx]);
  }
}
