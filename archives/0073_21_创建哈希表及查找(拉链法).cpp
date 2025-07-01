// 实现哈希表创建及查找算法，哈希函数使用除余法，用拉链法处理冲突。

// Sample Input
// 12
// 19 14 23 1 68 20 84 27 55 11 10 79

// Sample Output
// 1.75

// Prepend Code Start
#include<iostream>
using namespace std;

#define P 13

typedef struct HashNode{
   int  key;
   struct HashNode *next; 
}HashNode,* HashTable;

void CreateHash(HashTable HT[],int n); //输入不大于m的n个不为0（0表示空值）的数，用拉链法解决冲突构造散列表
float ASL(HashTable HT[]); //计算平均查找长度

int main()
{
    int i,n;
    HashTable HT[P];
    for(i=0;i<P;i++)
     HT[i]=NULL;
    cin >> n;
    CreateHash(HT,n);
    cout << ASL(HT);
    return 0;
}
// Prepend Code End

int N;
int cnt[1000] = {0};

void CreateHash(HashTable HT[], int n) {
  N = n;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    int idx = m % P;
    cnt[idx]++;

    HashNode *node = new HashNode{m, nullptr};

    if (!HT[idx]) {
      HT[idx] = node;
    }

    else {
      HashNode *p = HT[idx];
      while (p->next) {
        p = p->next;
      }
      p->next = node;
    }
  }
}

float ASL(HashTable _[]) {
  float sum = 0;
  for (int i = 0; i < P; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      sum += j;
    }
  }
  return sum / N;
}
