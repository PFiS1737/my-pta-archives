// 本题要求实现带头结点的循环单链表的创建和单链表的区间删除。
// L是一个带头结点的循环单链表，函数ListCreate_CL用于创建一个循环单链表，
// 函数ListDelete_CL用于删除取值大于min小于max的链表元素。

// Sample Input
// 6
// 1 2 3 4 5 6
// 2 5

// Sample Output
// 1 2 5 6

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
typedef int  ElemType; //假设线性表中的元素均为整型  
  
typedef struct LNode
{  
    ElemType data;  
    struct LNode *next; 
}LNode,*LinkList; //循环单链表类型定义与单链表定义相同，区别在尾节点next取值

Status ListCreate_CL(LinkList &CL);  

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max);

void ListPrint_CL(LinkList &CL) 
{   //输出单链表,空表时输出Empty List。 
    LNode *p=CL->next;  //p指向第一个元素结点
    if(p==CL){
      printf("Empty List");
      return;
    }
    while(p!=CL)  
    {   
        if(p->next!=CL)
            printf("%d ",p->data);   
        else
            printf("%d",p->data);      
        p=p->next; 
    } 
}    
int main() 
{  
    LinkList CL;
    ElemType min,max;
    if(ListCreate_CL(CL)!= OK) 
    {
       printf("循环链表创建失败！！！\n");
       return -1;
    }
    scanf("%d%d",&min,&max);    
    ListDelete_CL(CL,min,max);   
    ListPrint_CL(CL);      
    return 0;
}
// Prepend Code End


#include <iostream>
using namespace std;

Status ListCreate_CL(LinkList &CL) {
  int n;
  cin >> n;

  LNode *p = CL = new LNode;

  while (n--) {
    LNode *s = new LNode;
    cin >> s->data;
    p->next = s;
    p = s;
  }

  p->next = CL;

  return OK;
}

void ListDelete_CL(LinkList &CL, ElemType min, ElemType max) {
  LNode *p = CL->next;

  if (p == CL)
    return;

  while (p->next != CL) {
    if (p->next->data > min && p->next->data < max) {
      LNode *q = p->next;
      p->next = q->next;
      delete q;
    } else {
      p = p->next;
    }
  }
}
