// 实现哈希表创建及查找算法，哈希函数使用除余法，用线性探测法处理冲突。

// Sample Input
// 12
// 19 14 23 1 68 20 84 27 55 11 10 79
// 55

// Sample Output
// search success，The key is located in 6

// Prepend Code Start
#include<iostream>
using namespace std;

#define m 16 
#define NULLKEY 0 //单元为空的标记

struct HashTable{
   int  key;
};

void CreateHash(HashTable HT[],int n); //输入不大于m的n个不为0（0表示空值）的数，用线性探查法解决冲突构造散列表
int SearchHash(HashTable HT[],int key); //输入一个值key，在散列表中查找key位置

int main()
{    int value,key;
    int result;
    int i,j,n;
    HashTable HT[m];
    for(i=0;i<m;i++)
     HT[i].key=0;
    cin >> n;
    if(n>m) return 0;
    CreateHash(HT,n);
    cin >> key;
    result=SearchHash(HT,key);
    if(result!=-1)
        cout << "search success，The key is located in "<< result+1;
    else
        cout << "search failed";
    return 0;
}
// Prepend Code End

void CreateHash(HashTable HT[], int n) {
  for (int i = 0; i < m; i++)
    HT[i].key = NULLKEY;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;

    int j = v % 13; // 13 为不超过 m 的最大质数

    if (HT[j].key == NULLKEY) {
      HT[j].key = v;
    }

    else {
      for (int k = 1; k < m; k++) { // 线性探查
        int p = (j + k) % m;
        if (HT[p].key == NULLKEY) {
          HT[p].key = v;
          break;
        }
      }
    }
  }
}

int SearchHash(HashTable HT[], int key) {
  int i = key % 13;
  for (int j = 0; j < m; j++) {
    int p = (i + j) % m;
    if (HT[p].key == key) {
      return p;
    }
  }
  return -1;
}
