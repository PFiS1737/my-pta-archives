// 程序用链队列作存储结构，实现队列（元素为整型）的基本运算。
// 本题只需完成 DeQueue函数，然后提交系统。

// Sample Input
// 1 3 5 7 9 -1

// Sample Output
// Head:1
// Pop:1 3 5 7 9 NULL

// Prepend Code Start
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode* next;
}QNode;

typedef struct
{
    QNode* front;
    QNode* rear;
}LinkQueue;

void InitQNode(LinkQueue& Q)
{
    Q.front = new QNode;
    Q.rear = Q.front;
    Q.front->next = NULL;
}

bool GetHead(LinkQueue Q, ElemType& e)
{
    if (Q.front == Q.rear)
    {
        cout << "NULL" << endl;
        return  false;
    }
    e = Q.front->next->data;
    return true;
}

void EnQueue(LinkQueue &Q, ElemType e);//无需编写，题目会提供完整代码

bool DeQueue(LinkQueue &Q, ElemType &e);//待完成函数

int main()
{
    LinkQueue Q;
    ElemType x =0, e = 0;
    InitQNode(Q);
    cin >> x;
    while (x != -1)
    {
        EnQueue(Q, x);
        cin >> x;
    }
    cout << "Head:";
    if (GetHead(Q, e))
    {
        cout << e << endl;
    }
    cout << "Pop:";
    while (DeQueue(Q, e))
    {
        cout << e << ' ';
    }
    return 0;
}
// Prepend Code End

// 补充定义
void EnQueue(LinkQueue &Q, ElemType e) {
  QNode *p = new QNode;
  p->data = e;
  p->next = NULL;
  Q.rear->next = p;
  Q.rear = p;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
  if (Q.front->next && GetHead(Q, e)) {
    Q.front->next = Q.front->next->next;
    return true;
  }
  cout << "NULL" << endl;
  return false;
}
