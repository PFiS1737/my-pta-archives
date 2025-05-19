// 本题要求实现顺序表的创建和就地逆置操作函数。
// L是一个顺序表，函数ListCreate_Sq(SqList &L)用于创建一个顺序表，
// 函数ListReverse_Sq(SqList &L)是在不引入辅助数组的前提下将顺序表中的元素进行逆置，如原顺序表元素依次为1,2,3,4，则逆置后为4,3,2,1。

// Sample Input
// 4
// 1 2 3 4

// Sample Output
// 4 3 2 1

// Prepend Code Start
//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct{
    ElemType* base;   //存储空间基地址
    int size;       //表中元素的个数
    int capacity;     //表容量大小
}SqList;    //顺序表类型定义

Status ListCreate_Sq(SqList &L);
void ListReverse_Sq(SqList &L);

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: 创建失败！！！\n");
        return -1;
    }
    
    ListReverse_Sq(L);

    if(L.size){
    for(p=L.base;p<L.base+L.size-1;++p){
        printf("%d ",*p);
    }
    printf("%d",*p); 
    }
    return 0;
}
// Prepend Code End

Status ListCreate_Sq(SqList &L) {
  scanf("%d", &L.size);

  int n = L.size / LIST_INIT_SIZE + 1;
  L.capacity = n * LIST_INIT_SIZE;

  L.base = (ElemType *)malloc(L.capacity * sizeof(ElemType));
  if (!L.base) {
    exit(OVERFLOW);
  }

  for (int i = 0; i < L.size; i++) {
    scanf("%d", &L.base[i]);
  }

  return OK;
}

void ListReverse_Sq(SqList &L) {
  for (int i = 0; i < L.size / 2; i++) {
    ElemType temp = L.base[i];
    L.base[i] = L.base[L.size - 1 - i];
    L.base[L.size - 1 - i] = temp;
  }
}
